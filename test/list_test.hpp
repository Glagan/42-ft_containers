/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 18:41:00 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TEST_HPP
# define LIST_TEST_HPP

template<typename T>
bool less_than_99(T const &nbr)
{
	return (nbr < 99);
}

template<typename T>
bool less_than_43(T const &nbr)
{
	return (nbr < 43);
}

template<typename T>
bool less_than_1(T const &nbr)
{
	return (nbr < 1);
}

template<typename T>
bool lesser_than_rhs(T const &nbr1, T const &nbr2)
{
	return (nbr1 <= nbr2);
}

template<typename T>
bool sort_desc(T const &nbr1, T const &nbr2)
{
	return (nbr1 > nbr2);
}

bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

template<typename test_type>
void test_List(void)
{
	std::cout << "\n---basic\n\n";

	ft::List<test_type> empty_list;
	if (empty_list.begin() == empty_list.end())
		std::cout << "[begin] == [end] on empty list" << '\n';
	else
		std::cout << "!!! [begin] != [end] on empty list !!!" << '\n';
	std::cout << "max_size = " << empty_list.max_size() << '\n';
	std::cout << "empty? " << empty_list.empty() << '\n';
	std::cout << "empty list size = " << empty_list.size() << '\n';

	ft::List<test_type> lst;
	lst.push_back(5);
	lst.push_back(42);

	std::cout << "list [5, 42].size() = " << lst.size() << '\n';
	std::cout << "[5, 42].front() = " << lst.front() << " (it:" << *lst.begin() << ")" << '\n';
	std::cout << "[5, 42].back()  = " << lst.back() << " (it:" << *--lst.end() << ")" << '\n';

	std::cout << "\n---push_back\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);

		typename ft::List<test_type>::iterator it = lst.begin();
		typename ft::List<test_type>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		typename ft::List<test_type>::reverse_iterator rit = lst.rbegin();
		typename ft::List<test_type>::reverse_iterator rite = lst.rend();
		i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		std::cout << "pop_back from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++)
		{
			lst.pop_back();
			it = lst.begin();
			ite = lst.end();
			if (i == 0) std::cout << "[5, 42]:" << '\n';
			else if (i == 1) std::cout << "[5]:" << '\n';
			else
			{
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
		ft::List<test_type> lst;
		lst.push_front(3);
		lst.push_front(42);
		lst.push_front(5);

		typename ft::List<test_type>::iterator it = lst.begin();
		typename ft::List<test_type>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		typename ft::List<test_type>::reverse_iterator rit = lst.rbegin();
		typename ft::List<test_type>::reverse_iterator rite = lst.rend();
		i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		std::cout << "pop_front from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++)
		{
			lst.pop_front();
			it = lst.begin();
			ite = lst.end();
			if (i == 0) std::cout << "[42, 3]:" << '\n';
			else if (i == 1) std::cout << "[3]:" << '\n';
			else
			{
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
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);

		typename ft::List<test_type>::iterator it = lst.begin();
		typename ft::List<test_type>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		ft::List<test_type> lst2(lst);
		lst.clear();

		it = lst.begin();
		ite = lst.end();
		i = 1;
		std::cout << "cleared vector []:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		it = lst2.begin();
		ite = lst2.end();
		i = 1;
		std::cout << "copied vector before clear [5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';
	}

	std::cout << "\n---erase\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);

		display_container("[5, 42, 3]:", lst);
		std::cout << "[3] -> " << *lst.erase(++lst.begin()) << '\n';
		display_container("42 deleted [5, 3]:", lst);

		typename ft::List<test_type>::iterator it = lst.erase(--lst.end());
		std::cout << "deleted [end] -> ";
		if (it == lst.end())
			std::cout << "returned [end]" << '\n';
		else
			std::cout << "!!! didn't return [end] !!!" << '\n';

		it = lst.erase(lst.begin());
		std::cout << "deleted [begin] -> ";
		if (it == lst.begin() && it == lst.end())
			std::cout << "returned [begin] and [end]" << '\n';
		else
			std::cout << "!!! didn't return [begin] and [end] !!!" << '\n';
	}

	std::cout << "\n---assign\n\n";
	{
		ft::List<test_type> lst;

		lst.assign(5, 42);
		display_container("[42, 42, 42, 42, 42]:", lst);

		ft::List<test_type> lst2;
		lst2.assign(5, 43);
		display_container("lst2[43, 43, 43, 43, 43]:", lst2);
		lst.assign(lst2.begin(), lst2.end());
		display_container("lst [43, 43, 43, 43, 43]:", lst);

		lst2.assign(5, 44);
		display_container("lst[43, 43, 43, 43, 43]:", lst);
		display_container("lst2[44, 44, 44, 44, 44]:", lst2);
	}

	std::cout << "\n---insert\n\n";
	{
		ft::List<test_type> lst;

		lst.insert(lst.begin(), 5);
		display_container("[5]:", lst);

		lst.insert(lst.begin(), 2, 42);
		display_container("lst[42, 42, 5]:", lst);

		ft::List<test_type> lst2;

		lst2.insert(lst2.begin(), lst.begin(), lst.end());
		display_container("lst to lst2[42, 42, 5]:", lst2);

		lst2.insert(lst2.end(), lst.begin(), lst.end());
		display_container("lst to lst2[42, 42, 5, 42, 42, 5]:", lst2);
	}

	std::cout << "\n---remove\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);

		display_container("[5, 42, 43, 42, 44, 5, 45]:", lst);

		lst.remove(45);
		display_container("[5, 42, 43, 42, 44, 5] delete {45} :", lst);

		lst.remove(5);
		display_container("[42, 43, 42, 44] delete {5}:", lst);

		lst.remove(99);
		display_container("[42, 43, 42, 44] delete {99}:", lst);

		lst.remove(42);
		display_container("[42, 43, 42, 44] delete {42}:", lst);

		lst.remove(43);
		display_container("[42, 43, 42, 44] delete {43}:", lst);

		lst.remove(44);
		display_container("[42, 43, 42, 44] delete {44}:", lst);
	}

	std::cout << "\n---remove_if\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);

		display_container("[5, 42, 43, 42, 44, 5, 45]:", lst);

		lst.remove_if(&less_than_43<test_type>);
		display_container("[43, 44, 45] delete {<43}:", lst);

		lst.remove_if(&less_than_1<test_type>);
		display_container("[43, 44, 45] delete {<1}:", lst);

		lst.remove_if(&less_than_99<test_type>);
		display_container("[] delete {<99}:", lst);
	}

	std::cout << "\n---unique\n\n";
	{
		ft::List<test_type> lst;
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

		lst.unique();
		display_container("[5, 42, 44, 43, 44, 5, 45] {unique}:", lst);

		lst.unique();
		display_container("[5, 42, 44, 43, 44, 5, 45] {unique: no change}:", lst);

		lst.remove(43);
		display_container("[5, 42, 44, 44, 5, 45] delete {43}:", lst);

		lst.unique();
		display_container("[5, 42, 44, 5, 45] {unique}:", lst);
	}

	std::cout << "\n---unique (binary pred)\n\n";
	{
		ft::List<test_type> lst;
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

		lst.unique(&lesser_than_rhs<test_type>);
		display_container("[5, 42, 44, 43, 44, 5, 45] {lesser_than_rhs}:", lst);

		lst.unique(&lesser_than_rhs<test_type>);
		display_container("[5, 42, 44, 43, 44, 5, 45] {lesser_than_rhs: no change}:", lst);

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

			lst.unique(&same_integral_part);
			display_container("[2.72, 3.14, 12.15, 15.3, 72.25, 73.0] {same_integral_part}:", lst);
		}
	}

	std::cout << "\n---merge\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);

		ft::List<test_type> lst2;
		lst2.push_back(12);
		lst2.push_back(28);
		lst2.push_back(45);
		lst2.push_back(5);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';

		display_container("[5, 42, 43, 44]:", lst);
		display_container("[12, 28, 45, 5]:", lst2);

		lst.merge(lst2);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';
		std::cout << "lst2 empty ? " << lst2.size() << '\n';
		display_container("[5, 5, 12, 28, 42, 43, 44, 45] {lst after merge}:", lst);
		display_container("empty lst2 after merge []:", lst2);
	}

	std::cout << "\n---merge (comp)\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);

		ft::List<test_type> lst2;
		lst2.push_back(12);
		lst2.push_back(28);
		lst2.push_back(45);
		lst2.push_back(5);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';

		display_container("[5, 42, 43, 44]:", lst);
		display_container("[12, 28, 45, 5]:", lst2);

		std::cout << "reverse merge comparator:" << '\n';
		lst.merge(lst2, &lesser_than_rhs<test_type>);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << '\n';
		std::cout << "lst2 empty ? " << lst2.size() << '\n';
		display_container("[5, 5, 12, 28, 42, 43, 44, 45] {lst after merge}:", lst);
		display_container("empty lst2 after merge []:", lst2);
	}

	std::cout << "\n---sort\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(44);
		lst.push_back(58);
		lst.push_back(43);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(5);

		display_container("[44, 58, 43, 43, 42, 42, 5]:", lst);

		lst.sort();
		display_container("[5, 42, 42, 43, 43, 44, 58] {sorted}:", lst);

		lst.sort();
		display_container("[5, 42, 42, 43, 43, 44, 58] {sorted: no change}:", lst);
	}

	std::cout << "\n---sort (comp)\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(43);
		lst.push_back(58);
		lst.push_back(43);

		display_container("[5, 42, 42, 44, 43, 58, 43]:", lst);

		lst.sort(&sort_desc<test_type>);
		display_container("[58, 44, 43, 43, 42, 42, 5] {sorted desc}:", lst);

		lst.sort(&sort_desc<test_type>);
		display_container("[58, 44, 43, 43, 42, 42, 5] {sorted desc: no change}:", lst);
	}

	std::cout << "\n---reverse\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);
		lst.push_back(58);

		display_container("[5, 42, 43, 44, 58]:", lst);

		lst.reverse();
		display_container("[58, 44, 43, 42, 5] {reversed}:", lst);

		lst.reverse();
		display_container("[5, 42, 43, 44, 58] {reversed twice}:", lst);

		ft::List<test_type> lst2;
		lst2.push_back(5);
		lst2.push_back(42);

		display_container("[5, 42]:", lst2);

		lst2.reverse();
		display_container("[42, 5] {reversed}:", lst2);

		lst2.reverse();
		display_container("[5, 42] {reversed twice}:", lst2);
	}

	std::cout << "\n---resize\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);

		display_container("[5, 42]:", lst);

		lst.resize(5, 43);
		display_container("[5, 42, 43, 43, 43]:", lst);

		lst.resize(1);
		display_container("[5]:", lst);

		lst.resize(0);
		display_container("[]:", lst);

		lst.resize(5);
		display_container("[0, 0, 0, 0, 0]:", lst);
	}

	std::cout << "\n---splice\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);

		ft::List<test_type> lst2;
		lst2.push_back(43);
		lst2.push_back(45);
		lst2.push_back(58);

		display_container("[5, 42]:", lst);
		display_container("[43, 45, 58]:", lst2);

		lst.splice(lst.begin(), lst2, lst2.begin());
		display_container("[43, 5, 42] {spliced first element of lst2 at begin}:", lst);
		display_container("[45, 58] {first element removed}:", lst2);

		lst.splice(lst.end(), lst2, lst2.begin(), lst2.end());
		display_container("[43, 5, 42, 45, 58] {splice everything at end}:", lst);
		display_container("[] {empty}:", lst2);

		lst2.splice(lst2.begin(), lst);
		display_container("[] {empty now}:", lst);
		display_container("[43, 5, 42, 45, 58] {spliced content of lst}:", lst2);
	}

	std::cout << "\n---comparison\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);

		ft::List<test_type> lst2;
		lst2.push_back(5);
		lst2.push_back(42);

		ft::List<test_type> lst3;
		lst3.push_back(5);
		lst3.push_back(42);
		lst3.push_back(43);

		ft::List<test_type> lst4;
		lst4.push_back(99);
		lst4.push_back(42);
		lst4.push_back(43);

		std::cout << "same list:" << '\n'
			<< "comparison == " << (lst == lst2) << '\n'
			<< "comparison != " << (lst != lst2) << '\n'
			<< "comparison <  " << (lst < lst2) << '\n'
			<< "comparison >  " << (lst > lst2) << '\n'
			<< "comparison <= " << (lst <= lst2) << '\n'
			<< "comparison >= " << (lst >= lst2) << '\n';

		std::cout << "lesser list:" << '\n'
			<< "comparison == " << (lst == lst3) << '\n'
			<< "comparison != " << (lst != lst3) << '\n'
			<< "comparison <  " << (lst < lst3) << '\n'
			<< "comparison >  " << (lst > lst3) << '\n'
			<< "comparison <= " << (lst <= lst3) << '\n'
			<< "comparison >= " << (lst >= lst3) << '\n';

		std::cout << "upper list:" << '\n'
			<< "comparison == " << (lst4 == lst) << '\n'
			<< "comparison != " << (lst4 != lst) << '\n'
			<< "comparison <  " << (lst4 < lst) << '\n'
			<< "comparison >  " << (lst4 > lst) << '\n'
			<< "comparison <= " << (lst4 <= lst) << '\n'
			<< "comparison >= " << (lst4 >= lst) << '\n';
	}

	std::cout << '\n';
}

#endif
