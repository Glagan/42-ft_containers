/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:39:23 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/15 19:59:19 by ncolomer         ###   ########.fr       */
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

	std::cout << "empty map iterator check: ";
	if (map.begin() == map.end())
		std::cout << "begin == end, OK\n";
	else
		std::cout << "!!! begin != end !!!\n";

	map[5] = 42;
	std::cout << "42 => " << map[5] << std::endl;
	map[5] = 43;
	std::cout << "43 => " << map[5] << std::endl;
	map[10] = 42;
	std::cout << "42 => " << map[10] << std::endl;

	map[6] = 44;
	map[7] = 45;
	map[8] = 46;
	map[9] = 47;
	map[11] = 48;
	map[12] = 49;

	std::cout << "[5 => 43, 6 => 44, 7 => 45, 8 => 46, 9 => 47, 10 => 42, 11 => 48, 12 => 49]:\n";

	ft::Map<int, int>::iterator it = map.begin();
	ft::Map<int, int>::iterator ite = map.end();
	while (it != ite)
	{
		std::cout << "it.first " << it->first << " it.second " << it->second << '\n';
		++it;
	}
}

#endif
