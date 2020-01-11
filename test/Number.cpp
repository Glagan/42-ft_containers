/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:14:47 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 18:05:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number():
	n(0)
{
	std::cout << "default constructor of Number" << std::endl;
}

Number::Number(int const &n):
	n(n)
{
	std::cout << "assignation constructor of Number" << std::endl;
}

Number::Number(Number const &other):
	n(other.n)
{
	std::cout << "copy constructor of Number" << std::endl;
}

Number::~Number()
{
	std::cout << "destructor of Number" << std::endl;
}

Number &Number::operator=(Number const &other)
{
	std::cout << "operator= of Number" << std::endl;
	this->n = other.n;
	return (*this);
}

Number &Number::operator=(int value)
{
	this->n = value;
	return (*this);
}

bool Number::operator==(Number const &b)
{
	return (this->n == b.n);
}

bool Number::operator!=(Number const &b)
{
	return (this->n != b.n);
}

bool Number::operator<(Number const &b)
{
	return (this->n < b.n);
}

bool Number::operator<=(Number const &b)
{
	return (this->n <= b.n);
}

bool Number::operator>(Number const &b)
{
	return (this->n > b.n);
}

bool Number::operator>=(Number const &b)
{
	return (this->n >= b.n);
}

bool Number::operator==(int const &n)
{
	return (this->n == n);
}

bool Number::operator!=(int const &n)
{
	return (this->n != n);
}

bool Number::operator<(int const &n)
{
	return (this->n < n);
}

bool Number::operator<=(int const &n)
{
	return (this->n <= n);
}

bool Number::operator>(int const &n)
{
	return (this->n > n);
}

bool Number::operator>=(int const &n)
{
	return (this->n >= n);
}

bool operator==(Number const &lhs, Number const &rhs)
{
	return (lhs.getValue() == rhs.getValue());
}

bool operator!=(Number const &lhs, Number const &rhs)
{
	return (lhs.getValue() != rhs.getValue());
}

bool operator<(Number const &lhs, Number const &rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

bool operator<=(Number const &lhs, Number const &rhs)
{
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>(Number const &lhs, Number const &rhs)
{
	return (lhs.getValue() > rhs.getValue());
}

bool operator>=(Number const &lhs, Number const &rhs)
{
	return (lhs.getValue() >= rhs.getValue());
}

int Number::getValue(void) const
{
	return (this->n);
}

std::ostream &operator<<(std::ostream &out, Number const &n)
{
	out << n.getValue();
	return (out);
}
