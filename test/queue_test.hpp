/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:45:43 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/04 19:05:07 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_TEST_HPP
# define QUEUE_TEST_HPP

template<class QueueType, class ListType>
void test_Queue(void)
{
	std::cout << "\n---basic\n\n";

	QueueType empty_queue;
	{
		std::cout << "empty? " << empty_queue.empty() << '\n';
		std::cout << "empty queue size = " << empty_queue.size() << '\n';
			assert(empty_queue.empty());
			assert(empty_queue.size() == 0);
	}

	QueueType que;
	std::cout << "[] (size: " << que.size() << ")\n";
	que.push(5);
	std::cout << "[5] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ", empty? " << que.empty() << ")\n";
		assert(que.size() == 1);
	que.push(42);
	std::cout << "[5, 42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";

	std::cout << "queue [5, 42].size() = " << que.size() << '\n';
		assert(que.size() == 2);

	que.front() = 99;
	std::cout << "[99, 42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		assert(que.front() == 99);
		assert(que.back() == 42);
	que.pop();
	std::cout << "[42] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		assert(que.back() == 42);
		assert(que.front() == 42);
	que.pop();
	std::cout << "[] (size: " << que.size() << ")\n";
		assert(que.size() == 0);

	std::cout << "\n---with container\n\n";
	{
		ListType lst;
		lst.push_back(5);
		lst.push_back(42);
		lst.push_back(43);
		lst.push_back(99);
		display_container("[5, 42, 43, 99] {List}:", lst);
			assert(lst.size() == 4);

		QueueType que(lst);
		std::cout << "queue empty? " << que.empty() << '\n';
		std::cout << "queue size " << que.size() << '\n';
			assert(!que.empty());
			assert(que.size() == 4);

		std::cout << "[5, 42, 43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
		que.pop();
		std::cout << "[42, 43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 3);
		que.pop();
		std::cout << "[43, 99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 2);
		que.pop();
		std::cout << "[99] front: " << que.front() << ", back: " << que.back() << " (size: " << que.size() << ")\n";
			assert(que.size() == 1);
		que.pop();
		std::cout << "[] (size: " << que.size() << ")\n";
			assert(que.size() == 0);

		display_container("[5, 42, 43, 99] {ft::List after, no change}:", lst);
	}

	std::cout << "\n---comparison\n\n";
	{
		QueueType que;
		que.push(5);
		que.push(42);
		assert(que.size() == 2);

		QueueType que2;
		que2.push(5);
		que2.push(42);
		assert(que2.size() == 2);

		QueueType que3;
		que3.push(5);
		que3.push(42);
		que3.push(43);
		assert(que3.size() == 3);

		QueueType que4;
		que4.push(99);
		que4.push(5);
		que4.push(42);
		assert(que4.size() == 3);

		std::cout << "same queue:" << '\n'
			<< "comparison == " << (que == que2) << '\n'
			<< "comparison != " << (que != que2) << '\n'
			<< "comparison <  " << (que < que2) << '\n'
			<< "comparison >  " << (que > que2) << '\n'
			<< "comparison <= " << (que <= que2) << '\n'
			<< "comparison >= " << (que >= que2) << '\n';
		assert(que == que2);
		assert(!(que != que2));
		assert(!(que < que2));
		assert(!(que > que2));
		assert(que <= que2);
		assert(que >= que2);

		std::cout << "lesser queue:" << '\n'
			<< "comparison == " << (que == que3) << '\n'
			<< "comparison != " << (que != que3) << '\n'
			<< "comparison <  " << (que < que3) << '\n'
			<< "comparison >  " << (que > que3) << '\n'
			<< "comparison <= " << (que <= que3) << '\n'
			<< "comparison >= " << (que >= que3) << '\n';
		assert(!(que == que3));
		assert(que != que3);
		assert(que < que3);
		assert(!(que > que3));
		assert(que <= que3);
		assert(!(que >= que3));

		std::cout << "upper queue:" << '\n'
			<< "comparison == " << (que4 == que) << '\n'
			<< "comparison != " << (que4 != que) << '\n'
			<< "comparison <  " << (que4 < que) << '\n'
			<< "comparison >  " << (que4 > que) << '\n'
			<< "comparison <= " << (que4 <= que) << '\n'
			<< "comparison >= " << (que4 >= que) << '\n';
		assert(!(que4 == que));
		assert(que4 != que);
		assert(!(que4 < que));
		assert(que4 > que);
		assert(!(que4 <= que));
		assert(que4 >= que);
	}

	std::cout << '\n';
}

#endif
