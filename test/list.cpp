/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/09 19:54:43 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <list>

void test_List(void)
{
	ft::List<int> empty_list;
	(void)empty_list;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(42);

	std::cout << *--lst.end() << std::endl;

	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);
		std::cout << "Last list element: " << *--lst.end() << std::endl;

		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		int i = 0;
		std::cout << "5, 42, 3:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;

		ft::List<int>::reverse_iterator rit = lst.rbegin();
		ft::List<int>::reverse_iterator rite = lst.rend();
		i = 0;
		std::cout << "(reverse) 5, 42, 3:" << std::endl;
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << std::endl;
	}

	{
		ft::List<int> lst;
		lst.push_front(5);
		lst.push_front(42);
		lst.push_front(3);

		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		int i = 0;
		std::cout << "5, 42, 3:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;

		ft::List<int>::reverse_iterator rit = lst.rbegin();
		ft::List<int>::reverse_iterator rite = lst.rend();
		i = 0;
		std::cout << "(reverse) 5, 42, 3:" << std::endl;
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << std::endl;
	}
}
