/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:05 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 17:16:51 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <cstddef>
# include <cmath>
# include "include/List.hpp"

namespace ft
{
template<typename T>
class Stack
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
	Stack(container_type const &container=container_type()): c(container) {}
	virtual ~Stack() {}

	Stack &operator=(Stack const &other)
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

	reference top(void)
	{
		return (this->c.back());
	}

	const_reference top(void) const
	{
		return (this->c.back());
	}

	void push(const_reference val)
	{
		this->c.push_back(val);
	}

	void pop(void)
	{
		this->c.pop_back();
	}

	template<typename stack_type>
	friend bool operator==(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template<typename stack_type>
	friend bool operator!=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
	{
		return (lhs.c != rhs.c);
	}

	template<typename stack_type>
	friend bool operator<(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
	{
		return (lhs.c < rhs.c);
	}

	template<typename stack_type>
	friend bool operator<=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template<typename stack_type>
	friend bool operator>(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
	{
		return (lhs.c > rhs.c);
	}

	template<typename stack_type>
	friend bool operator>=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
	{
		return (lhs.c >= rhs.c);
	}
};
}

#endif
