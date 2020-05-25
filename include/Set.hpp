/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:03 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/02 18:58:59 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "MapBase.hpp"

namespace ft
{
template<typename T, typename Compare = ft::less<T> >
class Set:
	public MapBase<T, T, Compare>
{
public:
	typedef MapBase<T, T, Compare> base;
	using typename base::difference_type;
	using typename base::size_type;
	using typename base::key_type;
	using typename base::value_type;
	using typename base::pointer;
	using typename base::const_pointer;
	using typename base::reference;
	using typename base::const_reference;
	using typename base::key_compare;
	using typename base::value_compare;
	using typename base::tree_type;
	using typename base::node_type;
	using typename base::node_pointer;
	using typename base::iterator;
	using typename base::const_iterator;
	using typename base::reverse_iterator;
	using typename base::const_reverse_iterator;
public:
	Set(): base() {}
	Set(iterator first, iterator last): base(first, last) {}
	Set(Set const &other): base(other) {}
	virtual ~Set() {}

	Set &operator=(Set const &other) {
		this->base::operator=(other);
		return (*this);
	}

	typename std::pair<iterator, bool> insert(const_reference val) {
		node_pointer node = this->m_tree.find(val);
		if (node)
			return (std::make_pair(iterator(node), false));
		node_pointer inserted = this->m_tree.insert(val);
		++this->m_size;
		return (std::make_pair(iterator(inserted), true));
	}
	iterator insert(iterator position, const_reference val) {
		node_pointer node = this->m_tree.find(position.as_node(), val);
		if (node)
			return (iterator(node));
		++this->m_size;
		return (iterator(this->m_tree.insert(position.as_node(), val)));
	}
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		while (first != last)
			this->insert(*first++);
	}

	value_compare value_comp(void) const {
		return (this->m_tree.key_compare());
	}
};

template<typename T, typename Compare>
void swap(Set<T, Compare> &x, Set<T, Compare> &y) {
	x.swap(y);
}

template<typename T, typename Compare = ft::less<T> >
class Multiset:
	public MapBase<T, T, Compare>
{
public:
	typedef MapBase<T, T, Compare> base;
	using typename base::difference_type;
	using typename base::size_type;
	using typename base::key_type;
	using typename base::value_type;
	using typename base::pointer;
	using typename base::const_pointer;
	using typename base::reference;
	using typename base::const_reference;
	using typename base::key_compare;
	using typename base::value_compare;
	using typename base::tree_type;
	using typename base::node_type;
	using typename base::node_pointer;
	using typename base::iterator;
	using typename base::const_iterator;
	using typename base::reverse_iterator;
	using typename base::const_reverse_iterator;
public:
	Multiset(): base() {}
	Multiset(iterator first, iterator last): base(first, last) {}
	Multiset(Multiset const &other): base(other) {}
	virtual ~Multiset() {}

	Multiset &operator=(Multiset const &other) {
		this->base::operator=(other);
		return (*this);
	}

	iterator insert(const_reference val) {
		node_pointer inserted = this->m_tree.insert(val);
		++this->m_size;
		return (iterator(inserted));
	}
	iterator insert(iterator position, const_reference val) {
		++this->m_size;
		return (iterator(this->m_tree.insert(position.as_node(), val)));
	}
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		while (first != last)
			this->insert(*first++);
	}

	value_compare value_comp(void) const {
		return (this->m_tree.key_compare());
	}
};

template<typename T, typename Compare>
void swap(Multiset<T, Compare> &x, Multiset<T, Compare> &y) {
	x.swap(y);
}
}

#endif
