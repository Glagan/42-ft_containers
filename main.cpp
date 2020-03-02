/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/02 16:18:32 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test.hpp"

int main(void)
{
	test("Vector");
	test_Vector<int>();
#ifdef FULL
	test_Vector<Number>();
#endif
	end_test("Vector");
	test("List");
	test_List<int>();
#ifdef FULL
	test_List<Number>();
#endif
	end_test("List");
	test("Stack");
	test_Stack<int>();
#ifdef FULL
	test_Stack<Number>();
#endif
	end_test("Stack");
	test("Queue");
	test_Queue<int>();
#ifdef FULL
	test_Queue<Number>();
#endif
	end_test("Queue");
	test("Map");
	test_Map<int, int>();
#ifdef FULL
	test_Map<char, int>(48);
	test_Map<char, Number>(48);
	test_Map<Number, int>();
	test_Map<Number, Number>();
#endif
	end_test("Map");

// 	test("Deque");
// 	test_Deque<int>();
// #ifdef FULL
// 	test_Deque<Number>();
// #endif
// 	end_test("Deque");

	test("Set");
	test_Set<int>();
#ifdef FULL
	test_Set<Number>();
#endif
	end_test("Set");

	test("Multiset");
	test_Multiset<int>();
#ifdef FULL
	test_Multiset<Number>();
#endif
	end_test("Multiset");

	test("Multimap");
	test_Multimap<int, int>();
#ifdef FULL
	test_Multimap<char, int>(48);
	test_Multimap<char, Number>(48);
	test_Multimap<Number, int>();
	test_Multimap<Number, Number>();
#endif
	end_test("Multimap");

	// Check Number count
	std::cout << "Total Number created: " << Number::getCreated() << '\n'
			<< "Total Number destructed: " << Number::getDestructed() << '\n';

	return (0);
}
