/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 13:20:40 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename test_type>
void test_Vector(void)
{
	std::cout << "---basic\n" << '\n';

	ft::Vector<test_type> empty_vector;
	if (empty_vector.begin() == empty_vector.end())
		std::cout << "[begin] == [end] on empty vector" << '\n';
	else
		std::cout << "!!! [begin] != [end] on empty vector !!!" << '\n';
	std::cout << "capacity? " << empty_vector.capacity() << '\n';
	std::cout << "max_size " << empty_vector.max_size() << '\n';
	std::cout << "empty? " << empty_vector.empty() << '\n';
	std::cout << "empty vector size = " << empty_vector.size() << '\n';

	ft::Vector<test_type> vec;
	vec.push_back(5);
	vec.push_back(42);

	std::cout << "vector [5, 42].size() = " << vec.size() << '\n';
	std::cout << "[5, 42].front() = " << vec.front() << " (it:" << *vec.begin() << ")" << '\n';
	std::cout << "[5, 42].back()  = " << vec.back() << " (it:" << *--vec.end() << ")" << '\n';

	for (size_t i = 0; i < 2; i++)
		std::cout << "vector[" << i << "] = " << vec[i] << " == vector.at(" << i << ") = " << vec.at(i) << '\n';
	display_container("vector [5, 42] with iterators:", vec);

	std::cout << "reverse:\n";
	{
		typename ft::Vector<test_type>::reverse_iterator it = vec.rbegin();
		typename ft::Vector<test_type>::reverse_iterator ite = vec.rend();
		while (it != ite)
		{
			std::cout << *it++;
			if (it == ite)
				std::cout << '\n';
			else
				std::cout << ", ";
		}
	}

	std::cout << "\n---reserve\n" << '\n';
	{
		ft::Vector<test_type> vec;
		std::cout << "empty vector capacity " << vec.capacity() << '\n';
		vec.reserve(256);
		std::cout << "empty vector{reserved 256} capacity " << vec.capacity() << '\n';
		vec.reserve(64);
		std::cout << "empty vector{reserved 64, no change} capacity " << vec.capacity() << '\n';
	}

	std::cout << "\n---push_back\n" << '\n';
	{
		ft::Vector<test_type> vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);

		typename ft::Vector<test_type>::iterator it = vec.begin();
		typename ft::Vector<test_type>::iterator ite = vec.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		typename ft::Vector<test_type>::reverse_iterator rit = vec.rbegin();
		typename ft::Vector<test_type>::reverse_iterator rite = vec.rend();
		i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		std::cout << "pop_back from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++)
		{
			vec.pop_back();
			it = vec.begin();
			ite = vec.end();
			if (i == 0) std::cout << "[5, 42]:" << '\n';
			else if (i == 1) std::cout << "[5]:" << '\n';
			else
			{
				std::cout << "[]:" << '\n';
				break ;
			}
			while (it != ite)
				std::cout << *it++ << ", ";
			std::cout << '\n';
		}
	}

	std::cout << "\n---clear\n" << '\n';
	{
		ft::Vector<test_type> vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);

		typename ft::Vector<test_type>::iterator it = vec.begin();
		typename ft::Vector<test_type>::iterator ite = vec.end();
		int i = 1;
		std::cout << "[5, 42, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		ft::Vector<test_type> vec2(vec);
		vec.clear();

		it = vec.begin();
		ite = vec.end();
		i = 1;
		std::cout << "cleared vector []:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';

		it = vec2.begin();
		ite = vec2.end();
		i = 1;
		std::cout << "copied vector before clear [5, 2, 3]:" << '\n';
		while (it != ite)
			std::cout << i++ << " -> " << *it++ << '\n';
	}

	std::cout << "\n---erase\n" << '\n';
	{
		ft::Vector<test_type> vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);

		display_container("[5, 42, 3]:", vec);
		std::cout << "[3] -> " << *vec.erase(++vec.begin()) << '\n';
		display_container("42 deleted [5, 3]:", vec);

		typename ft::Vector<test_type>::iterator it = vec.erase(--vec.end());
		std::cout << "deleted [end] -> ";
		if (it == vec.end())
			std::cout << "returned [end]" << '\n';
		else
			std::cout << "!!! didn't return [end] !!!" << '\n';

		it = vec.erase(vec.begin());
		std::cout << "deleted [begin] -> ";
		if (it == vec.begin() && it == vec.end())
			std::cout << "returned [begin] and [end]" << '\n';
		else
			std::cout << "!!! didn't return [begin] and [end] !!!" << '\n';
	}

	std::cout << "\n---assign\n" << '\n';
	{
		ft::Vector<test_type> vec;

		vec.assign(5, 42);
		display_container("[42, 42, 42, 42, 42]:", vec);

		ft::Vector<test_type> vec2;
		vec2.assign(5, 43);
		display_container("vec2[43, 43, 43, 43, 43]:", vec2);
		vec.assign(vec2.begin(), vec2.end());
		display_container("vec [43, 43, 43, 43, 43]:", vec);

		vec2.assign(5, 44);
		display_container("vec[43, 43, 43, 43, 43]:", vec);
		display_container("vec2[44, 44, 44, 44, 44]:", vec2);
	}

	std::cout << "\n---insert\n" << '\n';
	{
		ft::Vector<test_type> vec;

		vec.insert(vec.begin(), 5);
		display_container("[5]:", vec);

		vec.insert(vec.begin(), 2, 42);
		display_container("vec[42, 42, 5]:", vec);

		ft::Vector<test_type> vec2;

		vec2.insert(vec2.begin(), vec.begin(), vec.end());
		display_container("vec to vec2[42, 42, 5]:", vec2);

		vec2.insert(vec2.end(), vec.begin(), vec.end());
		display_container("vec to vec2[42, 42, 5, 42, 42, 5]:", vec2);
	}

	std::cout << "\n---resize\n" << '\n';
	{
		ft::Vector<test_type> vec;
		vec.push_back(5);
		vec.push_back(42);

		display_container("[5, 42]:", vec);

		vec.resize(5, 43);
		display_container("[5, 42, 43, 43, 43]:", vec);

		vec.resize(1);
		display_container("[5]:", vec);

		vec.resize(0);
		display_container("[]:", vec);

		vec.resize(5);
		display_container("[0, 0, 0, 0, 0]:", vec);
	}

	std::cout << "\n---comparison\n" << '\n';
	{
		ft::Vector<test_type> vec;
		vec.push_back(5);
		vec.push_back(42);

		ft::Vector<test_type> vec2;
		vec2.push_back(5);
		vec2.push_back(42);

		ft::Vector<test_type> vec3;
		vec3.push_back(5);
		vec3.push_back(42);
		vec3.push_back(43);

		ft::Vector<test_type> vec4;
		vec4.push_back(99);
		vec4.push_back(42);
		vec4.push_back(43);

		std::cout << "same vector:" << '\n'
			<< "comparison == " << (vec == vec2) << '\n'
			<< "comparison != " << (vec != vec2) << '\n'
			<< "comparison <  " << (vec < vec2) << '\n'
			<< "comparison >  " << (vec > vec2) << '\n'
			<< "comparison <= " << (vec <= vec2) << '\n'
			<< "comparison >= " << (vec >= vec2) << '\n';

		std::cout << "lesser vector:" << '\n'
			<< "comparison == " << (vec == vec3) << '\n'
			<< "comparison != " << (vec != vec3) << '\n'
			<< "comparison <  " << (vec < vec3) << '\n'
			<< "comparison >  " << (vec > vec3) << '\n'
			<< "comparison <= " << (vec <= vec3) << '\n'
			<< "comparison >= " << (vec >= vec3) << '\n';

		std::cout << "upper vector:" << '\n'
			<< "comparison == " << (vec4 == vec) << '\n'
			<< "comparison != " << (vec4 != vec) << '\n'
			<< "comparison <  " << (vec4 < vec) << '\n'
			<< "comparison >  " << (vec4 > vec) << '\n'
			<< "comparison <= " << (vec4 <= vec) << '\n'
			<< "comparison >= " << (vec4 >= vec) << '\n';
	}
}
