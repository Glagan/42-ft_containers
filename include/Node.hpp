/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:09:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/12 17:22:33 by ncolomer         ###   ########.fr       */
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
	Node(): previous_(nullptr), value_(), next_(nullptr) {}
	Node(value_type const &val):
		previous_(nullptr), value_(val), next_(nullptr) {}
	Node(Node *previous, value_type const &val, Node *next=nullptr):
		previous_(previous), value_(val), next_(next) {}
	Node(Node const &other):
		previous_(other.previous_), value_(other.val), next_(other.next_) {}
	virtual ~Node() {}

	Node &operator=(Node const &other)
	{
		this->previous_ = other.previous_;
		this->value_ = other.value_;
		this->next_ = other.next_;
		return (*this);
	}

	void insert_before(Node *node)
	{
		if (this->previous_)
		{
			node->previous_ = this->previous_;
			this->previous_->next_ = node;
		}
		node->next_ = this;
		this->previous_ = node;
	}

	void insert_after(Node *node)
	{
		if (this->next_)
		{
			node->next_ = this->next_;
			this->next_->previous_ = node;
		}
		node->previous_ = this;
		this->next_ = node;
	}

	void disconnect(void)
	{
		if (this->previous_)
			this->previous_->next_ = this->next_;
		if (this->next_)
			this->next_->previous_ = this->previous_;
	}

	void swap(Node *node)
	{
		if (this->next_ == node)
		{
			if (this->previous_)
				this->previous_->next_ = node;
			node->previous_ = this->previous_;
			this->previous_ = node;
			if (node->next_)
				node->next_->previous_ = this;
			this->next_ = node->next_;
			node->next_ = this;
		}
		else if (this->previous_ == node)
		{
			if (node->previous_)
				node->previous_->next_ = this;
			this->previous_ = node->previous_;
			node->previous_ = this;
			if (this->next_)
				this->next_->previous_ = node;
			node->next_ = this->next_;
			this->next_ = node;
		}
		else
		{
			Node<value_type> *previous = this->previous_;
			Node<value_type> *next = this->next_;

			if (this->previous_)
				this->previous_->next_ = node;
			if (this->next_)
				this->next_->previous_ = node;
			this->previous_ = node->previous_;
			this->next_ = node->next_;
			if (node->previous_)
				node->previous_->next_ = this;
			if (node->next_)
				node->next_->previous_ = this;
			node->previous_ = previous;
			node->next_ = next;
		}
	}

	void swap_values(Node *node)
	{
		value_type tmp;
		std::memmove(static_cast<void*>(&tmp), static_cast<void*>(&node->value_), 1);
		std::memmove(static_cast<void*>(&node->value_), static_cast<void*>(&this->value_), 1);
		std::memmove(static_cast<void*>(&this->value_), static_cast<void*>(&tmp), 1);
	}

	value_type &value(void)
	{
		return (this->value_);
	}

	value_type const &value(void) const
	{
		return (this->value_);
	}

	Node *&previous(void)
	{
		return (this->previous_);
	}

	Node const *previous(void) const
	{
		return (this->previous_);
	}

	Node *&next(void)
	{
		return (this->next_);
	}

	Node const *next(void) const
	{
		return (this->next_);
	}
};
}

#endif
