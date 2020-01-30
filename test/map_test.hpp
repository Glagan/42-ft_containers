/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:39:23 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/26 18:39:00 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include "test/test.hpp"
# include <functional>
# include <map>
# include <vector>

/**
 * offset is used to display '0' instead of char 0
 **/
template<typename key_type, typename value_type>
void test_Map(int offset=0)
{
	std::cout << "\n---basic\n\n";
	{
		ft::Map<key_type, value_type> empty_map;
		if (empty_map.begin() == empty_map.end())
			std::cout << "[begin] == [end] on empty map" << '\n';
		else
			std::cout << "!!! [begin] != [end] on empty map !!!" << '\n';
		std::cout << "max_size = " << empty_map.max_size() << '\n';
		std::cout << "size: " << empty_map.size() << " (0), empty? " << empty_map.empty() << '\n';

		ft::Map<key_type, value_type> mp;
		mp[5+offset] = 42;
		mp[7+offset] = 28;
		mp[9+offset] = 44;

		std::cout << "map [5:42, 7:28, 9:44].size() = " << mp.size() << '\n';
		typename ft::Map<key_type, value_type>::iterator it = mp.begin();
		std::cout << "[5:42, 7:28, 9:44].[5] = " << mp[5+offset] << " (it: first: " << (*it).first << ", second: " << (*it).second << ")" << '\n';
		it = --mp.end();
		std::cout << "[5:42, 7:28, 9:44].[9] = " << mp[9+offset] << " (it: first: " << (*it).first << ", second: " << (*it).second << ")" << '\n';

		ft::Map<key_type, value_type> mp2 = mp;

		display_container("copied map2 [5:42, 7:28, 9:44]:", mp2);
		mp2.clear();
		display_container("cleared map2 []:", mp2);

		display_container("map [5:42, 7:28, 9:44]:", mp);
		mp.erase(7+offset);
		display_container("map [5:42, 9:44]:", mp);
		mp.erase(5+offset);
		display_container("map [9:44]:", mp);
		mp.erase(9+offset);
		display_container("map []:", mp);

		mp.key_comp();
		mp.value_comp();
	}

	std::cout << "\n---basic (bigger map)\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5+offset, 5));
		mp.insert(std::make_pair(6+offset, 6));
		mp.insert(std::make_pair(7+offset, 7));
		mp.insert(std::make_pair(8+offset, 8));
		mp.insert(std::make_pair(9+offset, 9));
		mp.insert(std::make_pair(10+offset, 10));
		mp.insert(std::make_pair(11+offset, 11));

		std::cout << "size: " << mp.size() << " (7), empty? " << mp.empty() << '\n';
		display_container("map [5:5, ..., 11:11]:", mp);
		mp.erase(7);
		display_container("map erased 7 [5:5, ..., 11:11]:", mp);
		mp.erase(5);
		display_container("map erased 5 [5:5, ..., 11:11]:", mp);
		mp.erase(++mp.begin(), --mp.end());
		display_container("map erased everything except begin,end [6:6, 11:11]:", mp);
	}

	std::cout << "\n---insert\n\n";
	{
		ft::Map<key_type, value_type> mp;

		mp.insert(mp.begin(), std::make_pair(5+offset, 42));
		display_container("map [5:42]:", mp);
		mp.insert(mp.begin(), std::make_pair(6+offset, 43));
		display_container("map [5:42, 6:43]:", mp);
		mp.insert(mp.begin(), std::make_pair(4+offset, 44));
		display_container("map [4:44, 5:42, 6:43]:", mp);

		mp.insert(--mp.end(), std::make_pair(3+offset, 45));
		display_container("map [3:45, 4:44, 5:42, 6:43]:", mp);
		mp.insert(--mp.end(), std::make_pair(7+offset, 46));
		display_container("map [3:45, 4:44, 5:42, 6:43, 7:46]:", mp);

		ft::Map<key_type, value_type> mp2;
		mp2.insert(mp.begin(), mp.end());
		display_container("map2 [3:45, 4:44, 5:42, 6:43, 7:46]:", mp2);
		mp.erase(mp.begin(), mp.end());
		display_container("map2 (map cleared) [3:45, 4:44, 5:42, 6:43, 7:46]:", mp2);
	}

	std::cout << "\n---erase\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5+offset, 42));
		mp.insert(std::make_pair(6+offset, 43));
		mp.insert(std::make_pair(7+offset, 44));
		mp.insert(std::make_pair(8+offset, 45));
		mp.insert(std::make_pair(9+offset, 46));
		display_container("map [5:42, 6:43, 7:44, 8:45, 9:46]:", mp);

		ft::Map<key_type, value_type> mp2(mp);
		display_container("map2 [5:42, 6:43, 7:44, 8:45, 9:46]:", mp2);
		mp2.erase(mp2.begin(), mp2.end());
		display_container("map2 []:", mp2);

		mp2 = mp;
		display_container("map2 [5:42, 6:43, 7:44, 8:45, 9:46]:", mp2);
		mp2.erase(++mp2.rend(), --mp2.rbegin());
		display_container("map2 [5:42, 9:46]:", mp2);
		mp2.erase(mp2.begin());
		display_container("map2 [9:46]:", mp2);
		std::cout << "size: " << mp2.size() << " (1), empty? " << mp2.empty() << '\n';
	}

	std::cout << '\n';
}

#endif
