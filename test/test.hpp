/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:27:56 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/31 02:54:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# ifdef def_test_full
#  define FULL
# endif

# include <iostream>
# include "test/Number.hpp"
# include "include/Vector.hpp"
# include "include/List.hpp"
# include "include/Stack.hpp"
# include "include/Queue.hpp"
# include "include/Map.hpp"
# include "include/Set.hpp"

void test(std::string const &what)
{
	std::cout << "######################################## START TEST " << what << std::endl;
}

void end_test(std::string const &what)
{
	std::cout << "######################################## END TEST " << what << '\n' << std::endl;
}

template<typename Container>
void display_container(std::string const &header, Container const &ctn)
{
	typename Container::const_iterator it = ctn.begin();
	typename Container::const_iterator ite = ctn.end();
	std::cout << header;
	if (it == ite)
		std::cout << " empty !";
	std::cout << '\n';
	while (it != ite)
	{
		std::cout << *it;
		if (++it == ite)
			std::cout << '\n';
		else
			std::cout <<  ", ";
	}
}

template<typename key_type, typename value_type>
void display_container(std::string const &header, ft::Map<key_type, value_type> const &ctn)
{
	typename ft::Map<key_type, value_type>::const_iterator it = ctn.begin();
	typename ft::Map<key_type, value_type>::const_iterator ite = ctn.end();
	std::cout << header;
	if (it == ite)
		std::cout << " empty !";
	std::cout << '\n';
	while (it != ite)
	{
		std::cout << (*it).first << " => " << (*it).second;
		if (++it == ite)
			std::cout << '\n';
		else
			std::cout <<  ", ";
	}
}

# include "vector_test.hpp"
# include "list_test.hpp"
# include "stack_test.hpp"
# include "queue_test.hpp"
# include "map_test.hpp"
# include "set_test.hpp"

#endif
