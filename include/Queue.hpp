/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:01 by ncolomer          #+#    #+#             */
/*   Updated: 2020/02/24 18:11:52 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "List.hpp"

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
	container_type container;
public:
	Queue(container_type const &container=container_type()): container(container) {}
	virtual ~Queue() {}

	Queue &operator=(Queue const &other) {
		this->container = other.container;
		return (*this);
	}

	bool empty(void) const {
		return (this->container.empty());
	}
	size_t size(void) const {
		return (this->container.size());
	}

	reference front(void) {
		return (this->container.front());
	}
	const_reference front(void) const {
		return (this->container.front());
	}

	reference back(void) {
		return (this->container.back());
	}
	const_reference back(void) const {
		return (this->container.back());
	}

	void push(const_reference val) {
		this->container.push_back(val);
	}
	void pop(void) {
		this->container.pop_front();
	}

	template<typename queue_type>
	friend bool operator==(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs) {
		return (lhs.container == rhs.container);
	}

	template<typename queue_type>
	friend bool operator!=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs) {
		return (lhs.container != rhs.container);
	}

	template<typename queue_type>
	friend bool operator<(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs) {
		return (lhs.container < rhs.container);
	}

	template<typename queue_type>
	friend bool operator<=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs) {
		return (lhs.container <= rhs.container);
	}

	template<typename queue_type>
	friend bool operator>(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs) {
		return (lhs.container > rhs.container);
	}

	template<typename queue_type>
	friend bool operator>=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs) {
		return (lhs.container >= rhs.container);
	}
};
}

#endif
