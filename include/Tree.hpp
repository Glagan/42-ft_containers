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
	struct Node
	{
		value_type value;
		Node *parent;
		Node *left;
		Node *right;

		Node(const_reference val=value_type()):
			value(val), parent(nullptr), left(nullptr), right(nullptr) {}
	};
	typedef Node* node_pointer;
protected:
	node_pointer root;
	node_pointer begin_;
	node_pointer end_;
	value_compare comp;

	void unbound_node(node_pointer node)
	{
		if (!node)
			return ;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
	}

	void make_bounds(void)
	{
		this->begin_ = new Node();
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

	template<typename Tp>
	node_pointer find(Tp const &val, node_pointer node)
	{
		if (node == this->end_ || !node)
			return (nullptr);
		bool comp_left = comp(val, node->value);
		if (!comp_left && !comp(node->value, val))
			return (node);
		if (comp_left)
			return (this->find(val, node->left));
		return (this->find(val, node->right));
	}

	void insert(node_pointer node, node_pointer new_node)
	{
		if (comp(new_node->value, node->value))
		{
			if (node->left)
			{
				this->insert(node->left, new_node);
				return ;
			}
			else
				node->left = new_node;
		}
		else
		{
			if (node->right)
			{
				this->insert(node->right, new_node);
				return ;
			}
			else
				node->right = new_node;
		}
		new_node->parent = node;
	}

	node_pointer erase(node_pointer node)
	{
		if (!node)
			return (node);
		// No children
		if (!node->left && !node->right)
		{
			if (node == this->root)
			{
				this->root = this->begin_ = this->end_;
				this->unbound_node(this->end_);
			}
			delete node;
		}
		// case 2: one child (right)
		else if (!node->left)
		{
			if (node->parent)
				node->parent->right = node->right;
			node->right->parent = node->parent;
			if (node == this->root)
				this->root = node->right;
			delete node;
		}
		// case 3: one child (left)
		else if (!node->right)
		{
			if (node->parent)
				node->parent->left = node->left;
			node->left->parent = node->parent;
			if (node == this->root)
				this->root = node->left;
			delete node;
		}
		// case 4: two children
		else
		{
			node_pointer tmp = node->right; // find minimal value of right sub tree
			while (tmp && tmp->left != NULL)
				tmp = tmp->left;
			if (node->parent)
				node->parent->right = tmp;
			tmp->parent = node->parent;
			std::memmove(&node->value, &tmp->value, sizeof(value_type));
			if (node == this->root)
				this->root = node;
			node->right = erase(node->right); // delete the duplicate node
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
			this->insert(this->root, new_node);
		}
		this->repair_bounds();
		return (new_node);
	}

	node_pointer insert(node_pointer hint, const_reference val)
	{
		if (!hint || this->root == this->end_)
			return (this->insert(val));
		node_pointer new_node = new Node(val);
		if (this->end_->parent)
			this->end_->parent->right = nullptr;
		// TODO: Check if hint is not good
		this->insert(hint, new_node);
		this->repair_bounds();
		return (new_node);
	}

	template<typename Tp>
	node_pointer find(Tp const &val)
	{
		return (this->find(val, this->root));
	}

	template<typename Tp>
	node_pointer find(node_pointer hint, Tp const &val)
	{
		// TODO: Check if hint is not good
		if (!hint)
			return (this->find(val, this->root));
		return (this->find(val, hint));
	}

	template<typename Tp>
	size_type erase(Tp const &key)
	{
		node_pointer node = nullptr;
		size_type total = 0;

		while ((node = this->find(key)))
		{
			if (this->end_->parent)
				this->end_->parent->right = nullptr;
			this->erase(node);
			this->repair_bounds();
			total++;
		}
		return (total);
	}

	node_pointer begin(void) const
	{
		return (this->begin_);
	}

	node_pointer end(void) const
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
