/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 16:54:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include "include/Iterator.hpp"

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
public:
	Vector();
	Vector(size_type n, const_reference val=value_type());
	Vector(iterator first, iterator last);
	Vector(Vector const &other);
	virtual ~Vector();

	Vector &operator=(Vector const &other);

	iterator begin(void);
	const_iterator begin(void) const;
	reverse_iterator rbegin(void);
	const_reverse_iterator rbegin(void) const;
	iterator end(void);
	const_iterator end(void) const;
	reverse_iterator rend(void);
	const_reverse_iterator rend(void) const;

	size_type size(void) const;
	size_type max_size(void) const;
	void resize(size_type size, value_type val=value_type());
	size_type capacity(void) const;
	bool empty(void) const;
	void reserve(size_type size);

	reference operator[](size_type idx);
	const_reference operator[](size_type idx) const;
	reference at(size_type idx);
	const_reference at(size_type idx) const;
	reference front(void);
	const_reference front(void) const;
	reference back(void);
	const_reference back(void) const;

	void assign(iterator first, iterator last);
	void assign(const_iterator first, const_iterator last);
	void assign(size_type size, const_reference val);
	void push_back(const_reference val);
	void pop_back(void);
	iterator insert(iterator position, const_reference val);
	void insert(iterator position, size_type size, const_reference val);
	void insert(iterator position, iterator first, iterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(Vector &other);
	void clear(void);
};

template <class value_type>
bool operator==(Vector<value_type> const &lhs, Vector<value_type> const &rhs);
template <class value_type>
bool operator!=(Vector<value_type> const &lhs, Vector<value_type> const &rhs);
template <class value_type>
bool operator<(Vector<value_type> const &lhs, Vector<value_type> const &rhs);
template <class value_type>
bool operator<=(Vector<value_type> const &lhs, Vector<value_type> const &rhs);
template <class value_type>
bool operator>(Vector<value_type> const &lhs, Vector<value_type> const &rhs);
template <class value_type>
bool operator>=(Vector<value_type> const &lhs, Vector<value_type> const &rhs);
}

# include "src/Vector.ipp"

#endif
