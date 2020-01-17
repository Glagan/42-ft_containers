/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:23:17 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/15 16:48:46 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
template<typename first_type, typename second_type>
class Pair
{
public:
	first_type first;
	second_type second;

	Pair(): first(), second() {}
	Pair(first_type const &first, second_type const &second): first(first), second(second) {}
	template<class U, class V>
	Pair(Pair<U, V> const &other): first(other.first), second(other.second) {}
	virtual ~Pair() {}

	Pair &operator=(Pair const &other)
	{
		this->first = other.first;
		this->second = other.second;
		return (*this);
	}
};

template <typename first_type, typename second_type>
bool operator==(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename first_type, typename second_type>
bool operator!=(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs)
{
	return (!(lhs == rhs));
}

template <typename first_type, typename second_type>
bool operator<(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <typename first_type, typename second_type>
bool operator<=(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs)
{
	return (!(rhs < lhs));
}

template <typename first_type, typename second_type>
bool operator>(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs)
{
	return (rhs < lhs);
}

template <typename first_type, typename second_type>
bool operator>= (Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs)
{
	return (!(lhs < rhs));
}

template <typename first_type, typename second_type>
Pair<first_type, second_type> make_pair(first_type const &first, second_type const &second)
{
	return (Pair<first_type, second_type>(first, second));
}
}

#endif
