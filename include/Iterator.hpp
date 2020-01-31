/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:16:55 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/18 18:26:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "include/Node.hpp"

namespace ft
{
template<typename T>
class Iterator
{
public:
	typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const * const_pointer;
    typedef value_type& reference;
    typedef value_type const & const_reference;
    typedef std::ptrdiff_t difference_type;
protected:
	pointer p;
public:
	Iterator():
		p(nullptr) {}
	Iterator(pointer p):
		p(p) {}
	Iterator(Iterator const &other):
		p(other.p) {}
	virtual ~Iterator() {}

	Iterator &operator=(Iterator const &other)
	{
		this->p = other.p;
		return (*this);
	}

	reference operator*()
	{
		return (*this->p);
	}
	const_reference operator*() const
	{
		return (*this->p);
	}
	pointer operator->()
	{
		return (this->p);
	}
	const_pointer operator->() const
	{
		return (this->p);
	}
    reference operator[](int val)
	{
		return (*(this->p + val));
	}
    const_reference operator[](int val) const
	{
		return (*(this->p + val));
	}

	Iterator operator++(int)
	{
		Iterator tmp(*this);
		++this->p;
		return (tmp);
	}
	Iterator &operator++()
	{
		++this->p;
		return (*this);
	}
	Iterator operator--(int)
	{
		Iterator tmp(*this);
		--this->p;
		return (tmp);
	}
	Iterator &operator--()
	{
		--this->p;
		return (*this);
	}

