/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:46 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/11 18:58:28 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <limits>
# include "Node.hpp"
# include "Iterator.hpp"
# include "Algorithm.hpp"

namespace ft
{
template<typename T>
class Deque;

template<typename T>
class DequeIterator: IteratorTrait
{
	friend class Deque<T>;
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef ptrdiff_t difference_type;
protected:
	pointer const * p;
public:
	DequeIterator():
		p(nullptr) {}
	DequeIterator(DequeIterator const &other):
		p(other.p) {}
	DequeIterator(pointer const * p):
		p(p) {}
	virtual ~DequeIterator() {}

	reference operator*() {
		return (**this->p);
	}
	const_reference operator*() const {
		return (**this->p);
	}
	pointer operator->() {
		return (*this->p);
	}
	const_pointer operator->() const {
		return (*this->p);
	}
    reference operator[](int val) {
		return (**(this->p + val));
	}
    const_reference operator[](int val) const {
		return (**(this->p + val));
	}

	DequeIterator operator++(int) {
		DequeIterator tmp(*this);
		++this->p;
		return (tmp);
	}
	DequeIterator &operator++() {
		++this->p;
		return (*this);
	}
	DequeIterator operator--(int) {
		DequeIterator tmp(*this);
		--this->p;
		return (tmp);
	}
	DequeIterator &operator--() {
		--this->p;
		return (*this);
	}

	DequeIterator &operator+=(int value) {
		this->p += value;
		return (*this);
	}
	DequeIterator operator+(int value) const {
		DequeIterator tmp(*this);
		return (tmp += value);
	}
	DequeIterator &operator-=(int value) {
		this->p -= value;
		return (*this);
	}
	DequeIterator operator-(int value) const {
		DequeIterator tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(DequeIterator const &other) const {
		return (this->p - other.p);
	}

	bool operator==(DequeIterator const &other) const {
		return (this->p == other.p);
	}
	bool operator!=(DequeIterator const &other) const {
		return (this->p != other.p);
	}
	bool operator<(DequeIterator const &other) const {
		return (this->p < other.p);
	}
	bool operator<=(DequeIterator const &other) const {
		return (this->p <= other.p);
	}
	bool operator>(DequeIterator const &other) const {
		return (this->p > other.p);
	}
	bool operator>=(DequeIterator const &other) const {
		return (this->p >= other.p);
	}
};

template<typename T>
class Deque
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef ptrdiff_t difference_type;
	typedef DequeIterator<value_type> iterator;
	typedef DequeIterator<value_type> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ReverseIterator<const_iterator> const_reverse_iterator;
private:
	pointer* m_container;
	size_type m_capacity;
	size_type m_start;
	size_type m_size;

	void reserve(size_type capacity) {
		if (capacity > this->m_capacity) {
			// Double capacity on every new allocations
			size_type real_capacity = (this->m_capacity == 0) ? (capacity > 64) ? capacity : 64
									: (this->m_capacity * 2 > capacity) ? this->m_capacity * 2 : capacity;
			// Allocate an array of *blocks* Block*
			pointer* tmp = static_cast<pointer*>(::operator new(sizeof(pointer*) * real_capacity));
			// Offset to center the old blocks - 2 center, 1 back, 0 front
			size_type offset = (real_capacity / 2) - (this->m_size / 2);
			// Move old blocks
			for (size_type i = offset, j = this->m_start; j < this->m_start + this->m_size; ++i, ++j)
				tmp[i] = this->m_container[j];
			// Move tmp to m_container
			::operator delete(this->m_container);
			this->m_container = tmp;
			this->m_capacity = real_capacity;
			this->m_start = offset;
		}
	}

