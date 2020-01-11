/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 18:28:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cassert>
# include <cstddef>
# include <cmath>

namespace ft
{
template<typename T>
class Vector
{
protected:
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & const_reference;
private:
	size_type capacity_;
	size_type size_;
	pointer container;
public:
	class iterator
	{
	protected:
		value_type *pointer;
	public:
		iterator();
		iterator(value_type *vec);
		iterator(iterator const &other);
		virtual ~iterator();

		iterator &operator=(iterator const &other);

		value_type &operator*() const;
		value_type *operator->() const;
		bool operator==(iterator const &other) const;
		bool operator!=(iterator const &other) const;
		bool operator<(iterator const &other) const;
		bool operator<=(iterator const &other) const;
		bool operator>(iterator const &other) const;
		bool operator>=(iterator const &other) const;

		iterator operator++(int);
		iterator &operator++();
		iterator operator--(int);
		iterator &operator--();
		iterator &operator+=(int value);
		iterator operator+(int value) const;
		iterator &operator-=(int value);
		iterator operator-(int value) const;
	};
	class const_iterator
	{
	protected:
		value_type const *pointer;
	public:
		const_iterator();
		const_iterator(value_type const *vec);
		const_iterator(const_iterator const &other);
		const_iterator(iterator const &other);
		virtual ~const_iterator();

		const_iterator &operator=(const_iterator const &other);

		value_type const &operator*() const;
		value_type const *operator->() const;
		bool operator==(const_iterator const &other) const;
		bool operator!=(const_iterator const &other) const;
		bool operator<(const_iterator const &other) const;
		bool operator<=(const_iterator const &other) const;
		bool operator>(const_iterator const &other) const;
		bool operator>=(const_iterator const &other) const;
		const_iterator &operator+=(int value);
		const_iterator operator+(int value) const;
		const_iterator &operator-=(int value);
		const_iterator operator-(int value) const;

		const_iterator operator++(int);
		const_iterator &operator++();
		const_iterator operator--(int);
		const_iterator &operator--();
	};
	class reverse_iterator: virtual public iterator
	{
	public:
		reverse_iterator();
		reverse_iterator(value_type *vec);
		reverse_iterator(reverse_iterator const &other);
		reverse_iterator(iterator const &other);
		virtual ~reverse_iterator();

		reverse_iterator &operator=(reverse_iterator const &other);

		value_type &operator*() const;
		value_type *operator->() const;
		reverse_iterator operator++(int);
		reverse_iterator &operator++();
		reverse_iterator operator--(int);
		reverse_iterator &operator--();
	};
	class const_reverse_iterator: public const_iterator, public reverse_iterator
	{
	public:
		const_reverse_iterator();
		const_reverse_iterator(value_type const *vec);
		const_reverse_iterator(const_reverse_iterator const &other);
		const_reverse_iterator(reverse_iterator const &other);
		virtual ~const_reverse_iterator();

		value_type const &operator*() const;
		value_type const *operator->() const;
		const_reverse_iterator &operator=(const_reverse_iterator const &other);
	};

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
