/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:26 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 16:31:22 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
template<typename value_type>
Stack<value_type>::Stack(container_type const &container)
{
	this->c = container;
}

template<typename value_type>
Stack<value_type>::~Stack()
{
	this->c.clear();
}

template<typename value_type>
Stack<value_type> &Stack<value_type>::operator=(Stack const &other)
{
	this->c = other.c;
	return (*this);
}

template<typename value_type>
bool Stack<value_type>::empty(void) const
{
	return (this->c.empty());
}

template<typename value_type>
size_t Stack<value_type>::size(void) const
{
	return (this->c.size());
}

template<typename value_type>
value_type &Stack<value_type>::top(void)
{
	return (this->c.back());
}

template<typename value_type>
value_type const &Stack<value_type>::top(void) const
{
	return (this->c.back());
}

template<typename value_type>
void Stack<value_type>::push(value_type const &val)
{
	this->c.push_back(val);
}

template<typename value_type>
void Stack<value_type>::pop(void)
{
	this->c.pop_back();
}

template<typename stack_type>
bool operator==(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
{
	return (lhs.c == rhs.c);
}

template<typename stack_type>
bool operator!=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
{
	return (lhs.c != rhs.c);
}

template<typename stack_type>
bool operator<(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
{
	return (lhs.c < rhs.c);
}

template<typename stack_type>
bool operator<=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
{
	return (lhs.c <= rhs.c);
}

template<typename stack_type>
bool operator>(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
{
	return (lhs.c > rhs.c);
}

template<typename stack_type>
bool operator>=(Stack<stack_type> const &lhs, Stack<stack_type> const &rhs)
{
	return (lhs.c >= rhs.c);
}
}
