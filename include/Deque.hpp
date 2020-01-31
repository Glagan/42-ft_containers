/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:46 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/31 02:41:32 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <cstddef>
# include <cmath>
# include "include/Node.hpp"
# include "include/Iterator.hpp"
# include "include/Algorithm.hpp"

namespace ft
{
template<typename T>
class Deque
{
public:
	typedef size_t size_type;
	typedef T value_type;
	// typedef Node<value_type> node_type;
	// typedef node_type* node_pointer;
	typedef value_type* pointer;
	typedef value_type const *const_pointer;
	typedef value_type& reference;
	typedef value_type const &const_reference;
	// typedef ListIterator<value_type, node_type> iterator;
	// typedef ListIterator<value_type const, node_type const> const_iterator;
	// typedef ReverseListIterator<value_type, node_type> reverse_iterator;
	// typedef ReverseListIterator<value_type const, node_type const> const_reverse_iterator;
private:
	// TODO: Attributes
public:
	Deque();
	Deque(size_type n, const_reference val=value_type());
	Deque(iterator first, iterator last);
	Deque(Deque const &other);
	virtual ~Deque();

	List &operator=(List const &other);

	iterator begin(void)
	{
		return (iterator(this->begin_));
	}
	const_iterator begin(void) const
	{
		return (const_iterator(this->begin_));
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
		return (iterator(this->end_));
	}
	const_iterator end(void) const
	{
		return (const_iterator(this->end_));
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
		return (((std::pow(2, 64) - 1) / sizeof(Node<value_type>)) - 1);
	}
    void resize(size_type n, value_type val=value_type());

    reference operator[](size_type n);
    const_reference operator[](size_type n) const;

    reference at(size_type n);
    const_reference at(size_type n) const;

    reference front(void);
    const_reference front(void) const;

    reference back(void);
    const_reference back(void) const;

    template <typename InputIterator>
	void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const_reference val);

    void push_back(const_reference val);
    void pop_back(void);

    void push_front(const_reference val);
    void pop_front(void);

    iterator insert(iterator position, const_reference val);
    void insert(iterator position, size_type n, const_reference val);
    template<typename InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last);

    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);

    void swap(Deque &x);
    void clear(void);
};

template<typename T>
bool operator==(Deque<T> const &lhs, Deque<T> const &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template<typename T>
bool operator!=(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (rhs < lhs);
}

template<typename T>
bool operator>=(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (!(lhs < rhs));
}

template<typename T>
void swap(Deque<T> &x, Deque<T> &y);
}

#endif