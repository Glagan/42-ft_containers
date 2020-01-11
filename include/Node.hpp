/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:09:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 18:28:31 by ncolomer         ###   ########.fr       */
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
	Node(Node *previous, value_type const &val, Node *next=nullptr);
	Node(Node const &other);
	~Node();

	Node &operator=(Node const &other);

	void insert_before(Node *node);
	void insert_after(Node *node);
	void disconnect(void);
	void swap(Node *node);
	void swap_values(Node *node);
	value_type &value(void);
	value_type const &value(void) const;
	Node *&previous(void);
	Node const *previous(void) const;
	Node *&next(void);
	Node const *next(void) const;
};
}

# include "src/Node.ipp"

#endif
