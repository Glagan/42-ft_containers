/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 15:35:34 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <list>

template<typename T>
void display_list(std::string const &header, ft::List<T> const &list)
{
	typename ft::List<T>::const_iterator it = list.begin();
	typename ft::List<T>::const_iterator ite = list.end();
	std::cout << header << std::endl;
	while (it != ite)
	{
		std::cout << *it;
		if (++it == ite)
			std::cout << std::endl;
		else
			std::cout <<  ", ";
	}
}

bool less_than_99(int const &nbr)
{
	return (nbr < 99);
}

bool less_than_43(int const &nbr)
{
	return (nbr < 43);
}

bool less_than_1(int const &nbr)
{
	return (nbr < 1);
}

bool lesser_than_rhs(int const &nbr1, int const &nbr2)
{
	return (nbr1 <= nbr2);
}

bool sort_desc(int const &nbr1, int const &nbr2)
{
	return (nbr1 > nbr2);
}

bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

void test_List(void)
{
	std::cout << "---basic\n" << std::endl;

	ft::List<int> empty_list;
	if (empty_list.begin() == empty_list.end())
		std::cout << "[begin] == [end] on empty list" << std::endl;
	else
		std::cout << "!!! [begin] != [end] on empty list !!!" << std::endl;
	std::cout << "max_size = " << empty_list.max_size() << std::endl;
	std::cout << "empty? " << empty_list.empty() << std::endl;
	std::cout << "empty list size = " << empty_list.size() << std::endl;

	ft::List<int> lst;
	lst.push_back(5);
	lst.push_back(42);

	std::cout << "list [5, 42].size() = " << lst.size() << std::endl;
	std::cout << "[5, 42].front() = " << lst.front() << " (it:" << *lst.begin() << ")" << std::endl;
	std::cout << "[5, 42].back()  = " << lst.back() << " (it:" << *--lst.end() << ")" << std::endl;

	std::cout << "\n---push_back\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);

		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;

		ft::List<int>::reverse_iterator rit = lst.rbegin();
		ft::List<int>::reverse_iterator rite = lst.rend();
		i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << std::endl;
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << std::endl;

		std::cout << "pop_back from [5, 42, 3]:" << std::endl;
		for (size_t i = 0; i < 3; i++)
		{
			lst.pop_back();
			it = lst.begin();
			ite = lst.end();
			if (i == 0) std::cout << "[5, 42]:" << std::endl;
			else if (i == 1) std::cout << "[5]:" << std::endl;
			else
			{
				std::cout << "[]:" << std::endl;
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << std::endl;
		}
	}

	std::cout << "\n---push_front\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_front(3);
		lst.push_front(42);
		lst.push_front(5);

		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;

		ft::List<int>::reverse_iterator rit = lst.rbegin();
		ft::List<int>::reverse_iterator rite = lst.rend();
		i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << std::endl;
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << std::endl;

		std::cout << "pop_front from [5, 42, 3]:" << std::endl;
		for (size_t i = 0; i < 3; i++)
		{
			lst.pop_front();
			it = lst.begin();
			ite = lst.end();
			if (i == 0) std::cout << "[42, 3]:" << std::endl;
			else if (i == 1) std::cout << "[3]:" << std::endl;
			else
			{
				std::cout << "[]:" << std::endl;
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << std::endl;
		}
	}

	std::cout << "\n---clear\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);

		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;

		ft::List<int> lst2(lst);
		lst.clear();

		it = lst.begin();
		ite = lst.end();
		i = 1;
		std::cout << "cleared vector []:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;

		it = lst2.begin();
		ite = lst2.end();
		i = 1;
		std::cout << "copied vector before clear [5, 2, 3]:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;
	}

	std::cout << "\n---erase\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(3);

		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << std::endl;
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << std::endl;
		std::cout << "[3] -> " << *lst.erase(++lst.begin()) << std::endl;

		it = lst.begin();
		ite = lst.end();
		std::cout << "42 deleted [5, 3]:" << std::endl;
		while (it != ite)
			std::cout << *it++ << std::endl;

		it = lst.erase(--lst.end());
		std::cout << "deleted [end] -> ";
		if (it == lst.end())
			std::cout << "returned [end]" << std::endl;
		else
			std::cout << "!!! didn't return [end] !!!" << std::endl;

		it = lst.erase(lst.begin());
		std::cout << "deleted [begin] -> ";
		if (it == lst.begin() && it == lst.end())
			std::cout << "returned [begin] and [end]" << std::endl;
		else
			std::cout << "!!! didn't return [begin] and [end] !!!" << std::endl;
	}

	std::cout << "\n---assign\n" << std::endl;
	{
		ft::List<int> lst;

		lst.assign(5, 42);
		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		int i = 1;
		std::cout << "[42, 42, 42, 42, 42]:\n\t";
		while (it != ite)
			std::cout << "[" << i++ << "] " << *it++ <<  ", ";
		std::cout << std::endl;

		ft::List<int> lst2;
		lst2.assign(5, 43);

		lst.assign(lst2.begin(), lst2.end());
		it = lst.begin();
		ite = lst.end();
		i = 1;
		std::cout << "[43, 43, 43, 43, 43]:\n\t";
		while (it != ite)
			std::cout << "[" << i++ << "] " << *it++ << ", ";
		std::cout << std::endl;
		lst2.assign(5, 44);

		it = lst.begin();
		ite = lst.end();
		std::cout << "lst[43, 43, 43, 43, 43]:\n\t";
		while (it != ite)
			std::cout <<  *it++ << ", ";
		std::cout << std::endl;

		it = lst2.begin();
		ite = lst2.end();
		std::cout << "lst2[44, 44, 44, 44, 44]:\n\t";
		while (it != ite)
			std::cout << *it++ << ", ";
		std::cout << std::endl;
	}

	std::cout << "\n---insert\n" << std::endl;
	{
		ft::List<int> lst;

		lst.insert(lst.begin(), 5);
		ft::List<int>::iterator it = lst.begin();
		ft::List<int>::iterator ite = lst.end();
		std::cout << "[5]:" << std::endl;
		while (it != ite)
			std::cout << *it++ <<  ", ";
		std::cout << std::endl;

		lst.insert(lst.begin(), 2, 42);
		it = lst.begin();
		ite = lst.end();
		std::cout << "lst[42, 42, 5]:" << std::endl;
		while (it != ite)
			std::cout << *it++ <<  ", ";
		std::cout << std::endl;

		ft::List<int> lst2;

		lst2.insert(lst2.begin(), lst.begin(), lst.end());
		it = lst2.begin();
		ite = lst2.end();
		std::cout << "lst to lst2[42, 42, 5]:" << std::endl;
		while (it != ite)
			std::cout << *it++ <<  ", ";
		std::cout << std::endl;

		lst2.insert(lst2.end(), lst.begin(), lst.end());
		it = lst2.begin();
		ite = lst2.end();
		std::cout << "lst to lst2[42, 42, 5, 42, 42, 5]:" << std::endl;
		while (it != ite)
			std::cout << *it++ <<  ", ";
		std::cout << std::endl;
	}

	std::cout << "\n---remove\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);

		display_list("[5, 42, 43, 42, 44, 5, 45]:", lst);

		lst.remove(45);
		display_list("[5, 42, 43, 42, 44, 5] delete {45} :", lst);

		lst.remove(5);
		display_list("[42, 43, 42, 44] delete {5}:", lst);

		lst.remove(99);
		display_list("[42, 43, 42, 44] delete {99}:", lst);

		lst.remove(42);
		display_list("[42, 43, 42, 44] delete {42}:", lst);

		lst.remove(43);
		display_list("[42, 43, 42, 44] delete {43}:", lst);

		lst.remove(44);
		display_list("[42, 43, 42, 44] delete {44}:", lst);
	}

	std::cout << "\n---remove_if\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(5);
		lst.push_back(45);

		display_list("[5, 42, 43, 42, 44, 5, 45]:", lst);

		lst.remove_if(&less_than_43);
		display_list("[43, 44, 45] delete {<43}:", lst);

		lst.remove_if(&less_than_1);
		display_list("[43, 44, 45] delete {<1}:", lst);

		lst.remove_if(&less_than_99);
		display_list("[] delete {<99}:", lst);
	}

	std::cout << "\n---unique\n" << std::endl;
	{
		ft::List<int> lst;
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

		display_list("[5, 5, 42, 42, 44, 43, 44, 5, 45, 45]:", lst);

		lst.unique();
		display_list("[5, 42, 44, 43, 44, 5, 45] {unique}:", lst);

		lst.unique();
		display_list("[5, 42, 44, 43, 44, 5, 45] {unique: no change}:", lst);

		lst.remove(43);
		display_list("[5, 42, 44, 44, 5, 45] delete {43}:", lst);

		lst.unique();
		display_list("[5, 42, 44, 5, 45] {unique}:", lst);
	}

	std::cout << "\n---unique (binary pred)\n" << std::endl;
	{
		ft::List<int> lst;
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

		display_list("[5, 5, 42, 42, 44, 43, 44, 5, 45, 45]:", lst);

		lst.unique(&lesser_than_rhs);
		display_list("[5, 42, 44, 43, 44, 5, 45] {lesser_than_rhs}:", lst);

		lst.unique(&lesser_than_rhs);
		display_list("[5, 42, 44, 43, 44, 5, 45] {lesser_than_rhs: no change}:", lst);

		std::cout << "double list:" << std::endl;
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

			display_list("[2.72, 3.14, 12.15, 12.77, 15.3, 72.25, 73.0, 73.35]:", lst);

			lst.unique(&same_integral_part);
			display_list("[2.72, 3.14, 12.15, 15.3, 72.25, 73.0] {same_integral_part}:", lst);
		}
	}

	std::cout << "\n---merge\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);

		ft::List<int> lst2;
		lst2.push_back(12);
		lst2.push_back(28);
		lst2.push_back(45);
		lst2.push_back(5);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << std::endl;

		display_list("[5, 42, 43, 44]:", lst);
		display_list("[12, 28, 45, 5]:", lst2);

		lst.merge(lst2);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << std::endl;
		std::cout << "lst2 empty ? " << lst2.size() << std::endl;
		display_list("[5, 5, 12, 28, 42, 43, 44, 45] {lst after merge}:", lst);
		display_list("empty lst2 after merge []:", lst2);
	}

	std::cout << "\n---merge (comp)\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);

		ft::List<int> lst2;
		lst2.push_back(12);
		lst2.push_back(28);
		lst2.push_back(45);
		lst2.push_back(5);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << std::endl;

		display_list("[5, 42, 43, 44]:", lst);
		display_list("[12, 28, 45, 5]:", lst2);

		std::cout << "reverse merge comparator:" << std::endl;
		lst.merge(lst2, &lesser_than_rhs);

		std::cout << "lst size "<< lst.size() << ", lst2 size " << lst2.size() << std::endl;
		std::cout << "lst2 empty ? " << lst2.size() << std::endl;
		display_list("[5, 5, 12, 28, 42, 43, 44, 45] {lst after merge}:", lst);
		display_list("empty lst2 after merge []:", lst2);
	}

	std::cout << "\n---sort\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(44);
		lst.push_back(58);
		lst.push_back(43);
		lst.push_back(43);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(5);

		display_list("[44, 58, 43, 43, 42, 42, 5]:", lst);

		lst.sort();
		display_list("[5, 42, 42, 43, 43, 44, 58] {sorted}:", lst);

		lst.sort();
		display_list("[5, 42, 42, 43, 43, 44, 58] {sorted: no change}:", lst);
	}

	std::cout << "\n---sort (comp)\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(42);
		lst.push_back(44);
		lst.push_back(43);
		lst.push_back(58);
		lst.push_back(43);

		display_list("[5, 42, 42, 44, 43, 58, 43]:", lst);

		lst.sort(&sort_desc);
		display_list("[58, 44, 43, 43, 42, 42, 5] {sorted desc}:", lst);

		lst.sort(&sort_desc);
		display_list("[58, 44, 43, 43, 42, 42, 5] {sorted desc: no change}:", lst);
	}

	std::cout << "\n---reverse\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(44);
		lst.push_back(58);

		display_list("[5, 42, 43, 44, 58]:", lst);

		lst.reverse();
		display_list("[58, 44, 43, 42, 5] {reversed}:", lst);

		lst.reverse();
		display_list("[5, 42, 43, 44, 58] {reversed twice}:", lst);

		ft::List<int> lst2;
		lst2.push_back(5);
		lst2.push_back(42);

		display_list("[5, 42]:", lst2);

		lst2.reverse();
		display_list("[42, 5] {reversed}:", lst2);

		lst2.reverse();
		display_list("[5, 42] {reversed twice}:", lst2);
	}

	std::cout << "\n---resize\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);

		display_list("[5, 42]:", lst);

		lst.resize(5, 43);
		display_list("[5, 42, 43, 43, 43]:", lst);

		lst.resize(1);
		display_list("[5]:", lst);

		lst.resize(0);
		display_list("[]:", lst);

		lst.resize(5);
		display_list("[0, 0, 0, 0, 0]:", lst);
	}

	std::cout << "\n---splice\n" << std::endl;
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);

		ft::List<int> lst2;
		lst2.push_back(43);
		lst2.push_back(45);
		lst2.push_back(58);

		display_list("[5, 42]:", lst);
		display_list("[43, 45, 58]:", lst2);

		lst.splice(lst.begin(), lst2, lst2.begin());
		display_list("[43, 5, 42] {spliced first element of lst2 at begin}:", lst);
		display_list("[45, 58] {first element removed}:", lst2);

		lst.splice(lst.end(), lst2, lst2.begin(), lst2.end());
		display_list("[43, 5, 42, 45, 58] {splice everything at end}:", lst);
		display_list("[] {empty}:", lst2);

		lst2.splice(lst2.begin(), lst);
		display_list("[] {empty now}:", lst);
		display_list("[43, 5, 42, 45, 58] {spliced content of lst}:", lst2);
	}
}