	Iterator &operator+=(int value)
	{
		this->p += value;
		return (*this);
	}
	Iterator operator+(int value) const
	{
		Iterator tmp(*this);
		return (tmp += value);
	}
	Iterator &operator-=(int value)
	{
		this->p -= value;
		return (*this);
	}
	Iterator operator-(int value) const
	{
		Iterator tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(Iterator const &other) const
	{
		return (this->p - other.p);
	}

	bool operator==(Iterator const &other) const
	{
		return (this->p == other.p);
	}
	bool operator!=(Iterator const &other) const
	{
		return (this->p != other.p);
	}
	bool operator<(Iterator const &other) const
	{
		return (this->p < other.p);
	}
	bool operator<=(Iterator const &other) const
	{
		return (this->p <= other.p);
	}
	bool operator>(Iterator const &other) const
	{
		return (this->p > other.p);
	}
	bool operator>=(Iterator const &other) const
	{
		return (this->p >= other.p);
	}
};

template<typename T>
class ReverseIterator:
	virtual public Iterator<T>
{
public:
	using typename Iterator<T>::value_type;
    using typename Iterator<T>::pointer;
    using typename Iterator<T>::const_pointer;
    using typename Iterator<T>::reference;
    using typename Iterator<T>::const_reference;
    using typename Iterator<T>::difference_type;
public:
	ReverseIterator():
		Iterator<T>(nullptr) {}
	ReverseIterator(pointer p):
		Iterator<T>(p) {}
	ReverseIterator(Iterator<T> const &other):
		Iterator<T>(other) {}
	ReverseIterator(ReverseIterator const &other):
		Iterator<T>(other.p) {}
	virtual ~ReverseIterator() {}

	ReverseIterator &operator=(ReverseIterator const &other)
	{
		this->p = other.p;
		return (*this);
	}

	reference operator*()
	{
		Iterator<T> tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const
	{
		Iterator<T> tmp(*this);
		return (*--tmp);
	}
	pointer operator->()
	{
		Iterator<T> tmp(*this);
		return (&*--tmp);
	}
	const_pointer operator->() const
	{
		Iterator<T> tmp(*this);
		return (&*--tmp);
	}
	ReverseIterator operator++(int)
	{
		ReverseIterator tmp(*this);
		operator++();
		return (tmp);
	}
	ReverseIterator &operator++()
	{
		--this->p;
		return (*this);
	}
	ReverseIterator operator--(int)
	{
		ReverseIterator tmp(*this);
		operator--();
		return (tmp);
	}
	ReverseIterator &operator--()
	{
		++this->p;
		return (*this);
	}
};

template<typename T, typename N>
class ListIterator:
	virtual public Iterator<N>
{
public:
	typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const * const_pointer;
    typedef value_type& reference;
    typedef value_type const & const_reference;
	typedef N node_type;
	typedef node_type* node_pointer;
    typedef std::ptrdiff_t difference_type;
public:
	ListIterator():
		Iterator<node_type>(nullptr) {}
	ListIterator(node_pointer p):
		Iterator<node_type>(p) {}
	ListIterator(Iterator<node_type> const &other):
		Iterator<node_type>(other) {}
	ListIterator(ListIterator<value_type, node_type> const &other):
		Iterator<node_type>(other) {}
	virtual ~ListIterator() {}

	node_pointer as_node(void) const
	{
		return (this->p);
	}

	reference operator*()
	{
		return (this->p->value());
	}
	const_reference operator*() const
	{
		return (this->p->value());
	}
	pointer operator->()
	{
		return (&this->p->value());
	}
	const_pointer operator->() const
	{
		return (&this->p->value());
	}

	ListIterator &operator++()
	{
		this->p = this->p->next();
		return (*this);
	}
	ListIterator operator++(int)
	{
		ListIterator tmp(*this);
		this->p = this->p->next();
		return (tmp);
	}
	ListIterator &operator--()
	{
		this->p = this->p->previous();
		return (*this);
	}
	ListIterator operator--(int)
	{
		ListIterator tmp(*this);
		this->p = this->p->previous();
		return (tmp);
	}

	ListIterator &operator+=(int value)
	{
		if (value > 0)
		{
			for (int i = 0; i < value; i++)
				this->p = this->p->next();
		}
		else
		{
			for (int i = value; i > 0; i--)
				this->p = this->p->previous();
		}
	}
	ListIterator operator+(int value) const
	{
		ListIterator tmp(*this);
		return (tmp += value);
	}
	ListIterator &operator-=(int value)
	{
		operator+=(-value);
		return (*this);
	}
	ListIterator operator-(int value) const
	{
		ListIterator tmp(*this);
		return (tmp -= value);
	}
};

template<typename T, typename N>
class ReverseListIterator:
	virtual public ListIterator<T, N>,
	virtual public ReverseIterator<N>
{
public:
	using typename ListIterator<T, N>::value_type;
    using typename ListIterator<T, N>::pointer;
    using typename ListIterator<T, N>::const_pointer;
    using typename ListIterator<T, N>::reference;
    using typename ListIterator<T, N>::const_reference;
    using typename ListIterator<T, N>::node_type;
    using typename ListIterator<T, N>::node_pointer;
    using typename ListIterator<T, N>::difference_type;
public:
	ReverseListIterator():
		Iterator<node_type>(nullptr), ListIterator<value_type, node_type>(nullptr), ReverseIterator<node_type>(nullptr) {}
	ReverseListIterator(node_pointer p):
		Iterator<node_type>(p), ListIterator<value_type, node_type>(p), ReverseIterator<node_type>(p) {}
	ReverseListIterator(Iterator<node_type> const &other):
		Iterator<node_type>(other), ListIterator<value_type, node_type>(other), ReverseIterator<node_type>(other) {}
	ReverseListIterator(ReverseListIterator<value_type, node_type> const &other):
		Iterator<node_type>(other.p), ListIterator<value_type, node_type>(other.p), ReverseIterator<node_type>(other.p) {}
	virtual ~ReverseListIterator() {}

	ReverseListIterator &operator=(ReverseListIterator const &other)
	{
		this->p = other.p;
		return (*this);
	}

	reference operator*()
	{
		ListIterator<value_type, node_type> tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const
	{
		ListIterator<value_type, node_type> tmp(*this);
		return (*--tmp);
	}
	pointer operator->()
	{
		ListIterator<value_type, node_type> tmp(*this);
		return (&*--tmp);
	}
	const_pointer operator->() const
	{
		ListIterator<value_type, node_type> tmp(*this);
		return (&*--tmp);
	}
	ReverseListIterator operator++(int)
	{
		ReverseListIterator tmp(*this);
		operator++();
		return (tmp);
	}
	ReverseListIterator &operator++()
	{
		this->p = this->p->previous();
		return (*this);
	}
	ReverseListIterator operator--(int)
	{
		ReverseListIterator tmp(*this);
		operator--();
		return (tmp);
	}
	ReverseListIterator &operator--()
	{
		this->p = this->p->next();
		return (*this);
	}
};

template<typename T, typename N>
class TreeIterator:
	virtual public Iterator<N>
{
public:
	typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const * const_pointer;
    typedef value_type& reference;
    typedef value_type const & const_reference;
	typedef N node_type;
	typedef node_type* node_pointer;
    typedef std::ptrdiff_t difference_type;
protected:
	void previous()
	{
		//std::cout << "node " << this->p << ", parent " << this->p->parent << ", left " << this->p->left << ", right " << this->p->right << std::endl;
		if (this->p->left)
		{
			this->p = this->p->left;
			while (this->p->right)
				this->p = this->p->right;
		}
		else
			this->p = this->p->parent;
	}
	void next()
	{
		//std::cout << "node " << this->p << ", parent " << this->p->parent << ", left " << this->p->left << ", right " << this->p->right << std::endl;
		if (this->p->right)
		{
			this->p = this->p->right;
			while (this->p->left)
				this->p = this->p->left;
		}
		else
		{
			node_pointer tmp = this->p;
			this->p = this->p->parent;
			while (this->p->left != tmp)
			{
				tmp = this->p;
				this->p = this->p->parent;
			}
		}
	}
public:
	TreeIterator():
		Iterator<node_type>(nullptr) {}
	TreeIterator(node_pointer p):
		Iterator<node_type>(p) {}
	TreeIterator(TreeIterator const &other):
		Iterator<node_type>(other.p) {}
	TreeIterator(Iterator<node_type> const &other):
		Iterator<node_type>(other) {}
	virtual ~TreeIterator() {}

	node_pointer as_node(void) const
	{
		return (this->p);
	}

	TreeIterator &operator=(TreeIterator const &other)
	{
		this->p = other.p;
		return (*this);
	}

	reference operator*()
	{
		return (this->p->value);
	}
	const_reference operator*() const
	{
		return (this->p->value);
	}
	pointer operator->()
	{
		return (&this->p->value);
	}
	const_pointer operator->() const
	{
		return (&this->p->value);
	}

	TreeIterator operator++(int)
	{
		TreeIterator tmp(*this);
		this->next();
		return (tmp);
	}
	TreeIterator &operator++()
	{
		this->next();
		return (*this);
	}
	TreeIterator operator--(int)
	{
		TreeIterator tmp(*this);
		this->previous();
		return (tmp);
	}
	TreeIterator &operator--()
	{
		this->previous();
		return (*this);
	}

	TreeIterator &operator+=(int value)
	{
		if (value > 0)
		{
			for (int i = 0; i < value; i++)
				this->next();
		}
		else
		{
			for (int i = value; i > 0; i--)
				this->previous();
		}
		return (*this);
	}
	TreeIterator operator+(int value) const
	{
		TreeIterator tmp(*this);
		return (tmp += value);
	}
	TreeIterator &operator-=(int value)
	{
		operator+=(-value);
		return (*this);
	}
	TreeIterator operator-(int value) const
	{
		TreeIterator tmp(*this);
		return (tmp -= value);
	}
};

template<typename T, typename N>
class ReverseTreeIterator:
	virtual public TreeIterator<T, N>,
	virtual public ReverseIterator<N>
{
public:
	using typename TreeIterator<T, N>::value_type;
    using typename TreeIterator<T, N>::pointer;
    using typename TreeIterator<T, N>::const_pointer;
    using typename TreeIterator<T, N>::reference;
    using typename TreeIterator<T, N>::const_reference;
    using typename TreeIterator<T, N>::node_type;
    using typename TreeIterator<T, N>::node_pointer;
    using typename TreeIterator<T, N>::difference_type;
public:
	ReverseTreeIterator():
		Iterator<node_type>(nullptr), TreeIterator<value_type, node_type>(nullptr), ReverseIterator<node_type>(nullptr) {}
	ReverseTreeIterator(pointer p):
		Iterator<node_type>(p), TreeIterator<value_type, node_type>(p), ReverseIterator<node_type>(p) {}
	ReverseTreeIterator(Iterator<node_type> const &other):
		Iterator<node_type>(other), TreeIterator<value_type, node_type>(other), ReverseIterator<node_type>(other) {}
	ReverseTreeIterator(ReverseTreeIterator<value_type, node_type> const &other):
		Iterator<node_type>(other.p), TreeIterator<value_type, node_type>(other.p), ReverseIterator<node_type>(other.p) {}
	virtual ~ReverseTreeIterator() {}

	ReverseTreeIterator &operator=(ReverseTreeIterator const &other)
	{
		this->p = other.p;
		return (*this);
	}

	reference operator*()
	{
		TreeIterator<value_type, node_type> tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const
	{
		TreeIterator<value_type, node_type> tmp(*this);
		return (*--tmp);
	}
	pointer operator->()
	{
		TreeIterator<value_type, node_type> tmp(*this);
		return (&*--tmp);
	}
	const_pointer operator->() const
	{
		TreeIterator<value_type, node_type> tmp(*this);
		return (&*--tmp);
	}
	ReverseTreeIterator operator++(int)
	{
		ReverseTreeIterator tmp(*this);
		operator++();
		return (tmp);
	}
	ReverseTreeIterator &operator++()
	{
		this->previous();
		return (*this);
	}
	ReverseTreeIterator operator--(int)
	{
		ReverseTreeIterator tmp(*this);
		operator--();
		return (tmp);
	}
	ReverseTreeIterator &operator--()
	{
		this->next();
		return (*this);
	}
};
}

#endif
