/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:22 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 16:45:34 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
template<typename value_type>
Queue<value_type>::Queue(container_type const &container)
{
	this->c = container;
}

template<typename value_type>
Queue<value_type>::~Queue()
{
	this->c.clear();
}

template<typename value_type>
Queue<value_type> &Queue<value_type>::operator=(Queue const &other)
{
	this->c = other.c;
	return (*this);
}

template<typename value_type>
bool Queue<value_type>::empty(void) const
{
	return (this->c.empty());
}

template<typename value_type>
size_t Queue<value_type>::size(void) const
{
	return (this->c.size());
}

template<typename value_type>
value_type &Queue<value_type>::front(void)
{
	return (this->c.front());
}

template<typename value_type>
value_type const &Queue<value_type>::front(void) const
{
	return (this->c.front());
}

template<typename value_type>
value_type &Queue<value_type>::back(void)
{
	return (this->c.back());
}

template<typename value_type>
value_type const &Queue<value_type>::back(void) const
{
	return (this->c.back());
}

template<typename value_type>
void Queue<value_type>::push(value_type const &val)
{
	this->c.push_back(val);
}

template<typename value_type>
void Queue<value_type>::pop(void)
{
	this->c.pop_front();
}

template<typename queue_type>
bool operator==(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
{
	return (lhs.c == rhs.c);
}

template<typename queue_type>
bool operator!=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
{
	return (lhs.c != rhs.c);
}

template<typename queue_type>
bool operator<(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
{
	return (lhs.c < rhs.c);
}

template<typename queue_type>
bool operator<=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
{
	return (lhs.c <= rhs.c);
}

template<typename queue_type>
bool operator>(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
{
	return (lhs.c > rhs.c);
}

template<typename queue_type>
bool operator>=(Queue<queue_type> const &lhs, Queue<queue_type> const &rhs)
{
	return (lhs.c >= rhs.c);
}
}
