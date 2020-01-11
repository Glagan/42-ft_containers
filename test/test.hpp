/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:27:56 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 16:23:54 by ncolomer         ###   ########.fr       */
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

template<typename T>
void display_list(std::string const &header, ft::List<T> const &list)
{
	typename ft::List<T>::const_iterator it = list.begin();
	typename ft::List<T>::const_iterator ite = list.end();
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

#endif
