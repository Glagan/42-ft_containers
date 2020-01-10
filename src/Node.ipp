/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:09:41 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/10 13:54:52 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
template<typename value_type>
Node<value_type>::Node():
	previous_(nullptr), next_(nullptr)
{
}

template<typename value_type>
Node<value_type>::Node(value_type const &val):
	previous_(nullptr), value_(val), next_(nullptr)
{
}

template<typename value_type>
Node<value_type>::Node(Node<value_type> *previous, value_type const &val, Node<value_type> *next):
	previous_(previous), value_(val), next_(next)
{
}

template<typename value_type>
Node<value_type>::Node(Node const &other):
	previous_(other.previous_), value_(other.value_), next_(other.next_)
{
}

template<typename value_type>
Node<value_type>::~Node()
{
}

template<typename value_type>
Node<value_type> &Node<value_type>::operator=(Node const &other)
{
	this->previous_ = other.previous_;
	this->value_ = other.value_;
	this->next_ = other.next_;
	return (*this);
}

template<typename value_type>
void Node<value_type>::insert_before(Node<value_type> *node)
{
	if (this->previous_)
	{
		node->previous() = this->previous_;
		this->previous_->next() = node;
	}
	node->next() = this;
	this->previous_ = node;
}

template<typename value_type>
void Node<value_type>::insert_after(Node<value_type> *node)
{
	if (this->next_)
	{
		node->next() = this->next_;
		this->next_->previous() = node;
	}
	node->previous() = this;
	this->next_ = node;
}

template<typename value_type>
void Node<value_type>::disconnect(void)
{
	if (this->previous_)
		this->previous_->next() = this->next_;
	if (this->next_)
		this->next_->previous() = this->previous_;
}

template<typename value_type>
void Node<value_type>::swap(Node<value_type> *node)
{
	Node<value_type> *previous = this->previous_;
	Node<value_type> *next = this->next_;

	this->previous_ = node->previous_;
	this->next_ = node->next_;
	node->previous_ = previous;
	node->next_ = next;
}

template<typename value_type>
value_type &Node<value_type>::value(void)
{
	return (this->value_);
}

template<typename value_type>
value_type const &Node<value_type>::value(void) const
{
	return (this->value_);
}

template<typename value_type>
Node<value_type> *&Node<value_type>::previous(void)
{
	return (this->previous_);
}

template<typename value_type>
Node<value_type> const *Node<value_type>::previous(void) const
{
	return (this->previous_);
}

template<typename value_type>
Node<value_type> *&Node<value_type>::next(void)
{
	return (this->next_);
}

template<typename value_type>
Node<value_type> const *Node<value_type>::next(void) const
{
	return (this->next_);
}
}
