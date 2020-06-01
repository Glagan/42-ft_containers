/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:54:57 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/04 19:04:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

template<class StackType, class ContainerType>
void test_Stack(void)
{
	std::cout << "\n---basic\n\n";

	StackType empty_stack;
	{
		std::cout << "empty? " << empty_stack.empty() << '\n';
		std::cout << "empty stack size = " << empty_stack.size() << '\n';
			assert(empty_stack.empty());
			assert(empty_stack.size() == 0);
	}

	StackType stk;
	std::cout << "[] (size: " << stk.size() << ")\n";
		assert(stk.size() == 0);
	stk.push(5);
	std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ", empty? " << stk.empty() << ")\n";
		assert(stk.top() == 5);
		assert(stk.size() == 1);
	stk.push(42);
	std::cout << "[5, 42].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
		assert(stk.top() == 42);

	std::cout << "stack [5, 42].size() = " << stk.size() << '\n';
		assert(stk.size() == 2);

	stk.top() = 99;
	std::cout << "[5, 99].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
		assert(stk.top() == 99);
		assert(stk.size() == 2);
	stk.pop();
	std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
		assert(stk.top() == 5);
		assert(stk.size() == 1);
	stk.pop();
	std::cout << "[] (size: " << stk.size() << ")\n";
		assert(stk.size() == 0);

	std::cout << "\n---with container\n\n";
	{
		ContainerType ctn;
		ctn.push_back(5);
		ctn.push_back(42);
		ctn.push_back(43);
		ctn.push_back(99);
		display_container("[5, 42, 43, 99] {List or Deque}:", ctn);
			assert(ctn.size() == 4);

		StackType stk(ctn);
		std::cout << "stack empty? " << stk.empty() << '\n';
		std::cout << "stack size = " << stk.size() << '\n';
			assert(!stk.empty());
			assert(stk.size() == 4);

		std::cout << "[5, 42, 43, 99].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 99);
			assert(stk.size() == 4);
		stk.pop();
		std::cout << "[5, 42, 43].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 43);
			assert(stk.size() == 3);
		stk.pop();
		std::cout << "[5, 42].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 42);
			assert(stk.size() == 2);
		stk.pop();
		std::cout << "[5].top() = " << stk.top() << " (size: " << stk.size() << ")\n";
			assert(stk.top() == 5);
			assert(stk.size() == 1);
		stk.pop();
		std::cout << "[] (size: " << stk.size() << ")\n";
			assert(stk.size() == 0);

		display_container("[5, 42, 43, 99] {ft::List after, no change}:", ctn);
	}

	std::cout << "\n---comparison\n\n";
	{
		StackType stk;
		stk.push(5);
		stk.push(42);
		assert(stk.size() == 2);

		StackType stk2;
		stk2.push(5);
		stk2.push(42);
		assert(stk2.size() == 2);

		StackType stk3;
		stk3.push(5);
		stk3.push(42);
		stk3.push(43);
		assert(stk3.size() == 3);

		StackType stk4;
		stk4.push(99);
		stk4.push(5);
		stk4.push(42);
		assert(stk4.size() == 3);

		std::cout << "same stack:\n"
			<< "comparison == " << (stk == stk2) << '\n'
			<< "comparison != " << (stk != stk2) << '\n'
			<< "comparison <  " << (stk < stk2) << '\n'
			<< "comparison >  " << (stk > stk2) << '\n'
			<< "comparison <= " << (stk <= stk2) << '\n'
			<< "comparison >= " << (stk >= stk2) << '\n';
		assert(stk == stk2);
		assert(!(stk != stk2));
		assert(!(stk < stk2));
		assert(!(stk > stk2));
		assert(stk <= stk2);
		assert(stk >= stk2);

		std::cout << "lesser stack:\n"
			<< "comparison == " << (stk == stk3) << '\n'
			<< "comparison != " << (stk != stk3) << '\n'
			<< "comparison <  " << (stk < stk3) << '\n'
			<< "comparison >  " << (stk > stk3) << '\n'
			<< "comparison <= " << (stk <= stk3) << '\n'
			<< "comparison >= " << (stk >= stk3) << '\n';
		assert(!(stk == stk3));
		assert(stk != stk3);
		assert(stk < stk3);
		assert(!(stk > stk3));
		assert(stk <= stk3);
		assert(!(stk >= stk3));

		std::cout << "upper stack:\n"
			<< "comparison == " << (stk4 == stk) << '\n'
			<< "comparison != " << (stk4 != stk) << '\n'
			<< "comparison <  " << (stk4 < stk) << '\n'
			<< "comparison >  " << (stk4 > stk) << '\n'
			<< "comparison <= " << (stk4 <= stk) << '\n'
			<< "comparison >= " << (stk4 >= stk) << '\n';
		assert(!(stk4 == stk));
		assert(stk4 != stk);
		assert(!(stk4 < stk));
		assert(stk4 > stk);
		assert(!(stk4 <= stk));
		assert(stk4 >= stk);
	}

	std::cout << '\n';
}

#endif
