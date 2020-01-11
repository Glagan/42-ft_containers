/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:27:56 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 16:46:57 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include "test/Number.hpp"
# include "include/Vector.hpp"
# include "include/List.hpp"
# include "include/Stack.hpp"
# include "include/Queue.hpp"

template<typename Container>
void display_container(std::string const &header, Container const &ctn)
{
	typename Container::const_iterator it = ctn.begin();
	typename Container::const_iterator ite = ctn.end();
	std::cout << header << '\n';
	while (it != ite)
	{
		std::cout << *it;
		if (++it == ite)
			std::cout << '\n';
		else
			std::cout <<  ", ";
	}
}

void test_Vector(void);
void test_List(void);
void test_Stack(void);
void test_Queue(void);
void test_Map(void);

#endif
