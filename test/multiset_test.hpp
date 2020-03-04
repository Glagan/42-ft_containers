/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiset_test.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:35:10 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/04 19:29:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTISET_TEST_HPP
# define MULTISET_TEST_HPP

template<class SetType>
void test_Multiset(void)
{
	std::cout << "\n---basic\n\n";
	{
		SetType empty_set;
		{

			std::cout << "[begin] == [end] on empty set" << '\n';
                assert(empty_set.begin() == empty_set.end());
			std::cout << "max_size = " << empty_set.max_size() << '\n';
			std::cout << "size: " << empty_set.size() << " (0), empty? " << empty_set.empty() << '\n';
                assert(empty_set.empty());
                assert(empty_set.size() == 0);
		}

		SetType mp;
		mp.insert(5);   assert(mp.find(5) != mp.end());
		mp.insert(7);   assert(mp.find(7) != mp.end());
		mp.insert(9);   assert(mp.find(9) != mp.end());
		{
			std::cout << "set [5, 7, 9].size() = " << mp.size() << '\n';
                assert(mp.size() == 3);
			typename SetType::iterator it = mp.begin();
			std::cout << "[5, 7, 9].[5] = " << *mp.find(5) << " (it: " << (*it) << ")" << '\n';
			it = --mp.end();
			std::cout << "[5, 7, 9].[9] = " << *mp.find(9) << " (it: " << (*it) << ")" << '\n';

			SetType mp2 = mp;

			display_container("copied set2 [5, 7, 9]:", mp2);
                assert(mp2.size() == 3);
                assert(mp2.find(5) != mp2.end());
                assert(mp2.find(7) != mp2.end());
                assert(mp2.find(9) != mp2.end());
			mp2.clear();
			display_container("cleared set2 []:", mp2);
                assert(mp2.size() == 0);

			display_container("set [5, 7, 9]:", mp);
			mp.erase(7);
                assert(mp.find(7) == mp.end());
                assert(mp.size() == 2);
			display_container("set [5, 9]:", mp);
			mp.erase(5);
                assert(mp.find(5) == mp.end());
                assert(mp.size() == 1);
			display_container("set [9]:", mp);
			mp.erase(9);
                assert(mp.find(9) == mp.end());
			display_container("set []:", mp);
                assert(mp.size() == 0);

			mp.key_comp();
			mp.value_comp();
		}
	}

	std::cout << "\n---basic (bigger set)\n\n";
	{
		SetType mp;
		mp.insert(5); mp.insert(5);
		mp.insert(6);
		mp.insert(7); mp.insert(7); mp.insert(7);
		mp.insert(8); mp.insert(8);
		mp.insert(9);
		mp.insert(10);
		mp.insert(11);

		std::cout << "size: " << mp.size() << " (7), empty? " << mp.empty() << '\n';
		display_container("set [5, ..., 11]:", mp);
            assert(mp.find(7) != mp.end());
            assert(mp.size() == 11);
		display_container("set erased 7 [5, ..., 11]:", mp);
		mp.erase(5);
            assert(mp.find(5) == mp.end());
            assert(mp.size() == 9);
		display_container("set erased 5 [5, ..., 11]:", mp);
		mp.erase(++mp.begin(), --mp.end());
		display_container("set erased everything except begin,end [6, 11]:", mp);
            assert(mp.find(6) != mp.end());
            assert(mp.find(11) != mp.end());
            assert(mp.size() == 2);
	}

	std::cout << "\n---insert\n\n";
	{
		SetType mp;

		mp.insert(mp.begin(), 5);
		display_container("set [5]:", mp);
            assert(mp.find(5) != mp.end());
            assert(mp.size() == 1);
		mp.insert(mp.begin(), 6);
		display_container("set [5, 6]:", mp);
            assert(mp.find(6) != mp.end());
            assert(mp.size() == 2);
		mp.insert(mp.begin(), 4);
		display_container("set [4, 5, 6]:", mp);
            assert(mp.find(4) != mp.end());
            assert(mp.size() == 3);

		mp.insert(--mp.end(), 3);
		display_container("set [3, 4, 5, 6]:", mp);
            assert(mp.find(3) != mp.end());
            assert(mp.size() == 4);
		mp.insert(--mp.end(), 7);
		display_container("set [3, 4, 5, 6, 7]:", mp);
            assert(mp.find(7) != mp.end());
            assert(mp.size() == 5);

		SetType mp2;
		mp2.insert(mp.begin(), mp.end());
		display_container("set2 [3, 4, 5, 6, 7]:", mp2);
            assert(mp2.size() == 5);
		mp.erase(mp.begin(), mp.end());
		display_container("set cleared:", mp);
            assert(mp.size() == 0);
		display_container("set2 (set cleared) [3, 4, 5, 6, 7]:", mp2);
            assert(mp2.size() == 5);
	}

	std::cout << "\n---erase\n\n";
	{
		SetType mp;
		mp.insert(5);
		mp.insert(6);
		mp.insert(6);
		mp.insert(7);
		mp.insert(7);
		mp.insert(8);
		mp.insert(9);
		display_container("set [5, 6, 6, 7, 7, 8, 9]:", mp);
            assert(mp.size() == 7);

		SetType mp2(mp);
		display_container("set2 [5, 6, 6, 7, 7, 8, 9]:", mp2);
            assert(mp.size() == 7);
		mp2.erase(mp2.begin(), mp2.end());
		display_container("set2 []:", mp2);
            assert(mp2.size() == 0);

		mp2 = mp;
		display_container("set2 [5, 6, 6, 7, 7, 8, 9]:", mp2);
            assert(mp2.size() == 7);
		mp2.erase(mp2.begin());
		display_container("set2 [6, 6, 7, 7, 8, 9]:", mp2);
		std::cout << "size: " << mp2.size() << " (1), empty? " << mp2.empty() << '\n';
            assert(mp2.size() == 6);
	}

	std::cout << "\n---find\n\n";
	{
		SetType mp;
		mp.insert(5);
		mp.insert(5);
		mp.insert(7);
		mp.insert(7);
		mp.insert(6);

		display_container("set [5, 5, 6, 7, 7]:", mp);
            assert(mp.size() == 5);
		std::cout << "find(99) " << ((mp.find(99) == mp.end()) ? "== end" : "!= end !!!") << '\n';
            assert(mp.find(99) == mp.end());
		std::cout << "find(42) " << ((mp.find(42) == mp.end()) ? "== end" : "!= end !!!") << '\n';
            assert(mp.find(42) == mp.end());
		std::cout << "find(5) " << ((mp.find(5) == mp.begin()) ? "== begin" : "!= begin !!!") << '\n';
            assert(mp.find(5) != mp.end());
		std::cout << "find(6) " << ((mp.find(6) == ++(++mp.begin())) ? "== begin + 2" : "!= begin + 2 !!!") << '\n';
            assert(mp.find(6) != mp.end());
		std::cout << "find(7) " << ((mp.find(7) == --(--mp.end())) ? "== end - 2" : "!= end - 2 !!!") << '\n';
            assert(mp.find(7) != mp.end());
	}

	std::cout << "\n---count\n\n";
	{
		SetType mp;
		mp.insert(5);
		mp.insert(5);
		mp.insert(7);
		mp.insert(7);
		mp.insert(6);
		mp.insert(6);

		display_container("set [5, 5, 6, 6, 7, 7]:", mp);
            assert(mp.size() == 6);
		std::cout << "count(5) " << mp.count(5) << " (2)\n";
            assert(mp.count(5) == 2);
		std::cout << "count(6) " << mp.count(6) << " (2)\n";
            assert(mp.count(6) == 2);
		std::cout << "count(7) " << mp.count(7) << " (2)\n";
            assert(mp.count(7) == 2);
		std::cout << "count(99) " << mp.count(99) << " (0)\n";
            assert(mp.count(99) == 0);
	}

	std::cout << "\n---bounds\n\n";
	{
		SetType mp;
		mp.insert(5);
		mp.insert(7);
		mp.insert(9);
		mp.insert(11);
		mp.insert(3);
		mp.insert(1);
		mp.insert(-1);
		mp.insert(6);
		mp.insert(8);

		display_container("set [-1, 1, 3, 5, 6, 7, 8, 9, 11]:", mp);
            assert(mp.size() == 9);
		std::cout << "lower_bound(5): " << *mp.lower_bound(5) << " (5)\n";
            assert(mp.lower_bound(5) != mp.end());
		std::cout << "lower_bound(4): " << *mp.lower_bound(4) << " (5)\n";
            assert(mp.lower_bound(4) != mp.end());
		std::cout << "lower_bound(99): " << (((mp.lower_bound(99)) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
            assert(mp.lower_bound(99) == mp.end());
		std::cout << "lower_bound(-99): " << *mp.lower_bound(-99) << " (-1)\n";
            assert(mp.lower_bound(-99) != mp.end());
		std::cout << "upper_bound(5): " << *mp.upper_bound(5) << " (6)\n";
            assert(mp.upper_bound(5) != mp.end());
		std::cout << "upper_bound(4): " << *mp.upper_bound(4) << " (5)\n";
            assert(mp.upper_bound(4) != mp.end());
		std::cout << "upper_bound(99): " << (((mp.upper_bound(99)) == mp.end()) ? "end" : "!!! not end !!!") << " (end)\n";
            assert(mp.upper_bound(99) == mp.end());
		std::cout << "upper_bound(-99): " << *mp.upper_bound(-99) << " (-1)\n";
            assert(mp.upper_bound(-99) != mp.end());
	}

	std::cout << "\n---equal_range\n\n";
	{
		SetType mp;
		mp.insert(5);
		mp.insert(7);
		mp.insert(9);
		mp.insert(11);
		mp.insert(3);
		mp.insert(1);
		mp.insert(-1);
		mp.insert(6);
		mp.insert(8);

		display_container("set [-1, 1, 3, 5, 6, 7, 8, 9, 11]:", mp);
            assert(mp.size() == 9);
		std::cout << "equal_range(5) " << *(mp.equal_range(5)).first << "," << *(mp.equal_range(5)).second << " (5,6)\n";
            assert(mp.equal_range(5).first != mp.end() && mp.equal_range(5).second != mp.end() );
		std::cout << "equal_range(6) " << *(mp.equal_range(6)).first << "," << *(mp.equal_range(7)).second << " (6,8)\n";
            assert(mp.equal_range(6).first != mp.end() && mp.equal_range(6).second != mp.end() );
		std::cout << "equal_range(10) " << *(mp.equal_range(10)).first << "," << *(mp.equal_range(10)).second << " (11,11)\n";
            assert(mp.equal_range(10).first != mp.end() && mp.equal_range(10).second != mp.end() );
		std::cout << "equal_range(99) " << (((mp.equal_range(99)).first == mp.end()) ? "end" : "!!! not end !!!") << "," << (((mp.equal_range(99)).second == mp.end()) ? "end" : "!!! not end !!!") << " (end,end)\n";
            assert(mp.equal_range(99).first == mp.end() && mp.equal_range(99).second == mp.end() );
		std::cout << "equal_range(-99) " << *(mp.equal_range(-99)).first << "," << *(mp.equal_range(-99)).second << " (-1,-1)\n";
            assert(mp.equal_range(-99).first != mp.end() && mp.equal_range(-99).second != mp.end() );
	}

	std::cout << "\n---swap\n\n";
	{
		SetType mp;
		mp.insert(5);
		mp.insert(7);
		mp.insert(9);

		SetType mp2;
		mp2.insert(11);
		mp2.insert(12);
		mp2.insert(13);

		display_container("set [5, 7, 9]:", mp);
            assert(mp.find(5) != mp.end());
            assert(mp.find(7) != mp.end());
            assert(mp.find(9) != mp.end());
            assert(mp.size() == 3);
		display_container("set2 [11, 12, 13]:", mp2);
            assert(mp2.find(11) != mp2.end());
            assert(mp2.find(12) != mp2.end());
            assert(mp2.find(13) != mp2.end());
            assert(mp2.size() == 3);
		mp.swap(mp2);
		std::cout << "---swapped\n";
		display_container("set [11, 12, 13]:", mp);
            assert(mp.find(11) != mp.end());
            assert(mp.find(12) != mp.end());
            assert(mp.find(13) != mp.end());
            assert(mp.size() == 3);
		display_container("set2 [5, 7, 9]:", mp2);
            assert(mp2.find(5) != mp2.end());
            assert(mp2.find(7) != mp2.end());
            assert(mp2.find(9) != mp2.end());
            assert(mp2.size() == 3);
		mp.swap(mp2);
		std::cout << "---swapped\n";
		display_container("set [5, 7, 9]:", mp);
            assert(mp.find(5) != mp.end());
            assert(mp.find(7) != mp.end());
            assert(mp.find(9) != mp.end());
            assert(mp.size() == 3);
		display_container("set2 [11, 12, 13]:", mp2);
            assert(mp2.find(11) != mp2.end());
            assert(mp2.find(12) != mp2.end());
            assert(mp2.find(13) != mp2.end());
            assert(mp2.size() == 3);
	}
}

#endif
