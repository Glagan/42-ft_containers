/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:23:17 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 18:36:17 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
template<typename type_left, typename type_right>
class Pair
{
private:
public:
	Pair();
	Pair(Pair const &other);
	virtual ~Pair();

	Pair &operator=(Pair const &other);

};
}

# include "src/Pair.ipp"

#endif
