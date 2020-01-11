/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:51 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 18:41:11 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include "include/Pair.hpp"

namespace ft
{
template<typename K, typename T, typename Compare>
class Map
{
protected:
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef K key_type;
	typedef T mapped_type;
	typedef Pair<key_type, mapped_type> value_type;
	typedef Pair<key_type, mapped_type> *pointer;
	typedef Pair<key_type, mapped_type> const * const_pointer;
	typedef Pair<key_type, mapped_type> &reference;
	typedef Pair<key_type, mapped_type> const & const_reference;
	typedef Compare key_compare;
private:
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

		mapped_type &operator*() const;
		mapped_type *operator->() const;
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

		mapped_type const &operator*() const;
		mapped_type const *operator->() const;
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

	class value_compare
	{
		value_compare();
		virtual ~value_compare();
	};

	Map();
	Map(size_type size, const_reference val=value_type());
	Map(iterator first, iterator last);
	Map(Map const &other);
	virtual ~Map();

	Map &operator=(Map const &other);

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

	mapped_type& operator[](key_type const &k);

	Pair<iterator, bool> insert(const_reference val);
	iterator insert(iterator position, const_reference val);
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last);
	void erase(iterator position);
	size_type erase(key_type const &key);
	void erase(iterator first, iterator last);
	void swap(Map &x);
	void clear(void);

	key_compare key_comp(void) const;
	value_compare value_comp(void) const;

	iterator find(key_type const &key);
	const_iterator find(key_type const &key) const;
	size_type count(key_type const &k) const;
	iterator lower_bound(key_type const &key);
	const_iterator lower_bound(key_type const &key) const;
	iterator upper_bound(key_type const &key);
	const_iterator upper_bound(key_type const &key) const;
	Pair<iterator, iterator> equal_range(key_type const &key);
	Pair<const_iterator, const_iterator> equal_range(key_type const &key) const;
};
}

# include "src/Map.ipp"

#endif
