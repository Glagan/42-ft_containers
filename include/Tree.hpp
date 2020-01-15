/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:10:11 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/15 20:15:14 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <utility>

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
		bool color;

		static Node* get_parent(Node* n)
		{
			// Note that parent is set to null for the root node.
			return (n == nullptr ? nullptr : n->parent);
		}

		static Node* get_grand_parent(Node* n)
		{
			// Note that it will return nullptr if this is root or child of root
			return (get_parent(get_parent(n)));
		}

		static Node* get_sibling(Node* n)
		{
			Node* p = get_parent(n);
			// No parent means no sibling.
			if (p == nullptr)
				return (nullptr);
			if (n == p->left)
				return (p->right);
			return (p->left);
		}

		static Node* get_uncle(Node* n)
		{
			Node* p = get_parent(n);

			// No parent means no uncle
			return get_sibling(p);
		}

		static void rotate_left(Node* n)
		{
			Node* nnew = n->right;
			Node* p = get_parent(n);
			assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
										// they cannot become internal nodes.
			n->right = nnew->left;
			nnew->left = n;
			n->parent = nnew;
			// Handle other child/parent pointers.
			if (n->right != nullptr) {
				n->right->parent = n;
			}

			// Initially n could be the root.
			if (p != nullptr) {
				if (n == p->left) {
					p->left = nnew;
				} else if (n == p->right) {
					p->right = nnew;
				}
			}
			nnew->parent = p;
		}

		static void rotate_right(Node* n)
		{
			Node* nnew = n->left;
			Node* p = get_parent(n);
			assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
										// they cannot become internal nodes.

			n->left = nnew->right;
			nnew->right = n;
			n->parent = nnew;

			// Handle other child/parent pointers.
			if (n->left != nullptr) {
				n->left->parent = n;
			}

			// Initially n could be the root.
			if (p != nullptr) {
				if (n == p->left) {
					p->left = nnew;
				} else if (n == p->right) {
					p->right = nnew;
				}
			}
			nnew->parent = p;
		}

		static void insert_repair(Node* n)
		{
			if (get_parent(n) == nullptr) {
				n->color = 0;
			} else if (get_parent(n)->color == 0) {
				return ;
			} else if (get_uncle(n) != nullptr && get_uncle(n)->color == 1) {
				get_parent(n)->color = 0;
				get_uncle(n)->color = 0;
				get_grand_parent(n)->color = 1;
				insert_repair(get_grand_parent(n));
			} else {
				// Step 1
				Node* p = get_parent(n);
				Node* g = get_grand_parent(n);

				if (n == p->right && p == g->left) {
					rotate_left(p);
					n = n->left;
				} else if (n == p->left && p == g->right) {
					rotate_right(p);
					n = n->right;
				}

				// Step 2
				p = get_parent(n);
				g = get_grand_parent(n);

				if (n == p->left) {
					rotate_right(g);
				} else {
					rotate_left(g);
				}
				p->color = 0;
				g->color = 1;
			}
		}

		/*void ReplaceNode(Node* n, Node* child)
		{
			child->parent = n->parent;
			if (n == n->parent->left) {
				n->parent->left = child;
			} else {
				n->parent->right = child;
			}
		}

		void DeleteCase6(Node* n)
		{
			Node* s = get_sibling(n);

			s->color = n->parent->color;
			n->parent->color = 0;

			if (n == n->parent->left) {
				s->right->color = 0;
				rotate_left(n->parent);
			} else {
				s->left->color = 0;
				rotate_right(n->parent);
			}
		}

		void DeleteCase5(Node* n)
		{
			Node* s = get_sibling(n);

			// This if statement is trivial, due to case 2 (even though case 2 changed
			// the sibling to a sibling's child, the sibling's child can't be red, since
			// no red parent can have a red child).
			if (s->color == 0) {
				// The following statements just force the red to be on the left of the
				// left of the parent, or right of the right, so case six will rotate
				// correctly.
				if ((n == n->parent->left) && (s->right->color == 0) &&
					(s->left->color == 1)) {
					// This last test is trivial too due to cases 2-4.
					s->color = 1;
					s->left->color = 0;
					rotate_right(s);
				} else if ((n == n->parent->right) && (s->left->color == 0) &&
						(s->right->color == 1)) {
					// This last test is trivial too due to cases 2-4.
					s->color = 1;
					s->right->color = 0;
					rotate_left(s);
				}
			}
			DeleteCase6(n);
		}

		void DeleteCase4(Node* n)
		{
			Node* s = get_sibling(n);

			if ((n->parent->color == 1) && (s->color == 0) &&
				(s->left->color == 0) && (s->right->color == 0)) {
				s->color = 1;
				n->parent->color = 0;
			} else {
				DeleteCase5(n);
			}
		}

		void DeleteCase3(Node* n)
		{
			Node* s = get_sibling(n);

			if ((n->parent->color == 0) && (s->color == 0) &&
				(s->left->color == 0) && (s->right->color == 0)) {
				s->color = 1;
				DeleteCase1(n->parent);
			} else {
				DeleteCase4(n);
			}
		}

		void DeleteCase2(Node* n)
		{
			Node* s = get_sibling(n);

			if (s->color == 1) {
				n->parent->color = 1;
				s->color = 0;
				if (n == n->parent->left) {
					rotate_left(n->parent);
				} else {
					rotate_right(n->parent);
				}
			}
			DeleteCase3(n);
		}

		void DeleteCase1(Node* n)
		{
			if (n->parent != nullptr) {
				DeleteCase2(n);
			}
		}

		void DeleteOneChild(Node* n)
		{
			// Precondition: n has at most one non-leaf child.
			Node* child = (n->right == nullptr) ? n->left : n->right;
			assert(child);

			ReplaceNode(n, child);
			if (n->color == 0) {
				if (child->color == 1) {
					child->color = 0;
				} else {
					DeleteCase1(child);
				}
			}
			free(n);
		}*/
	public:
		Node():
			value(), parent(nullptr), left(nullptr), right(nullptr), color(0)
		{
		}
		Node(value_type const &value, bool color=1):
			value(value), parent(nullptr), left(nullptr), right(nullptr), color(color)
		{
		}
		Node(Node const &other):
			value(other.value), parent(other.parent), left(other.left), right(other.right), color(other.color)
		{
		}
		virtual ~Node()
		{
		}

		Node &operator=(Node const &other)
		{
			this->value = other.value;
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
			this->color = other.color;
			return (*this);
		}

		value_type &get_value(void)
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
private:
	void make_bounds(void)
	{
		this->begin_ = new Node;
		this->end_ = this->begin_;
		this->root = this->end_;
	}

	void repair_bounds(void)
	{
		Node *tmp = this->root;
		while (tmp->left)
			tmp = tmp->left;
		this->begin_ = tmp;
		this->root->parent = this->end_;
	}

	void insert_recurse(Node* root, Node* n) {
		// Recursively descend the tree until a leaf is found.
		if (root != nullptr)
		{
			if (n->value < root->value)
			{ // TODO: comp()
				if (root->left != nullptr)
				{
					this->insert_recurse(root->left, n);
					return;
				}
				else
					root->left = n;
			}
			else
			{ // n->key >= root->key
				if (root->right != nullptr)
				{
					this->insert_recurse(root->right, n);
					return;
				}
				else
					root->right = n;
			}
		}
		// Insert new Node n.
		n->parent = root;
	}

	void insert_at_root(Node* n) {
		this->root->parent = nullptr;
		// Insert new Node into the current tree.
		this->insert_recurse(this->root, n);
		// Repair the tree in case any of the red-black properties have been violated.
		Node::insert_repair(n);
		this->root = n;
		while (Node::get_parent(this->root) != nullptr)
			this->root = Node::get_parent(this->root);
		this->root = n;
		this->repair_bounds();
	}
protected:
	Node *root;
	Node *begin_;
	Node *end_;
	value_compare comp;
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
	virtual ~Tree() {}

	Tree &operator=(Tree const &other)
	{
		this->root = other.root;
		this->begin_ = other.begin_;
		this->end_ = other.end_;
		this->comp = other.comp;
		// TODO; Copy
		return (*this);
	}

	Node *insert(const_reference val)
	{
		Node *new_node = new Node(val);
		if (this->root == this->end_)
		{
			this->root = new_node;
			this->root->color = 0;
			this->begin_ = this->root;
			this->root->parent = this->end_;
		}
		else
			this->insert_at_root(new_node);
		return (new_node);
	}

	template<typename Tp>
	Node *find(Tp const &val)
	{
		return (this->find(val, this->root));
	}

	template<typename Tp>
	Node *find(Tp const &val, Node *node)
	{
		if (node == this->end_ || !node)
			return (nullptr);
		if (val == node->value.first)
			return (node);
		if (comp(val, node->value))
			return (this->find(val, node->left));
		return (this->find(val, node->right));
	}

	Node *begin_bound(void) const
	{
		return (this->begin_);
	}

	Node *end_bound(void) const
	{
		return (this->end_);
	}
};

#endif
