/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/19 18:34:34 by ncolomer         ###   ########.fr       */
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

	// Check Number count
	std::cout << "Total Number created: " << Number::getCreated() << '\n'
			<< "Total Number destructed: " << Number::getDestructed() << '\n';

	return (0);
}
