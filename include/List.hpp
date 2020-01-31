/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:49 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/15 15:22:52 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include "include/Node.hpp"
# include "include/Iterator.hpp"
# include "include/Algorithm.hpp"

namespace ft
{
template<typename T>
class List
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef Node<value_type> node_type;
	typedef node_type* node_pointer;
	typedef value_type* pointer;
	typedef value_type const *const_pointer;
	typedef value_type& reference;
	typedef value_type const &const_reference;
	typedef ListIterator<value_type, node_type> iterator;
	typedef ListIterator<value_type const, node_type const> const_iterator;
	typedef ReverseListIterator<value_type, node_type> reverse_iterator;
	typedef ReverseListIterator<value_type const, node_type const> const_reverse_iterator;
private:
	node_pointer begin_;
	node_pointer end_;
	size_type size_;

	void make_bounds(void)
	{
		this->end_ = new Node<value_type>();
		this->reset_bounds();
	}
	void reset_bounds(void)
	{
		this->begin_ = this->end_;
		this->end_->previous() = nullptr;
		this->end_->next() = nullptr;
	}
public:
	List():
		begin_(nullptr), end_(nullptr), size_(0)
	{
		this->make_bounds();
	}
	List(size_type n, const_reference val=value_type()):
		begin_(nullptr), end_(nullptr), size_(0)
	{
		this->make_bounds();
		this->assign(n, val);
	}
	List(iterator first, iterator last):
		begin_(nullptr), end_(nullptr), size_(0)
	{
		this->make_bounds();
		this->assign(first, last);
	}
	List(List const &other):
		begin_(nullptr), end_(nullptr), size_(0)
	{
		this->make_bounds();
		this->assign(other.begin(), other.end());
	}
	virtual ~List()
	{
		this->clear();
		delete this->end_;
	}

	List &operator=(List const &other)
	{
		this->assign(other.begin(), other.end());
		return (*this);
	}

