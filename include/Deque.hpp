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
template<typename T, size_t chunk_size>
class DequeIterator
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef pointer* chunk;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef ptrdiff_t difference_type;
protected:
	chunk node;
	pointer current;
	pointer first;
	pointer last;

	void set_chunk(chunk new_chunk) {
		this->node = new_chunk;
		this->first = *new_chunk;
		this->last = this->first + chunk_size;
	}
public:
	DequeIterator():
		node(nullptr), current(nullptr), first(nullptr), last(nullptr) {}
	DequeIterator(DequeIterator const &other):
		node(other.node), current(other.current), first(other.first), last(other.last) {}
	DequeIterator(chunk node, size_type idx):
		node(node) {
		size_type map = (idx % 10);
		this->first = node[map];
		this->current = node[map] + (idx / 10);
		this->last = node[map] + chunk_size;
	}
	virtual ~DequeIterator() {}

	reference operator*() {
		return (*this->current);
	}
	const_reference operator*() const {
		return (*this->current);
	}
	pointer operator->() {
		return (this->current);
	}
	const_pointer operator->() const {
		return (this->current);
	}
	DequeIterator operator++(int) {
		DequeIterator tmp(*this);
		++*this;
		return (tmp);
	}
	DequeIterator &operator++() {
		++this->current;
		if (this->current == this->last) {
			this->set_chunk(this->node + 1);
			this->current = this->first;
		}
		return (*this);
	}
	DequeIterator operator--(int) {
		DequeIterator tmp(*this);
		--*this;
		return (tmp);
	}
	DequeIterator& operator--() {
		if (this->current == this->first) {
			this->set_chunk(this->node - 1);
			this->current = this->last;
		}
		--this->current;
		return (*this);
	}
	DequeIterator &operator+=(difference_type n) {
		difference_type offset = n + (this->current - first);
		if (offset >= 0 && offset < difference_type(chunk_size))
			this->current += n;
		else {
			difference_type node_offset;
			if (offset > 0)
				node_offset = offset / difference_type(chunk_size);
			else
				node_offset = -((-offset - 1) / difference_type(chunk_size)) - 1;
			this->set_chunk(this->node + node_offset);
			this->current = first + (offset - (node_offset * chunk_size));
		}

		return *this;
	}
	DequeIterator operator+(difference_type n) const {
		DequeIterator tmp(*this);
		return (tmp += n);
	}
	DequeIterator &operator-=(difference_type n) {
		return (*this += -n);
	}
	DequeIterator operator-(difference_type n) const {
		DequeIterator tmp(*this);
		return (tmp -= n);
	}
	reference operator[](difference_type index) const {
		return (*(*this + index));
	}

	bool operator==(DequeIterator const &other) const {
		return (this->current == other.current);
	}
	bool operator!=(DequeIterator const &other) const {
		return (this->current != other.current);
	}
	bool operator<(DequeIterator const &other) const {
		return (this->current < other.current);
	}
	bool operator<=(DequeIterator const &other) const {
		return (this->current <= other.current);
	}
	bool operator>(DequeIterator const &other) const {
		return (this->current > other.current);
	}
	bool operator>=(DequeIterator const &other) const {
		return (this->current >= other.current);
	}
};

template<typename T>
class Deque
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef pointer* chunk;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef ptrdiff_t difference_type;
	typedef DequeIterator<value_type, 10> iterator;
	typedef DequeIterator<value_type const, 10> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ReverseIterator<const_iterator> const_reverse_iterator;
private:
	chunk m_container;
	size_type m_start;
	size_type m_size;
	size_type m_chunk_count;
	size_type m_capacity;

	pointer allocate_pointer(void) {
		return ((pointer)::operator new (sizeof(value_type) * 10)); // Create Single Chunk
	}

	void ensure_capacity(size_type elements) {
		if (this->m_capacity == 0) {
			// Allocate new (chunk) and set everything to nullptr
			size_type rounded = (elements % 10);
			if (rounded > 0)
				elements += rounded;
			elements = (elements > 100) ? elements : 100;
			this->m_chunk_count = (elements / 10) + 1;
			this->m_container = (chunk)::operator new (sizeof(pointer) * this->m_chunk_count); // Create Map
			for (size_type i = 0; i < this->m_chunk_count; ++i)
				this->m_container[i] = nullptr;
			this->m_capacity = this->m_chunk_count * 10;
			this->m_start = 10 * (this->m_chunk_count / 2);
		} else if (this->m_capacity < elements) {
			do {
				this->m_capacity *= 2;
			} while (this->m_capacity < elements);
			size_type new_chunk_count = (this->m_capacity / 10) + 1;
			// allocate new (chunk)
			chunk tmp = (chunk)::operator new (sizeof(pointer) * new_chunk_count);
			size_type chunk_count_diff = (new_chunk_count - this->m_chunk_count) / 2;
			// Copy old (pointer)s to the new (chunk) -- set new (pointer)s to nullptr
			for (size_type j = 0; j < new_chunk_count; ++j) {
				if (j < chunk_count_diff || j > this->m_chunk_count)
					tmp[j] = nullptr;
				else
					tmp[chunk_count_diff + j] = this->m_container[j];
			}
			::operator delete(this->m_container);
			this->m_container = tmp;
			this->m_start = this->m_start + (chunk_count_diff * 10);
			this->m_chunk_count = new_chunk_count;
		}
	}
