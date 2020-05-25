/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/05 16:43:57 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include "Iterator.hpp"
# include "Algorithm.hpp"

namespace ft
{
template<typename T>
class VectorIterator: IteratorTrait
{
public:
	typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const * const_pointer;
    typedef value_type& reference;
    typedef value_type const & const_reference;
    typedef std::ptrdiff_t difference_type;
protected:
	pointer p;
public:
	VectorIterator(): p(nullptr) {}
	VectorIterator(pointer p): p(p) {}
	VectorIterator(VectorIterator const &other): p(other.p) {}
	virtual ~VectorIterator() {}

	VectorIterator &operator=(VectorIterator const &other) {
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		return (*this->p);
	}
	const_reference operator*() const {
		return (*this->p);
	}
	pointer operator->() {
		return (this->p);
	}
	const_pointer operator->() const {
		return (this->p);
	}
    reference operator[](int val) {
		return (*(this->p + val));
	}
    const_reference operator[](int val) const {
		return (*(this->p + val));
	}

	VectorIterator operator++(int) {
		VectorIterator tmp(*this);
		++this->p;
		return (tmp);
	}
	VectorIterator &operator++() {
		++this->p;
		return (*this);
	}
	VectorIterator operator--(int) {
		VectorIterator tmp(*this);
		--this->p;
		return (tmp);
	}
	VectorIterator &operator--() {
		--this->p;
		return (*this);
	}

	VectorIterator &operator+=(int value) {
		this->p += value;
		return (*this);
	}
	VectorIterator operator+(int value) const {
		VectorIterator tmp(*this);
		return (tmp += value);
	}
	VectorIterator &operator-=(int value) {
		this->p -= value;
		return (*this);
	}
	VectorIterator operator-(int value) const {
		VectorIterator tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(VectorIterator const &other) const {
		return (this->p - other.p);
	}

	bool operator==(VectorIterator const &other) const {
		return (this->p == other.p);
	}
	bool operator!=(VectorIterator const &other) const {
		return (this->p != other.p);
	}
	bool operator<(VectorIterator const &other) const {
		return (this->p < other.p);
	}
	bool operator<=(VectorIterator const &other) const {
		return (this->p <= other.p);
	}
	bool operator>(VectorIterator const &other) const {
		return (this->p > other.p);
	}
	bool operator>=(VectorIterator const &other) const {
		return (this->p >= other.p);
	}
};

template<typename T>
class Vector
{
public:
    typedef std::ptrdiff_t difference_type;
	typedef unsigned long size_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & const_reference;
	typedef VectorIterator<value_type> iterator;
	typedef VectorIterator<value_type const> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ReverseIterator<const_iterator> const_reverse_iterator;
private:
	pointer m_container;
	size_type m_capacity;
	size_type m_size;

	void copy_construct(size_type idx, const_reference val) {
		new(&this->m_container[idx]) value_type(val);
	}
public:
	Vector(): m_capacity(0), m_size(0), m_container(nullptr) {}
	Vector(size_type n, const_reference val=value_type()):
		m_capacity(0), m_size(0), m_container(nullptr) {
		this->assign(n, val);
	}
	Vector(iterator first, iterator last):
		m_capacity(0), m_size(0), m_container(nullptr) {
		this->assign(first, last);
	}
	Vector(Vector const &other):
		m_capacity(0), m_size(other.m_size), m_container(nullptr) {
		this->reserve(other.m_capacity);
		// this->assign(other.begin(), other.end());
		std::memcpy(static_cast<void*>(this->m_container), static_cast<void*>(other.m_container), other.m_size * sizeof(value_type));
	}
	virtual ~Vector() {
		this->clear();
		if (this->m_container)
			::operator delete(this->m_container);
	}

	Vector &operator=(Vector const &other) {
		this->clear();
		if (this->m_capacity < other.m_capacity)
			this->reserve(other.m_capacity);
		// this->assign(other.begin(), other.end());
		std::memcpy(static_cast<void*>(this->m_container), static_cast<void*>(other.m_container), other.m_size * sizeof(value_type));
		return (*this);
	}

	iterator begin(void) {
		return (iterator(this->m_container));
	}
	const_iterator begin(void) const {
		return (const_iterator(this->m_container));
	}
	reverse_iterator rbegin(void) {
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void) {
		return (iterator(&(this->m_container[this->m_size])));
	}
	const_iterator end(void) const {
		return (const_iterator(&(this->m_container[this->m_size])));
	}
	reverse_iterator rend(void) {
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const {
		return (const_reverse_iterator(this->begin()));
	}

	size_type size(void) const {
		return (this->m_size);
	}

	size_type max_size(void) const {
		return (ft::min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / sizeof(value_type)));
	}

	void resize(size_type size, value_type val=value_type()) {
		if (size > this->m_capacity)
			this->reserve(size);
		if (size > this->m_size) {
			for (size_type i = this->m_size; i < size; ++i)
				this->copy_construct(i, val);
			this->m_size = size;
		} else if (size < this->m_size) {
			for (size_type i = size; i < this->m_size; ++i)
				this->m_container[i].value_type::~value_type();
			this->m_size = size;
		}
	}

	size_type capacity(void) const {
		return (this->m_capacity);
	}

	bool empty(void) const {
		return (this->m_size == 0);
	}

