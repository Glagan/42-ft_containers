/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:49 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 14:08:00 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include "Node.hpp"

namespace ft
{
template<typename T>
class List
{
protected:
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type *pointer;
	typedef value_type const *const_pointer;
	typedef value_type &reference;
	typedef value_type const &const_reference;
private:
	Node<value_type> *begin_;
	Node<value_type> *end_;
	size_t size_;

	void make_bounds(void);
	void reset_bounds(void);

	static bool value_equal(value_type const &a, value_type const &b);
	static bool value_less(value_type const &a, value_type const &b);
public:
	class iterator
	{
	protected:
		Node<value_type> *pointer;
	public:
		iterator();
		iterator(Node<value_type> *vec);
		iterator(iterator const &other);
		virtual ~iterator();

		iterator &operator=(iterator const &other);
		Node<value_type> *as_node(void) const;

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
		iterator& operator+=(int value);
        iterator operator+(int value) const;
        iterator& operator-=(int value);
        iterator operator-(int value) const;
	};
	class const_iterator
	{
	protected:
		Node<value_type> const * pointer;
	public:
		const_iterator();
		const_iterator(Node<value_type> const * vec);
		const_iterator(const_iterator const &other);
		const_iterator(iterator const &other);
		virtual ~const_iterator();

		const_iterator &operator=(const_iterator const &other);
		Node<value_type> const *as_node(void) const;

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
		reverse_iterator(Node<value_type> *vec);
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
		const_reverse_iterator(Node<value_type> const * vec);
		const_reverse_iterator(const_reverse_iterator const &other);
		const_reverse_iterator(reverse_iterator const &other);
		virtual ~const_reverse_iterator();

		value_type const &operator*() const;
		value_type const *operator->() const;
		const_reverse_iterator &operator=(const_reverse_iterator const &other);
	};

	List();
	List(size_t n, const_reference val=value_type());
	List(iterator first, iterator last);
	List(List const &other);
	virtual ~List();

	List &operator=(List const &other);

	iterator begin(void);
	const_iterator begin(void) const;
	reverse_iterator rbegin(void);
	const_reverse_iterator rbegin(void) const;
	iterator end(void);
	const_iterator end(void) const;
	reverse_iterator rend(void);
	const_reverse_iterator rend(void) const;

	bool empty(void) const;
	size_t size(void) const;
	size_t max_size(void) const;

	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	void assign(iterator first, iterator last);
	void assign(const_iterator first, const_iterator last);
	void assign(size_t size, const_reference val);
	void push_front(const_reference val);
	void pop_front(void);
	void push_back(const_reference val);
	void pop_back(void);
	iterator insert(iterator position, const_reference val);
	void insert(iterator position, size_t size, const_reference val);
	void insert(iterator position, List::iterator first, List::iterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(List<value_type> &other);
	void resize(size_t n, value_type val=value_type());
	void clear(void);

	void splice(iterator position, List<value_type> &x);
	void splice(iterator position, List<value_type> &x, iterator it);
	void splice(iterator position, List<value_type> &x, iterator first, iterator last);
	void remove(const_reference val);
	template<typename Predicate>
	void remove_if(Predicate pred);
	void unique(void);
	template<typename BinaryPredicate>
	void unique(BinaryPredicate binary_pred);
	void merge(List &x);
	template<typename Compare>
	void merge(List &x, Compare comp);
	void sort(void);
	template<typename Compare>
	void sort(Compare comp);
	void reverse(void);
};

template<typename T>
bool operator==(List<T> const &lhs, List<T> const &rhs);
template<typename T>
bool operator!=(List<T> const &lhs, List<T> const &rhs);
template<typename T>
bool operator<(List<T> const &lhs, List<T> const &rhs);
template<typename T>
bool operator<=(List<T> const &lhs, List<T> const &rhs);
template<typename T>
bool operator>(List<T> const &lhs, List<T> const &rhs);
template<typename T>
bool operator>=(List<T> const &lhs, List<T> const &rhs);
}

# include "src/List.ipp"

#endif
