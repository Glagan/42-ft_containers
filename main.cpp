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

void test(std::string const &what)
{
	std::cout << "######################################## START TEST " << what << std::endl;
}

void end_test(std::string const &what)
{
	std::cout << "######################################## END TEST " << what << '\n' << std::endl;
}

int main(void)
{
	test("Vector");
	test_Vector<int>();
	test_Vector<Number>();
	end_test("Vector");
	test("List");
	test_List<int>();
	test_List<Number>();
	end_test("List");
	test("Stack");
	test_Stack<int>();
	test_Stack<Number>();
	end_test("Stack");
	test("Queue");
	test_Queue<int>();
	test_Queue<Number>();
	end_test("Queue");
	test("Map");
	test_Map<int, int>();
	//test_Map<char, int>();
	//test_Map<char, Number>();
	//test_Map<Number, int>();
	//test_Map<Number, Number>();
	end_test("Map");

	// Check Number count
	std::cout << "Total Number created: " << Number::getCreated() << '\n'
			<< "Total Number destructed: " << Number::getDestructed() << '\n';

	// Leaks
	/*
	std::cout << "\n#####" << '\n';
	system("leaks ft_containers");
	std::cout << "#####" << std::endl;
	//*/
	return (0);
}
