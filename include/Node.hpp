/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:09:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/08 18:06:02 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
template<typename value_type>
class Node
{
private:
	Node<value_type> *previous_;
	value_type value_;
	Node<value_type> *next_;
public:
	Node();
	Node(value_type const &val);
	Node(Node<value_type> *previous, value_type const &val, Node<value_type> *next);
	Node(Node<value_type> const &other);
	~Node();

	Node<value_type> &operator=(Node<value_type> const &other);

	void erase(void);
	value_type &value(void);
	value_type const &value(void) const;
	Node<value_type> *previous(void);
	Node<value_type> const *previous(void) const;
	Node<value_type> *next(void);
	Node<value_type> const *next(void) const;
};
}

# include "src/Node.ipp"

#endif
