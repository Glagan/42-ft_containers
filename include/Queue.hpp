/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:01 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 17:18:17 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include "include/List.hpp"

namespace ft
{
template<typename T>
class Queue
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef List<value_type> container_type;
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & const_reference;
protected:
	container_type c;
public:
	Queue(container_type const &container=container_type()): c(container) {}
	virtual ~Queue() {}

	Queue &operator=(Queue const &other)
	{
		this->c = other.c;
		return (*this);
	}

	bool empty(void) const
	{
		return (this->c.empty());
	}

	size_t size(void) const
	{
		return (this->c.size());
	}

	reference front(void)
	{
		return (this->c.front());
	}

	const_reference front(void) const
	{
		return (this->c.front());
	}

	reference back(void)
	{
		return (this->c.back());
	}

	const_reference back(void) const
	{
		return (this->c.back());
	}

	void push(const_reference val)
	{
		this->c.push_back(val);
	}

	void pop(void)
	{
		this->c.pop_front();
	}

	template<typename queue_type>
	friend bool operator==(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template<typename queue_type>
	friend bool operator!=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
	{
		return (lhs.c != rhs.c);
	}

	template<typename queue_type>
	friend bool operator<(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
	{
		return (lhs.c < rhs.c);
	}

	template<typename queue_type>
	friend bool operator<=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template<typename queue_type>
	friend bool operator>(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
	{
		return (lhs.c > rhs.c);
	}

	template<typename queue_type>
	friend bool operator>=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
	{
		return (lhs.c >= rhs.c);
	}
};
}

#endif
