/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:45:43 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 18:39:15 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_TEST_HPP
# define QUEUE_TEST_HPP

# include "test/test.hpp"

template<typename test_type>
void test_Queue(void)
{
	std::cout << "---basic\n" << '\n';

	ft::Queue<test_type> empty_queue;
	std::cout << "empty? " << empty_queue.empty() << '\n';
	std::cout << "empty queue size = " << empty_queue.size() << '\n';

	ft::Queue<test_type> que;
	std::cout << "[] (size: " << que.size() << ")\n";
	que.push(5);
	std::cout << "[5] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ", empty? " << que.empty() << ")\n";
	que.push(42);
	std::cout << "[5, 42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";

	std::cout << "queue [5, 42].size() = " << que.size() << '\n';

	que.front() = 99;
	std::cout << "[99, 42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
	que.pop();
	std::cout << "[42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
	que.pop();
	std::cout << "[] (size: " << que.size() << ")\n";

	std::cout << "\n---with container\n" << '\n';
	{
		ft::List<test_type> lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(99);
		display_container("[5, 42, 43, 99] {ft::List}:", lst);

		ft::Queue<test_type> que(lst);
		std::cout << "queue empty? " << que.empty() << '\n';
		std::cout << "queue size = " << que.size() << '\n';

		std::cout << "[5, 42, 43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		que.pop();
		std::cout << "[42, 43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		que.pop();
		std::cout << "[43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		que.pop();
		std::cout << "[99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		que.pop();
		std::cout << "[] (size: " << que.size() << ")\n";

		display_container("[5, 42, 43, 99] {ft::List after, no change}:", lst);
	}

	std::cout << "\n---comparison\n" << '\n';
	{
		ft::Queue<test_type> que;
		que.push(5);
		que.push(42);

		ft::Queue<test_type> que2;
		que2.push(5);
		que2.push(42);

		ft::Queue<test_type> que3;
		que3.push(5);
		que3.push(42);
		que3.push(43);

		ft::Queue<test_type> que4;
		que4.push(99);
		que4.push(5);
		que4.push(42);

		std::cout << "same queue:" << '\n'
			<< "comparison == " << (que == que2) << '\n'
			<< "comparison != " << (que != que2) << '\n'
			<< "comparison <  " << (que < que2) << '\n'
			<< "comparison >  " << (que > que2) << '\n'
			<< "comparison <= " << (que <= que2) << '\n'
			<< "comparison >= " << (que >= que2) << '\n';

		std::cout << "lesser queue:" << '\n'
			<< "comparison == " << (que == que3) << '\n'
			<< "comparison != " << (que != que3) << '\n'
			<< "comparison <  " << (que < que3) << '\n'
			<< "comparison >  " << (que > que3) << '\n'
			<< "comparison <= " << (que <= que3) << '\n'
			<< "comparison >= " << (que >= que3) << '\n';

		std::cout << "upper queue:" << '\n'
			<< "comparison == " << (que4 == que) << '\n'
			<< "comparison != " << (que4 != que) << '\n'
			<< "comparison <  " << (que4 < que) << '\n'
			<< "comparison >  " << (que4 > que) << '\n'
			<< "comparison <= " << (que4 <= que) << '\n'
			<< "comparison >= " << (que4 >= que) << '\n';
	}
}

#endif
