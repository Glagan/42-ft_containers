/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:39:23 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/02 18:52:53 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# define k(x) x+offset

template<typename key_type, typename value_type>
void test_Map(int offset=0)
{
	std::cout << "\n---basic\n\n";
	{
		ft::Map<key_type, value_type> empty_map;
		{
			assert(empty_map.begin() == empty_map.end());
			assert(empty_map.empty());
			assert(empty_map.size() == 0);

			std::cout << "[begin] == [end] on empty map" << '\n';
			std::cout << "max_size = " << empty_map.max_size() << '\n';
			std::cout << "size: " << empty_map.size() << " (0), empty? " << empty_map.empty() << '\n';
		}

		ft::Map<key_type, value_type> mp;
		mp[k(5)] = 42;
		mp[k(7)] = 28;
		mp[k(9)] = 44;
		{
			std::cout << "map [5:42, 7:28, 9:44].size() = " << mp.size() << '\n';
			typename ft::Map<key_type, value_type>::iterator it = mp.begin();
			std::cout << "[5:42, 7:28, 9:44].[5] = " << mp[k(5)] << " (it: first: " << (*it).first << ", second: " << (*it).second << ")" << '\n';
			it = --mp.end();
			std::cout << "[5:42, 7:28, 9:44].[9] = " << mp[k(9)] << " (it: first: " << (*it).first << ", second: " << (*it).second << ")" << '\n';

			ft::Map<key_type, value_type> mp2 = mp;

			display_container("copied map2 [5:42, 7:28, 9:44]:", mp2);
			mp2.clear();
			display_container("cleared map2 []:", mp2);

			display_container("map [5:42, 7:28, 9:44]:", mp);
			mp.erase(k(7));
			display_container("map [5:42, 9:44]:", mp);
			mp.erase(k(5));
			display_container("map [9:44]:", mp);
			mp.erase(k(9));
			display_container("map []:", mp);

			mp.key_comp();
			mp.value_comp();
		}
	}

	std::cout << "\n---basic (bigger map)\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(k(5), 5));
		mp.insert(std::make_pair(k(6), 6));
		mp.insert(std::make_pair(k(7), 7));
		mp.insert(std::make_pair(k(8), 8));
		mp.insert(std::make_pair(k(9), 9));
		mp.insert(std::make_pair(k(10), 10));
		mp.insert(std::make_pair(k(11), 11));

		std::cout << "size: " << mp.size() << " (7), empty? " << mp.empty() << '\n';
		display_container("map [5:5, ..., 11:11]:", mp);
		mp.erase(k(7));
		display_container("map erased 7 [5:5, ..., 11:11]:", mp);
		mp.erase(k(5));
		display_container("map erased 5 [5:5, ..., 11:11]:", mp);
		mp.erase(++mp.begin(), --mp.end());
		display_container("map erased everything except begin,end [6:6, 11:11]:", mp);
	}

	std::cout << "\n---insert\n\n";
	{
		ft::Map<key_type, value_type> mp;

		mp.insert(mp.begin(), std::make_pair(k(5), 42));
		display_container("map [5:42]:", mp);
		mp.insert(mp.begin(), std::make_pair(k(6), 43));
		display_container("map [5:42, 6:43]:", mp);
		mp.insert(mp.begin(), std::make_pair(k(4), 44));
		display_container("map [4:44, 5:42, 6:43]:", mp);

		mp.insert(--mp.end(), std::make_pair(k(3), 45));
		display_container("map [3:45, 4:44, 5:42, 6:43]:", mp);
		mp.insert(--mp.end(), std::make_pair(k(7), 46));
		display_container("map [3:45, 4:44, 5:42, 6:43, 7:46]:", mp);

		ft::Map<key_type, value_type> mp2;
		mp2.insert(mp.begin(), mp.end());
		display_container("map2 [3:45, 4:44, 5:42, 6:43, 7:46]:", mp2);
		mp.erase(mp.begin(), mp.end());
		display_container("map cleared:", mp);
		display_container("map2 (map cleared) [3:45, 4:44, 5:42, 6:43, 7:46]:", mp2);
	}

	std::cout << "\n---erase\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(6), 43));
		mp.insert(std::make_pair(k(7), 44));
		mp.insert(std::make_pair(k(8), 45));
		mp.insert(std::make_pair(k(9), 46));
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
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(7), 43));
		mp.insert(std::make_pair(k(6), 48));

		display_container("map [5:42, 6:48, 7:43]:", mp);
		std::cout << "find(99) " << ((mp.find(k(99)) == mp.end()) ? "== end" : "!= end !!!") << '\n';
		std::cout << "find(42) " << ((mp.find(k(42)) == mp.end()) ? "== end" : "!= end !!!") << '\n';
		std::cout << "find(5) " << ((mp.find(k(5)) == mp.begin()) ? "== begin" : "!= begin !!!") << '\n';
		std::cout << "find(6) " << ((mp.find(k(6)) == ++mp.begin()) ? "== ++begin" : "!= ++begin !!!") << '\n';
		std::cout << "find(7) " << ((mp.find(k(7)) == --mp.end()) ? "== --end" : "!= --end !!!") << '\n';
	}

	std::cout << "\n---count\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(5), 99));
		mp.insert(std::make_pair(k(7), 43));
		mp.insert(std::make_pair(k(7), 34));
		mp.insert(std::make_pair(k(6), 48));
		mp.insert(std::make_pair(k(6), 84));

		display_container("map [5:42, 6:48, 7:43]:", mp);
		std::cout << "count(5) " << mp.count(k(5)) << " (1)\n";
		std::cout << "count(6) " << mp.count(k(6)) << " (1)\n";
		std::cout << "count(7) " << mp.count(k(7)) << " (1)\n";
		std::cout << "count(99) " << mp.count(k(99)) << " (0)\n";
	}

	std::cout << "\n---bounds\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(7), 44));
		mp.insert(std::make_pair(k(9), 95));
		mp.insert(std::make_pair(k(11), 10));
		mp.insert(std::make_pair(k(3), 12));
		mp.insert(std::make_pair(k(1), 78));
		mp.insert(std::make_pair(k(-1), 65));
		mp.insert(std::make_pair(k(6), 32));
		mp.insert(std::make_pair(k(8), 1));

		display_container("map [-1:65, 1:78, 3:12, 5:42, 6:32, 7:44, 8:1, 9:95, 11:10]:", mp);
		std::cout << "lower_bound(5): " << mp.lower_bound(k(5))->first << " (5)\n";
		std::cout << "lower_bound(4): " << mp.lower_bound(k(4))->first << " (5)\n";
		std::cout << "lower_bound(99): " << (((mp.lower_bound(k(99))) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
		std::cout << "lower_bound(-99): " << mp.lower_bound(k(-99))->first << " (-1)\n";
		std::cout << "upper_bound(5): " << mp.upper_bound(k(5))->first << " (6)\n";
		std::cout << "upper_bound(4): " << mp.upper_bound(k(4))->first << " (5)\n";
		std::cout << "upper_bound(99): " << (((mp.upper_bound(k(99))) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
		std::cout << "upper_bound(-99): " << mp.upper_bound(k(-99))->first << " (-1)\n";
	}

	std::cout << "\n---equal_range\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(7), 44));
		mp.insert(std::make_pair(k(9), 95));
		mp.insert(std::make_pair(k(11), 10));
		mp.insert(std::make_pair(k(3), 12));
		mp.insert(std::make_pair(k(1), 78));
		mp.insert(std::make_pair(k(-1), 65));
		mp.insert(std::make_pair(k(6), 32));
		mp.insert(std::make_pair(k(8), 1));

		display_container("map [-1:65, 1:78, 3:12, 5:42, 6:32, 7:44, 8:1, 9:95, 11:10]:", mp);
		std::cout << "equal_range(5) " << (mp.equal_range(k(5))).first->first << "," << (mp.equal_range(k(5))).second->first << " (5,6)\n";
		std::cout << "equal_range(6) " << (mp.equal_range(k(6))).first->first << "," << (mp.equal_range(k(7))).second->first << " (6,8)\n";
		std::cout << "equal_range(10) " << (mp.equal_range(k(10))).first->first << "," << (mp.equal_range(k(10))).second->first << " (11,11)\n";
		std::cout << "equal_range(99) " << (((mp.equal_range(k(99))).first == mp.end()) ? "end" : "!!! not end !!!") << "," << (((mp.equal_range(k(99))).second == mp.end()) ? "end" : "!!! not end !!!") << " (end,end)\n";
		std::cout << "equal_range(-99) " << (mp.equal_range(k(-99))).first->first << "," << (mp.equal_range(k(-99))).second->first << " (-1,-1)\n";
	}

	std::cout << "\n---swap\n\n";
	{
		ft::Map<key_type, value_type> mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(7), 43));
		mp.insert(std::make_pair(k(9), 44));

		ft::Map<key_type, value_type> mp2;
		mp2.insert(std::make_pair(k(11), 84));
		mp2.insert(std::make_pair(k(12), 85));
		mp2.insert(std::make_pair(k(13), 86));

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
