/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:27:56 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 18:42:34 by ncolomer         ###   ########.fr       */
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
# include "include/Map.hpp"

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

# include "test/vector_test.hpp"
# include "test/list_test.hpp"
# include "test/stack_test.hpp"
# include "test/queue_test.hpp"
# include "test/map_test.hpp"

#endif