	iterator begin(void)
	{
		return (iterator(this->begin_));
	}
	const_iterator begin(void) const
	{
		return (const_iterator(this->begin_));
	}
	reverse_iterator rbegin(void)
	{
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const
	{
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void)
	{
		return (iterator(this->end_));
	}
	const_iterator end(void) const
	{
		return (const_iterator(this->end_));
	}
	reverse_iterator rend(void)
	{
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const
	{
		return (const_reverse_iterator(this->begin()));
	}

	bool empty(void) const
	{
		return (this->size_ == 0);
	}
	size_type size(void) const
	{
		return (this->size_);
	}
	size_type max_size(void) const
	{
		return (((std::pow(2, 64) - 1) / sizeof(Node<value_type>)) - 1);
	}

	reference front()
	{
		return (this->begin_->value());
	}
	const_reference front() const
	{
		return (this->begin_->value());
	}
	reference back()
	{
		return (this->end_->previous()->value());
	}
	const_reference back() const
	{
		return (this->end_->previous()->value());
	}

	void assign(iterator first, iterator last)
	{
		this->clear();
		while (first != last)
			this->push_back(*first++);
	}
	void assign(const_iterator first, const_iterator last)
	{
		this->clear();
		while (first != last)
			this->push_back(*first++);
	}
	void assign(size_type size, const_reference val)
	{
		this->clear();
		for (size_type i = 0; i < size; i++)
			this->push_back(val);
	}

	void push_front(const_reference val)
	{
		node_pointer tmp = new node_type(val);
		if (this->size_ == 0)
			this->end_->insert_before(tmp);
		else
			this->begin_->insert_before(tmp);
		this->begin_ = tmp;
		++this->size_;
	}
	void pop_front(void)
	{
		if (this->size_ == 1)
		{
			delete this->begin_;
			this->begin_ = this->end_;
			this->end_->previous() = nullptr;
		}
		else if (this->size_ >= 1)
		{
			node_pointer tmp = this->begin_->next();
			this->begin_->disconnect();
			delete this->begin_;
			this->begin_ = tmp;
		}
		--this->size_;
	}
	void push_back(const_reference val)
	{
		node_pointer tmp = new node_type(val);
		this->end_->insert_before(tmp);
		if (this->size_ == 0)
			this->begin_ = tmp;
		++this->size_;
	}
	void pop_back(void)
	{
		if (this->size_ == 1)
			this->pop_front();
		else if (this->size_ >= 1)
		{
			node_pointer tmp = this->end_->previous();
			this->end_->previous()->disconnect();
			delete tmp;
			--this->size_;
		}
	}

	iterator insert(iterator position, const_reference val)
	{
		if (position == this->begin())
		{
			this->push_front(val);
			return (this->begin());
		}
		else if (position == this->end())
		{
			this->push_back(val);
			return (this->end());
		}
		node_pointer newNode = new node_type(val);
		position.as_node()->insert_before(newNode);
		++this->size_;
		return (iterator(newNode));
	}
	void insert(iterator position, size_type size, const_reference val)
	{
		for (size_type i = 0; i < size; i++)
			this->insert(position, val);
	}
	void insert(iterator position, iterator first, List::iterator last)
	{
		while (first != last)
			this->insert(position, *first++);
	}

	iterator erase(iterator position)
	{
		if (position == this->begin())
		{
			this->pop_front();
			return (this->begin());
		}
		else if (position == this->end())
		{
			this->pop_back();
			return (this->end());
		}
		node_pointer next = position.as_node()->next();
		position.as_node()->disconnect();
		delete position.as_node();
		--this->size_;
		return (iterator(next));
	}
	iterator erase(iterator first, iterator last)
	{
		while (first != last)
			this->erase(first++);
		return (first);
	}

	void swap(List &other)
	{
		node_pointer tmp = this->begin_;
		this->begin_ = other.begin_;
		other.begin_ = tmp;
		tmp = this->end_;
		this->end_ = other.end_;
		other.end_ = tmp;
		size_type stmp = this->size_;
		this->size_ = other.size_;
		other.size_ = stmp;
	}

	void resize(size_type n, value_type val=value_type())
	{
		if (n == 0)
			this->clear();
		else if (n < this->size_)
		{
			size_t i = 0;
			iterator first = this->begin();
			while (i < n)
			{
				++i;
				++first;
			}
			this->erase(first, this->end());
		}
		else
			this->insert(this->end(), n - this->size_, val);
	}

	void clear(void)
	{
		this->erase(this->begin(), this->end());
		this->reset_bounds();
	}

	void splice(iterator position, List &x)
	{
		this->splice(position, x, x.begin(), x.end());
	}
	void splice(iterator position, List &x, iterator it)
	{
		iterator next = it;
		this->splice(position, x, it, ++next);
	}
	void splice(iterator position, List &x, iterator first, iterator last)
	{
		while (first != last)
		{
			node_pointer tmp = first++.as_node();
			if (tmp == x.begin_)
				x.begin_ = tmp->next();
			tmp->disconnect();
			position.as_node()->insert_before(tmp);
			if (position.as_node() == this->begin_)
				this->begin_ = tmp;
			++this->size_;
			--x.size_;
		}
		if (x.size_ == 0)
			x.reset_bounds();
	}

	void remove(const_reference val)
	{
		iterator first = this->begin();
		iterator last = this->end();

		while (first != last)
		{
			if (*first == val)
				first = this->erase(first);
			else
				++first;
		}
	}
	template<typename Predicate>
	void remove_if(Predicate pred)
	{
		iterator first = this->begin();
		iterator last = this->end();

		while (first != last)
		{
			if ((*pred)(*first))
				first = this->erase(first);
			else
				++first;
		}
	}

	void unique(void)
	{
		this->unique(&equal<value_type>);
	}
	template<typename BinaryPredicate>
	void unique(BinaryPredicate binary_pred)
	{
		iterator previous = this->begin();
		iterator next = previous;
		iterator last = this->end();

		++next;
		while (next != last)
		{
			if ((*binary_pred)(*next, *previous++))
				next = this->erase(next);
			else
				++next;
		}
	}

	void merge(List &x)
	{
		if (&x == this)
			return ;
		this->merge(x, &less_than<value_type>);
	}
	template<typename Compare>
	void merge(List &x, Compare comp)
	{
		if (&x == this)
			return ;
		if (this->size_ == 0)
		{
			this->assign(x.begin(), x.end());
			x.clear();
			return ;
		}
		iterator otherFirst = x.begin();
		iterator next = otherFirst;
		iterator otherLast = x.end();

		while (next != otherLast)
		{
			iterator first = this->begin();
			iterator last = this->end();

			otherFirst = next++;
			while (first != last)
			{
				if ((*comp)(*otherFirst, *first))
					break ;
				++first;
			}
			otherFirst.as_node()->disconnect();
			first.as_node()->insert_before(otherFirst.as_node());
			if (first == this->begin())
				this->begin_ = this->begin_->previous();
			++this->size_;
		}
		x.size_ = 0;
		x.reset_bounds();
	}

	void sort(void)
	{
		if (this->size_ <= 1)
			return ;
		this->sort(&less_than<value_type>);
	}
	template<typename Compare>
	void sort(Compare comp)
	{
		if (this->size_ <= 1)
			return ;
		iterator first = this->begin();
		iterator last = this->end();
		iterator next;
		iterator tmp;

		while (first != last)
		{
			next = first;
			while (++next != last)
			{
				if ((*comp)(*next, *first))
				{
					if (first.as_node() == this->begin_)
						this->begin_ = next.as_node();
					first.as_node()->swap(next.as_node());
					tmp = next;
					next = first;
					first = tmp;
				}
			}
			++first;
		}
	}

	void reverse(void)
	{
		if (this->size_ <= 1)
			return ;
		size_t limit = this->size_ / 2;
		iterator first = this->begin();
		iterator last = this->end();

		this->begin_ = this->end_->previous();
		for (size_t i = 0; i < limit; i++)
		{
			--last;
			first++.as_node()->swap(last--.as_node());
		}
	}
};

template<typename value_type>
bool operator==(List<value_type> const &lhs, List<value_type> const &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator!=(List<T> const &lhs, List<T> const &rhs)
{
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(List<T> const &lhs, List<T> const &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(List<T> const &lhs, List<T> const &rhs)
{
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(List<T> const &lhs, List<T> const &rhs)
{
	return (rhs < lhs);
}

template<typename T>
bool operator>=(List<T> const &lhs, List<T> const &rhs)
{
	return (!(lhs < rhs));
}

template<typename T>
void swap(List<T> &x, List<T> &y)
{
	x.swap(y);
}
}

#endif
