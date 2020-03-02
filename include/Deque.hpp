/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:46 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/02 17:47:51 by ncolomer         ###   ########.fr       */
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
	typedef T value_type;
	typedef value_type* pointer;
	typedef pointer* chunk;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef ptrdiff_t difference_type;
protected:
	pointer current;
	pointer first;
	pointer last;
	chunk node;

	void set_chunk(chunk new_chunk) {
		this->node = new_chunk;
		this->first = *new_chunk;
		this->last = this->first + chunk_size;
	}
public:
	DequeIterator():
		current(nullptr), first(nullptr), last(nullptr), node(nullptr) {}
	DequeIterator(DequeIterator const &other):
		current(other.current), first(other.first), last(other.last), node(other.node) {}
	DequeIterator(pointer current, chunk node):
		current(current), first(*other.node), last(*other.node + chunk_size), node(node) {}
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
	iterator m_first;
	iterator m_last;
	chunk m_container;
	size_type m_capacity;
	size_type m_size;

	void ensure_capacity(size_type elements) {
		if (this->m_capacity == 0) {
			size_type rounded = (elements % 10);
			if (rounded > 0) {
				elements += rounded;
			}
			elements = (elements > 100) ? elements : 100;
			size_type chunk_count = (elements / 10) + 1;
			this->m_container = (chunk)::operator new (sizeof(pointer) * chunk_count); // Create Map
			for (size_type i = 0; i < chunk_count; ++i) {
				this->m_container[i] = nullptr;
				// (pointer)::operator new (sizeof(value_type) * 10); // Create Single Chunk
			}
			this->m_capacity = chunk_count * 10;
			this->m_first = this->m_container[chunk_count / 2];
			this->m_last = this->m_first;
		} else if (this->m_capacity < elements) {
			size_type const oldCapacity = this->m_capacity;
			do {
				this->m_capacity *= 2;
			} while (this->m_capacity < elements);
			size_type chunk_count = (this->m_capacity / 10) + 1;
			chunk tmp = (chunk)::operator new (sizeof(pointer) * chunk_count);

			// TODO: Find which new pointers to allocate in the map (the first x and last y)

			size_type new_first_pos = (chunk_count / 2) - ((this->size / 10) / 2);
			iterator new_first = tmp[new_first_pos] + (this->size % 10);
			iterator old_first = this->begin();
			while (old_first != this->end()) {
				new (new_first++) value_type(*old_first++);
			}
			::operator delete(this->m_container);
			this->m_container = tmp;
			this->m_first = tmp[new_first_pos] + (this->size % 10);
			this->m_last = new_first;
		}
	}
public:
	Deque():
		m_first(nullptr), m_last(nullptr),
		m_container(nullptr), m_capacity(0), m_size(0) {}
	Deque(size_type n, const_reference val=value_type()):
		m_first(nullptr), m_last(nullptr),
		m_container(nullptr), m_capacity(0), m_size(0) {
		this->assign(n, val);
	}
	Deque(iterator first, iterator last):
		m_first(nullptr), m_last(nullptr),
		m_container(nullptr), m_capacity(0), m_size(0) {
		this->assign(first, last);
	}
	Deque(Deque const &other):
		m_first(nullptr), m_last(nullptr),
		m_container(nullptr), m_capacity(0), m_size(0) {
		this->assign(other.m_first, other.m_last);
	}
	virtual ~Deque() {
		this->clear();
		for (size_type i = 0; i < (this->m_capacity / 10); ++i) {
			::operator delete(this->m_container[i]);
		}
		::operator delete(this->m_container);
	}

	Deque &operator=(Deque const &other) {
		this->assign(other.m_first, other.m_last);
	}

	iterator begin(void) {
		return (iterator(this->m_first, ));
	}
	const_iterator begin(void) const {
		return (const_iterator(this->m_first));
	}
	reverse_iterator rbegin(void) {
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void) {
		return (iterator(this->m_last));
	}
	const_iterator end(void) const {
		return (const_iterator(this->m_last));
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
		return (std::numeric_limits<value_type>::max() - 1); // TODO
	}
    void resize(size_type n, value_type val=value_type()); // TODO

    reference operator[](size_type n) {
		return (this->m_first[n]);
	}
    const_reference operator[](size_type n) const {
		return (this->m_first[n]);
	}
    reference at(size_type n) {
		if (n < this->m_size)
			throw std::out_of_range("Deque index out of range");
		return (this->m_first[n]);
	}
    const_reference at(size_type n) const {
		if (n < this->m_size)
			throw std::out_of_range("Deque index out of range");
		return (this->m_first[n]);
	}

    reference front(void) {
		return (*this->m_first);
	}
    const_reference front(void) const {
		return (*this->m_first);
	}
    reference back(void) {
		iterator tmp = m_last;
		--tmp;
		return (*--tmp);
	}
    const_reference back(void) const {
		iterator tmp = m_last;
		--tmp;
		return (*--tmp);
	}

	void assign(iterator first, iterator last) {
		this->clear();
		this->ensure_capacity(last - first);
		 // TODO
	}
    void assign(size_type n, const_reference val) {
		this->clear();
		this->ensure_capacity(n);
		// TODO
	}

    void push_back(const_reference val) {
		this->ensure_capacity(this->m_size + 1);
		// TODO
	}
    void pop_back(void); // TODO

    void push_front(const_reference val) {
		this->ensure_capacity(this->m_size + 1);
		// TODO
	}
    void pop_front(void); // TODO

    iterator insert(iterator position, const_reference val) {
		this->ensure_capacity(this->m_size + 1);
		// TODO
	}
    void insert(iterator position, size_type n, const_reference val) {
		this->ensure_capacity(this->m_size + n);
		// TODO
	}
    template<typename InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last) {
		this->ensure_capacity(this->m_size + (last - first));
		 // TODO
	}

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
		iterator itmp = this->m_first;
		this->m_first = other.m_first;
		other.m_first = itmp;
		itmp = this->m_last;
		this->m_last = other.m_last;
		other.m_last = itmp;
	}
    void clear(void) {
		while (this->m_first != this->m_last) {
			// (*this->m_first++).value_type::~value_type(); // TODO
		}
		size_type chunk_count = (this->m_capacity / 10) + 1;
		this->m_first = this->m_container[chunk_count / 2];
		this->m_last = this->m_first;
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