/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 19:07:54 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstring>
# include <cassert>
# include <cstddef>
# include <cmath>
# include "include/Iterator.hpp"
# include "include/Algorithm.hpp"

namespace ft
{
template<typename T>
class Vector
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & const_reference;
	typedef Iterator<value_type> iterator;
	typedef Iterator<value_type const> const_iterator;
	typedef ReverseIterator<value_type> reverse_iterator;
	typedef ReverseIterator<value_type const> const_reverse_iterator;
private:
	size_type capacity_;
	size_type size_;
	pointer container;

	void copy_construct(size_type idx, const_reference val)
	{
		new(&this->container[idx]) value_type(val);
	}
public:
	Vector():
		capacity_(0), size_(0), container(nullptr)
	{
	}
	Vector(size_type n, const_reference val=value_type()):
		capacity_(0), size_(0), container(nullptr)
	{
		this->assign(n, val);
	}
	Vector(iterator first, iterator last):
		capacity_(0), size_(0), container(nullptr)
	{
		this->assign(first, last);
	}
	Vector(Vector const &other):
		capacity_(0), size_(other.size_), container(nullptr)
	{
		this->reserve(other.capacity_);
		// this->assign(other.begin(), other.end());
		std::memcpy(static_cast<void*>(this->container), static_cast<void*>(other.container), other.size_ * sizeof(value_type));
	}
	virtual ~Vector()
	{
		this->clear();
		if (this->container)
			::operator delete(this->container);
	}

	Vector &operator=(Vector const &other)
	{
		this->clear();
		if (this->capacity_ < other.capacity_)
			this->reserve(other.capacity_);
		// this->assign(other.begin(), other.end());
		std::memcpy(static_cast<void*>(this->container), static_cast<void*>(other.container), other.size_ * sizeof(value_type));
		return (*this);
	}

