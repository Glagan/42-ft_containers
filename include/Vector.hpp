/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/04 19:41:54 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cassert>
# include <cstddef>

namespace ft
{
template<typename value_type>
class Vector
{
	size_t capacity_;
	size_t size_;
	value_type *container;
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
		int distance(iterator const &other) const;

		iterator operator++(int);
		iterator &operator++();
		iterator operator--(int);
		iterator &operator--();
	};
	class const_iterator
	{
	protected:
		value_type const * pointer;
	public:
		const_iterator();
		const_iterator(value_type const * vec);
		const_iterator(iterator const &other);
		const_iterator(const_iterator const &other);
		virtual ~const_iterator();

		const_iterator &operator=(const_iterator const &other);

		value_type &operator*() const;
		value_type *operator->() const;
		bool operator==(const_iterator const &other) const;
		bool operator!=(const_iterator const &other) const;
		bool operator<(const_iterator const &other) const;
		bool operator<=(const_iterator const &other) const;
		bool operator>(const_iterator const &other) const;
		bool operator>=(const_iterator const &other) const;

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
		virtual ~reverse_iterator();

		reverse_iterator &operator=(reverse_iterator const &other);

		reverse_iterator operator++(int);
		reverse_iterator operator++();
		reverse_iterator operator--(int);
		reverse_iterator operator--();
	};
	class const_reverse_iterator: public const_iterator, public reverse_iterator
	{
	public:
		const_reverse_iterator();
		const_reverse_iterator(value_type const * vec);
		const_reverse_iterator(const_reverse_iterator const &other);
		virtual ~const_reverse_iterator();

		const_reverse_iterator &operator=(const_reverse_iterator const &other);
	};

	Vector();
	Vector(size_t n, value_type const &val=value_type());
	Vector(Vector<value_type>::iterator first, Vector<value_type>::iterator last);
	Vector(Vector<value_type> const &other);
	virtual ~Vector();

	Vector<value_type> &operator=(Vector<value_type> const &other);

	typename Vector<value_type>::iterator begin(void);
	typename Vector<value_type>::const_iterator begin(void) const;
	typename Vector<value_type>::reverse_iterator rbegin(void);
	typename Vector<value_type>::const_reverse_iterator rbegin(void) const;
	typename Vector<value_type>::iterator end(void);
	typename Vector<value_type>::const_iterator end(void) const;
	typename Vector<value_type>::reverse_iterator rend(void);
	typename Vector<value_type>::const_reverse_iterator rend(void) const;

	size_t size(void) const;
	size_t max_size(void) const;
	void resize(size_t size, value_type val=value_type());
	size_t capacity(void) const;
	bool empty(void) const;
	void reserve(size_t size);

	value_type &operator[](size_t idx);
	value_type const &operator[](size_t idx) const;
	value_type &at(size_t idx);
	value_type const &at(size_t idx) const;
	value_type &front(void);
	value_type const &front(void) const;
	value_type &back(void);
	value_type const &back(void) const;

	void assign(Vector<value_type>::iterator first, Vector<value_type>::iterator last);
	void assign(size_t size, value_type const &val);
	void push_back(value_type const &val);
	void pop_back(void);
	Vector<value_type>::iterator insert(Vector<value_type>::iterator position, value_type const &val);
	void insert(Vector<value_type>::iterator position, size_t size, value_type const &val);
	void insert(Vector<value_type>::iterator position, Vector::iterator first, Vector::iterator last);
	Vector<value_type>::iterator erase(Vector<value_type>::iterator position);
	Vector<value_type>::iterator erase(Vector::iterator first, Vector::iterator last);
	void swap(Vector<value_type> &other);
	void clear(void);
};
}

# include "src/Vector.ipp"

#endif
