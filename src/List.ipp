/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/07 19:19:11 by ncolomer         ###   ########.fr       */
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
	container(nullptr), end(nullptr), size_(0)
{
}

template<typename value_type>
List<value_type>::List(size_t n, value_type const &val):
	container(nullptr), end(nullptr), size_(0)
{
	this->assign(n, val);
}

template<typename value_type>
List<value_type>::List(List<value_type>::iterator first, List<value_type>::iterator last):
	container(nullptr), end(nullptr), size_(0)
{
	this->assign(first, last);
}

template<typename value_type>
List<value_type>::List(List<value_type> const &other):
	container(nullptr), end(nullptr), size_(0)
{
	this->assign(other.begin(), other.end());
}

template<typename value_type>
List<value_type>::~List()
{
	bool over = false;

	Node<value_type> *tmp;
	while (this->container)
	{
		tmp = this->container->next();
		if (tmp == this->container)
			over = true;
		delete this->container;
		this->container = tmp;
		if (over)
			return ;
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
	return (List<value_type>::iterator(this->container));
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::begin(void) const
{
	return (List<value_type>::const_iterator(this->container));
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
	// TODO: Find a way to know if this is the end of the list since the list chain itself
	return (List<value_type>::iterator(this->end));
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::end(void) const
{
	// TODO: Find a way to know if this is the end of the list since the list chain itself
	return (List<value_type>::const_iterator(this->end));
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
	return (this->container->value());
}

template<typename value_type>
value_type const &List<value_type>::front() const
{
	return (this->container->value());
}

template<typename value_type>
value_type &List<value_type>::back()
{
	return (this->container->previous()->value());
}

template<typename value_type>
value_type const &List<value_type>::back() const
{
	return (this->container->previous()->value());
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::iterator first, List<value_type>::iterator last)
{
	this->clear();
	while (first != last)
		this->container.push_back(*first++);
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::const_iterator first, List<value_type>::const_iterator last)
{
	this->clear();
	while (first != last)
		this->container.push_back(*first++);
}

template<typename value_type>
void List<value_type>::assign(size_t size, value_type const &val)
{
	this->clear();
	for (size_t i = 0; i < size; i++)
		this->container.push_back(val);
}

template<typename value_type>
void List<value_type>::push_front(value_type const &val)
{
	Node<value_type> *tmp = new Node<value_type>(val);
	if (this->size_ == 0)
	{
		tmp->previous = tmp;
		tmp->next = tmp;
		this->end = tmp;
	}
	else
	{
		tmp->previous = this->container->previous;
		this->container->previous = tmp;
		tmp->next = this->container;
	}
	this->container = tmp;
	this->size_++;
}

template<typename value_type>
void List<value_type>::pop_front(void)
{
	if (this->size_ == 1)
	{
		delete this->container;
		this->container = nullptr;
		this->end = nullptr;
	}
	else
	{
		Node<value_type> *tmp = this->container;
		this->container->previous->next = this->container->next;
		this->container->next->previous = this->container->previous;
		this->container = this->container->previous;
		delete tmp;
	}
	if (--this->size_ == 1)
		this->end = this->container;
}

template<typename value_type>
void List<value_type>::push_back(value_type const &val)
{
	Node<value_type> *tmp = new Node<value_type>(val);
	if (this->size_ == 0)
		this->push_front;
	else
	{
		tmp->previous = this->end;
		this->end->next = tmp;
		tmp->next = this->container;
		this->end = tmp;
		this->size_++;
	}
}

template<typename value_type>
void List<value_type>::pop_back(void)
{
	if (this->size_ == 1)
		this->pop_front();
	else
	{
		Node<value_type> *tmp = this->end;
		this->end->previous->next = this->end->next;
		this->end->next->previous = this->end->previous;
		this->end = this->end->previous;
		delete tmp;
		if (--this->size_ == 1)
			this->container = this->end;
	}
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::insert(List<value_type>::iterator position, value_type const &val)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::insert(List<value_type>::iterator position, size_t size, value_type const &val)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::insert(List<value_type>::iterator position, List::iterator first, List::iterator last)
{
	// TODO: TODO
}

template<typename value_type>
List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator position)
{
	// TODO: TODO
}

template<typename value_type>
List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator first, List<value_type>::iterator last)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::swap(List<value_type> &other)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::clear(void)
{
	bool over = false;

	Node<value_type> *tmp;
	while (this->container)
	{
		tmp = this->container->next();
		if (tmp == this->container)
			over = true;
		delete this->container;
		this->container = tmp;
		if (over)
			return ;
	}
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
	// TODO: TODO
}

template<typename value_type>
template<typename Predicate>
void List<value_type>::remove_if(Predicate pred)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::unique(void)
{
	// TODO: TODO
}

template<typename value_type>
template<typename BinaryPredicate>
void List<value_type>::unique(BinaryPredicate binary_pred)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::merge(List &x)
{
	// TODO: TODO
}

template<typename value_type>
template<typename Compare>
void List<value_type>::merge(List &x, Compare comp)
{
}

template<typename value_type>
void List<value_type>::sort(void)
{
	// TODO: TODO
}

template<typename value_type>
template<typename Compare>
void List<value_type>::sort(List &x, Compare comp)
{
	// TODO: TODO
}

template<typename value_type>
void List<value_type>::reverse(void)
{
	// TODO: TODO
}
}