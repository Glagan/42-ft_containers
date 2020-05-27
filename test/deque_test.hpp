/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:35:17 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/11 15:22:32 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_TEST_HPP
# define DEQUE_TEST_HPP

template<typename DequeType>
void test_Deque(void)
{
	std::cout << "\n---basic\n\n";
	{
		DequeType empty_deque;
		{
			std::cout << "[begin] == [end] on empty deque" << '\n';
				assert(empty_deque.begin() == empty_deque.end());
			// std::cout << "max_size (deque) " << empty_deque.max_size() << '\n';
			std::cout << "empty? " << empty_deque.empty() << '\n';
				assert(empty_deque.empty());
			std::cout << "empty deque size = " << empty_deque.size() << '\n';
				assert(empty_deque.size() == 0);
		}

		DequeType deq;
		deq.push_back(5);
		deq.push_back(42);
		deq.push_front(6);
		deq.push_front(24);
		{
			std::cout << "deque [24, 6, 5, 42].size() = " << deq.size() << '\n';
				assert(deq.size() == 4);
			std::cout << "[24, 6, 5, 42].front() = " << deq.front() << " (it:" << *deq.begin() << ")" << '\n';
				assert(deq.front() == 24);
				assert(*deq.begin() == 24);
			std::cout << "[24, 6, 5, 42].back()  = " << deq.back() << " (it:" << *--deq.end() << ")" << '\n';
				assert(deq.back() == 42);
				assert(*--deq.end() == 42);

			for (size_t i = 0; i < 4; i++) {
				std::cout << "deque[" << i << "] = " << deq[i] << " == deque.at(" << i << ") = " << deq.at(i) << '\n';
					assert(deq[i] == deq.at(i));
			}
			display_container("deque [24, 6, 5, 42] with iterators:", deq);
		}

		std::cout << "reverse:\n";
		typename DequeType::reverse_iterator it = deq.rbegin();
		typename DequeType::reverse_iterator ite = deq.rend();
		while (it != ite) {
			std::cout << *it++;
			if (it == ite)
				std::cout << '\n';
			else
				std::cout << ", ";
		}
	}

	// std::cout << "\n---reserve\n\n";
	// {
	// 	DequeType deq;
	// 	std::cout << "empty deque capacity " << deq.capacity() << '\n';
	// 		assert(deq.capacity() == 0);
	// 	deq.reserve(256);
	// 		assert(deq.capacity() == 256);
	// 	std::cout << "empty deque{reserved 256} capacity " << deq.capacity() << '\n';
	// 	deq.reserve(64);
	// 	std::cout << "empty deque{reserved 64, no change} capacity " << deq.capacity() << '\n';
	// 		assert(deq.capacity() == 256);
	// }

	std::cout << "\n---push_back\n\n";
	{
		DequeType deq;
		deq.push_back(5);
		deq.push_back(42);
		deq.push_back(3);
			assert(deq.size() == 3);

		display_container("[5, 42, 3]:", deq);

		typename DequeType::reverse_iterator rit = deq.rbegin();
		typename DequeType::reverse_iterator rite = deq.rend();
		int i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		typename DequeType::iterator it;
		typename DequeType::iterator ite;
		std::cout << "pop_back from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++) {
			deq.pop_back();
			it = deq.begin();
			ite = deq.end();
			if (i == 0) std::cout << "[5, 42]:" << '\n';
			else if (i == 1) std::cout << "[5]:" << '\n';
			else {
				std::cout << "[]:" << '\n';
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << '\n';
		}
	}

	std::cout << "\n---push_front\n\n";
	{
		DequeType deq;
		deq.push_front(3);
		deq.push_front(42);
		deq.push_front(5);
			assert(deq.size() == 3);

		display_container("[5, 42, 3]:", deq);

		typename DequeType::reverse_iterator rit = deq.rbegin();
		typename DequeType::reverse_iterator rite = deq.rend();
		int i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		typename DequeType::iterator it;
		typename DequeType::iterator ite;
		std::cout << "pop_front from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++) {
			deq.pop_front();
			it = deq.begin();
			ite = deq.end();
			if (i == 0) std::cout << "[5, 42]:" << '\n';
			else if (i == 1) std::cout << "[5]:" << '\n';
			else {
				std::cout << "[]:" << '\n';
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << '\n';
		}
	}

	std::cout << "\n---clear\n\n";
	{
		DequeType deq;
		deq.push_back(5);
		deq.push_back(42);
		deq.push_back(3);
			assert(deq.size() == 3);

		display_container("[5, 42, 3]:", deq);

		DequeType deq2(deq);
		deq.clear();

		display_container("cleared deque []:", deq);
			assert(deq.size() == 0);
		display_container("copied deque before clear [5, 42, 3]", deq2);
			assert(deq2.size() == 3);
	}

	std::cout << "\n---erase\n\n";
	{
		DequeType deq;
		deq.push_back(5);
		deq.push_back(42);
		deq.push_back(3);
			assert(deq.size() == 3);

		display_container("[5, 42, 3]:", deq);
		std::cout << "[3] -> " << *deq.erase(++deq.begin()) << '\n';
		display_container("42 deleted [5, 3]:", deq);
			assert(deq.front() == 5);
			assert(deq.back() == 3);
			assert(deq.size() == 2);

		typename DequeType::iterator it = deq.erase(--deq.end());
		std::cout << "deleted [end]\n";
			assert(it == deq.end());
			assert(deq.front() == 5);
			assert(deq.back() == 5);
			assert(deq.size() == 1);

		it = deq.erase(deq.begin());
		std::cout << "deleted [begin]\n";
			assert(it == deq.end());
			assert(deq.size() == 0);

		DequeType deq2;
		deq2.push_back(5);
		deq2.push_back(42);
		deq2.push_back(3);
			assert(deq2.size() == 3);
		display_container("deq2 [5, 42, 3]:", deq2);
		it = deq2.erase(deq2.begin(), deq2.end());
		display_container("single erase deq2 []:", deq2);
			assert(it == deq2.end());
			assert(deq2.size() == 0);
	}

	std::cout << "\n---assign\n\n";
	{
		DequeType deq;

		deq.assign(5, 42);
		display_container("[42, 42, 42, 42, 42]:", deq);
			assert(deq.size() == 5);

		DequeType deq2;
		deq2.assign(5, 43);
		display_container("deq2[43, 43, 43, 43, 43]:", deq2);
			assert(deq2.size() == 5);
		deq.assign(deq2.begin(), deq2.end());
		display_container("deq [43, 43, 43, 43, 43]:", deq);
			assert(deq.size() == 5);

		deq2.assign(5, 44);
		display_container("deq[43, 43, 43, 43, 43]:", deq);
		display_container("deq2[44, 44, 44, 44, 44]:", deq2);
			assert(deq2.size() == 5);
	}

	std::cout << "\n---insert\n\n";
	{
		DequeType deq;
			assert(deq.size() == 0);

		assert(deq.insert(deq.begin(), 5) == deq.begin());
		display_container("[5]:", deq);
			assert(deq.front() == 5);
			assert(deq.back() == 5);
			assert(deq.size() == 1);

		deq.insert(deq.begin(), 2, 42);
		display_container("deq[42, 42, 5]:", deq);
			assert(deq.front() == 42);
			assert(deq.back() == 5);
			assert(deq.size() == 3);

		DequeType deq2;
			assert(deq2.size() == 0);

		deq2.insert(deq2.begin(), deq.begin(), deq.end());
		display_container("deq2[42, 42, 5]:", deq2);
		std::cout << "insert deq into deq2\n";
			assert(deq2.front() == 42);
		std::cout << "front\n";
			assert(deq2.back() == 5);
		std::cout << "back\n";
			assert(deq2.size() == 3);
		std::cout << "size\n";

		deq2.insert(deq2.end(), deq.begin(), deq.end());
		display_container("deq + deq2[42, 42, 5, 42, 42, 5]:", deq2);
			assert(deq2.front() == 42);
			assert(deq2.back() == 5);
			assert(deq2.size() == 6);
	}

	std::cout << "\n---resize\n\n";
	{
		DequeType deq;
		deq.push_back(5);
		deq.push_back(42);

		display_container("base [5, 42]:", deq);
			assert(deq.size() == 2);

		deq.resize(5, 43);
		display_container("expand 43 [5, 42, 43, 43, 43]:", deq);
			assert(deq.back() == 43);
			assert(deq.size() == 5);

		deq.resize(1);
		display_container("shrink [5]:", deq);
			assert(deq.back() == 5);
			assert(deq.size() == 1);

		deq.resize(0);
		display_container("empty []:", deq);
			assert(deq.size() == 0);

		deq.resize(5);
		display_container("expand default value [0, 0, 0, 0, 0]:", deq);
			assert(deq.back() == 0);
			assert(deq.size() == 5);
	}

	std::cout << "\n---comparison\n\n";
	{
		DequeType deq;
		deq.push_back(5);
		deq.push_back(42);
			assert(deq.size() == 2);

		DequeType deq2;
		deq2.push_back(5);
		deq2.push_back(42);
			assert(deq2.size() == 2);

		DequeType deq3;
		deq3.push_back(5);
		deq3.push_back(42);
		deq3.push_back(43);
			assert(deq3.size() == 3);

		DequeType deq4;
		deq4.push_back(99);
		deq4.push_back(42);
		deq4.push_back(43);
			assert(deq4.size() == 3);

		std::cout << "same deque:" << '\n'
			<< "comparison == " << (deq == deq2) << '\n'
			<< "comparison != " << (deq != deq2) << '\n'
			<< "comparison <  " << (deq < deq2) << '\n'
			<< "comparison >  " << (deq > deq2) << '\n'
			<< "comparison <= " << (deq <= deq2) << '\n'
			<< "comparison >= " << (deq >= deq2) << '\n';
		assert(deq == deq2);
		assert(!(deq != deq2));
		assert(!(deq < deq2));
		assert(!(deq > deq2));
		assert(deq <= deq2);
		assert(deq >= deq2);

		std::cout << "lesser deque:" << '\n'
			<< "comparison == " << (deq == deq3) << '\n'
			<< "comparison != " << (deq != deq3) << '\n'
			<< "comparison <  " << (deq < deq3) << '\n'
			<< "comparison >  " << (deq > deq3) << '\n'
			<< "comparison <= " << (deq <= deq3) << '\n'
			<< "comparison >= " << (deq >= deq3) << '\n';
		assert(!(deq == deq3));
		assert(deq != deq3);
		assert(deq < deq3);
		assert(!(deq > deq3));
		assert(deq <= deq3);
		assert(!(deq >= deq3));

		std::cout << "upper deque:" << '\n'
			<< "comparison == " << (deq4 == deq) << '\n'
			<< "comparison != " << (deq4 != deq) << '\n'
			<< "comparison <  " << (deq4 < deq) << '\n'
			<< "comparison >  " << (deq4 > deq) << '\n'
			<< "comparison <= " << (deq4 <= deq) << '\n'
			<< "comparison >= " << (deq4 >= deq) << '\n';
		assert(!(deq4 == deq));
		assert(deq4 != deq);
		assert(!(deq4 < deq));
		assert(deq4 > deq);
		assert(!(deq4 <= deq));
		assert(deq4 >= deq);
	}

	std::cout << "\n---swap\n\n";
	{
		DequeType deq;
		deq.push_back(5);
		deq.push_back(42);
		deq.push_back(43);
			assert(deq.size() == 3);

		DequeType deq2;
		deq2.push_back(12);
		deq2.push_back(30);
		deq2.push_back(60);
			assert(deq2.size() == 3);

		display_container("deq [5, 42, 43]:", deq);
            assert(deq[0] == 5);
            assert(deq[1] == 42);
            assert(deq[2] == 43);
            assert(deq.size() == 3);
		display_container("deq2 [12, 30, 60]:", deq2);
            assert(deq2[0] == 12);
            assert(deq2[1] == 30);
            assert(deq2[2] == 60);
            assert(deq2.size() == 3);
		deq.swap(deq2);
		std::cout << "---swapped\n";
		display_container("deq [12, 30, 60]:", deq);
            assert(deq[0] == 12);
            assert(deq[1] == 30);
            assert(deq[2] == 60);
            assert(deq.size() == 3);
		display_container("deq2 [5, 42, 43]:", deq2);
            assert(deq2[0] == 5);
            assert(deq2[1] == 42);
            assert(deq2[2] == 43);
            assert(deq2.size() == 3);
		deq.swap(deq2);
		std::cout << "---swapped\n";
		display_container("deq [5, 42, 43]:", deq);
            assert(deq[0] == 5);
            assert(deq[1] == 42);
            assert(deq[2] == 43);
            assert(deq.size() == 3);
		display_container("deq2 [12, 30, 60]:", deq2);
            assert(deq2[0] == 12);
            assert(deq2[1] == 30);
            assert(deq2[2] == 60);
            assert(deq2.size() == 3);
	}

	std::cout << '\n';
}

#endif
