/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapBase.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:09:11 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/05 16:42:01 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPBASE_HPP
# define MAPBASE_HPP

# include <utility>
# include "Algorithm.hpp"
# include "Tree.hpp"

namespace ft
{
template<typename K, typename T, typename Compare = ft::less<K> >
class MapBase
{
public:
	typedef std::ptrdiff_t difference_type;
	typedef unsigned long size_type;
	typedef K key_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef Compare key_compare;
	typedef Compare value_compare;
	typedef Tree<value_type, key_compare> tree_type;
	typedef typename tree_type::Node node_type;
	typedef node_type* node_pointer;
	typedef TreeIterator<value_type, node_type> iterator;
	typedef TreeIterator<value_type const, node_type const> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ReverseIterator<const_iterator> const_reverse_iterator;
protected:
	tree_type m_tree;
	size_type m_size;
public:
	MapBase(): m_tree(), m_size(0) {}
	MapBase(iterator first, iterator last): m_tree(), m_size(0) {
		this->insert(first, last);
	}
	MapBase(MapBase const &other):
		m_tree(other.m_tree), m_size(other.m_size) {}
	virtual ~MapBase() {}

	MapBase &operator=(MapBase const &other) {
		this->clear();
		this->m_tree = other.m_tree;
		this->m_size = other.m_size;
		return (*this);
	}

	iterator begin(void) {
		return (iterator(this->m_tree.begin()));
	}
	const_iterator begin(void) const {
		return (const_iterator(this->m_tree.begin()));
	}
	reverse_iterator rbegin(void) {
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void) {
		return (iterator(this->m_tree.end()));
	}
	const_iterator end(void) const {
		return (const_iterator(this->m_tree.end()));
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
						std::numeric_limits<size_type>::max() / (sizeof(node_type) + sizeof(pointer))));
	}

	void erase(iterator position) {
		this->m_tree.erase(position.as_node());
		--this->m_size;
	}
	size_type erase(key_type const &key) {
		size_type count = this->m_tree.erase(key);
		this->m_size -= count;
		return (count);
	}
	void erase(iterator first, iterator last) {
		if (first == this->begin() && last == this->end())
			this->clear();
		else {
			iterator next;
			while (first != last) {
				first = this->m_tree.erase(first.as_node());
				--this->m_size;
			}
		}
	}

	void swap(MapBase &other) {
		this->m_tree.swap(other.m_tree);
		ft::swap(this->m_size, other.m_size);
	}

	void clear(void) {
		if (this->m_size > 0)
			this->m_tree.make_empty();
		this->m_size = 0;
	}

	iterator find(key_type const &key) {
		node_pointer node = this->m_tree.find(key);
		if (node)
			return (iterator(node));
		return (this->end());
	}
	const_iterator find(key_type const &key) const {
		node_pointer node = this->m_tree.find(key);
		if (node)
			return (const_iterator(node));
		return (this->end());
	}

	value_compare key_comp(void) const {
		return (this->m_tree.key_compare());
	}

	size_type count(key_type const &k) const {
		const_iterator it = this->begin();
		const_iterator ite = this->end();
		size_type total = 0;

		while (it != ite) {
			if (!this->key_comp()(*it, k) && !this->key_comp()(k, *it))
				++total;
			++it;
		}
		return (total);
	}

	iterator lower_bound(key_type const &key) {
		iterator it = this->begin();
		iterator ite = this->end();

		while (it != ite) {
			if (!this->key_comp()(*it, key))
				return (iterator(it));
			++it;
		}
		return (this->end());
	}
	const_iterator lower_bound(key_type const &key) const {
		const_iterator it = this->begin();
		const_iterator ite = this->end();

		while (it != ite) {
			if (!this->key_comp()(*it, key))
				return (const_iterator(it));
			++it;
		}
		return (this->end());
	}
	iterator upper_bound(key_type const &key) {
		iterator it = this->begin();
		iterator ite = this->end();

		while (it != ite) {
			if (this->key_comp()(key, *it))
				return (iterator(it));
			++it;
		}
		return (this->end());
	}
	const_iterator upper_bound(key_type const &key) const {
		const_iterator it = this->begin();
		const_iterator ite = this->end();

		while (it != ite) {
			if (this->key_comp()(key, *it))
				return (const_iterator(it));
			++it;
		}
		return (this->end());
	}

	typename std::pair<iterator, iterator> equal_range(key_type const &key) {
		return (std::pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key)));
	}
	typename std::pair<const_iterator, const_iterator> equal_range(key_type const &key) const {
		return (std::pair<const_iterator, const_iterator>(this->lower_bound(key), this->upper_bound(key)));
	}
};
}

#endif
