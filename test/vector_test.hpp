/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:29 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/05 16:42:59 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

template<class VectorType>
void test_Vector(void)
{
	std::cout << "\n---basic\n\n";
	{
		VectorType empty_vector;
		{
			std::cout << "[begin] == [end] on empty vector" << '\n';
				assert(empty_vector.begin() == empty_vector.end());
			std::cout << "capacity? " << empty_vector.capacity() << '\n';
				assert(empty_vector.capacity() == 0);
			std::cout << "max_size (vector) " << empty_vector.max_size() << '\n';
			std::cout << "empty? " << empty_vector.empty() << '\n';
				assert(empty_vector.empty());
			std::cout << "empty vector size = " << empty_vector.size() << '\n';
				assert(empty_vector.size() == 0);
		}

		VectorType vec;
		vec.push_back(5);
		vec.push_back(42);
		{
			std::cout << "vector [5, 42].size() = " << vec.size() << '\n';
				assert(vec.size() == 2);
			std::cout << "[5, 42].front() = " << vec.front() << " (it:" << *vec.begin() << ")" << '\n';
				assert(vec.front() == 5);
				assert(*vec.begin() == 5);
			std::cout << "[5, 42].back()  = " << vec.back() << " (it:" << *--vec.end() << ")" << '\n';
				assert(vec.back() == 42);
				assert(*--vec.end() == 42);

			for (size_t i = 0; i < 2; i++) {
				std::cout << "vector[" << i << "] = " << vec[i] << " == vector.at(" << i << ") = " << vec.at(i) << '\n';
					assert(vec[i] == vec.at(i));
			}
			display_container("vector [5, 42] with iterators:", vec);
		}

		std::cout << "reverse:\n";
		typename VectorType::reverse_iterator it = vec.rbegin();
		typename VectorType::reverse_iterator ite = vec.rend();
		while (it != ite) {
			std::cout << *it++;
			if (it == ite)
				std::cout << '\n';
			else
				std::cout << ", ";
		}
	}

	std::cout << "\n---reserve\n\n";
	{
		VectorType vec;
		std::cout << "empty vector capacity " << vec.capacity() << '\n';
			assert(vec.capacity() == 0);
		vec.reserve(256);
			assert(vec.capacity() >= 256);
		std::cout << "empty vector{reserved 256} capacity " << vec.capacity() << '\n';
		vec.reserve(64);
		std::cout << "empty vector{reserved 64, no change} capacity " << vec.capacity() << '\n';
			assert(vec.capacity() >= 256);
	}

	std::cout << "\n---push_back\n\n";
	{
		VectorType vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);
			assert(vec.size() == 3);

		display_container("[5, 42, 3]:", vec);

		typename VectorType::reverse_iterator rit = vec.rbegin();
		typename VectorType::reverse_iterator rite = vec.rend();
		int i = 1;
		std::cout << "(reverse) [5, 42, 3]:" << '\n';
		while (rit != rite)
			std::cout << i++ << " -> " << *rit++ << '\n';

		typename VectorType::iterator it;
		typename VectorType::iterator ite;
		std::cout << "pop_back from [5, 42, 3]:" << '\n';
		for (size_t i = 0; i < 3; i++) {
			vec.pop_back();
			it = vec.begin();
			ite = vec.end();
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
		VectorType vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);
			assert(vec.size() == 3);

		display_container("[5, 42, 3]:", vec);

		VectorType vec2(vec);
		vec.clear();

		display_container("cleared vector []:", vec);
			assert(vec.size() == 0);
		display_container("copied vector before clear [5, 42, 3]", vec2);
			assert(vec2.size() == 3);
	}

	std::cout << "\n---erase\n\n";
	{
		VectorType vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(3);
			assert(vec.size() == 3);

		display_container("[5, 42, 3]:", vec);
		std::cout << "[3] -> " << *vec.erase(++vec.begin()) << '\n';
		display_container("42 deleted [5, 3]:", vec);
			assert(vec.size() == 2);

		typename VectorType::iterator it = vec.erase(--vec.end());
		std::cout << "deleted [end]\n";
			assert(it == vec.end());
			assert(vec.size() == 1);

		it = vec.erase(vec.begin());
		std::cout << "deleted [begin]\n";
			assert(it == vec.end());
			assert(vec.size() == 0);
	}

	std::cout << "\n---assign\n\n";
	{
		VectorType vec;

		vec.assign(5, 42);
		display_container("[42, 42, 42, 42, 42]:", vec);
			assert(vec.size() == 5);

		VectorType vec2;
		vec2.assign(5, 43);
		display_container("vec2[43, 43, 43, 43, 43]:", vec2);
			assert(vec2.size() == 5);
		vec.assign(vec2.begin(), vec2.end());
		display_container("vec [43, 43, 43, 43, 43]:", vec);
			assert(vec.size() == 5);

		vec2.assign(5, 44);
		display_container("vec[43, 43, 43, 43, 43]:", vec);
		display_container("vec2[44, 44, 44, 44, 44]:", vec2);
			assert(vec2.size() == 5);
	}

	std::cout << "\n---insert\n\n";
	{
		VectorType vec;
			assert(vec.size() == 0);

		vec.insert(vec.begin(), 5);
		display_container("[5]:", vec);
			assert(vec.front() == 5);
			assert(vec.back() == 5);
			assert(vec.size() == 1);

		vec.insert(vec.begin(), 2, 42);
		display_container("vec[42, 42, 5]:", vec);
			assert(vec.front() == 42);
			assert(vec.back() == 5);
			assert(vec.size() == 3);

		VectorType vec2;
			assert(vec2.size() == 0);

		vec2.insert(vec2.begin(), vec.begin(), vec.end());
		display_container("vec2[42, 42, 5]:", vec2);
			assert(vec2.front() == 42);
			assert(vec2.back() == 5);
			assert(vec2.size() == 3);

		vec2.insert(vec2.end(), vec.begin(), vec.end());
		display_container("vec + vec2[42, 42, 5, 42, 42, 5]:", vec2);
			assert(vec2.front() == 42);
			assert(vec2.back() == 5);
			assert(vec2.size() == 6);
	}

	std::cout << "\n---resize\n\n";
	{
		VectorType vec;
		vec.push_back(5);
		vec.push_back(42);

		display_container("[5, 42]:", vec);
			assert(vec.size() == 2);

		vec.resize(5, 43);
		display_container("[5, 42, 43, 43, 43]:", vec);
			assert(vec.back() == 43);
			assert(vec.size() == 5);

		vec.resize(1);
		display_container("[5]:", vec);
			assert(vec.back() == 5);
			assert(vec.size() == 1);

		vec.resize(0);
		display_container("[]:", vec);
			assert(vec.size() == 0);

		vec.resize(5);
		display_container("[0, 0, 0, 0, 0]:", vec);
			assert(vec.back() == 0);
			assert(vec.size() == 5);
	}

	std::cout << "\n---comparison\n\n";
	{
		VectorType vec;
		vec.push_back(5);
		vec.push_back(42);
			assert(vec.size() == 2);

		VectorType vec2;
		vec2.push_back(5);
		vec2.push_back(42);
			assert(vec2.size() == 2);

		VectorType vec3;
		vec3.push_back(5);
		vec3.push_back(42);
		vec3.push_back(43);
			assert(vec3.size() == 3);

		VectorType vec4;
		vec4.push_back(99);
		vec4.push_back(42);
		vec4.push_back(43);
			assert(vec4.size() == 3);

		std::cout << "same vector:" << '\n'
			<< "comparison == " << (vec == vec2) << '\n'
			<< "comparison != " << (vec != vec2) << '\n'
			<< "comparison <  " << (vec < vec2) << '\n'
			<< "comparison >  " << (vec > vec2) << '\n'
			<< "comparison <= " << (vec <= vec2) << '\n'
			<< "comparison >= " << (vec >= vec2) << '\n';
		assert(vec == vec2);
		assert(!(vec != vec2));
		assert(!(vec < vec2));
		assert(!(vec > vec2));
		assert(vec <= vec2);
		assert(vec >= vec2);

		std::cout << "lesser vector:" << '\n'
			<< "comparison == " << (vec == vec3) << '\n'
			<< "comparison != " << (vec != vec3) << '\n'
			<< "comparison <  " << (vec < vec3) << '\n'
			<< "comparison >  " << (vec > vec3) << '\n'
			<< "comparison <= " << (vec <= vec3) << '\n'
			<< "comparison >= " << (vec >= vec3) << '\n';
		assert(!(vec == vec3));
		assert(vec != vec3);
		assert(vec < vec3);
		assert(!(vec > vec3));
		assert(vec <= vec3);
		assert(!(vec >= vec3));

		std::cout << "upper vector:" << '\n'
			<< "comparison == " << (vec4 == vec) << '\n'
			<< "comparison != " << (vec4 != vec) << '\n'
			<< "comparison <  " << (vec4 < vec) << '\n'
			<< "comparison >  " << (vec4 > vec) << '\n'
			<< "comparison <= " << (vec4 <= vec) << '\n'
			<< "comparison >= " << (vec4 >= vec) << '\n';
		assert(!(vec4 == vec));
		assert(vec4 != vec);
		assert(!(vec4 < vec));
		assert(vec4 > vec);
		assert(!(vec4 <= vec));
		assert(vec4 >= vec);
	}

	std::cout << "\n---swap\n\n";
	{
		VectorType vec;
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(43);
			assert(vec.size() == 3);

		VectorType vec2;
		vec2.push_back(12);
		vec2.push_back(30);
		vec2.push_back(60);
			assert(vec2.size() == 3);

		display_container("vec [5, 42, 43]:", vec);
            assert(vec[0] == 5);
            assert(vec[1] == 42);
            assert(vec[2] == 43);
            assert(vec.size() == 3);
		display_container("vec2 [12, 30, 60]:", vec2);
            assert(vec2[0] == 12);
            assert(vec2[1] == 30);
            assert(vec2[2] == 60);
            assert(vec2.size() == 3);
		vec.swap(vec2);
		std::cout << "---swapped\n";
		display_container("vec [12, 30, 60]:", vec);
            assert(vec[0] == 12);
            assert(vec[1] == 30);
            assert(vec[2] == 60);
            assert(vec.size() == 3);
		display_container("vec2 [5, 42, 43]:", vec2);
            assert(vec2[0] == 5);
            assert(vec2[1] == 42);
            assert(vec2[2] == 43);
            assert(vec2.size() == 3);
		vec.swap(vec2);
		std::cout << "---swapped\n";
		display_container("vec [5, 42, 43]:", vec);
            assert(vec[0] == 5);
            assert(vec[1] == 42);
            assert(vec[2] == 43);
            assert(vec.size() == 3);
		display_container("vec2 [12, 30, 60]:", vec2);
            assert(vec2[0] == 12);
            assert(vec2[1] == 30);
            assert(vec2[2] == 60);
            assert(vec2.size() == 3);
	}

	std::cout << '\n';
}

#endif
