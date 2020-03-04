/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:51 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/04 19:24:44 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "MapBase.hpp"

namespace ft
{
template<typename K, typename T, typename Compare = ft::less<K> >
class MapKeyCompare:
	std::binary_function<std::pair<K, T>, std::pair<K, T>, bool>
{
public:
	typedef typename std::pair<K, T> value_type;
private:
	Compare comp;
public:
	MapKeyCompare(Compare const &comp=Compare()): comp(comp) {}
	virtual ~MapKeyCompare() {}

	bool operator()(const value_type& a, const value_type& b) const {
		return (comp(a.first, b.first));
	}
	bool operator()(const value_type& a, const K& b) const {
		return (comp(a.first, b));
	}
	bool operator()(const K& a, const value_type& b) const {
		return (comp(a, b.first));
	}
};
template<typename K, typename T, typename Compare = MapKeyCompare<K, T> >
class Map:
	public MapBase<K, std::pair<K, T>, Compare>
{
public:
	typedef MapBase<K, std::pair<K, T>, Compare> base;
	using typename base::difference_type;
	using typename base::size_type;
	using typename base::key_type;
	using typename base::value_type;
	typedef T mapped_type;
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
	Map(): base() {}
	Map(iterator first, iterator last): base(first, last) {}
	Map(Map const &other): base(other) {}
	virtual ~Map() {}

	Map &operator=(Map const &other) {
		this->base::operator=(other);
		return (*this);
	}

	mapped_type &operator[](key_type const &k) {
		node_pointer found = this->tree.find(k);
		if (found)
			return (found->value.second);
		++this->size_;
		return (this->tree.insert(std::make_pair(k, mapped_type()))->value.second);
	}

	typename std::pair<iterator, bool> insert(const_reference val) {
		node_pointer node = this->tree.find(val);
		if (node)
			return (std::make_pair(iterator(node), false));
		node_pointer inserted = this->tree.insert(val);
		++this->size_;
		return (std::make_pair(iterator(inserted), true));
	}
	iterator insert(iterator position, const_reference val) {
		node_pointer node = this->tree.find(position.as_node(), val);
		if (node)
			return (iterator(node));
		++this->size_;
		return (iterator(this->tree.insert(position.as_node(), val)));
	}
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		while (first != last)
			this->insert(*first++);
	}

	value_compare value_comp(void) const {
		return (value_compare()); // TODO
	}
};

template<typename K, typename T, typename Compare>
void swap(Map<K, T, Compare> &x, Map<K, T, Compare> &y) {
	x.swap(y);
}

template<typename K, typename T, typename Compare = MapKeyCompare<K, T> >
class Multimap:
	public MapBase<K, std::pair<K, T>, Compare>
{
public:
	typedef MapBase<K, std::pair<K, T>, Compare> base;
	using typename base::difference_type;
	using typename base::size_type;
	using typename base::key_type;
	using typename base::value_type;
	typedef T mapped_type;
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
	Multimap(): base() {}
	Multimap(iterator first, iterator last): base(first, last) {}
	Multimap(Multimap const &other): base(other) {}
	virtual ~Multimap() {}

	Multimap &operator=(Multimap const &other) {
		this->base::operator=(other);
		return (*this);
	}

	iterator insert(const_reference val) {
		node_pointer inserted = this->tree.insert(val);
		++this->size_;
		return (iterator(inserted));
	}
	iterator insert(iterator position, const_reference val) {
		++this->size_;
		return (iterator(this->tree.insert(position.as_node(), val)));
	}
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		while (first != last)
			this->insert(*first++);
	}

	value_compare value_comp(void) const {
		return (value_compare()); // TODO
	}
};

template<typename K, typename T, typename Compare>
void swap(Multimap<K, T, Compare> &x, Multimap<K, T, Compare> &y) {
	x.swap(y);
}
}

#endif
