/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:09:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/05 14:57:29 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <cstring>

namespace ft
{
template<typename value_type>
class Node
{
private:
	Node<value_type> *m_previous;
	value_type m_value;
	Node<value_type> *m_next;
public:
	Node(): m_previous(nullptr), m_value(), m_next(nullptr) {}
	Node(value_type const &val):
		m_previous(nullptr), m_value(val), m_next(nullptr) {}
	Node(Node *previous, value_type const &val, Node *next=nullptr):
		m_previous(previous), m_value(val), m_next(next) {}
	Node(Node const &other):
		m_previous(other.m_previous), m_value(other.val), m_next(other.m_next) {}
	virtual ~Node() {}

	Node &operator=(Node const &other) {
		this->m_previous = other.m_previous;
		this->m_value = other.m_value;
		this->m_next = other.m_next;
		return (*this);
	}

	void insert_before(Node *node) {
		if (this->m_previous) {
			node->m_previous = this->m_previous;
			this->m_previous->m_next = node;
		}
		node->m_next = this;
		this->m_previous = node;
	}
	void insert_after(Node *node) {
		if (this->m_next) {
			node->m_next = this->m_next;
			this->m_next->m_previous = node;
		}
		node->m_previous = this;
		this->m_next = node;
	}

	void disconnect(void) {
		if (this->m_previous)
			this->m_previous->m_next = this->m_next;
		if (this->m_next)
			this->m_next->m_previous = this->m_previous;
	}

	void swap(Node *node) {
		if (this->m_next == node) {
			if (this->m_previous)
				this->m_previous->m_next = node;
			node->m_previous = this->m_previous;
			this->m_previous = node;
			if (node->m_next)
				node->m_next->m_previous = this;
			this->m_next = node->m_next;
			node->m_next = this;
		} else if (this->m_previous == node) {
			if (node->m_previous)
				node->m_previous->m_next = this;
			this->m_previous = node->m_previous;
			node->m_previous = this;
			if (this->m_next)
				this->m_next->m_previous = node;
			node->m_next = this->m_next;
			this->m_next = node;
		} else {
			Node<value_type> *previous = this->m_previous;
			Node<value_type> *next = this->m_next;

			if (this->m_previous)
				this->m_previous->m_next = node;
			if (this->m_next)
				this->m_next->m_previous = node;
			this->m_previous = node->m_previous;
			this->m_next = node->m_next;
			if (node->m_previous)
				node->m_previous->m_next = this;
			if (node->m_next)
				node->m_next->m_previous = this;
			node->m_previous = previous;
			node->m_next = next;
		}
	}

	void reverse(void) {
		Node<value_type> *tmp = this->m_previous;
		this->m_previous = this->m_next;
		this->m_next = tmp;
	}

	void swap_values(Node *node) {
		value_type tmp;
		std::memmove(static_cast<void*>(&tmp), static_cast<void*>(&node->m_value), 1);
		std::memmove(static_cast<void*>(&node->m_value), static_cast<void*>(&this->m_value), 1);
		std::memmove(static_cast<void*>(&this->m_value), static_cast<void*>(&tmp), 1);
	}

	value_type &value(void) {
		return (this->m_value);
	}
	value_type const &value(void) const {
		return (this->m_value);
	}

	Node *&previous(void) {
		return (this->m_previous);
	}
	Node const *previous(void) const {
		return (this->m_previous);
	}

	Node *&next(void) {
		return (this->m_next);
	}
	Node const *next(void) const {
		return (this->m_next);
	}
};
}

#endif
