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
		mp2.erase(++mp2.rbegin(), --mp2.rend());
		display_container("map2 [5:42, 6:43]:", mp2);
		mp2.erase(mp2.begin());
		display_container("map2 [6:43]:", mp2);
		std::cout << "size: " << mp2.size() << " (1), empty? " << mp2.empty() << '\n';
	}

	std::cout << "\n---find\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5+offset, 42));
		mp.insert(std::make_pair(7+offset, 43));
		mp.insert(std::make_pair(6+offset, 48));

		display_container("map [5:42, 6:48, 7:43]:", mp);
		std::cout << "find(99) " << ((mp.find(99) == mp.end()) ? "== end" : "!= end !!!") << '\n';
		std::cout << "find(42) " << ((mp.find(42) == mp.end()) ? "== end" : "!= end !!!") << '\n';
		std::cout << "find(5) " << ((mp.find(5) == mp.begin()) ? "== begin" : "!= begin !!!") << '\n';
		std::cout << "find(6) " << ((mp.find(6) == ++mp.begin()) ? "== ++begin" : "!= ++begin !!!") << '\n';
		std::cout << "find(7) " << ((mp.find(7) == --mp.end()) ? "== --end" : "!= --end !!!") << '\n';
	}

	std::cout << "\n---count\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5+offset, 42));
		mp.insert(std::make_pair(5+offset, 99));
		mp.insert(std::make_pair(7+offset, 43));
		mp.insert(std::make_pair(7+offset, 34));
		mp.insert(std::make_pair(6+offset, 48));
		mp.insert(std::make_pair(6+offset, 84));

		display_container("map [5:42, 6:48, 7:43]:", mp);
		std::cout << "count(5) " << mp.count(5) << " (1)\n";
		std::cout << "count(6) " << mp.count(6) << " (1)\n";
		std::cout << "count(7) " << mp.count(7) << " (1)\n";
		std::cout << "count(99) " << mp.count(99) << " (0)\n";
	}

	std::cout << "\n---bounds\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5+offset, 42));
		mp.insert(std::make_pair(7+offset, 44));
		mp.insert(std::make_pair(9+offset, 95));
		mp.insert(std::make_pair(11+offset, 10));
		mp.insert(std::make_pair(3+offset, 12));
		mp.insert(std::make_pair(1+offset, 78));
		mp.insert(std::make_pair(-1+offset, 65));
		mp.insert(std::make_pair(6+offset, 32));
		mp.insert(std::make_pair(8+offset, 1));

		display_container("map [-1:65, 1:78, 3:12, 5:42, 6:32, 7:44, 8:1, 9:95, 11:10]:", mp);
		std::cout << "lower_bound(5): " << mp.lower_bound(5)->first << " (5)\n";
		std::cout << "lower_bound(4): " << mp.lower_bound(4)->first << " (5)\n";
		std::cout << "lower_bound(99): " << (((mp.lower_bound(99)) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
		std::cout << "lower_bound(-99): " << mp.lower_bound(-99)->first << " (-1)\n";
		std::cout << "upper_bound(5): " << mp.upper_bound(5)->first << " (6)\n";
		std::cout << "upper_bound(4): " << mp.upper_bound(4)->first << " (5)\n";
		std::cout << "upper_bound(99): " << (((mp.upper_bound(99)) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
		std::cout << "upper_bound(-99): " << mp.upper_bound(-99)->first << " (-1)\n";
	}

	std::cout << "\n---equal_range\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5+offset, 42));
		mp.insert(std::make_pair(7+offset, 44));
		mp.insert(std::make_pair(9+offset, 95));
		mp.insert(std::make_pair(11+offset, 10));
		mp.insert(std::make_pair(3+offset, 12));
		mp.insert(std::make_pair(1+offset, 78));
		mp.insert(std::make_pair(-1+offset, 65));
		mp.insert(std::make_pair(6+offset, 32));
		mp.insert(std::make_pair(8+offset, 1));

		display_container("map [-1:65, 1:78, 3:12, 5:42, 6:32, 7:44, 8:1, 9:95, 11:10]:", mp);
		std::cout << "equal_range(5) " << (mp.equal_range(5)).first->first << "," << (mp.equal_range(5)).second->first << " (5,6)\n";
		std::cout << "equal_range(6) " << (mp.equal_range(6)).first->first << "," << (mp.equal_range(7)).second->first << " (6,8)\n";
		std::cout << "equal_range(10) " << (mp.equal_range(10)).first->first << "," << (mp.equal_range(10)).second->first << " (11,11)\n";
		std::cout << "equal_range(99) " << (((mp.equal_range(99)).first == mp.end()) ? "end" : "!!! not end !!!") << "," << (((mp.equal_range(99)).second == mp.end()) ? "end" : "!!! not end !!!") << " (end,end)\n";
		std::cout << "equal_range(-99) " << (mp.equal_range(-99)).first->first << "," << (mp.equal_range(-99)).second->first << " (-1,-1)\n";
	}

	std::cout << "\n---swap\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(5+offset, 42));
		mp.insert(std::make_pair(7+offset, 43));
		mp.insert(std::make_pair(9+offset, 44));

		ft::Map<key_type, value_type> mp2;
		mp2.insert(std::make_pair(11+offset, 84));
		mp2.insert(std::make_pair(12+offset, 85));
		mp2.insert(std::make_pair(13+offset, 86));

		display_container("map [5:42, 7:43, 9:44]:", mp);
		display_container("map2 [11:84, 12:85, 13:86]:", mp2);
		mp.swap(mp2);
		std::cout << "---swapped\n";
		display_container("map [11:84, 12:85, 13:86]:", mp);
		display_container("map2 [5:42, 7:43, 9:44]:", mp2);
		ft::swap(mp, mp2);
		std::cout << "---swapped\n";
		display_container("map [5:42, 7:43, 9:44]:", mp);
		display_container("map2 [11:84, 12:85, 13:86]:", mp2);
	}

	std::cout << '\n';
}

#endif
