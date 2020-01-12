/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:23:24 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 13:54:19 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
template<typename first_type, typename second_type>
Pair<first_type, second_type>::Pair():
	first(), second()
{
}

template<typename first_type, typename second_type>
Pair<first_type, second_type>::Pair(first_type const &first, first_type const &second):
	first(first), second(second)
{
}

template<typename first_type, typename second_type>
template<typename U, typename V>
Pair<first_type, second_type>::Pair(Pair<U, V> const &other):
	first(other.first), second(other.second)
{
}

template<typename first_type, typename second_type>
Pair<first_type, second_type>::~Pair()
{
}

template<typename first_type, typename second_type>
Pair<first_type, second_type> &Pair<first_type, second_type>::operator=(Pair const &other)
{
	this->first = other.first;
	this->second = other.second;
	return (*this);
}

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
