/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:23:17 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 13:53:32 by ncolomer         ###   ########.fr       */
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

	Pair();
	Pair(first_type const &first, first_type const &second);
	template<class U, class V>
	Pair(Pair<U, V> const &other);
	virtual ~Pair();

	Pair &operator=(Pair const &other);
	Pair &operator=(second_type const &second);
};

template <typename first_type, typename second_type>
bool operator==(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs);
template <typename first_type, typename second_type>
bool operator!=(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs);
template <typename first_type, typename second_type>
bool operator<(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs);
template <typename first_type, typename second_type>
bool operator<=(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs);
template <typename first_type, typename second_type>
bool operator>(Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs);
template <typename first_type, typename second_type>
bool operator>= (Pair<first_type, second_type> const &lhs, Pair<first_type, second_type> const &rhs);
template <typename first_type, typename second_type>
Pair<first_type, second_type> make_pair(first_type const &first, second_type const &second);
}

# include "src/Pair.ipp"

#endif
