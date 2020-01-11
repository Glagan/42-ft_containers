/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:54:57 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 16:40:45 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <stack>

void test_Stack(void)
{
	std::cout << "---basic\n" << '\n';

	ft::Stack<int> empty_stack;
	std::cout << "empty? " << empty_stack.empty() << '\n';
	std::cout << "empty stack size = " << empty_stack.size() << '\n';

	ft::Stack<int> stk;
	std::cout << "[] (size: " << stk.size() << ")\n";
	stk.push(5);
	std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ", empty? " << stk.empty() << ")\n";
	stk.push(42);
	std::cout << "[5, 42].top() = " << stk.top() << " (size: " << stk.size() << ")\n";

	std::cout << "stack [5, 42].size() = " << stk.size() << '\n';

	stk.top() = 99;
	std::cout << "[5, 99].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
	stk.pop();
	std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
	stk.pop();
	std::cout << "[] (size: " << stk.size() << ")\n";

	std::cout << "\n---with container\n" << '\n';
	{
		ft::List<int> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(99);
		display_list("[5, 42, 43, 99] {ft::List}:", lst);

		ft::Stack<int> stk(lst);
		std::cout << "stack empty? " << stk.empty() << '\n';
		std::cout << "stack size = " << stk.size() << '\n';

		std::cout << "[5, 42, 43, 99].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
		stk.pop();
		std::cout << "[5, 42, 43].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
		stk.pop();
		std::cout << "[5, 42].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
		stk.pop();
		std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
		stk.pop();
		std::cout << "[] (size: " << stk.size() << ")\n";

		display_list("[5, 42, 43, 99] {ft::List after, no change}:", lst);
	}

	std::cout << "\n---comparison\n" << '\n';
	{
		ft::Stack<int> stk;
		stk.push(5);
		stk.push(42);

		ft::Stack<int> stk2;
		stk2.push(5);
		stk2.push(42);

		ft::Stack<int> stk3;
		stk3.push(5);
		stk3.push(42);
		stk3.push(43);

		ft::Stack<int> stk4;
		stk4.push(99);
		stk4.push(5);
		stk4.push(42);

		std::cout << "same stack:" << '\n'
			<< "comparison == " << (stk == stk2) << '\n'
			<< "comparison != " << (stk != stk2) << '\n'
			<< "comparison <  " << (stk < stk2) << '\n'
			<< "comparison >  " << (stk > stk2) << '\n'
			<< "comparison <= " << (stk <= stk2) << '\n'
			<< "comparison >= " << (stk >= stk2) << '\n';

		std::cout << "lesser stack:" << '\n'
			<< "comparison == " << (stk == stk3) << '\n'
			<< "comparison != " << (stk != stk3) << '\n'
			<< "comparison <  " << (stk < stk3) << '\n'
			<< "comparison >  " << (stk > stk3) << '\n'
			<< "comparison <= " << (stk <= stk3) << '\n'
			<< "comparison >= " << (stk >= stk3) << '\n';

		std::cout << "upper stack:" << '\n'
			<< "comparison == " << (stk4 == stk) << '\n'
			<< "comparison != " << (stk4 != stk) << '\n'
			<< "comparison <  " << (stk4 < stk) << '\n'
			<< "comparison >  " << (stk4 > stk) << '\n'
			<< "comparison <= " << (stk4 <= stk) << '\n'
			<< "comparison >= " << (stk4 >= stk) << '\n';
	}
}
