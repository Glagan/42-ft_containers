/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 17:26:16 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test.hpp"

void test(std::string const &what)
{
	std::cout << "#################### START TEST " << what << std::endl;
}

void end_test(std::string const &what)
{
	std::cout << "#################### END TEST " << what << '\n' << std::endl;
}

int main(void)
{
	test("Vector");
	test_Vector();
	end_test("Vector");
	// test("List");
	// test_List();
	// end_test("List");
	// test("Stack");
	// test_Stack();
	// end_test("Stack");
	// test("Queue");
	// test_Queue();
	// end_test("Queue");
	/*test("Map");
	test_Map();
	end_test("Map");*/

	// Leaks
	/*
	std::cout << "#####" << std::endl;
	system("leaks ft_containers");
	std::cout << "#####" << std::endl;
	*/
	return (0);
}
