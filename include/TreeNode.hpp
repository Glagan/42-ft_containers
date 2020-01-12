/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:54:28 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 21:11:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREENODE_HPP
# define TREENODE_HPP

# include "include/Pair.hpp"

namespace ft
{
template<typename T, typename Compare>
class TreeNode
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef Compare key_compare;
protected:
	Pair<T, bool> value;
	struct node *parent;
	struct node *left;
	struct node *right;
public:
	TreeNode();
	TreeNode(TreeNode const &other);
	virtual ~TreeNode();

	TreeNode &operator=(TreeNode const &other);

};
}

#endif
