/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:03 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/31 02:48:23 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <cstddef>
# include <cmath>
# include <utility>
# include "include/Algorithm.hpp"
# include "include/Tree.hpp"

namespace ft
{
template<typename T, typename Compare = ft::less<T> >
class Set
{
public:
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef T key_type;
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
	typedef ReverseTreeIterator<value_type, node_type> reverse_iterator;
	typedef ReverseTreeIterator<value_type const, node_type const> const_reverse_iterator;
private:
	tree_type tree;
	size_type size_;
public:
	Set():
		tree(), size_(0)
	{
	}
	Set(iterator first, iterator last):
		tree(), size_(0)
	{
		this->insert(first, last);
	}
	Set(Set const &other):
		tree(other.tree), size_(other.size_)
	{
	}
	virtual ~Set()
	{
	}

	Set &operator=(Set const &other)
	{
		this->clear();
		this->tree = other.tree;
		this->size_ = other.size_;
		return (*this);
	}

	iterator begin(void)
	{
		return (iterator(this->tree.begin()));
	}
	const_iterator begin(void) const
	{
		return (const_iterator(this->tree.begin()));
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
		return (iterator(this->tree.end()));
	}
	const_iterator end(void) const
	{
		return (const_iterator(this->tree.end()));
	}
	reverse_iterator rend(void)
	{
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const
	{
		return (const_reverse_iterator(this->begin()));
	}

	bool empty(void) const
	{
		return (this->size_ == 0);
	}
	size_type size(void) const
	{
		return (this->size_);
	}
	size_type max_size(void) const
	{
		return (((std::pow(2, 64) - 1) / sizeof(node_type)) - 1);
	}

	typename std::pair<iterator, bool> insert(const_reference val)
	{
		node_pointer node = this->tree.find(val);
		if (node)
			return (std::make_pair(iterator(node), false));
		node_pointer inserted = this->tree.insert(val);
		++this->size_;
		return (std::make_pair(iterator(inserted), true));
	}
	iterator insert(iterator position, const_reference val)
	{
		node_pointer node = this->tree.find(position.as_node(), val);
		if (node)
			return (iterator(node));
		++this->size_;
		return (iterator(this->tree.insert(position.as_node(), val)));
	}
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		while (first != last)
			this->insert(*first++);
	}

	void erase(iterator position)
	{
		this->tree.erase(position.as_node());
		--this->size_;
	}
	size_type erase(key_type const &key)
	{
		size_type count = this->tree.erase(key);
		this->size_ -= count;
		return (count);
	}
	void erase(iterator first, iterator last)
	{
		if (first == this->begin() && last == this->end())
			this->clear();
		else
		{
			iterator next;
			while (first != last)
			{
				first = this->tree.erase(first.as_node());
				--this->size_;
			}
		}
	}

	void swap(Set &other)
	{
		this->tree.swap(other.tree);
		size_type tmp = this->size_;
		this->size_ = other.size_;
		other.size_ = tmp;
	}

	void clear(void)
	{
		if (this->size_ > 0)
			this->tree.make_empty();
		this->size_ = 0;
	}

	// TODO:
	value_compare key_comp(void) const
	{
		return (this->tree.key_compare());
	}
	// TODO:
	value_compare value_comp(void) const
	{
		return (this->tree.key_compare());
	}

	iterator find(key_type const &key)
	{
		node_pointer node = this->tree.find(key);
		if (node)
			return (iterator(node));
		return (this->end());
	}
	const_iterator find(key_type const &key) const
	{
		node_pointer node = this->tree.find(key);
		if (node)
			return (const_iterator(node));
		return (this->end());
	}

	size_type count(key_type const &k) const
	{
		const_iterator it = this->begin();
		const_iterator ite = this->end();
		size_type total = 0;

		while (it != ite)
		{
			if (!this->key_comp()(*it, k) && !this->key_comp()(k, *it))
				++total;
			++it;
		}
		return (total);
	}

	iterator lower_bound(key_type const &key)
	{
		iterator it = this->begin();
		iterator ite = this->end();

		while (it != ite)
		{
			if (!this->key_comp()(*it, key))
				return (iterator(it));
			++it;
		}
		return (this->end());
	}
	const_iterator lower_bound(key_type const &key) const
	{
		const_iterator it = this->begin();
		const_iterator ite = this->end();

		while (it != ite)
		{
			if (!this->key_comp()(*it, key))
				return (const_iterator(it));
			++it;
		}
		return (this->end());
	}
	iterator upper_bound(key_type const &key)
	{
		iterator it = this->begin();
		iterator ite = this->end();

		while (it != ite)
		{
			if (this->key_comp()(key, *it))
				return (iterator(it));
			++it;
		}
		return (this->end());
	}
	const_iterator upper_bound(key_type const &key) const
	{
		const_iterator it = this->begin();
		const_iterator ite = this->end();

		while (it != ite)
		{
			if (this->key_comp()(key, *it))
				return (const_iterator(it));
			++it;
		}
		return (this->end());
	}

	typename std::pair<iterator, iterator> equal_range(key_type const &key)
	{
		return (std::pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key)));
	}
	typename std::pair<const_iterator, const_iterator> equal_range(key_type const &key) const
	{
		return (std::pair<const_iterator, const_iterator>(this->lower_bound(key), this->upper_bound(key)));
	}
};

template<typename T, typename Compare>
void swap(Set<T, Compare> &x, Set<T, Compare> &y)
{
	x.swap(y);
}
}

#endif
