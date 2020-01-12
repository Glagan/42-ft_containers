/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:01 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 14:07:35 by ncolomer         ###   ########.fr       */
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
	Queue(container_type const &container=container_type());
	virtual ~Queue();

	Queue &operator=(Queue const &other);

	bool empty(void) const;
	size_t size(void) const;
	reference front(void);
	const_reference front(void) const;
	reference back(void);
	const_reference back(void) const;
	void push(const_reference val);
	void pop(void);

	template<typename queue_type>
	friend bool operator==(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs);
	template<typename queue_type>
	friend bool operator!=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs);
	template<typename queue_type>
	friend bool operator<(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs);
	template<typename queue_type>
	friend bool operator<=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs);
	template<typename queue_type>
	friend bool operator>(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs);
	template<typename queue_type>
	friend bool operator>=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs);

};
}

# include "src/Queue.ipp"

#endif
