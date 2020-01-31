/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:14:47 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 19:00:01 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

int Number::created = 0;
int Number::destructed = 0;

Number::Number():
	n(0)
{
	Number::created++;
	#ifdef DEBUG
	std::cout << "default constructor of Number" << std::endl;
	#endif
}

Number::Number(int const &n):
	n(n)
{
	Number::created++;
	#ifdef DEBUG
	std::cout << "assignation constructor of Number" << std::endl;
	#endif
}

Number::Number(Number const &other):
	n(other.n)
{
	Number::created++;
	#ifdef DEBUG
	std::cout << "copy constructor of Number" << std::endl;
	#endif
}

Number::~Number()
{
	Number::destructed++;
	#ifdef DEBUG
	std::cout << "destructor of Number" << std::endl;
	#endif
}

Number &Number::operator=(Number const &other)
{
	#ifdef DEBUG
	std::cout << "operator= of Number" << std::endl;
	#endif
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

int Number::getCreated(void)
{
	return (Number::created);
}

int Number::getDestructed(void)
{
	return (Number::destructed);
}

std::ostream &operator<<(std::ostream &out, Number const &n)
{
	out << n.getValue();
	return (out);
}
