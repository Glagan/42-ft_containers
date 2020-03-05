/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimap_test.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:39:23 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/05 16:43:14 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIMAP_TEST_HPP
# define MULTIMAP_TEST_HPP

# ifndef k
# 	define k(x) (x+offset)
# endif

template<class MapType>
void test_Multimap(int offset=0)
{
	std::cout << "\n---basic\n\n";
	{
		MapType empty_map;
		{
			std::cout << "[begin] == [end] on empty map" << '\n';
				assert(empty_map.begin() == empty_map.end());
			// std::cout << "max_size (multimap) = " << empty_map.max_size() << '\n';
			std::cout << "size: " << empty_map.size() << " (0), empty? " << empty_map.empty() << '\n';
				assert(empty_map.empty());
				assert(empty_map.size() == 0);
		}

		MapType mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(7), 28));
		mp.insert(std::make_pair(k(9), 44));
		{
			std::cout << "map [5:42, 7:28, 9:44].size() = " << mp.size() << '\n';
				assert(mp.size() == 3);
			typename MapType::iterator it = mp.begin();
			std::cout << "[5:42, 7:28, 9:44].[5] = " << (*it).first << "[" << (*it).second << "]" << '\n';
				assert((*it).second == 42);
			it = --mp.end();
			std::cout << "[5:42, 7:28, 9:44].[9] = " << (*it).first << "[" << (*it).second << "]" << '\n';
				assert((*it).second == 44);

			MapType mp2 = mp;

			display_container("copied map2 [5:42, 7:28, 9:44]:", mp2);
				assert(mp2.size() == 3);
			mp2.clear();
			display_container("cleared map2 []:", mp2);
				assert(mp2.size() == 0);

			display_container("map [5:42, 7:28, 9:44]:", mp);
				assert(mp.size() == 3);
			mp.erase(k(7));
			display_container("map [5:42, 9:44]:", mp);
				assert(mp.size() == 2);
			mp.erase(k(5));
			display_container("map [9:44]:", mp);
				assert(mp.size() == 1);
			mp.erase(k(9));
			display_container("map []:", mp);
				assert(mp.size() == 0);

			mp.key_comp();
			mp.value_comp();
		}
	}

	std::cout << "\n---basic (bigger map)\n\n";
	{
		MapType mp;
		mp.insert(std::make_pair(k(5), 5));
		mp.insert(std::make_pair(k(5), 5));
		mp.insert(std::make_pair(k(6), 6));
		mp.insert(std::make_pair(k(7), 7));
		mp.insert(std::make_pair(k(7), 7));
		mp.insert(std::make_pair(k(8), 8));
		mp.insert(std::make_pair(k(9), 9));
		mp.insert(std::make_pair(k(9), 9));
		mp.insert(std::make_pair(k(10), 10));
		mp.insert(std::make_pair(k(11), 11));

		std::cout << "size: " << mp.size() << " (7), empty? " << mp.empty() << '\n';
		display_container("map [5:5, ..., 11:11]:", mp);
			assert(mp.size() == 10);
		mp.erase(k(7));
		display_container("map erased 7 [5:5, ..., 11:11]:", mp);
			assert(mp.size() == 8);
		mp.erase(k(5));
		display_container("map erased 5 [5:5, ..., 11:11]:", mp);
			assert(mp.size() == 6);
		mp.erase(++mp.begin(), --mp.end());
		display_container("map erased everything except begin,end [6:6, 11:11]:", mp);
			assert(mp.size() == 2);
	}

	std::cout << "\n---insert\n\n";
	{
		MapType mp;

		mp.insert(mp.begin(), std::make_pair(k(5), 42));
		display_container("map [5:42]:", mp);
			assert(mp.size() == 1);
		mp.insert(mp.begin(), std::make_pair(k(6), 43));
		display_container("map [5:42, 6:43]:", mp);
			assert(mp.size() == 2);
		mp.insert(mp.begin(), std::make_pair(k(4), 44));
		display_container("map [4:44, 5:42, 6:43]:", mp);
			assert(mp.size() == 3);

		mp.insert(--mp.end(), std::make_pair(k(3), 45));
		display_container("map [3:45, 4:44, 5:42, 6:43]:", mp);
			assert(mp.size() == 4);
		mp.insert(--mp.end(), std::make_pair(k(7), 46));
		display_container("map [3:45, 4:44, 5:42, 6:43, 7:46]:", mp);
			assert(mp.size() == 5);
		mp.insert(--mp.end(), std::make_pair(k(7), 46));
		display_container("map [3:45, 4:44, 5:42, 6:43, 7:46, 7:46]:", mp);
			assert(mp.size() == 6);
		mp.insert(std::make_pair(k(5), 48));
		mp.insert(--mp.end(), std::make_pair(k(5), 44));
		display_container("map [3:45, 4:44, 5:42, 5:44, 5:48, 6:43, 7:46, 7:46]:", mp);
			assert(mp.size() == 8);

		MapType mp2;
		mp2.insert(mp.begin(), mp.end());
		display_container("map2 [3:45, 4:44, 5:42, 5:44, 6:43, 7:46, 7:46]:", mp2);
			assert(mp2.size() == 8);
		mp.erase(mp.begin(), mp.end());
		display_container("map cleared:", mp);
			assert(mp.size() == 0);
		display_container("map2 (map cleared) [3:45, 4:44, 5:42, 5:44, 6:43, 7:46, 7:46]:", mp2);
			assert(mp2.size() == 8);
	}

	std::cout << "\n---erase\n\n";
	{
		MapType mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(6), 43));
		mp.insert(std::make_pair(k(7), 44));
		mp.insert(std::make_pair(k(7), 44));
		mp.insert(std::make_pair(k(8), 45));
		mp.insert(std::make_pair(k(8), 45));
		mp.insert(std::make_pair(k(9), 46));
		display_container("map [5:42, 5:42, 6:43, 7:44, 7:44, 8:45, 8:45, 9:46]:", mp);
			assert(mp.size() == 8);

		MapType mp2(mp);
		display_container("map2 [5:42, 5:42, 6:43, 7:44, 7:44, 8:45, 8:45, 9:46]:", mp2);
			assert(mp2.size() == 8);
		mp2.erase(mp2.begin(), mp2.end());
		display_container("map2 []:", mp2);
			assert(mp2.size() == 0);

		mp2 = mp;
		display_container("map2 [5:42, 5:42, 6:43, 7:44, 7:44, 8:45, 8:45, 9:46]:", mp2);
			assert(mp2.size() == 8);
		mp2.erase(mp2.begin());
		display_container("map2 [5:42, 6:43, 7:44, 7:44, 8:45, 8:45, 9:46]:", mp2);
		std::cout << "size: " << mp2.size() << " (1), empty? " << mp2.empty() << '\n';
			assert(mp2.size() == 7);
	}

	std::cout << "\n---find\n\n";
	{
		MapType mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(7), 43));
		mp.insert(std::make_pair(k(7), 43));
		mp.insert(std::make_pair(k(7), 46));
		mp.insert(std::make_pair(k(6), 48));
			assert(mp.size() == 6);

		display_container("map [5:42, 5:42, 6:48, 7:43, 7:43, 7:48]:", mp);
		std::cout << "find(99) " << ((mp.find(k(99)) == mp.end()) ? "== end" : "!= end !!!") << '\n';
			assert(mp.find(k(99)) == mp.end());
		std::cout << "find(42) " << ((mp.find(k(42)) == mp.end()) ? "== end" : "!= end !!!") << '\n';
			assert(mp.find(k(42)) == mp.end());
		std::cout << "find(5) " << ((mp.find(k(5)) == mp.begin()) ? "== begin" : "!= begin !!!") << '\n';
			assert(mp.find(k(5)) == mp.begin());
		std::cout << "find(6) " << ((mp.find(k(6)) == ++mp.begin()) ? "== begin + 2" : "!= begin + 2 !!!") << '\n';
			assert(mp.find(k(6)) == ++(++mp.begin()));
		std::cout << "find(7) " << ((mp.find(k(7)) == --mp.end()) ? "== --end" : "!= --end !!!") << '\n';
			assert(mp.find(k(7)) == --(--(--mp.end())));
	}

	std::cout << "\n---count\n\n";
	{
		MapType mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(5), 99));
		mp.insert(std::make_pair(k(7), 43));
		mp.insert(std::make_pair(k(7), 34));
		mp.insert(std::make_pair(k(6), 48));
		mp.insert(std::make_pair(k(6), 84));

		display_container("map [5:42, 6:48, 7:43]:", mp);
			assert(mp.size() == 6);
		std::cout << "count(5) " << mp.count(k(5)) << " (1)\n";
			assert(mp.count(k(5)) == 2);
		std::cout << "count(6) " << mp.count(k(6)) << " (1)\n";
			assert(mp.count(k(6)) == 2);
		std::cout << "count(7) " << mp.count(k(7)) << " (1)\n";
			assert(mp.count(k(7)) == 2);
		std::cout << "count(99) " << mp.count(k(99)) << " (0)\n";
			assert(mp.count(k(99)) == 0);
	}

	std::cout << "\n---bounds\n\n";
	{
		MapType mp;
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
			assert(mp.size() == 9);
		std::cout << "lower_bound(5): " << mp.lower_bound(k(5))->first << " (5)\n";
			assert(mp.lower_bound(k(5))->first == k(5));
		std::cout << "lower_bound(4): " << mp.lower_bound(k(4))->first << " (5)\n";
			assert(mp.lower_bound(k(4))->first == k(5));
		std::cout << "lower_bound(99): " << (((mp.lower_bound(k(99))) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
			assert(mp.lower_bound(k(99)) == mp.end());
		std::cout << "lower_bound(-99): " << mp.lower_bound(k(-99))->first << " (-1)\n";
			assert(mp.lower_bound(k(-99))->first == k(-1));
		std::cout << "upper_bound(5): " << mp.upper_bound(k(5))->first << " (6)\n";
			assert(mp.upper_bound(k(5))->first == k(6));
		std::cout << "upper_bound(4): " << mp.upper_bound(k(4))->first << " (5)\n";
			assert(mp.upper_bound(k(4))->first == k(5));
		std::cout << "upper_bound(99): " << (((mp.upper_bound(k(99))) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
			assert(mp.upper_bound(k(99)) == mp.end());
		std::cout << "upper_bound(-99): " << mp.upper_bound(k(-99))->first << " (-1)\n";
			assert(mp.upper_bound(k(-99))->first == k(-1));
	}

	std::cout << "\n---equal_range\n\n";
	{
		MapType mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(5), 48));
		mp.insert(std::make_pair(k(7), 44));
		mp.insert(std::make_pair(k(9), 95));
		mp.insert(std::make_pair(k(11), 10));
		mp.insert(std::make_pair(k(3), 12));
		mp.insert(std::make_pair(k(3), 14));
		mp.insert(std::make_pair(k(1), 78));
		mp.insert(std::make_pair(k(-1), 65));
		mp.insert(std::make_pair(k(6), 32));
		mp.insert(std::make_pair(k(8), 1));

		display_container("map [-1:65, 1:78, 3:12, 3:14, 5:42, 5,48, 6:32, 7:44, 8:1, 9:95, 11:10]:", mp);
			assert(mp.size() == 11);
		std::cout << "equal_range(5) " << (mp.equal_range(k(5))).first->first << "," << (mp.equal_range(k(5))).second->first << " (5,6)\n";
			assert(mp.equal_range(k(5)).first->first == k(5) && mp.equal_range(k(5)).second->first == k(6));
		std::cout << "equal_range(6) " << (mp.equal_range(k(6))).first->first << "," << (mp.equal_range(k(6))).second->first << " (6,7)\n";
			assert(mp.equal_range(k(6)).first->first == k(6) && mp.equal_range(k(6)).second->first == k(7));
		std::cout << "equal_range(10) " << (mp.equal_range(k(10))).first->first << "," << (mp.equal_range(k(10))).second->first << " (11,11)\n";
			assert(mp.equal_range(k(10)).first->first == k(11) && mp.equal_range(k(10)).second->first == k(11));
		std::cout << "equal_range(99) " << (((mp.equal_range(k(99))).first == mp.end()) ? "end" : "!!! not end !!!") << "," << (((mp.equal_range(k(99))).second == mp.end()) ? "end" : "!!! not end !!!") << " (end,end)\n";
			assert(mp.equal_range(k(99)).first == mp.end() && mp.equal_range(k(99)).second == mp.end());
		std::cout << "equal_range(-99) " << (mp.equal_range(k(-99))).first->first << "," << (mp.equal_range(k(-99))).second->first << " (-1,-1)\n";
			assert(mp.equal_range(k(-99)).first->first == k(-1) && mp.equal_range(k(-99)).second->first == k(-1));
	}

	std::cout << "\n---swap\n\n";
	{
		MapType mp;
		mp.insert(std::make_pair(k(5), 42));
		mp.insert(std::make_pair(k(7), 43));
		mp.insert(std::make_pair(k(9), 44));
		mp.insert(std::make_pair(k(9), 89));

		MapType mp2;
		mp2.insert(std::make_pair(k(11), 84));
		mp2.insert(std::make_pair(k(12), 85));
		mp2.insert(std::make_pair(k(13), 86));
		mp2.insert(std::make_pair(k(13), 47));

		display_container("map [5:42, 7:43, 9:44]:", mp);
			assert(mp.begin()->second == 42);
			assert((++mp.begin())->second == 43);
			assert((--(--mp.end()))->second == 44);
			assert(mp.size() == 4);
		display_container("map2 [11:84, 12:85, 13:86]:", mp2);
			assert(mp2.begin()->second == 84);
			assert((++mp2.begin())->second == 85);
			assert((--(--mp2.end()))->second == 86);
			assert(mp2.size() == 4);
		mp.swap(mp2);
		std::cout << "---swapped\n";
		display_container("map [11:84, 12:85, 13:86]:", mp);
			assert(mp.begin()->second == 84);
			assert((++mp.begin())->second == 85);
			assert((--(--mp.end()))->second == 86);
			assert(mp.size() == 4);
		display_container("map2 [5:42, 7:43, 9:44]:", mp2);
			assert(mp2.begin()->second == 42);
			assert((++mp2.begin())->second == 43);
			assert((--(--mp2.end()))->second == 44);
			assert(mp2.size() == 4);
		mp.swap(mp2);
		std::cout << "---swapped\n";
		display_container("map [5:42, 7:43, 9:44]:", mp);
			assert(mp.begin()->second == 42);
			assert((++mp.begin())->second == 43);
			assert((--(--mp.end()))->second == 44);
			assert(mp.size() == 4);
		display_container("map2 [11:84, 12:85, 13:86]:", mp2);
			assert(mp2.begin()->second == 84);
			assert((++mp2.begin())->second == 85);
			assert((--(--mp2.end()))->second == 86);
			assert(mp2.size() == 4);
	}

	std::cout << '\n';
}

#endif
