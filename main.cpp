/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/11 15:21:35 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test.hpp"
#include <fstream>

/**
 * * std tests
 **/
void start_all_std_tests(void) {
// 	test("Vector");
// 	test_Vector<std::vector<int> >();
// #ifdef FULL
// 	test_Vector<std::vector<Number> >();
// #endif
// 	end_test("Vector");

// 	test("List");
// 	test_List<std::list<int>, int>();
// #ifdef FULL
// 	test_List<std::list<Number>, Number>();
// #endif
// 	end_test("List");

// 	test("Stack");
// 	test_Stack<std::stack<int>, std::deque<int> >();
// #ifdef FULL
// 	test_Stack<std::stack<Number>, std::deque<Number> >();
// #endif
// 	end_test("Stack");

// 	test("Queue");
// 	test_Queue<std::queue<int>, std::deque<int> >();
// #ifdef FULL
// 	test_Queue<std::queue<Number>, std::deque<Number> >();
// #endif
// 	end_test("Queue");

// 	test("Map");
// 	test_Map<std::map<int, int> >();
// #ifdef FULL
// 	test_Map<std::map<char, int> >(48);
// 	test_Map<std::map<char, Number> >(48);
// 	test_Map<std::map<Number, int> >();
// 	test_Map<std::map<Number, Number> >();
// #endif
// 	end_test("Map");

// 	test("Multimap");
// 	test_Multimap<std::multimap<int, int> >();
// #ifdef FULL
// 	test_Multimap<std::multimap<char, int> >(48);
// 	test_Multimap<std::multimap<char, Number> >(48);
// 	test_Multimap<std::multimap<Number, int> >();
// 	test_Multimap<std::multimap<Number, Number> >();
// #endif
// 	end_test("Multimap");

// 	test("Set");
// 	test_Set<std::set<int> >();
// #ifdef FULL
// 	test_Set<std::set<Number> >();
// #endif
// 	end_test("Set");

// 	test("Multiset");
// 	test_Multiset<std::multiset<int> >();
// #ifdef FULL
// 	test_Multiset<std::multiset<Number> >();
// #endif
// 	end_test("Multiset");

// 	test("Deque");
// 	test_Deque<std::deque<int> >();
// #ifdef FULL
// 	test_Deque<std::deque<Number> >();
// #endif
// 	end_test("Deque");
}

/**
 * * ft tests
 **/
void start_all_ft_tests(void) {
// 	test("Vector");
// 	test_Vector<ft::Vector<int> >();
// #ifdef FULL
// 	test_Vector<ft::Vector<Number> >();
// #endif
// 	end_test("Vector");

// 	test("List");
// 	test_List<ft::List<int>, int>();
// #ifdef FULL
// 	test_List<ft::List<Number>, Number>();
// #endif
// 	end_test("List");

// 	test("Stack");
// 	test_Stack<ft::Stack<int>, ft::List<int> >();
// #ifdef FULL
// 	test_Stack<ft::Stack<Number>, ft::List<Number> >();
// #endif
// 	end_test("Stack");

// 	test("Queue");
// 	test_Queue<ft::Queue<int>, ft::List<int> >();
// #ifdef FULL
// 	test_Queue<ft::Queue<Number>,ft::List<Number> >();
// #endif
// 	end_test("Queue");

// 	test("Map");
// 	test_Map<ft::Map<int, int> >();
// #ifdef FULL
// 	test_Map<ft::Map<char, int> >(48);
// 	test_Map<ft::Map<char, Number> >(48);
// 	test_Map<ft::Map<Number, int> >();
// 	test_Map<ft::Map<Number, Number> >();
// #endif
// 	end_test("Map");

// 	test("Multimap");
// 	test_Multimap<ft::Multimap<int, int> >();
// #ifdef FULL
// 	test_Multimap<ft::Multimap<char, int> >(48);
// 	test_Multimap<ft::Multimap<char, Number> >(48);
// 	test_Multimap<ft::Multimap<Number, int> >();
// 	test_Multimap<ft::Multimap<Number, Number> >();
// #endif
// 	end_test("Multimap");

// 	test("Set");
// 	test_Set<ft::Set<int> >();
// #ifdef FULL
// 	test_Set<ft::Set<Number> >();
// #endif
// 	end_test("Set");

// 	test("Multiset");
// 	test_Multiset<ft::Multiset<int> >();
// #ifdef FULL
// 	test_Multiset<ft::Multiset<Number> >();
// #endif
// 	end_test("Multiset");

	test("Deque");
	test_Deque<ft::Deque<int> >();
#ifdef FULL
	test_Deque<ft::Deque<Number> >();
#endif
	end_test("Deque");
}

int main(void)
{
	std::streambuf *coutbuf = std::cout.rdbuf();

	std::ofstream stdOut("std_out");
    std::cout.rdbuf(stdOut.rdbuf());
	start_all_std_tests();
	stdOut.close();

    std::cout.rdbuf(coutbuf);

	// std::ofstream ftOut("ft_out");
    // std::cout.rdbuf(ftOut.rdbuf());
	start_all_ft_tests();
	// ftOut.close();

    // std::cout.rdbuf(coutbuf);

	// Check Number count
#ifdef FULL
	std::cout << "Total Number created: " << Number::getCreated() << '\n'
			<< "Total Number destructed: " << Number::getDestructed() << '\n';
	assert(Number::getCreated() == Number::getCreated());
#endif

	return (0);
}
