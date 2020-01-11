/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 17:59:56 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
template<typename value_type>
List<value_type>::iterator::iterator():
	pointer(nullptr)
{
}

template<typename value_type>
List<value_type>::iterator::iterator(Node<value_type> *val):
	pointer(val)
{
}

template<typename value_type>
List<value_type>::iterator::iterator(List<value_type>::iterator const &other):
	pointer(other.pointer)
{
}

template<typename value_type>
typename List<value_type>::iterator &List<value_type>::iterator::operator=(List<value_type>::iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
Node<value_type> *List<value_type>::iterator::as_node(void) const
{
	return (this->pointer);
}

template<typename value_type>
List<value_type>::iterator::~iterator()
{
}

template<typename value_type>
value_type &List<value_type>::iterator::operator*() const
{
	return (this->pointer->value());
}

template<typename value_type>
value_type *List<value_type>::iterator::operator->() const
{
	return (&this->pointer->value());
}

template<typename value_type>
bool List<value_type>::iterator::operator==(iterator const &other) const
{
	return (this->pointer == other.pointer);
}

template<typename value_type>
bool List<value_type>::iterator::operator!=(iterator const &other) const
{
	return (this->pointer != other.pointer);
}

template<typename value_type>
bool List<value_type>::iterator::operator<(iterator const &other) const
{
	return (this->pointer < other.pointer);
}

template<typename value_type>
bool List<value_type>::iterator::operator<=(iterator const &other) const
{
	return (this->pointer <= other.pointer);
}

template<typename value_type>
bool List<value_type>::iterator::operator>(iterator const &other) const
{
	return (this->pointer > other.pointer);
}

template<typename value_type>
bool List<value_type>::iterator::operator>=(iterator const &other) const
{
	return (this->pointer >= other.pointer);
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::iterator::operator++(int)
{
	iterator tmp(*this);
	operator++();
	return (tmp);
}

template<typename value_type>
typename List<value_type>::iterator &List<value_type>::iterator::operator++()
{
	this->pointer = this->pointer->next();
	return (*this);
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::iterator::operator--(int)
{
	iterator tmp(*this);
	operator--();
	return (tmp);
}

template<typename value_type>
typename List<value_type>::iterator &List<value_type>::iterator::operator--()
{
	this->pointer = this->pointer->previous();
	return (*this);
}

template<typename value_type>
typename List<value_type>::iterator& List<value_type>::iterator::operator+=(int value)
{
	if (value > 0)
	{
		for (int i = 0; i < value; i++)
			++this->pointer;
	}
	else
	{
		for (int i = value; i > 0; i--)
			--this->pointer;
	}
	return (*this);
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::iterator::operator+(int value) const
{
	iterator tmp(*this);
	tmp += value;
	return (tmp);
}

template<typename value_type>
typename List<value_type>::iterator& List<value_type>::iterator::operator-=(int value)
{
	this->pointer += -value;
	return (*this);
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::iterator::operator-(int value) const
{
	iterator tmp(*this);
	tmp -= value;
	return (tmp);
}

template<typename value_type>
List<value_type>::const_iterator::const_iterator():
	pointer(nullptr)
{
}

template<typename value_type>
List<value_type>::const_iterator::const_iterator(Node<value_type> const *val):
	pointer(val)
{
}

template<typename value_type>
List<value_type>::const_iterator::const_iterator(List<value_type>::const_iterator const &other):
	pointer(other.pointer)
{
}

template<typename value_type>
List<value_type>::const_iterator::const_iterator(List<value_type>::iterator const &other):
	pointer(other.pointer)
{
}

template<typename value_type>
typename List<value_type>::const_iterator &List<value_type>::const_iterator::operator=(List<value_type>::const_iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
Node<value_type> const *List<value_type>::const_iterator::as_node(void) const
{
	return (this->pointer);
}

template<typename value_type>
List<value_type>::const_iterator::~const_iterator()
{
}

template<typename value_type>
value_type const &List<value_type>::const_iterator::operator*() const
{
	return (this->pointer->value());
}

template<typename value_type>
value_type const *List<value_type>::const_iterator::operator->() const
{
	return (&this->pointer->value());
}

template<typename value_type>
bool List<value_type>::const_iterator::operator==(const_iterator const &other) const
{
	return (this->pointer == other.pointer);
}

template<typename value_type>
bool List<value_type>::const_iterator::operator!=(const_iterator const &other) const
{
	return (this->pointer != other.pointer);
}

template<typename value_type>
bool List<value_type>::const_iterator::operator<(const_iterator const &other) const
{
	return (this->pointer < other.pointer);
}

template<typename value_type>
bool List<value_type>::const_iterator::operator<=(const_iterator const &other) const
{
	return (this->pointer <= other.pointer);
}

template<typename value_type>
bool List<value_type>::const_iterator::operator>(const_iterator const &other) const
{
	return (this->pointer > other.pointer);
}

template<typename value_type>
bool List<value_type>::const_iterator::operator>=(const_iterator const &other) const
{
	return (this->pointer >= other.pointer);
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::const_iterator::operator++(int)
{
	const_iterator tmp(*this);
	operator++();
	return (tmp);
}

template<typename value_type>
typename List<value_type>::const_iterator &List<value_type>::const_iterator::operator++()
{
	this->pointer = this->pointer->next();
	return (*this);
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::const_iterator::operator--(int)
{
	const_iterator tmp(*this);
	operator--();
	return (tmp);
}

template<typename value_type>
typename List<value_type>::const_iterator &List<value_type>::const_iterator::operator--()
{
	this->pointer = this->pointer->previous();
	return (*this);
}

template<typename value_type>
typename List<value_type>::const_iterator& List<value_type>::const_iterator::operator+=(int value)
{
	if (value > 0)
	{
		for (int i = 0; i < value; i++)
			++this->pointer;
	}
	else
	{
		for (int i = value; i > 0; i--)
			--this->pointer;
	}
	return (*this);
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::const_iterator::operator+(int value) const
{
	const_iterator tmp(*this);
	tmp += value;
	return (tmp);
}

template<typename value_type>
typename List<value_type>::const_iterator& List<value_type>::const_iterator::operator-=(int value)
{
	this->pointer += -value;
	return (*this);
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::const_iterator::operator-(int value) const
{
	const_iterator tmp(*this);
	tmp -= value;
	return (tmp);
}

template<typename value_type>
List<value_type>::reverse_iterator::reverse_iterator():
	iterator(nullptr)
{
}

template<typename value_type>
List<value_type>::reverse_iterator::reverse_iterator(Node<value_type> *val):
	iterator(val)
{
}

template<typename value_type>
List<value_type>::reverse_iterator::reverse_iterator(List<value_type>::reverse_iterator const &other):
	iterator(other.pointer)
{
}

template<typename value_type>
List<value_type>::reverse_iterator::reverse_iterator(List<value_type>::iterator const &other):
	iterator(other)
{
}

template<typename value_type>
typename List<value_type>::reverse_iterator &List<value_type>::reverse_iterator::operator=(List<value_type>::reverse_iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
List<value_type>::reverse_iterator::~reverse_iterator()
{
}

template<typename value_type>
value_type &List<value_type>::reverse_iterator::operator*() const
{
	return (this->pointer->previous()->value());
}

template<typename value_type>
value_type *List<value_type>::reverse_iterator::operator->() const
{
	return (&this->pointer->previous()->value());
}

template<typename value_type>
typename List<value_type>::reverse_iterator List<value_type>::reverse_iterator::operator++(int)
{
	reverse_iterator tmp(*this);
	operator++();
	return (tmp);
}

template<typename value_type>
typename List<value_type>::reverse_iterator &List<value_type>::reverse_iterator::operator++()
{
	this->pointer = this->pointer->previous();
	return (*this);
}

template<typename value_type>
typename List<value_type>::reverse_iterator List<value_type>::reverse_iterator::operator--(int)
{
	reverse_iterator tmp(*this);
	operator--();
	return (tmp);
}

template<typename value_type>
typename List<value_type>::reverse_iterator &List<value_type>::reverse_iterator::operator--()
{
	this->pointer = this->pointer->next();
	return (*this);
}


template<typename value_type>
List<value_type>::const_reverse_iterator::const_reverse_iterator():
	const_iterator(nullptr), reverse_iterator(nullptr)
{
}

template<typename value_type>
List<value_type>::const_reverse_iterator::const_reverse_iterator(Node<value_type> const *val):
	const_iterator(val), reverse_iterator(val)
{
}

template<typename value_type>
List<value_type>::const_reverse_iterator::const_reverse_iterator(List<value_type>::const_reverse_iterator const &other):
	const_iterator(other.pointer), reverse_iterator(other.pointer)
{
}

template<typename value_type>
List<value_type>::const_reverse_iterator::const_reverse_iterator(List<value_type>::reverse_iterator const &other):
	const_iterator(other.pointer), reverse_iterator(other.pointer)
{
}

template<typename value_type>
typename List<value_type>::const_reverse_iterator &List<value_type>::const_reverse_iterator::operator=(List<value_type>::const_reverse_iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
List<value_type>::const_reverse_iterator::~const_reverse_iterator()
{
}

template<typename value_type>
value_type const &List<value_type>::const_reverse_iterator::operator*() const
{
	const_iterator tmp(*this);
	return (*--tmp);
}

template<typename value_type>
value_type const *List<value_type>::const_reverse_iterator::operator->() const
{
	iterator tmp(*this);
	return (&*--tmp);
}

template<typename value_type>
List<value_type>::List():
	begin_(nullptr), end_(nullptr), size_(0)
{
	this->make_bounds();
}

template<typename value_type>
List<value_type>::List(size_t n, value_type const &val):
	begin_(nullptr), end_(nullptr), size_(0)
{
	this->make_bounds();
	this->assign(n, val);
}

template<typename value_type>
List<value_type>::List(List<value_type>::iterator first, List<value_type>::iterator last):
	begin_(nullptr), end_(nullptr), size_(0)
{
	this->make_bounds();
	this->assign(first, last);
}

template<typename value_type>
List<value_type>::List(List<value_type> const &other):
	begin_(nullptr), end_(nullptr), size_(0)
{
	this->make_bounds();
	this->assign(other.begin(), other.end());
}

template<typename value_type>
List<value_type>::~List()
{
	this->clear();
	delete this->end_;
}

template<typename value_type>
void List<value_type>::make_bounds(void)
{
	this->end_ = new Node<value_type>();
	this->reset_bounds();
}

template<typename value_type>
void List<value_type>::reset_bounds(void)
{
	this->begin_ = this->end_;
	this->end_->previous() = nullptr;
	this->end_->next() = nullptr;
}

template<typename value_type>
List<value_type> &List<value_type>::operator=(List<value_type> const &other)
{
	this->assign(other.begin(), other.end());
	return (*this);
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::begin(void)
{
	return (List<value_type>::iterator(this->begin_));
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::begin(void) const
{
	return (List<value_type>::const_iterator(this->begin_));
}

template<typename value_type>
typename List<value_type>::reverse_iterator List<value_type>::rbegin(void)
{
	return (List<value_type>::reverse_iterator(this->end()));
}

template<typename value_type>
typename List<value_type>::const_reverse_iterator List<value_type>::rbegin(void) const
{
	return (List<value_type>::const_reverse_iterator(this->end()));
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::end(void)
{
	return (List<value_type>::iterator(this->end_));
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::end(void) const
{
	return (List<value_type>::const_iterator(this->end_));
}

template<typename value_type>
typename List<value_type>::reverse_iterator List<value_type>::rend(void)
{
	return (List<value_type>::reverse_iterator(this->begin()));
}

template<typename value_type>
typename List<value_type>::const_reverse_iterator List<value_type>::rend(void) const
{
	return (List<value_type>::const_reverse_iterator(this->begin()));
}

template<typename value_type>
bool List<value_type>::empty(void) const
{
	return (this->size_ == 0);
}

template<typename value_type>
size_t List<value_type>::size(void) const
{
	return (this->size_);
}

template<typename value_type>
size_t List<value_type>::max_size(void) const
{
	return (((std::pow(2, 64) - 1) / ((sizeof(Node<value_type>) * 2) + sizeof(value_type))) - 1);
}

template<typename value_type>
value_type &List<value_type>::front()
{
	return (this->begin_->value());
}

template<typename value_type>
value_type const &List<value_type>::front() const
{
	return (this->begin_->value());
}

template<typename value_type>
value_type &List<value_type>::back()
{
	return (this->end_->previous()->value());
}

template<typename value_type>
value_type const &List<value_type>::back() const
{
	return (this->end_->previous()->value());
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::iterator first, List<value_type>::iterator last)
{
	this->clear();
	while (first != last)
		this->push_back(*first++);
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::const_iterator first, List<value_type>::const_iterator last)
{
	this->clear();
	while (first != last)
		this->push_back(*first++);
}

template<typename value_type>
void List<value_type>::assign(size_t size, value_type const &val)
{
	this->clear();
	for (size_t i = 0; i < size; i++)
		this->push_back(val);
}

template<typename value_type>
void List<value_type>::push_front(value_type const &val)
{
	Node<value_type> *tmp = new Node<value_type>(val);
	if (this->size_ == 0)
		this->end_->insert_before(tmp);
	else
		this->begin_->insert_before(tmp);
	this->begin_ = tmp;
	++this->size_;
}

template<typename value_type>
void List<value_type>::pop_front(void)
{
	if (this->size_ == 1)
	{
		delete this->begin_;
		this->begin_ = this->end_;
		this->end_->previous() = nullptr;
	}
	else if (this->size_ >= 1)
	{
		Node<value_type> *tmp = this->begin_->next();
		this->begin_->disconnect();
		delete this->begin_;
		this->begin_ = tmp;
	}
	--this->size_;
}

template<typename value_type>
void List<value_type>::push_back(value_type const &val)
{
	Node<value_type> *tmp = new Node<value_type>(val);
	this->end_->insert_before(tmp);
	if (this->size_ == 0)
		this->begin_ = tmp;
	++this->size_;
}

template<typename value_type>
void List<value_type>::pop_back(void)
{
	if (this->size_ == 1)
		this->pop_front();
	else if (this->size_ >= 1)
	{
		Node<value_type> *tmp = this->end_->previous();
		this->end_->previous()->disconnect();
		delete tmp;
		--this->size_;
	}
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::insert(List<value_type>::iterator position, value_type const &val)
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
	Node<value_type> *newNode = new Node<value_type>(val);
	position.as_node()->insert_before(newNode);
	++this->size_;
	return (List<value_type>::iterator(newNode));
}

template<typename value_type>
void List<value_type>::insert(List<value_type>::iterator position, size_t size, value_type const &val)
{
	for (size_t i = 0; i < size; i++)
		this->insert(position, val);
}

template<typename value_type>
void List<value_type>::insert(List<value_type>::iterator position, List::iterator first, List::iterator last)
{
	while (first != last)
		this->insert(position, *first++);
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator position)
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
	Node<value_type> *next = position.as_node()->next();
	position.as_node()->disconnect();
	delete position.as_node();
	--this->size_;
	return (List<value_type>::iterator(next));
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator first, List<value_type>::iterator last)
{
	while (first != last)
		this->erase(first++);
	return (first);
}

template<typename value_type>
void List<value_type>::swap(List<value_type> &other)
{
	(void)other;
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::resize(size_t n, value_type val)
{
	if (n == 0)
		this->clear();
	else if (n < this->size_)
	{
		size_t i = 0;
		List<value_type>::iterator first = this->begin();
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

template<typename value_type>
void List<value_type>::clear(void)
{
	this->erase(this->begin(), this->end());
	this->reset_bounds();
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x)
{
	this->splice(position, x, x.begin(), x.end());
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x, List<value_type>::iterator it)
{
	List<value_type>::iterator next = it;
	this->splice(position, x, it, ++next);
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x, List<value_type>::iterator first, List<value_type>::iterator last)
{
	while (first != last)
	{
		Node<value_type> *tmp = first++.as_node();
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

template<typename value_type>
bool List<value_type>::value_equal(value_type const &a, value_type const &b)
{
	return (a == b);
}

template<typename value_type>
void List<value_type>::remove(value_type const &val)
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();

	while (first != last)
	{
		if (*first == val)
			first = this->erase(first);
		else
			++first;
	}
}

template<typename value_type>
template<typename Predicate>
void List<value_type>::remove_if(Predicate pred)
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();

	while (first != last)
	{
		if ((*pred)(*first))
			first = this->erase(first);
		else
			++first;
	}
}

template<typename value_type>
void List<value_type>::unique(void)
{
	this->unique(&List<value_type>::value_equal);
}

template<typename value_type>
template<typename BinaryPredicate>
void List<value_type>::unique(BinaryPredicate binary_pred)
{
	List<value_type>::iterator previous = this->begin();
	List<value_type>::iterator next = previous;
	List<value_type>::iterator last = this->end();

	++next;
	while (next != last)
	{
		if ((*binary_pred)(*next, *previous++))
			next = this->erase(next);
		else
			++next;
	}
}

template<typename value_type>
bool List<value_type>::value_less(value_type const &a, value_type const &b)
{
	return (a < b);
}

template<typename value_type>
void List<value_type>::merge(List &x)
{
	if (&x == this)
		return ;
	this->merge(x, &List<value_type>::value_less);
}

template<typename value_type>
template<typename Compare>
void List<value_type>::merge(List &x, Compare comp)
{
	if (&x == this)
		return ;
	if (this->size_ == 0)
	{
		this->assign(x.begin(), x.end());
		x.clear();
		return ;
	}
	List<value_type>::iterator otherFirst = x.begin();
	List<value_type>::iterator next = otherFirst;
	List<value_type>::iterator otherLast = x.end();

	while (next != otherLast)
	{
		List<value_type>::iterator first = this->begin();
		List<value_type>::iterator last = this->end();

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

template<typename value_type>
void List<value_type>::sort(void)
{
	if (this->size_ <= 1)
		return ;
	this->sort(&List<value_type>::value_less);
}

template<typename value_type>
template<typename Compare>
void List<value_type>::sort(Compare comp)
{
	if (this->size_ <= 1)
		return ;
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();
	List<value_type>::iterator next;
	List<value_type>::iterator tmp;

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

template<typename value_type>
void List<value_type>::reverse(void)
{
	if (this->size_ <= 1)
		return ;
	size_t limit = this->size_ / 2;
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();

	this->begin_ = this->end_->previous();
	for (size_t i = 0; i < limit; i++)
	{
		--last;
		first++.as_node()->swap(last--.as_node());
	}
}

template<typename T>
bool operator==(List<T> const &lhs, List<T> const &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename List<T>::const_iterator first1 = lhs.begin();
	typename List<T>::const_iterator last1 = lhs.end();
	typename List<T>::const_iterator first2 = rhs.begin();
	typename List<T>::const_iterator last2 = rhs.end();
	while (first1 != last1)
		if (*first1++ != *first2++)
			return (false);
	return (true);
}

template<typename value_type>
bool operator!=(List<value_type> const &lhs, List<value_type> const &rhs)
{
	return (!(lhs == rhs));
}

template<typename value_type>
bool operator<(List<value_type> const &lhs, List<value_type> const &rhs)
{
	typename List<value_type>::const_iterator first1 = lhs.begin();
	typename List<value_type>::const_iterator last1 = lhs.end();
	typename List<value_type>::const_iterator first2 = rhs.begin();
	typename List<value_type>::const_iterator last2 = rhs.end();

	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < *first2)
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template<typename value_type>
bool operator<=(List<value_type> const &lhs, List<value_type> const &rhs)
{
	return (!(rhs < lhs));
}

template<typename value_type>
bool operator>(List<value_type> const &lhs, List<value_type> const &rhs)
{
	return (rhs < lhs);
}

template<typename value_type>
bool operator>=(List<value_type> const &lhs, List<value_type> const &rhs)
{
	return (!(lhs < rhs));
}
}