	iterator begin(void)
	{
		return (iterator(this->container));
	}
	const_iterator begin(void) const
	{
		return (const_iterator(this->container));
	}
	reverse_iterator rbegin(void)
	{
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const
	{
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void)
	{
		return (iterator(&(this->container[this->size_])));
	}
	const_iterator end(void) const
	{
		return (const_iterator(&(this->container[this->size_])));
	}
	reverse_iterator rend(void)
	{
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const
	{
		return (const_reverse_iterator(this->begin()));
	}

	size_type size(void) const
	{
		return (this->size_);
	}

	size_type max_size(void) const
	{
		return (((std::pow(2, 64) - 1) / sizeof(value_type)) - 1);
	}

	void resize(size_type size, value_type val=value_type())
	{
		if (size > this->capacity_)
			this->reserve(size);
		if (size > this->size_)
		{
			for (size_type i = this->size_; i < size; ++i)
				this->copy_construct(i, val);
			this->size_ = size;
		}
		else if (size < this->size_)
		{
			for (size_type i = size; i < this->size_; ++i)
				this->container[i].value_type::~value_type();
			this->size_ = size;
		}
	}

	size_type capacity(void) const
	{
		return (this->capacity_);
	}

	bool empty(void) const
	{
		return (this->size_ == 0);
	}

	void reserve(size_type size)
	{
		if (this->capacity_ == 0)
		{
			size = (size > 128) ? size : 128;
			this->container = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
			this->capacity_ = size;
		}
		else if (size > this->capacity_)
		{
			size = (size > this->capacity_ * 2) ? size : this->capacity_ * 2;
			value_type *tmp = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
			if (this->container)
			{
				//std::memmove(static_cast<void*>(tmp), static_cast<void*>(this->container), this->size_ * sizeof(value_type));
				for (size_t i = 0; i < this->size_; ++i)
					new(&tmp[i]) value_type(this->container[i]);
				::operator delete(this->container);
			}
			this->container = tmp;
			this->capacity_ = size;
		}
	}

	reference operator[](size_type idx)
	{
		assert(idx < this->size_);
		return (this->at(idx));
	}
	const_reference operator[](size_type idx) const
	{
		assert(idx < this->size_);
		return (this->at(idx));
	}
	reference at(size_type idx)
	{
		assert(idx < this->size_);
		return (this->container[idx]);
	}
	const_reference at(size_type idx) const
	{
		assert(idx < this->size_);
		return (this->container[idx]);
	}

	reference front(void)
	{
		assert(!this->empty());
		return (this->container[0]);
	}
	const_reference front(void) const
	{
		assert(!this->empty());
		return (this->container[0]);
	}
	reference back(void)
	{
		assert(!this->empty());
		return (this->container[this->size_ - 1]);
	}
	const_reference back(void) const
	{
		assert(!this->empty());
		return (this->container[this->size_ - 1]);
	}

	void assign(iterator first, iterator last)
	{
		size_t length = last - first;
		if (length > this->capacity_)
			this->reserve(length);
		size_t i = 0;
		while (first != last)
		{
			if (i >= this->size_)
				this->copy_construct(i, *first);
			else
				this->container[i] = *first;
			++first;
			++i;
		}
		while (i < this->size_)
			this->container[i++].value_type::~value_type();
		this->size_ = length;
	}
	void assign(const_iterator first, const_iterator last)
	{
		size_t length = last - first;
		if (length > this->capacity_)
			this->reserve(length);
		size_t i = 0;
		while (first != last)
		{
			if (i >= this->size_)
				this->copy_construct(i, *first);
			else
				this->container[i] = *first;
			++first;
			++i;
		}
		while (i < this->size_)
			this->container[i++].value_type::~value_type();
		this->size_ = length;
	}
	void assign(size_type size, const_reference val)
	{
		if (size > this->capacity_)
			this->reserve(size);
		size_t i = 0;
		while (i < size)
		{
			if (i >= this->size_)
				this->copy_construct(i, val);
			else
				this->container[i] = val;
			++i;
		}
		while (i < this->size_)
			this->container[i++].value_type::~value_type();
		this->size_ = size;
	}

	void push_back(const_reference val)
	{
		if (this->size_ == this->capacity_)
			this->reserve(this->capacity_ * 2);
		new(&this->container[this->size_++]) value_type(val);
	}
	void pop_back(void)
	{
		assert(!this->empty());
		this->container[--this->size_].value_type::~value_type();
	}

	iterator insert(iterator position, const_reference val)
	{
		this->insert(position, 1, val);
		return (++position);
	}
	void insert(iterator position, size_type size, const_reference val)
	{
		iterator it = this->begin();
		if (this->size_ + size >= this->capacity_)
			this->reserve(this->size_ + size);
		size_type i = 0;
		while (it != position)
		{
			++it;
			++i;
		}
		// std::memmove
		for (size_type j = this->size_; j >= 1 && j >= i; j--)
			this->copy_construct(i + j + size - 1, this->container[j - 1]);
		for (size_type j = 0; j < size; j++)
			this->copy_construct(i + j, val);
		this->size_ += size;
	}
	void insert(iterator position, iterator first, iterator last)
	{
		size_type size = last - first;
		iterator it = this->begin();
		if (this->size_ + size >= this->capacity_)
			this->reserve(this->size_ + size);
		size_type i = 0;
		while (it != position)
		{
			++it;
			++i;
		}
		// std::memmove
		for (size_type j = this->size_ - 1; j > i + 1; j++)
			this->copy_construct(i + j + size, this->container[ + j - 1]);
		for (size_type j = 0; j < size; j++)
			this->copy_construct(i + j, *first++);
		this->size_ += size;
	}

	iterator erase(iterator position)
	{
		iterator tmp(position);
		++tmp;
		return (this->erase(position, tmp));
	}
	iterator erase(iterator first, iterator last)
	{
		iterator it = this->begin();
		size_type i = 0;
		while (it != first)
		{
			++it;
			++i;
		}
		if (it == this->end())
			return (this->end());
		size_type returnPosition = i;
		size_type deletedElements = 0;
		size_type stopPos = i;
		while (first != last)
		{
			(*first++).value_type::~value_type();
			++deletedElements;
			++stopPos;
		}
		// std::memmove ?
		for ( ; stopPos < this->size_; ++stopPos)
			this->copy_construct(i++, this->container[stopPos]);
		this->size_ -= deletedElements;
		return (iterator(&this->container[returnPosition]));
	}

	void swap(Vector &other)
	{
		pointer tmp = this->container;
		this->container = other.container;
		other.container = tmp;
		size_type stmp = this->size_;
		this->size_ = other.size_;
		other.size_ = stmp;
		stmp = this->capacity_;
		this->capacity_ = other.capacity_;
		other.capacity_ = stmp;
	}

	void clear(void)
	{
		for (size_type i = 0; i < this->size_; i++)
			this->container[i].value_type::~value_type();
		this->size_ = 0;
	}
};

template<typename T>
bool operator==(Vector<T> const &lhs, Vector<T> const &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template<typename T>
bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (rhs < lhs);
}

template<typename T>
bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs)
{
	return (!(lhs < rhs));
}

template<typename T>
void swap(Vector<T> &x, Vector<T> &y)
{
	x.swap(y);
}
}

#endif
