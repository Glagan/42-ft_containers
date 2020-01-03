/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/03 17:16:30 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/Vector.hpp"

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

	// A lot of elements
	for (size_t i = 0; i < 500; i++)
		vector.push_back(i);

	std::cout << "502 elements in vector (index): " << std::endl;
	for (size_t i = 0; i < 502; i++)
	{
		std::cout << vector[i] << " (" << vector.at(i) << ")";
		if (i < 501)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}

	std::cout << "502 elements in vector (iterator): " << std::endl;
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
	std::cout << "502 elements in vector (reverse_iterator): " << std::endl;
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

	// Leaks
	system("leaks ft_containers");
	return (0);
}
