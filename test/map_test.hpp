/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:39:23 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/15 18:53:05 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include "test/test.hpp"
# include <functional>
# include <map>
# include <vector>

template<typename key_type, typename value_type>
void test_Map(void)
{
	/*std::map<int, int> mapp;
	mapp.insert(std::make_pair(5, 42));
	std::cout << mapp[5] << std::endl;*/

	ft::Map<int, int> map;
	map[5] = 42;
	std::cout << "42 => " << map[5] << std::endl;
	map[5] = 43;
	std::cout << "43 => " << map[5] << std::endl;
	map[10] = 42;
	std::cout << "42 => " << map[10] << std::endl;
}

#endif
