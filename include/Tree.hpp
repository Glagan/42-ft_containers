/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:26:15 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 17:18:36 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include "include/Pair.hpp"

template <typename value_type, typename Compare>
class Tree
{
public:
	typedef size_t size_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef Compare key_compare;
protected:
	
public:
	Tree();
	Tree(Tree const &other);
	virtual ~Tree();

	Tree &operator=(Tree const &other);
};

#endif
