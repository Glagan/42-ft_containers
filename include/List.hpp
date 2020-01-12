/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:49 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 17:05:33 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include "include/Node.hpp"
# include "include/Iterator.hpp"

namespace ft
{
template<typename T>
class List
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef Node<value_type> node_type;
	typedef node_type* node_pointer;
	typedef value_type* pointer;
	typedef value_type const *const_pointer;
	typedef value_type& reference;
	typedef value_type const &const_reference;
	typedef ListIterator<value_type, node_type> iterator;
	typedef ListIterator<value_type const, node_type const> const_iterator;
	typedef ReverseListIterator<value_type, node_type> reverse_iterator;
	typedef ReverseListIterator<value_type const, node_type const> const_reverse_iterator;
private:
	node_pointer begin_;
	node_pointer end_;
	size_type size_;

	void make_bounds(void);
	void reset_bounds(void);

	static bool value_equal(value_type const &a, value_type const &b);
	static bool value_less(value_type const &a, value_type const &b);
public:
	List();
	List(size_type n, const_reference val=value_type());
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
	size_type size(void) const;
	size_type max_size(void) const;

	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	void assign(iterator first, iterator last);
	void assign(const_iterator first, const_iterator last);
	void assign(size_type size, const_reference val);
	void push_front(const_reference val);
	void pop_front(void);
	void push_back(const_reference val);
	void pop_back(void);
	iterator insert(iterator position, const_reference val);
	void insert(iterator position, size_type size, const_reference val);
	void insert(iterator position, List::iterator first, List::iterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(List &other);
	void resize(size_type n, value_type val=value_type());
	void clear(void);

	void splice(iterator position, List &x);
	void splice(iterator position, List &x, iterator it);
	void splice(iterator position, List &x, iterator first, iterator last);
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

template<typename value_type>
bool operator==(List<value_type> const &lhs, List<value_type> const &rhs);
template<typename value_type>
bool operator!=(List<value_type> const &lhs, List<value_type> const &rhs);
template<typename value_type>
bool operator<(List<value_type> const &lhs, List<value_type> const &rhs);
template<typename value_type>
bool operator<=(List<value_type> const &lhs, List<value_type> const &rhs);
template<typename value_type>
bool operator>(List<value_type> const &lhs, List<value_type> const &rhs);
template<typename value_type>
bool operator>=(List<value_type> const &lhs, List<value_type> const &rhs);
}

# include "src/List.ipp"

#endif