	void pre_insert(size_type count, size_type index) {
		// Capacity
		if (this->m_start + this->m_size + count - 1 >= this->m_capacity) {
			this->reserve(this->m_capacity + this->m_start + this->m_size + count);
		}
		// If there is not enough space on the right move everything to the right
		size_type move_start = this->m_start;
		if (this->m_start + count + this->m_size > this->m_capacity) {
			size_type missing_space = (this->m_start + count + this->m_size) - this->m_capacity;
			// everything between m_start and relative_index is moved to the right
			for (size_t i = 0; i < missing_space; i++) {
				this->m_container[this->m_start - missing_space + i] = this->m_container[this->m_start + i];
			}
			this->m_start -= missing_space;
		}
		// Move everything to the right
		size_type relative_index = move_start + index;
		for (size_type j = move_start + this->m_size; j > move_start && j >= relative_index; --j) {
			this->m_container[j + count - 1] = this->m_container[j - 1];
		}
	}
public:
	Deque(): m_container(nullptr), m_capacity(0), m_start(0), m_size(0) {}

	Deque(size_type n, const_reference val=value_type()):
		m_container(nullptr), m_capacity(0), m_start(0), m_size(0) {
		this->assign(n, val);
	}

	Deque(iterator first, iterator last):
		m_container(nullptr), m_capacity(0), m_start(0), m_size(0) {
		this->assign(first, last);
	}

	Deque(Deque const &other):
		m_container(nullptr), m_capacity(0), m_start(0), m_size(0) {
		this->assign(other.begin(), other.end());
	}

	virtual ~Deque() {
		this->clear();
		::operator delete(this->m_container);
	}

	Deque &operator=(Deque const &other) {
		this->assign(other.begin(), other.end());
	}

	iterator begin(void) {
		return (iterator(this->m_container + this->m_start));
	}

	const_iterator begin(void) const {
		return (const_iterator(this->m_container + this->m_start));
	}

	reverse_iterator rbegin(void) {
		return (reverse_iterator(this->end()));
	}

	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}

	iterator end(void) {
		return (iterator(this->m_container + this->m_start + this->m_size));
	}

	const_iterator end(void) const {
		return (const_iterator(this->m_container + this->m_start + this->m_size));
	}

	reverse_iterator rend(void) {
		return (reverse_iterator(this->begin()));
	}

	const_reverse_iterator rend(void) const {
		return (const_reverse_iterator(this->begin()));
	}

	bool empty(void) const {
		return (this->m_size == 0);
	}

	size_type size(void) const {
		return (this->m_size);
	}

