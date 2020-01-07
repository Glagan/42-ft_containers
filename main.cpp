/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/07 16:30:11 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "include/Vector.hpp"
#include "test/Number.hpp"

int main(void)
{
	ft::Vector<int> vector;
	std::vector<int> vv;

	std::cout << "size: " << vector.size() << std::endl
		<< "capacity: " << vector.capacity() << std::endl
		<< "empty?: " << vector.empty() << std::endl
		<< "max_size: " << vector.max_size() << std::endl;

	std::cout << "Empty vector: " << std::endl;
	ft::Vector<int>::iterator it;
	ft::Vector<int>::iterator ite;
	/*it = vector.begin();
	ite = vector.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}*/

	// 2 elements
	vector.push_back(5);
	vector.push_back(42);

	std::cout << "2 elements in vector (index): " << std::endl;
	for (size_t i = 0; i < 2; i++)
		std::cout << vector[i] << " (" << vector.at(i) << ")" << std::endl;

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
	for (size_t i = 0; i < 250; i++)
		vector.push_back(i);

	std::cout << "250 elements in vector (index): " << std::endl;
	for (size_t i = 0; i < 250; i++)
	{
		std::cout << vector[i] << " (" << vector.at(i) << ")";
		if (i < 249)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}

	std::cout << "250 elements in vector (iterator): " << std::endl;
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
	std::cout << "250 elements in vector (reverse_iterator): " << std::endl;
	ft::Vector<int>::reverse_iterator rit = vector.rbegin();
	ft::Vector<int>::reverse_iterator rite = vector.rend();
	while (rit != rite)
	{
		std::cout << *rit++;
		if (rit == rite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Assign
	std::cout << "50 `42` in vvector: " << std::endl;
	ft::Vector<int> vvector;
	vvector.assign(50, 42);
	it = vvector.begin();
	ite = vvector.end();
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
	vvector.insert(vvector.begin(), 50, 43);
	std::cout << "50 `43` and 50 `42` in vvector: " << std::endl;
	it = vvector.begin();
	ite = vvector.end();
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
	nvector.push_back(vvector);

	std::cout << "nvector size: " << vector.size() << std::endl
		<< "nvector capacity: " << vector.capacity() << std::endl
		<< "nvector empty?: " << vector.empty() << std::endl
		<< "nvector max_size: " << vector.max_size() << std::endl;

	std::cout << "50 `43` and 50 `42` in nvector[1]: " << std::endl;
	it = nvector[1].begin();
	ite = nvector[1].end();
	i = 0;
	while (it != ite)
	{
		std::cout << *it++ << "(" << ++i << ")";
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

	std::cout << "5 and 42 Number in nbvector (iterator): " << std::endl;
	ft::Vector<Number>::iterator itb = nbvector.begin();
	ft::Vector<Number>::iterator iteb = nbvector.end();
	i = 0;
	while (itb != iteb)
	{
		std::cout << *itb << "(" << ++i << ", "
				<< itb->getValue() << ")";
		if (++itb == iteb)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	std::cout << "42 and 5 Number in nbvector (reverse_iterator): " << std::endl;
	ft::Vector<Number>::reverse_iterator ritb = nbvector.rbegin();
	ft::Vector<Number>::reverse_iterator riteb = nbvector.rend();
	i = 0;
	while (ritb != riteb)
	{
		std::cout << *ritb << "(" << ++i << ", "
				<< ritb->getValue() << ")";
		if (++ritb == riteb)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	std::cout << "same vector comparison:" << std::endl
		<< "comparison ==" << (vvector == nvector[1]) << std::endl
		<< "comparison !=" << (vvector != nvector[1]) << std::endl
		<< "comparison < " << (vvector < nvector[1]) << std::endl
		<< "comparison > " << (vvector > nvector[1]) << std::endl
		<< "comparison <=" << (vvector <= nvector[1]) << std::endl
		<< "comparison >=" << (vvector >= nvector[1]) << std::endl;

	std::cout << "different vector comparison:" << std::endl
		<< "comparison ==" << (vector == nvector[1]) << std::endl
		<< "comparison !=" << (vector != nvector[1]) << std::endl
		<< "comparison < " << (vector < nvector[1]) << std::endl
		<< "comparison > " << (vector > nvector[1]) << std::endl
		<< "comparison <=" << (vector <= nvector[1]) << std::endl
		<< "comparison >=" << (vector >= nvector[1]) << std::endl;

	// Erase
	std::cout << "empty nvector[1] after erase:" << std::endl;
	/*it = nvector[1].erase(nvector[1].begin(), nvector[1].end());
	ite = nvector[1].end();
	i = 0;
	while (it != ite)
	{
		std::cout << *it++ << "(" << ++i << ")";
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}*/

	// Erase 25 to 75
	std::cout << "nvector[1] size: " << nvector[1].size() << std::endl
		<< "nvector[1] capacity: " << nvector[1].capacity() << std::endl
		<< "nvector[1] empty?: " << nvector[1].empty() << std::endl
		<< "nvector[1] max_size: " << nvector[1].max_size() << std::endl;
	std::cout << "nvector[1] after erase [25-75]:" << std::endl;
	nvector[1].erase(nvector[1].begin() + 25, nvector[1].begin() + 75);
	it = nvector[1].begin();
	ite = nvector[1].end();
	i = 0;
	while (it != ite)
	{
		std::cout << *it++ << "(" << ++i << ")";
		if (it == ite)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
	std::cout << "nvector[1] size: " << nvector[1].size() << std::endl
		<< "nvector[1] capacity: " << nvector[1].capacity() << std::endl
		<< "nvector[1] empty?: " << nvector[1].empty() << std::endl
		<< "nvector[1] max_size: " << nvector[1].max_size() << std::endl;

	// Erase first
	ft::Vector<Number> nbbvector;
	nbbvector.push_back(43);
	nbbvector.push_back(44);
	nbbvector.push_back(45);
	std::cout << "nbbvector after erasing first element:" << std::endl;
	itb = nbbvector.erase(nbbvector.begin());
	iteb = nbbvector.end();
	i = 0;
	while (itb != iteb)
	{
		std::cout << *itb << "(" << ++i << ", "
				<< itb->getValue() << ")";
		if (++itb == iteb)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	// Leaks
	//std::cout << "#####" << std::endl;
	//system("leaks ft_containers");
	//std::cout << "#####" << std::endl;
	return (0);
}