public:
	Deque():
		m_container(nullptr), m_start(0), m_size(0),
		m_chunk_count(0), m_capacity(0) {}
	Deque(size_type n, const_reference val=value_type()):
		m_container(nullptr), m_start(0), m_size(0),
		m_chunk_count(0), m_capacity(0) {
		this->assign(n, val);
	}
	Deque(iterator first, iterator last):
		m_container(nullptr), m_start(0), m_size(0),
		m_chunk_count(0), m_capacity(0) {
		this->assign(first, last);
	}
	Deque(Deque const &other):
		m_container(nullptr), m_start(0), m_size(0),
		m_chunk_count(0), m_capacity(0) {
		this->assign(other.begin(), other.end());
	}
	virtual ~Deque() {
		this->clear();
		for (size_type i = 0; i < (this->m_capacity / 10); ++i) {
			::operator delete(this->m_container[i]);
		}
		::operator delete(this->m_container);
	}

	Deque &operator=(Deque const &other) {
		this->assign(other.begin(), other.end());
	}

	iterator begin(void) {
		return (iterator(this->m_container, this->m_start));
	}
	const_iterator begin(void) const {
		return (const_iterator(this->m_container, this->m_start));
	}
	reverse_iterator rbegin(void) {
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void) {
		return (iterator(this->m_container, this->m_start + this->m_size));
	}
	const_iterator end(void) const {
		return (const_iterator(this->m_container, this->m_start + this->m_size));
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
		if (n > this->m_capacity) {
			this->ensure_capacity(n);
			while (this->m_size < n)
				this->push_back(val);
		} else if (n < this->m_capacity) {
			while (this->m_size > n)
				this->pop_back();
		}
	}

    reference operator[](size_type n) {
		size_type pos = (this->m_start + n);
		return (this->m_container[pos % 10][pos / 10]);
	}
    const_reference operator[](size_type n) const {
		size_type pos = (this->m_start + n);
		return (this->m_container[pos % 10][pos / 10]);
	}
    reference at(size_type n) {
		if (n < this->m_size)
			throw std::out_of_range("Deque index out of range");
		return (this->operator[](n));
	}
    const_reference at(size_type n) const {
		if (n < this->m_size)
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

	void assign(iterator first, iterator last); /* {
		this->clear();
		this->ensure_capacity(last - first);
		// TODO
	} */
    void assign(size_type n, const_reference val); /* {
		this->clear();
		this->ensure_capacity(n);
		// TODO
	} */

    void push_back(const_reference val) {
		this->ensure_capacity(this->m_size + 1);
		size_type pos = (this->m_start + this->m_size++);
		size_type chunk = (pos % 10);
		if (!this->m_container[chunk])
			this->m_container[chunk] = this->allocate_pointer();
		new(&this->m_container[chunk][pos / 10]) value_type(val);
	}
    void pop_back(void); // TODO

    void push_front(const_reference val); /* {
		this->ensure_capacity(this->m_size + 1);
		// TODO
	} */
    void pop_front(void); // TODO

    iterator insert(iterator position, const_reference val); /* {
		this->ensure_capacity(this->m_size + 1);
		// TODO
	} */
    void insert(iterator position, size_type n, const_reference val); /* {
		this->ensure_capacity(this->m_size + n);
		// TODO
	} */
    template<typename InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last); /* {
		this->ensure_capacity(this->m_size + (last - first));
		 // TODO
	} */

    iterator erase(iterator position); // TODO
    iterator erase(iterator first, iterator last); // TODO

    void swap(Deque &other) {
		chunk tmp = this->m_container;
		this->m_container = other.m_container;
		other.m_container = tmp;
		size_type stmp = this->m_size;
		this->m_size = other.m_size;
		other.m_size = stmp;
		stmp = this->m_capacity;
		this->m_capacity = other.m_capacity;
		other.m_capacity = stmp;
		stmp = this->m_start;
		this->m_start = other.m_start;
		other.m_start = stmp;
		stmp = this->m_chunk_count;
		this->m_chunk_count = other.m_chunk_count;
		other.m_chunk_count = stmp;
	}
    void clear(void) {
		// while (this->m_first != this->m_last) {
		// 	(*this->m_first++).value_type::~value_type(); // TODO
		// }
		// size_type chunk_count = (this->m_capacity / 10) + 1;
		// this->m_first = this->m_container[chunk_count / 2];
		// this->m_last = this->m_first;
		// this->m_size = 0;
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