	size_type max_size(void) const {
		return (ft::min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / sizeof(value_type)));
	}

	void resize(size_type n, value_type val=value_type()) {
		if (n > this->m_size) {
			this->insert(this->end(), n - this->m_size, val);
		} else if (n < this->m_size) {
			for (size_type i = n; i < this->m_size; ++i) {
				delete this->m_container[this->m_start + i];
			}
			this->m_size = n;
		}
	}

    reference operator[](size_type n) {
		return (*this->m_container[this->m_start + n]);
	}

    const_reference operator[](size_type n) const {
		return (*this->m_container[this->m_start + n]);
	}

    reference at(size_type n) {
		if (n >= this->m_size)
			throw std::out_of_range("Deque index out of range");
		return (this->operator[](n));
	}

    const_reference at(size_type n) const {
		if (n >= this->m_size)
			throw std::out_of_range("Deque index out of range");
		return (this->operator[](n));
	}

    reference front(void) {
		return (this->operator[](0));
	}

    const_reference front(void) const {
		return (this->operator[](0));
	}

    reference back(void) {
		return (this->operator[](this->m_size - 1));
	}

    const_reference back(void) const {
		return (this->operator[](this->m_size - 1));
	}

	void assign(iterator first, iterator last) {
		this->clear();
		size_type size = last - first;
		if (this->m_capacity < size) {
			this->reserve(size);
		}
		// Center the assign
		this->m_start = (this->m_capacity / 2) - ((this->m_capacity - size) / 2);
		while (first != last) {
			this->m_container[this->m_start + this->m_size++] = new value_type(*first);
			++first;
		}
	}
    void assign(size_type size, const_reference val) {
		this->clear();
		if (this->m_capacity < size) {
			this->reserve(size);
		}
		// Center the assign
		this->m_start = (this->m_capacity / 2) - ((this->m_capacity - size) / 2);
		for (; this->m_size < size; ++this->m_size) {
			this->m_container[this->m_start + this->m_size] = new value_type(val);
		}
	}

    void push_back(const_reference val) {
		// Capacity on the right
		if (this->m_start + this->m_size >= this->m_capacity) {
			this->reserve(this->m_capacity + 1);
		}
		// Assign
		this->m_container[this->m_start + this->m_size++] = new value_type(val);
	}
    void pop_back(void) {
		delete this->m_container[this->m_start + --this->m_size];
	}

	void push_front(const_reference val) {
		// Capacity on the right
		if (this->m_start == 0) {
			this->reserve(this->m_capacity + 1);
		}
		// Assign
		this->m_container[--this->m_start] = new value_type(val);
		++this->m_size;
	}
    void pop_front(void) {
		delete this->m_container[this->m_start++];
		--this->m_size;
	}

	iterator insert(iterator position, const_reference val) {
		const size_type index = position.p - this->m_container - this->m_start;
		this->insert(position, 1, val);
		return (this->m_container + this->m_start + index);
	}
    void insert(iterator position, size_type count, const_reference val) {
		if (count == 0) return;
		// Index -- before possible reallocation
		size_type index = position.p - this->m_container - this->m_start;
		this->pre_insert(count, index);
		// Insert on the left of position
		size_type relative_index = this->m_start + index;
		for (size_type i = 0; i < count; ++i) {
			this->m_container[relative_index + i] = new value_type(val);
		}
		this->m_size += count;
	}
    void insert(iterator position, iterator first, iterator last) {
		// Index relative to container end -- before possible reallocation
		const size_type count = last - first;
		if (count == 0) return;
		const size_type index = position.p - this->m_container - this->m_start;
		this->pre_insert(count, index);
		// Insert on the left of position
		size_type relative_index = this->m_start + index;
		size_type i = 0;
		while (first != last) {
			this->m_container[relative_index + i++] = new value_type(*first);
			++first;
		}
		this->m_size += count;
	}

    iterator erase(iterator position) {
		iterator tmp(position);
		++tmp;
		return (this->erase(position, tmp));
	}
    iterator erase(iterator first, iterator last) {
		if (first == last) return last;
		const size_type count = last - first;
		const size_type start_index = first.p - this->m_container - this->m_start;
		const size_type relative_index = this->m_start + start_index;
		const size_type relative_end_index = last.p - this->m_container;
		// Remove elements
		for (size_type i = 0; i < count; ++i) {
			delete this->m_container[relative_index + i];
		}
		// Move elements after erased to fill gaps
		for (size_type i = this->m_start + this->m_size, j = 0; i > relative_end_index; --i, ++j) {
			this->m_container[relative_index + j] = this->m_container[i - 1];
		}
		this->m_size -= count;
		return (this->end());
	}

	void swap(Deque &other) {
		pointer* tmp = this->m_container;
		this->m_container = other.m_container;
		other.m_container = tmp;
		ft::swap(this->m_capacity, other.m_capacity);
		ft::swap(this->m_start, other.m_start);
		ft::swap(this->m_size, other.m_size);
	}

	void clear(void) {
		for (size_type i = 0; i < this->m_size; ++i)
			delete this->m_container[this->m_start + i];
		this->m_start = this->m_capacity / 2;
		this->m_size = 0;
	}
};

template<typename T>
bool operator==(Deque<T> const &lhs, Deque<T> const &rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template<typename T>
bool operator!=(Deque<T> const &lhs, Deque<T> const &rhs) {
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(Deque<T> const &lhs, Deque<T> const &rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(Deque<T> const &lhs, Deque<T> const &rhs) {
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(Deque<T> const &lhs, Deque<T> const &rhs) {
	return (rhs < lhs);
}

template<typename T>
bool operator>=(Deque<T> const &lhs, Deque<T> const &rhs) {
	return (!(lhs < rhs));
}

template<typename T>
void swap(Deque<T> &x, Deque<T> &y) {
	x.swap(y);
}
}

#endif