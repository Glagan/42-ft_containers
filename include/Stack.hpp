/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:05 by ncolomer          #+#    #+#             */
/*   Updated: 2020/02/24 18:11:59 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "List.hpp"

namespace ft
{
template<typename T, typename K = ft::List<T> >
class Stack
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef K container_type;
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & const_reference;
protected:
	container_type container;
public:
	Stack(container_type const &container=container_type()): container(container) {}
	Stack(Stack const &other): container(other.container) {}
	virtual ~Stack() {}

	Stack &operator=(Stack const &other) {
		this->container = other.container;
		return (*this);
	}

	bool empty(void) const {
		return (this->container.empty());
	}
	size_t size(void) const {
		return (this->container.size());
	}

	reference top(void) {
		return (this->container.back());
	}
	const_reference top(void) const {
		return (this->container.back());
	}

	void push(const_reference val) {
		this->container.push_back(val);
	}
	void pop(void) {
		this->container.pop_back();
	}

	template<typename stack_type, typename container_type>
	friend bool operator==(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container == rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator!=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container != rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container < rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container <= rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container > rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container >= rhs.container);
	}
};
}

#endif