	void reserve(size_type size) {
		if (this->m_capacity == 0) {
			size = (size > 128) ? size : 128;
			this->m_container = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
			this->m_capacity = size;
		} else if (size > this->m_capacity) {
			size = (size > this->m_capacity * 2) ? size : this->m_capacity * 2;
			value_type *tmp = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
			if (this->m_container) {
				//std::memmove(static_cast<void*>(tmp), static_cast<void*>(this->container), this->m_size * sizeof(value_type));
				for (size_t i = 0; i < this->m_size; ++i)
					new(&tmp[i]) value_type(this->m_container[i]);
				::operator delete(this->m_container);
			}
			this->m_container = tmp;
			this->m_capacity = size;
		}
	}

	reference operator[](size_type idx) {
		return (this->m_container[idx]);
	}
	const_reference operator[](size_type idx) const {
		return (this->m_container[idx]);
	}
	reference at(size_type idx) {
		if (idx >= this->m_size)
			throw std::out_of_range("Vector index out of range");
		return (this->m_container[idx]);
	}
	const_reference at(size_type idx) const {
		if (idx >= this->m_size)
			throw std::out_of_range("Vector index out of range");
		return (this->m_container[idx]);
	}

	reference front(void) {
		return (this->m_container[0]);
	}
	const_reference front(void) const {
		return (this->m_container[0]);
	}
	reference back(void) {
		return (this->m_container[this->m_size - 1]);
	}
	const_reference back(void) const {
		return (this->m_container[this->m_size - 1]);
	}

	void assign(iterator first, iterator last) {
		size_t length = last - first;
		if (length > this->m_capacity)
			this->reserve(length);
		size_t i = 0;
		while (first != last) {
			if (i >= this->m_size)
				this->copy_construct(i, *first);
			else
				this->m_container[i] = *first;
			++first;
			++i;
		}
		while (i < this->m_size)
			this->m_container[i++].value_type::~value_type();
		this->m_size = length;
	}
	void assign(const_iterator first, const_iterator last) {
		size_t length = last - first;
		if (length > this->m_capacity)
			this->reserve(length);
		size_t i = 0;
		while (first != last) {
			if (i >= this->m_size)
				this->copy_construct(i, *first);
			else
				this->m_container[i] = *first;
			++first;
			++i;
		}
		while (i < this->m_size)
			this->m_container[i++].value_type::~value_type();
		this->m_size = length;
	}
	void assign(size_type size, const_reference val) {
		if (size > this->m_capacity)
			this->reserve(size);
		size_t i = 0;
		while (i < size) {
			if (i >= this->m_size)
				this->copy_construct(i, val);
			else
				this->m_container[i] = val;
			++i;
		}
		while (i < this->m_size)
			this->m_container[i++].value_type::~value_type();
		this->m_size = size;
	}

	void push_back(const_reference val) {
		if (this->m_size == this->m_capacity)
			this->reserve(this->m_capacity * 2);
		new(&this->m_container[this->m_size++]) value_type(val);
	}
	void pop_back(void) {
		this->m_container[--this->m_size].value_type::~value_type();
	}

	iterator insert(iterator position, const_reference val) {
		this->insert(position, 1, val);
		return (++position);
	}
	void insert(iterator position, size_type size, const_reference val) {
		iterator it = this->begin();
		if (this->m_size + size >= this->m_capacity)
			this->reserve(this->m_size + size);
		size_type i = 0;
		while (it != position) {
			++it;
			++i;
		}
		// std::memmove
		for (size_type j = this->m_size; j >= 1 && j >= i; j--)
			this->copy_construct(i + j + size - 1, this->m_container[j - 1]);
		for (size_type j = 0; j < size; j++)
			this->copy_construct(i + j, val);
		this->m_size += size;
	}
	void insert(iterator position, iterator first, iterator last) {
		size_type size = last - first;
		iterator it = this->begin();
		if (this->m_size + size >= this->m_capacity)
			this->reserve(this->m_size + size);
		size_type i = 0;
		while (it != position) {
			++it;
			++i;
		}
		// std::memmove
		for (size_type j = this->m_size - 1; j > i + 1; j++)
			this->copy_construct(i + j + size, this->m_container[ + j - 1]);
		for (size_type j = 0; j < size; j++)
			this->copy_construct(i + j, *first++);
		this->m_size += size;
	}

	iterator erase(iterator position) {
		iterator tmp(position);
		++tmp;
		return (this->erase(position, tmp));
	}
	iterator erase(iterator first, iterator last) {
		iterator it = this->begin();
		size_type i = 0;
		while (it != first) {
			++it;
			++i;
		}
		if (it == this->end())
			return (this->end());
		size_type returnPosition = i;
		size_type deletedElements = 0;
		size_type stopPos = i;
		while (first != last) {
			(*first++).value_type::~value_type();
			++deletedElements;
			++stopPos;
		}
		// std::memmove ?
		for ( ; stopPos < this->m_size; ++stopPos)
			this->copy_construct(i++, this->m_container[stopPos]);
		this->m_size -= deletedElements;
		return (iterator(&this->m_container[returnPosition]));
	}

	void swap(Vector &other) {
		ft::swap(this->m_container, other.m_container);
		ft::swap(this->m_capacity, other.m_capacity);
		ft::swap(this->m_size, other.m_size);
	}

	void clear(void) {
		for (size_type i = 0; i < this->m_size; i++)
			this->m_container[i].value_type::~value_type();
		this->m_size = 0;
	}
};

template<typename T>
bool operator==(Vector<T> const &lhs, Vector<T> const &rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template<typename T>
bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (rhs < lhs);
}

template<typename T>
bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (!(lhs < rhs));
}

template<typename T>
void swap(Vector<T> &x, Vector<T> &y) {
	x.swap(y);
}
}

#endif
