/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:54:57 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 18:40:17 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# include "test/test.hpp"

template<typename test_type>
void test_Stack(void)
{
	std::cout << "\n---basic\n\n";

	ft::Stack<test_type> empty_stack;
	std::cout << "empty? " << empty_stack.empty() << '\n';
	std::cout << "empty stack size = " << empty_stack.size() << '\n';

	ft::Stack<test_type> stk;
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

	std::cout << "\n---with container\n\n";
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(99);
		display_container("[5, 42, 43, 99] {ft::List}:", lst);

		ft::Stack<test_type> stk(lst);
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

		display_container("[5, 42, 43, 99] {ft::List after, no change}:", lst);
	}

	std::cout << "\n---comparison\n\n";
	{
		ft::Stack<test_type> stk;
		stk.push(5);
		stk.push(42);

		ft::Stack<test_type> stk2;
		stk2.push(5);
		stk2.push(42);

		ft::Stack<test_type> stk3;
		stk3.push(5);
		stk3.push(42);
		stk3.push(43);

		ft::Stack<test_type> stk4;
		stk4.push(99);
		stk4.push(5);
		stk4.push(42);

		std::cout << "same stack:\n"
			<< "comparison == " << (stk == stk2) << '\n'
			<< "comparison != " << (stk != stk2) << '\n'
			<< "comparison <  " << (stk < stk2) << '\n'
			<< "comparison >  " << (stk > stk2) << '\n'
			<< "comparison <= " << (stk <= stk2) << '\n'
			<< "comparison >= " << (stk >= stk2) << '\n';

		std::cout << "lesser stack:\n"
			<< "comparison == " << (stk == stk3) << '\n'
			<< "comparison != " << (stk != stk3) << '\n'
			<< "comparison <  " << (stk < stk3) << '\n'
			<< "comparison >  " << (stk > stk3) << '\n'
			<< "comparison <= " << (stk <= stk3) << '\n'
			<< "comparison >= " << (stk >= stk3) << '\n';

		std::cout << "upper stack:\n"
			<< "comparison == " << (stk4 == stk) << '\n'
			<< "comparison != " << (stk4 != stk) << '\n'
			<< "comparison <  " << (stk4 < stk) << '\n'
			<< "comparison >  " << (stk4 > stk) << '\n'
			<< "comparison <= " << (stk4 <= stk) << '\n'
			<< "comparison >= " << (stk4 >= stk) << '\n';
	}

	std::cout << '\n';
}

#endif
