/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/05 15:41:18 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Vector.hpp"
#include "test/Number.hpp"

int main(void)
{
	ft::Vector<int> vector;

	std::cout << "Empty vector: " << std::endl;
	ft::Vector<int>::iterator it = vector.begin();
	ft::Vector<int>::iterator ite = vector.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// 2 elements
	vector.push_back(5);
	vector.push_back(42);

	std::cout << "2 elements in vector (index): " << std::endl;
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << vector[i] << " (" << vector.at(i) << ")" << std::endl;
	}

	std::cout << "2 elements in vector (iterator): " << std::endl;
	it = vector.begin();
	ite = vector.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Clear elements
	vector.clear();

	// A lot of elements
	for (size_t i = 0; i < 500; i++)
		vector.push_back(i);

	std::cout << "500 elements in vector (index): " << std::endl;
	for (size_t i = 0; i < 500; i++)
	{
		std::cout << vector[i] << " (" << vector.at(i) << ")";
		if (i < 499)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}

	std::cout << "500 elements in vector (iterator): " << std::endl;
	it = vector.begin();
	ite = vector.end();
	while (it != ite)
	{
		std::cout << *it;
		it++;
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Reverse
	std::cout << "500 elements in vector (reverse_iterator): " << std::endl;
	ft::Vector<int>::reverse_iterator rit = vector.rbegin();
	ft::Vector<int>::reverse_iterator rite = vector.rend();
	while (rit != rite)
	{
		std::cout << *rit;
		rit++;
		if (rit == rite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Assign
	std::cout << "50 `42` in vector: " << std::endl;
	vector.assign(50, 42);
	it = vector.begin();
	ite = vector.end();
	int i = 0;
	while (it != ite)
	{
		std::cout << *it << "(" << ++i << ")";
		it++;
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Insert
	vector.insert(vector.begin(), 50, 43);
	std::cout << "50 `43` and 50 `42` in vector: " << std::endl;
	it = vector.begin();
	ite = vector.end();
	i = 0;
	while (it != ite)
	{
		std::cout << *it << "(" << ++i << ")";
		it++;
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Vector of Vector
	ft::Vector< ft::Vector<int> > nvector;
	nvector.push_back(vector);

	std::cout << "50 `43` and 50 `42` in nvector[0]: " << std::endl;
	it = nvector[0].begin();
	ite = nvector[0].end();
	i = 0;
	while (it != ite)
	{
		std::cout << *it << "(" << ++i << ")";
		it++;
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Vector of Number
	Number nb(5);
	ft::Vector< Number > nbvector;
	nbvector.push_back(nb);
	nb = 42;
	nbvector.push_back(nb);

	std::cout << "5 and 42 Number in nbvector: " << std::endl;
	ft::Vector<Number>::iterator itb = nbvector.begin();
	ft::Vector<Number>::iterator iteb = nbvector.end();
	i = 0;
	while (itb != iteb)
	{
		std::cout << *itb << "(" << ++i << ")";
		itb++;
		if (itb == iteb)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Leaks
	system("leaks ft_containers");
	return (0);
}
