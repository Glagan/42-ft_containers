/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:51 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 21:18:04 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include "include/Pair.hpp"
# include "include/TreeNode.hpp"

namespace ft
{
template<typename K, typename T, typename Compare>
class Map
{
public:
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef K const key_type;
	typedef T mapped_type;
	typedef Pair<key_type, mapped_type> value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef Compare key_compare;
	typedef TreeNode<value_type, key_compare> node_type;
	typedef node_type* node_pointer;
	typedef MapIterator<value_type, node_type> iterator;
	typedef MapIterator<value_type const, node_type const> const_iterator;
	typedef ReverseMapIterator<value_type, node_type> reverse_iterator;
	typedef ReverseMapIterator<value_type const, node_type const> const_reverse_iterator;

    class value_compare
    {
    protected:
        key_compare comp;

        value_compare(key_compare c):
			comp(c)
		{
		}
    public:
        bool operator()(const value_type& x, const value_type& y) const
		{
			return (comp(x.first, y.first));
		}
    };
private:
	TreeNode<value_type, value_compare> tree;
	size_type size_;
public:
	Map():
		tree(), size_(0)
	{
	}
	Map(iterator first, iterator last)
	{
		this->assign(first, last);
	}
	Map(Map const &other):
		tree(), size_(0)
	{
		this->insert(other.begin(), other.end());
	}
	virtual ~Map()
	{
		this->clear();
	}

	Map &operator=(Map const &other)
	{
		this->clear();
		this->insert(other.begin(), other.end());
	}

	iterator begin(void)
	{
		return (iterator(this->tree.minimum_node()));
	}
	const_iterator begin(void) const
	{
		return (const_iterator(this->tree.minimum_node()));
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
		return (iterator(this->tree.maximum_node()));
	}
	const_iterator end(void) const
	{
		return (const_iterator(this->tree.maximum_node()));
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
		return (this->size_ > 0);
	}
	size_type size(void) const
	{
		return (this->size_);
	}
	size_type max_size(void) const
	{
		return (((std::pow(2, 64) - 1) / sizeof(TreeNode<value_type, key_compare>)) - 1);
	}

	mapped_type& operator[](key_type const &k)
	{
		iterator it = this->find(k);
		if (it != this->end())
			return (*it);
		++this->size_;
		return (this->tree.insert(k)->value)
	}

	Pair<iterator, bool> insert(const_reference val)
	{
		iterator it = this->find(val.first);
		if (it != this->end())
			return (make_pair(it, false));
		TreeNode *inserted = this->tree.insert(val.first, val.second);
		return (make_pair(iterator(inserted, true)));
	}
	iterator insert(iterator position, const_reference val);
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last);
	void erase(iterator position);
	size_type erase(key_type const &key);
	void erase(iterator first, iterator last);
	void swap(Map &x);
	void clear(void)
	{
		if (this->size_)
			this->tree.clear_all();
		this->size_ = 0;
	}

	key_compare key_comp(void) const
	{
		return (key_compare);
	}
	value_compare value_comp(void) const
	{
		return (value_compare);
	}

	iterator find(key_type const &key)
	{
		TreeNode *node = this->find(key);
		if (node)
			return (iterator(node));
		return (this->end());
	}
	const_iterator find(key_type const &key) const
	{
		TreeNode *node = this->find(key);
		if (node)
			return (iterator(node));
		return (this->end());
	}
	size_type count(key_type const &k) const
	iterator lower_bound(key_type const &key);
	const_iterator lower_bound(key_type const &key) const;
	iterator upper_bound(key_type const &key);
	const_iterator upper_bound(key_type const &key) const;
	Pair<iterator, iterator> equal_range(key_type const &key);
	Pair<const_iterator, const_iterator> equal_range(key_type const &key) const;
};
}

#endif
