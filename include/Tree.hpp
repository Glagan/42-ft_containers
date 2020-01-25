/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:10:11 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/25 20:42:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <utility>

/**
 * Simple Binary Tree
 **/
template <typename T, typename Compare>
class Tree
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef Compare value_compare;

	class Node
	{
	private:
		friend class Tree;
	protected:
		value_type value;
		Node *parent;
		Node *left;
		Node *right;
	public:
		Node():
			value(), parent(nullptr), left(nullptr), right(nullptr) {}
		Node(value_type const &value):
			value(value), parent(nullptr), left(nullptr), right(nullptr) {}
		Node(Node const &other):
			value(other.value), parent(other.parent), left(other.left), right(other.right) {}
		virtual ~Node() {}

		Node &operator=(Node const &other)
		{
			this->value = other.value;
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
			return (*this);
		}

		value_type &get_value(void)
		{
			return (this->value);
		}

		value_type const &get_value(void) const
		{
			return (this->value);
		}

		Node *get_parent(void) const
		{
			return (this->parent);
		}

		Node *get_left(void) const
		{
			return (this->left);
		}

		Node *get_right(void) const
		{
			return (this->right);
		}
	};

	typedef Node* node_pointer;
private:
	void make_bounds(void)
	{
		this->begin_ = new Node;
		this->end_ = this->begin_;
		this->root = this->end_;
	}

	void repair_bounds(void)
	{
		node_pointer tmp = this->root;
		while (tmp->left)
			tmp = tmp->left;
		this->begin_ = tmp;
		tmp = this->root;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = this->end_;
		this->end_->parent = tmp;
	}
protected:
	node_pointer root;
	node_pointer begin_;
	node_pointer end_;
	value_compare comp;

	void insert_recurse(node_pointer node, node_pointer new_node)
	{
		if (comp(new_node->value, node->value))
		{
			if (node->left)
			{
				this->insert_recurse(node->left, new_node);
				return ;
			}
			else
				node->left = new_node;
		}
		else
		{
			if (node->right)
			{
				this->insert_recurse(node->right, new_node);
				return ;
			}
			else
				node->right = new_node;
		}
		new_node->parent = node;
	}

	node_pointer erase_node(node_pointer node)
	{
		if (!node)
			return (node);
		// No children
		if (!node->left && !node->right)
			delete node;
		// case 2: one child (right)
		else if (!node->left)
		{
			if (node->parent)
				node->parent->right = node->right;
			node->right->parent = node->parent;
			delete node;
		}
		// case 3: one child (left)
		else if (!node->right)
		{
			if (node->parent)
				node->parent->left = node->left;
			node->left->parent = node->parent;
			delete node;
		}
		// case 4: two children
		else
		{
			node_pointer tmp = node->right; // find minimal value of right sub tree
			while (tmp && tmp->right != NULL)
				tmp = tmp->right;
			if (node->parent)
				node->parent->right = tmp;
			tmp->parent = node->parent;
			std::memmove(&node->value, &tmp->value, sizeof(value_type));
			node->right = erase_node(node->right); // delete the duplicate node
		}
		return (node);
	}

	void delete_recurse(node_pointer node)
	{
		if (!node || node == this->end_)
			return ;
		delete_recurse(node->left);
		delete_recurse(node->right);
		delete node;
	}
public:
	Tree():
		root(nullptr), comp()
	{
		this->make_bounds();
	}
	Tree(Compare const &comp):
		root(nullptr), comp(comp)
	{
		this->make_bounds();
	}
	Tree(Tree const &other):
		root(other.root), begin_(other.begin_), end_(other.end_)
	{
		this->create_empty_node();
		// TODO; Copy
	}
	virtual ~Tree()
	{
		this->make_empty();
		delete this->end_;
	}

	Tree &operator=(Tree const &other)
	{
		if (this->root != this->end_)
			this->make_empty();
		this->comp = other.comp;
		// TODO; Copy
		return (*this);
	}

	node_pointer insert(const_reference val)
	{
		node_pointer new_node = new Node(val);
		if (this->root == this->end_)
			this->root = new_node;
		else
		{
			if (this->end_->parent)
				this->end_->parent->right = nullptr;
			this->insert_recurse(this->root, new_node);
		}
		this->repair_bounds();
		return (new_node);
	}

	template<typename Tp>
	node_pointer find(Tp const &val)
	{
		return (this->find(val, this->root));
	}

	template<typename Tp>
	node_pointer find(Tp const &val, node_pointer node)
	{
		if (node == this->end_ || !node)
			return (nullptr);
		bool comp_left = comp(val, node->value);
		if (!comp(node->value, val))
			return (node);
		if (comp_left)
			return (this->find(val, node->left));
		return (this->find(val, node->right));
	}

	// TODO: Check erase root
	template<typename Tp>
	bool erase(Tp const &key)
	{
		node_pointer node = this->find(key);
		if (node)
		{
			if (this->end_->parent)
				this->end_->parent->right = nullptr;
			this->erase_node(node);
			this->repair_bounds();
			return (true);
		}
		return (false);
	}

	node_pointer begin_bound(void) const
	{
		return (this->begin_);
	}

	node_pointer end_bound(void) const
	{
		return (this->end_);
	}

	void make_empty(void)
	{
		this->delete_recurse(this->root);
		this->end_->parent = nullptr;
		this->end_->left = nullptr;
		this->end_->right = nullptr;
		this->begin_ = this->root = this->end_;
	}
};

#endif
