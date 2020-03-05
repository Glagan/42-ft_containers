/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/05 16:43:21 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TEST_HPP
# define LIST_TEST_HPP

template<typename T>
bool less_than_99(T const &nbr) {
	return (nbr < 99);
}

template<typename T>
bool less_than_43(T const &nbr) {
	return (nbr < 43);
}

template<typename T>
bool less_than_1(T const &nbr) {
	return (nbr < 1);
}

template<typename T>
bool lesser_than_rhs(T const &nbr1, T const &nbr2) {
	return (nbr1 <= nbr2);
}

template<typename T>
bool sort_desc(T const &nbr1, T const &nbr2) {
	return (nbr1 > nbr2);
}

bool same_integral_part(double first, double second) {
	return (int(first) == int(second));
}

template<typename T>
bool equal_plus_one(T first, T second) {
	return (second == (first + 1));
}

template<class ListType, typename T>
void test_List(void)
{
	std::cout << "\n---basic\n\n";
	{
		ListType empty_list;
		{
			std::cout << "[begin] == [end] on empty list" << '\n';
				assert(empty_list.begin() == empty_list.end());
			// std::cout << "max_size (list) = " << empty_list.max_size() << '\n';
			std::cout << "empty? " << empty_list.empty() << '\n';
				assert(empty_list.empty());
			std::cout << "empty list size = " << empty_list.size() << '\n';
				assert(empty_list.size() == 0);
		}

		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		{
			std::cout << "list [5, 42].size() = " << lst.size() << '\n';
				assert(lst.size() == 2);
			std::cout << "[5, 42].front() = " << lst.front() << " (it:" << *lst.begin() << ")" << '\n';
				assert(lst.front() == 5);
				assert(*lst.begin() == 5);
			std::cout << "[5, 42].back()  = " << lst.back() << " (it:" << *--lst.end() << ")" << '\n';
				assert(lst.back() == 42);
				assert(*--lst.end() == 42);
		}
	}

	std::cout << "\n---push_back\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);
			assert(lst.size() == 3);

		int i = 1;
		display_container("[5, 42, 3]:", lst);

		typename ListType::reverse_iterator rit = lst.rbegin();
		typename ListType::reverse_iterator rite = lst.rend();
		i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		typename ListType::iterator it = lst.begin();
		typename ListType::iterator ite = lst.end();
		std::cout << "pop_back from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++) {
			lst.pop_back();
			it = lst.begin();
			ite = lst.end();
			if (i == 0) std::cout << "[5, 42]:" << '\n';
			else if (i == 1) std::cout << "[5]:" << '\n';
			else {
				std::cout << "[]:" << '\n';
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << '\n';
		}
	}

	std::cout << "\n---push_front\n\n";
	{
		ListType lst;
		lst.push_front(3);
		lst.push_front(42);
		lst.push_front(5);

		display_container("[5, 42, 3]:", lst);
			assert(lst.size() == 3);

		typename ListType::reverse_iterator rit = lst.rbegin();
		typename ListType::reverse_iterator rite = lst.rend();
		int i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		typename ListType::iterator it;
		typename ListType::iterator ite;
		std::cout << "pop_front from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++) {
			lst.pop_front();
			it = lst.begin();
			ite = lst.end();
			if (i == 0) std::cout << "[42, 3]:" << '\n';
			else if (i == 1) std::cout << "[3]:" << '\n';
			else {
				std::cout << "[]:" << '\n';
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << '\n';
		}
	}

	std::cout << "\n---clear\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);

		display_container("[5, 42, 3]:", lst);
			assert(lst.size() == 3);

		ListType lst2(lst);
		lst.clear();
			assert(lst.size() == 0);
			assert(lst2.size() == 3);

		display_container("cleared list []:", lst);
			assert(lst.size() == 0);

		display_container("copied list before clear [5, 42, 3]:", lst2);
			assert(lst2.size() == 3);
	}

	std::cout << "\n---erase\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);
			assert(lst.size() == 3);

		display_container("[5, 42, 3]:", lst);
		std::cout << "[3] -> " << *lst.erase(++lst.begin()) << '\n';
		display_container("42 deleted [5, 3]:", lst);
			assert(lst.size() == 2);

		typename ListType::iterator it = lst.erase(--lst.end());
		std::cout << "deleted [end] -> ";
			assert(it == lst.end());

		it = lst.erase(lst.begin());
		std::cout << "deleted [begin] -> ";
			assert(it == lst.end());
	}

	std::cout << "\n---assign\n\n";
	{
		ListType lst;
			assert(lst.size() == 0);

		lst.assign(5, 42);
		display_container("[42, 42, 42, 42, 42]:", lst);
			assert(lst.size() == 5);

		ListType lst2;
		lst2.assign(5, 43);
		display_container("lst2[43, 43, 43, 43, 43]:", lst2);
			assert(lst2.size() == 5);
		lst.assign(lst2.begin(), lst2.end());
		display_container("lst [43, 43, 43, 43, 43]:", lst);
			assert(lst.size() == 5);

		lst2.assign(5, 44);
		display_container("lst[43, 43, 43, 43, 43]:", lst);
			assert(lst.size() == 5);
		display_container("lst2[44, 44, 44, 44, 44]:", lst2);
			assert(lst2.size() == 5);
	}

	std::cout << "\n---insert\n\n";
	{
		ListType lst;
			assert(lst.size() == 0);

		lst.insert(lst.begin(), 5);
		display_container("[5]:", lst);
			assert(lst.size() == 1);

		lst.insert(lst.begin(), 2, 42);
		display_container("lst[42, 42, 5]:", lst);
			assert(lst.size() == 3);

		ListType lst2;
			assert(lst2.size() == 0);

		lst2.insert(lst2.begin(), lst.begin(), lst.end());
		display_container("lst to lst2[42, 42, 5]:", lst2);
			assert(lst2.size() == 3);

		lst2.insert(lst2.end(), lst.begin(), lst.end());
		display_container("lst to lst2[42, 42, 5, 42, 42, 5]:", lst2);
			assert(lst2.size() == 6);
	}

	std::cout << "\n---remove\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);

		display_container("[5, 42, 43, 42, 44, 5, 45]:", lst);
			assert(lst.size() == 7);

		lst.remove(45);
		display_container("[5, 42, 43, 42, 44, 5] delete {45} :", lst);
			assert(lst.size() == 6);

		lst.remove(5);
		display_container("[42, 43, 42, 44] delete {5}:", lst);
			assert(lst.size() == 4);

		lst.remove(99);
		display_container("[42, 43, 42, 44] delete {99}:", lst);
			assert(lst.size() == 4);

		lst.remove(42);
		display_container("[42, 43, 42, 44] delete {42}:", lst);
			assert(lst.size() == 2);

		lst.remove(43);
		display_container("[43, 44] delete {43}:", lst);
			assert(lst.size() == 1);

		lst.remove(44);
		display_container("[44] delete {44}:", lst);
			assert(lst.size() == 0);
	}

	std::cout << "\n---remove_if\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);

		display_container("[5, 42, 43, 42, 44, 5, 45]:", lst);
			assert(lst.size() == 7);

		lst.remove_if(&less_than_43<T>);
		display_container("[43, 44, 45] delete {<43}:", lst);
			assert(lst.size() == 3);

		lst.remove_if(&less_than_1<T>);
		display_container("[43, 44, 45] delete {<1}:", lst);
			assert(lst.size() == 3);

		lst.remove_if(&less_than_99<T>);
		display_container("[] delete {<99}:", lst);
			assert(lst.size() == 0);
	}

	std::cout << "\n---unique\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(43);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);
		lst.push_back(45);

		display_container("[5, 5, 42, 42, 44, 43, 44, 5, 45, 45]:", lst);
			assert(lst.size() == 10);

		lst.unique();
		display_container("[5, 42, 44, 43, 44, 5, 45] {unique}:", lst);
			assert(lst.size() == 7);

		lst.unique();
		display_container("[5, 42, 44, 43, 44, 5, 45] {unique: no change}:", lst);
			assert(lst.size() == 7);

		lst.remove(43);
		display_container("[5, 42, 44, 44, 5, 45] delete {43}:", lst);
			assert(lst.size() == 6);

		lst.unique();
		display_container("[5, 42, 44, 5, 45] {unique}:", lst);
			assert(lst.size() == 5);
	}

	std::cout << "\n---unique (binary pred)\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(43);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);
		lst.push_back(45);

		display_container("[5, 5, 42, 42, 44, 43, 44, 5, 45, 45]:", lst);
			assert(lst.size() == 10);

		lst.unique(&lesser_than_rhs<T>);
		display_container("[5, 42, 44, 43, 44, 5, 45] {lesser_than_rhs}:", lst);
			assert(lst.size() == 1);

		lst.unique(&lesser_than_rhs<T>);
		display_container("[5, 42, 44, 43, 44, 5, 45] {lesser_than_rhs: no change}:", lst);
			assert(lst.size() == 1);

		std::cout << "double list:" << '\n';
		{
			ft::List<double> lst;
			lst.push_back(2.72);
			lst.push_back(3.14);
			lst.push_back(12.15);
			lst.push_back(12.77);
			lst.push_back(15.3);
			lst.push_back(72.25);
			lst.push_back(73.0);
			lst.push_back(73.35);

			display_container("[2.72, 3.14, 12.15, 12.77, 15.3, 72.25, 73.0, 73.35]:", lst);
				assert(lst.size() == 8);

			lst.unique(&same_integral_part);
			display_container("[2.72, 3.14, 12.15, 15.3, 72.25, 73.0] {same_integral_part}:", lst);
				assert(lst.size() == 6);
		}
	}

	std::cout << "\n---unique (binary pred again)\n\n";
	{
		ListType lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(2);
		lst.push_back(6);

		display_container("[1, 2, 1, 2, 3, 2, 6]:", lst);
			assert(lst.size() == 7);

		lst.unique(&equal_plus_one<T>);
		display_container("[1, 1, 3, 2, 6] {equal_plus_one}:", lst);
			assert(lst.size() == 5);
	}

	std::cout << "\n---merge\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);

		ListType lst2;
		lst2.push_back(12);
		lst2.push_back(28);
		lst2.push_back(45);
		lst2.push_back(5);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';

		display_container("[5, 42, 43, 44]:", lst);
			assert(lst.size() == 4);
		display_container("[12, 28, 45, 5]:", lst2);
			assert(lst2.size() == 4);

		lst.merge(lst2);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';
		std::cout << "lst2 empty ? " << lst2.size() << '\n';
		display_container("[5, 5, 12, 28, 42, 43, 44, 45] {lst after merge}:", lst);
			assert(lst.size() == 8);
		display_container("empty lst2 after merge []:", lst2);
			assert(lst2.size() == 0);
	}

	std::cout << "\n---merge (comp)\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);

		ListType lst2;
		lst2.push_back(12);
		lst2.push_back(28);
		lst2.push_back(45);
		lst2.push_back(5);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';
			assert(lst.size() == 4);
			assert(lst2.size() == 4);

		display_container("[5, 42, 43, 44]:", lst);
		display_container("[12, 28, 45, 5]:", lst2);

		std::cout << "reverse merge comparator:" << '\n';
		lst.merge(lst2, &lesser_than_rhs<T>);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';
		std::cout << "lst2 empty ? " << lst2.size() << '\n';
		display_container("[5, 5, 12, 28, 42, 43, 44, 45] {lst after merge}:", lst);
			assert(lst.size() == 8);
		display_container("empty lst2 after merge []:", lst2);
			assert(lst2.size() == 0);
	}

	std::cout << "\n---sort\n\n";
	{
		ListType lst;
		lst.push_back(44);
		lst.push_back(58);
		lst.push_back(43);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(5);

		display_container("[44, 58, 43, 43, 42, 42, 5]:", lst);
			assert(lst.size() == 7);

		lst.sort();
		display_container("[5, 42, 42, 43, 43, 44, 58] {sorted}:", lst);
			assert(lst.size() == 7);

		lst.sort();
		display_container("[5, 42, 42, 43, 43, 44, 58] {sorted: no change}:", lst);
			assert(lst.size() == 7);
	}

	std::cout << "\n---sort (comp)\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(43);
		lst.push_back(58);
		lst.push_back(43);

		display_container("[5, 42, 42, 44, 43, 58, 43]:", lst);
			assert(lst.size() == 7);

		lst.sort(&sort_desc<T>);
		display_container("[58, 44, 43, 43, 42, 42, 5] {sorted desc}:", lst);
			assert(lst.size() == 7);

		lst.sort(&sort_desc<T>);
		display_container("[58, 44, 43, 43, 42, 42, 5] {sorted desc: no change}:", lst);
			assert(lst.size() == 7);
	}

	std::cout << "\n---reverse\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);
		lst.push_back(58);

		display_container("[5, 42, 43, 44, 58]:", lst);
			assert(lst.size() == 5);

		lst.reverse();
		display_container("[58, 44, 43, 42, 5] {reversed}:", lst);
			assert(lst.size() == 5);

		lst.reverse();
		display_container("[5, 42, 43, 44, 58] {reversed twice}:", lst);
			assert(lst.size() == 5);

		ListType lst2;
		lst2.push_back(5);
		lst2.push_back(42);

		display_container("[5, 42]:", lst2);
			assert(lst2.size() == 2);

		lst2.reverse();
		display_container("[42, 5] {reversed}:", lst2);
			assert(lst2.size() == 2);

		lst2.reverse();
		display_container("[5, 42] {reversed twice}:", lst2);
			assert(lst2.size() == 2);
	}

	std::cout << "\n---resize\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);

		display_container("[5, 42]:", lst);
			assert(lst.size() == 2);

		lst.resize(5, 43);
		display_container("[5, 42, 43, 43, 43]:", lst);
			assert(lst.size() == 5);

		lst.resize(1);
		display_container("[5]:", lst);
			assert(lst.size() == 1);

		lst.resize(0);
		display_container("[]:", lst);
			assert(lst.size() == 0);

		lst.resize(5);
		display_container("[0, 0, 0, 0, 0]:", lst);
			assert(lst.size() == 5);
	}

	std::cout << "\n---splice\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);

		ListType lst2;
		lst2.push_back(43);
		lst2.push_back(45);
		lst2.push_back(58);

		display_container("[5, 42]:", lst);
			assert(lst.size() == 2);
		display_container("[43, 45, 58]:", lst2);
			assert(lst2.size() == 3);

		lst.splice(lst.begin(), lst2, lst2.begin());
		display_container("[43, 5, 42] {spliced first element of lst2 at begin}:", lst);
			assert(lst.size() == 3);
		display_container("[45, 58] {first element removed}:", lst2);
			assert(lst2.size() == 2);

		lst.splice(lst.end(), lst2, lst2.begin(), lst2.end());
		display_container("[43, 5, 42, 45, 58] {splice everything at end}:", lst);
			assert(lst.size() == 5);
		display_container("[] {empty}:", lst2);
			assert(lst2.size() == 0);

		lst2.splice(lst2.begin(), lst);
		display_container("[] {empty now}:", lst);
			assert(lst.size() == 0);
		display_container("[43, 5, 42, 45, 58] {spliced content of lst}:", lst2);
			assert(lst2.size() == 5);
	}

	std::cout << "\n---comparison\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
			assert(lst.size() == 2);

		ListType lst2;
		lst2.push_back(5);
		lst2.push_back(42);
			assert(lst2.size() == 2);

		ListType lst3;
		lst3.push_back(5);
		lst3.push_back(42);
		lst3.push_back(43);
			assert(lst3.size() == 3);

		ListType lst4;
		lst4.push_back(99);
		lst4.push_back(42);
		lst4.push_back(43);
			assert(lst4.size() == 3);

		std::cout << "same list:" << '\n'
			<< "comparison == " << (lst == lst2) << '\n'
			<< "comparison != " << (lst != lst2) << '\n'
			<< "comparison <  " << (lst < lst2) << '\n'
			<< "comparison >  " << (lst > lst2) << '\n'
			<< "comparison <= " << (lst <= lst2) << '\n'
			<< "comparison >= " << (lst >= lst2) << '\n';
		assert(lst == lst2);
		assert(!(lst != lst2));
		assert(!(lst < lst2));
		assert(!(lst > lst2));
		assert(lst <= lst2);
		assert(lst >= lst2);

		std::cout << "lesser list:" << '\n'
			<< "comparison == " << (lst == lst3) << '\n'
			<< "comparison != " << (lst != lst3) << '\n'
			<< "comparison <  " << (lst < lst3) << '\n'
			<< "comparison >  " << (lst > lst3) << '\n'
			<< "comparison <= " << (lst <= lst3) << '\n'
			<< "comparison >= " << (lst >= lst3) << '\n';
		assert(!(lst == lst3));
		assert(lst != lst3);
		assert(lst < lst3);
		assert(!(lst > lst3));
		assert(lst <= lst3);
		assert(!(lst >= lst3));

		std::cout << "upper list:" << '\n'
			<< "comparison == " << (lst4 == lst) << '\n'
			<< "comparison != " << (lst4 != lst) << '\n'
			<< "comparison <  " << (lst4 < lst) << '\n'
			<< "comparison >  " << (lst4 > lst) << '\n'
			<< "comparison <= " << (lst4 <= lst) << '\n'
			<< "comparison >= " << (lst4 >= lst) << '\n';
		assert(!(lst4 == lst));
		assert(lst4 != lst);
		assert(!(lst4 < lst));
		assert(lst4 > lst);
		assert(!(lst4 <= lst));
		assert(lst4 >= lst);
	}

	std::cout << "\n---swap\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);

		ListType lst2;
		lst2.push_back(12);
		lst2.push_back(30);
		lst2.push_back(60);

		display_container("[5, 42, 43]:", lst);
            assert(lst.front() == 5);
            assert(*++lst.begin() == 42);
            assert(lst.back() == 43);
            assert(lst.size() == 3);
		display_container("[12, 30, 60]:", lst2);
            assert(lst2.front() == 12);
            assert(*++lst2.begin() == 30);
            assert(lst2.back() == 60);
            assert(lst2.size() == 3);
		lst.swap(lst2);
		std::cout << "---swapped\n";
		display_container("[12, 30, 60]:", lst);
            assert(lst.front() == 12);
            assert(*++lst.begin() == 30);
            assert(lst.back() == 60);
            assert(lst.size() == 3);
		display_container("[5, 42, 43]:", lst2);
            assert(lst2.front() == 5);
            assert(*++lst2.begin() == 42);
            assert(lst2.back() == 43);
            assert(lst2.size() == 3);
		lst.swap(lst2);
		std::cout << "---swapped\n";
		display_container("[5, 42, 43]:", lst);
            assert(lst.front() == 5);
            assert(*++lst.begin() == 42);
            assert(lst.back() == 43);
            assert(lst.size() == 3);
		display_container("[12, 30, 60]:", lst2);
            assert(lst2.front() == 12);
            assert(*++lst2.begin() == 30);
            assert(lst2.back() == 60);
            assert(lst2.size() == 3);
	}

	std::cout << '\n';
}

#endif
