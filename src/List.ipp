/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/08 19:27:35 by ncolomer         ###   ########.fr       */
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
	iterator tmp(*this);
	return (*--tmp);
}

template<typename value_type>
value_type *List<value_type>::reverse_iterator::operator->() const
{
	iterator tmp(*this);
	return (&*--tmp);
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
}

template<typename value_type>
List<value_type>::List(size_t n, value_type const &val):
	begin_(nullptr), end_(nullptr), size_(0)
{
	this->assign(n, val);
}

template<typename value_type>
List<value_type>::List(List<value_type>::iterator first, List<value_type>::iterator last):
	begin_(nullptr), end_(nullptr), size_(0)
{
	this->assign(first, last);
}

template<typename value_type>
List<value_type>::List(List<value_type> const &other):
	begin_(nullptr), end_(nullptr), size_(0)
{
	this->assign(other.begin(), other.end());
}

template<typename value_type>
List<value_type>::~List()
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();
	Node<value_type> *tmp;

	while (first != last)
	{
		tmp = *first++;
		delete tmp;
	}
}

template<typename value_type>
List<value_type> &List<value_type>::operator=(List<value_type> const &other)
{
	this->assign(other.begin(), other.end());
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
	return (List<value_type>::reverse_iterator(--this->end()));
}

template<typename value_type>
typename List<value_type>::const_reverse_iterator List<value_type>::rbegin(void) const
{
	return (List<value_type>::const_reverse_iterator(--this->end()));
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::end(void)
{
	return (List<value_type>::iterator(this->end_)++);
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::end(void) const
{
	return (List<value_type>::const_iterator(this->end_)++);
}

template<typename value_type>
typename List<value_type>::reverse_iterator List<value_type>::rend(void)
{
	return (List<value_type>::reverse_iterator(--this->begin()));
}

template<typename value_type>
typename List<value_type>::const_reverse_iterator List<value_type>::rend(void) const
{
	return (List<value_type>::const_reverse_iterator(--this->begin()));
}

template<typename value_type>
bool List<value_type>::empty(void) const
{
	return (this->size_ == 0)
}

template<typename value_type>
size_t List<value_type>::size(void) const
{
	return (this->size_);
}

template<typename value_type>
size_t List<value_type>::max_size(void) const
{
	return (((std::pow(2, 64) - 1) / ((sizeof(Node<value_type> * 2) + sizeof(value_type)) - 1);
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
	return (this->begin_->previous()->value());
}

template<typename value_type>
value_type const &List<value_type>::back() const
{
	return (this->begin_->previous()->value());
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::iterator first, List<value_type>::iterator last)
{
	this->clear();
	while (first != last)
		this->begin_.push_back(*first++);
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::const_iterator first, List<value_type>::const_iterator last)
{
	this->clear();
	while (first != last)
		this->begin_.push_back(*first++);
}

template<typename value_type>
void List<value_type>::assign(size_t size, value_type const &val)
{
	this->clear();
	for (size_t i = 0; i < size; i++)
		this->begin_.push_back(val);
}

template<typename value_type>
void List<value_type>::push_front(value_type const &val)
{
	if (this->size_ == 0)
	{
		tmp->previous = nullptr;
		tmp->next = nullptr;
		this->end_ = tmp;
	}
	else
	{
		Node<value_type> *tmp = new Node<value_type>(val);
		this->begin_->insert_before(tmp);
	}
	this->begin_ = tmp;
	++this->size_;
}

template<typename value_type>
void List<value_type>::pop_front(void)
{
	if (this->size_ == 1)
	{
		delete this->begin_;
		this->begin_ = nullptr;
		this->end_ = nullptr;
	}
	else
	{
		Node<value_type> *tmp = this->begin_;
		tmp->disconnect();
		delete tmp;
	}
	if (--this->size_ == 1)
		this->end_ = this->begin_;
}

template<typename value_type>
void List<value_type>::push_back(value_type const &val)
{
	if (this->size_ == 0)
		this->push_front(val);
	else
	{
		Node<value_type> *tmp = new Node<value_type>(val);
		this->end_->insert_after(tmp);
		this->end_ = tmp;
		++this->size_;
	}
}

template<typename value_type>
void List<value_type>::pop_back(void)
{
	if (this->size_ == 1)
		this->pop_front();
	else
	{
		Node<value_type> *tmp = this->end_;
		tmp->disconnect();
		delete tmp;
		if (--this->size_ == 1)
			this->begin_ = this->end_;
	}
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::insert(List<value_type>::iterator position, value_type const &val)
{
	if (node == this->end_)
		this->push_back(val);
	else
	{
		Node<value_type> *node = *position;
		Node<value_type> *newNode = new Node<value_type>(val);
		*position->insert_before(newNode); // TODO: can't access list previous/next from iterator
		++this->size_;
	}
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
List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator position)
{
	if (position == this->begin())
		this->pop_front();
	else if (position == this->end())
		this->pop_back();
	else
	{
		Node<value_type> *next = *position->next();
		*position->disconnect(); // TODO: can't access list previous/next from iterator
		delete *position;
		--this->size_;
	}
}

template<typename value_type>
List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator first, List<value_type>::iterator last)
{
	while (first != last)
		this->erase(*first++);
}

template<typename value_type>
void List<value_type>::swap(List<value_type> &other)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::clear(void)
{
	this->erase(this->begin(), this->end());
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x, List<value_type>::iterator it)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x, List<value_type>::iterator first, List<value_type>::iterator last)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::remove(value_type const &val)
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();

	while (first != last)
	{
		if (*first == val)
			this->erase(first);
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
			this->erase(first);
		++first;
	}
}

template<typename value_type>
void List<value_type>::unique(void)
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator next = first;
	List<value_type>::iterator last = this->end();

	while (++next != last)
	{
		if (*first++ == *next)
		{
			this->erase(next);
			next = first;
		}
	}
}

template<typename value_type>
template<typename BinaryPredicate>
void List<value_type>::unique(BinaryPredicate binary_pred)
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator next = first;
	List<value_type>::iterator last = this->end();

	while (++next != last)
	{
		if ((*binery_pred)(*first++, *next))
		{
			this->erase(next);
			next = first;
		}
	}
}

template<typename value_type>
void List<value_type>::merge(List &x)
{
	if (&x == this)
		return ;
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
			if (*otherFirst < *first)
			{
				*first->insert_before(*otherFirst); // TODO: can't access list previous/next from iterator
				break ;
			}
		}
	}
}

template<typename value_type>
template<typename Compare>
void List<value_type>::merge(List &x, Compare comp)
{
	if (&x == this)
		return ;
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
			{
				*first->insert_before(*otherFirst); // TODO: can't access list previous/next from iterator
				break ;
			}
		}
	}
}

template<typename value_type>
void List<value_type>::sort(void)
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();

	while (first != last)
	{
		List<value_type>::iterator next = first;
		while (++next != last)
			if (*first < *next)
				*first->swap(*next); // TODO: can't access list previous/next from iterator
		++first;
	}
}

template<typename value_type>
template<typename Compare>
void List<value_type>::sort(Compare comp)
{
	List<value_type>::iterator first = this->begin();
	List<value_type>::iterator last = this->end();

	while (first != last)
	{
		List<value_type>::iterator next = first;
		while (++next != last)
			if ((*comp)(*next, *first))
				*first->swap(*next); // TODO: can't access list previous/next from iterator
		++first;
	}
}

template<typename value_type>
void List<value_type>::reverse(void)
{
	Node<value_type> *tmp;
	tmp = this->begin_;
	this->begin_ = this->end_;
	this->end_ = tmp;
}
}
