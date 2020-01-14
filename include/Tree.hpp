/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:10:11 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/14 23:10:11 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

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
private:
	class TreeNode
	{
	public:
		value_type value;
		TreeNode *parent;
		TreeNode *left;
		TreeNode *right;
		bool color;

		TreeNode():
			value(), parent(nullptr), left(nullptr), right(nullptr), color(0)
		{
		}
		TreeNode(value_type const &value, bool color=1):
			value(value), parent(nullptr), left(nullptr), right(nullptr), color(color)
		{
		}
		TreeNode(TreeNode const &other):
			value(other.value), parent(other.nullptr), left(other.nullptr), right(other.nullptr), color(other.color)
		{
		}
		virtual ~TreeNode()
		{
		}

		TreeNode &operator=(TreeNode const &other)
		{
			this->value = other.value;
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
			this->color = other.color;
			return (*this);
		}
	};
protected:
	TreeNode *root;

	TreeNode *minimum_node(TreeNode *node)
	{
		while (node->left != nullptr)
			node = node->left;
		return (node);
	}

	TreeNode *maximum_node(TreeNode *node)
	{
		while (node->right != nullptr)
			node = node->right;
		return (node);
	}

	void left_rotate(TreeNode *x)
	{
		TreeNode *y = x->right;
		x->right = y->left;
		if (y->left != nullptr)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	void right_rotate(TreeNode *x)
	{
		TreeNode *y = x->left;
		x->left = y->right;
		if (y->right != nullptr)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	void fix_insert(TreeNode *k)
	{
		TreeNode *u;
		while (k->parent->color == 1)
		{
			if (k->parent == k->parent->parent->right)
			{
				u = k->parent->parent->left;
				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->left)
					{
						k = k->parent;
						right_rotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					left_rotate(k->parent->parent);
				}
			}
			else
			{
				u = k->parent->parent->right;

				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						k = k->parent;
						left_rotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					right_rotate(k->parent->parent);
				}
			}
			if (k == root)
				break;
		}
		root->color = 0;
	}

	TreeNode *search(TreeNode *node, value_type const &val)
	{
		if (node == nullptr || val == node->value)
			return (node);
		if (value_compare(val, node->value))
			return search(node->left, val);
		return search(node->right, val);
	}
public:
	Tree():
		root(nullptr)
	{
		this->root = new TreeNode();
	}
	Tree(Tree const &other):
		root(other.root)
	{
	}
	virtual ~Tree() {}

	Tree &operator=(Tree const &other)
	{
		this->root = other.root;
		return (*this);
	}

	TreeNode *insert(const_reference val)
	{
		TreeNode *node = new TreeNode(val);
		TreeNode *y = nullptr;
		TreeNode *x = this->root;

		while (x != nullptr)
		{
			y = x;
			if (value_compare(node->value, x->value))
				x = x->left;
			else
				x = x->right;
		}
		node->parent = y;
		if (y == nullptr)
			this->root = node;
		else if (value_compare(node->value, y->value))
			y->left = node;
		else
			y->right = node;
		if (node->parent == nullptr)
		{
			node->color = 0;
			return;
		}
		if (node->parent->parent == nullptr)
			return;
		this->fix_insert(node);
		return (node);
	}

	TreeNode *find(value_type const &val)
	{
		return (this->search(this->root));
	}
};

#endif
