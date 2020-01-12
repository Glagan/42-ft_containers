/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:05 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 14:07:29 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <cassert>
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
	Stack(container_type const &container=container_type());
	virtual ~Stack();

	Stack &operator=(Stack const &other);

	bool empty(void) const;
	size_t size(void) const;
	reference top(void);
	const_reference top(void) const;
	void push(const_reference val);
	void pop(void);

	template<typename stack_type>
	friend bool operator==(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs);
	template<typename stack_type>
	friend bool operator!=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs);
	template<typename stack_type>
	friend bool operator<(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs);
	template<typename stack_type>
	friend bool operator<=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs);
	template<typename stack_type>
	friend bool operator>(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs);
	template<typename stack_type>
	friend bool operator>=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs);

};
}

# include "src/Stack.ipp"

#endif
