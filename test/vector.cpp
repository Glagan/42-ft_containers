/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 17:24:33 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

/*
void test_Vector(void)
{
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
}
*/

void test_Vector(void)
{

	std::cout << "---basic\n" << '\n';

	ft::Vector<int> empty_vector;
	if (empty_vector.begin() == empty_vector.end())
		std::cout << "[begin] == [end] on empty vector" << '\n';
	else
		std::cout << "!!! [begin] != [end] on empty vector !!!" << '\n';
	std::cout << "capacity? " << empty_vector.capacity() << '\n';
	std::cout << "max_size " << empty_vector.max_size() << '\n';
	std::cout << "empty? " << empty_vector.empty() << '\n';
	std::cout << "empty vector size = " << empty_vector.size() << '\n';

	ft::Vector<int> vec;
	vec.push_back(5);
	vec.push_back(42);

	std::cout << "vector [5, 42].size() = " << vec.size() << '\n';
	std::cout << "[5, 42].front() = " << vec.front() << " (it:" << *vec.begin() << ")" << '\n';
	std::cout << "[5, 42].back()  = " << vec.back() << " (it:" << *--vec.end() << ")" << '\n';

	for (size_t i = 0; i < 2; i++)
		std::cout << "vector[" << i << "] = " << vec[i] << " == vector.at(" << i << ") = " << vec.at(i) << '\n';
	display_container("vector [5, 42] with iterators:", vec);

	std::cout << "reverse:\n";
	{
		ft::Vector<int>::reverse_iterator it = vec.rbegin();
		ft::Vector<int>::reverse_iterator ite = vec.rend();
		while (it != ite)
		{
			std::cout << *it++;
			if (it == ite)
				std::cout << '\n';
			else
				std::cout << ", ";
		}
	}

	std::cout << "\n---reserve\n" << '\n';
	{
		ft::Vector<int> vec;
		std::cout << "empty vector capacity " << vec.capacity() << '\n';
		vec.reserve(256);
		std::cout << "empty vector{reserved 256} capacity " << vec.capacity() << '\n';
		vec.reserve(64);
		std::cout << "empty vector{reserved 64, no change} capacity " << vec.capacity() << '\n';
	}

	std::cout << "\n---push_back\n" << '\n';
	{
		ft::Vector<int> vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);

		ft::Vector<int>::iterator it = vec.begin();
		ft::Vector<int>::iterator ite = vec.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		ft::Vector<int>::reverse_iterator rit = vec.rbegin();
		ft::Vector<int>::reverse_iterator rite = vec.rend();
		i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		std::cout << "pop_back from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++)
		{
			vec.pop_back();
			it = vec.begin();
			ite = vec.end();
			if (i == 0) std::cout << "[5, 42]:" << '\n';
			else if (i == 1) std::cout << "[5]:" << '\n';
			else
			{
				std::cout << "[]:" << '\n';
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << '\n';
		}
	}

	std::cout << "\n---clear\n" << '\n';
	{
		ft::Vector<int> vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);

		ft::Vector<int>::iterator it = vec.begin();
		ft::Vector<int>::iterator ite = vec.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		ft::Vector<int> vec2(vec);
		vec.clear();

		it = vec.begin();
		ite = vec.end();
		i = 1;
		std::cout << "cleared vector []:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		it = vec2.begin();
		ite = vec2.end();
		i = 1;
		std::cout << "copied vector before clear [5, 2, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';
	}

	std::cout << "\n---erase\n" << '\n';
	{
		ft::Vector<int> vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);

		display_container("[5, 42, 3]:", vec);
		std::cout << "[3] -> " << *vec.erase(++vec.begin()) << '\n';
		display_container("42 deleted [5, 3]:", vec);

		ft::Vector<int>::iterator it = vec.erase(--vec.end());
		std::cout << "deleted [end] -> ";
		if (it == vec.end())
			std::cout << "returned [end]" << '\n';
		else
			std::cout << "!!! didn't return [end] !!!" << '\n';

		it = vec.erase(vec.begin());
		std::cout << "deleted [begin] -> ";
		if (it == vec.begin() && it == vec.end())
			std::cout << "returned [begin] and [end]" << '\n';
		else
			std::cout << "!!! didn't return [begin] and [end] !!!" << '\n';
	}

	std::cout << "\n---assign\n" << '\n';
	{
		ft::Vector<int> vec;

		vec.assign(5, 42);
		display_container("[42, 42, 42, 42, 42]:", vec);

		ft::Vector<int> vec2;
		vec2.assign(5, 43);
		display_container("vec2[43, 43, 43, 43, 43]:", vec2);
		vec.assign(vec2.begin(), vec2.end());
		display_container("vec [43, 43, 43, 43, 43]:", vec);

		vec2.assign(5, 44);
		display_container("vec[43, 43, 43, 43, 43]:", vec);
		display_container("vec2[44, 44, 44, 44, 44]:", vec2);
	}

	std::cout << "\n---insert\n" << '\n';
	{
		ft::Vector<int> vec;

		vec.insert(vec.begin(), 5);
		display_container("[5]:", vec);

		vec.insert(vec.begin(), 2, 42);
		display_container("vec[42, 42, 5]:", vec);

		ft::Vector<int> vec2;

		vec2.insert(vec2.begin(), vec.begin(), vec.end());
		display_container("vec to vec2[42, 42, 5]:", vec2);

		vec2.insert(vec2.end(), vec.begin(), vec.end());
		display_container("vec to vec2[42, 42, 5, 42, 42, 5]:", vec2);
	}

	std::cout << "\n---resize\n" << '\n';
	{
		ft::Vector<int> vec;
		vec.push_back(5);
		vec.push_back(42);

		display_container("[5, 42]:", vec);

		vec.resize(5, 43);
		display_container("[5, 42, 43, 43, 43]:", vec);

		vec.resize(1);
		display_container("[5]:", vec);

		vec.resize(0);
		display_container("[]:", vec);

		vec.resize(5);
		display_container("[0, 0, 0, 0, 0]:", vec);
	}

	std::cout << "\n---comparison\n" << '\n';
	{
		ft::Vector<int> vec;
		vec.push_back(5);
		vec.push_back(42);

		ft::Vector<int> vec2;
		vec2.push_back(5);
		vec2.push_back(42);

		ft::Vector<int> vec3;
		vec3.push_back(5);
		vec3.push_back(42);
		vec3.push_back(43);

		ft::Vector<int> vec4;
		vec4.push_back(99);
		vec4.push_back(42);
		vec4.push_back(43);

		std::cout << "same vector:" << '\n'
			<< "comparison == " << (vec == vec2) << '\n'
			<< "comparison != " << (vec != vec2) << '\n'
			<< "comparison <  " << (vec < vec2) << '\n'
			<< "comparison >  " << (vec > vec2) << '\n'
			<< "comparison <= " << (vec <= vec2) << '\n'
			<< "comparison >= " << (vec >= vec2) << '\n';

		std::cout << "lesser vector:" << '\n'
			<< "comparison == " << (vec == vec3) << '\n'
			<< "comparison != " << (vec != vec3) << '\n'
			<< "comparison <  " << (vec < vec3) << '\n'
			<< "comparison >  " << (vec > vec3) << '\n'
			<< "comparison <= " << (vec <= vec3) << '\n'
			<< "comparison >= " << (vec >= vec3) << '\n';

		std::cout << "upper vector:" << '\n'
			<< "comparison == " << (vec4 == vec) << '\n'
			<< "comparison != " << (vec4 != vec) << '\n'
			<< "comparison <  " << (vec4 < vec) << '\n'
			<< "comparison >  " << (vec4 > vec) << '\n'
			<< "comparison <= " << (vec4 <= vec) << '\n'
			<< "comparison >= " << (vec4 >= vec) << '\n';
	}
}