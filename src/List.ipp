/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.ipp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:12 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/07 17:51:22 by ncolomer         ###   ########.fr       */
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
	return (*(this->pointer));
}

template<typename value_type>
value_type *List<value_type>::iterator::operator->() const
{
	return (this->pointer);
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
	++this->pointer;
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
	--this->pointer;
	return (*this);
}

template<typename value_type>
typename List<value_type>::iterator& List<value_type>::iterator::operator+=(int value)
{
	this->pointer += value;
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
	this->pointer -= value;
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
	return (*(this->pointer));
}

template<typename value_type>
value_type const *List<value_type>::const_iterator::operator->() const
{
	return (this->pointer);
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
	++this->pointer;
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
	--this->pointer;
	return (*this);
}

template<typename value_type>
typename List<value_type>::const_iterator& List<value_type>::const_iterator::operator+=(int value)
{
	this->pointer += value;
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
	this->pointer -= value;
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
	--this->pointer;
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
	++this->pointer;
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
List<value_type>::List()
{
}

template<typename value_type>
List<value_type>::List(size_t n, value_type const &val)
{
}

template<typename value_type>
List<value_type>::List(List<value_type>::iterator first, List<value_type>::iterator last)
{
}

template<typename value_type>
List<value_type>::List(List<value_type> const &other)
{
}

template<typename value_type>
List<value_type>::~List()
{
}

template<typename value_type>
List<value_type> &List<value_type>::operator=(List<value_type> const &other)
{
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::begin(void)
{
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::begin(void) const
{
}

template<typename value_type>
typename List<value_type>::reverse_iterator List<value_type>::rbegin(void)
{
}

template<typename value_type>
typename List<value_type>::const_reverse_iterator List<value_type>::rbegin(void) const
{
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::end(void)
{
}

template<typename value_type>
typename List<value_type>::const_iterator List<value_type>::end(void) const
{
}

template<typename value_type>
typename List<value_type>::reverse_iterator List<value_type>::rend(void)
{
}

template<typename value_type>
typename List<value_type>::const_reverse_iterator List<value_type>::rend(void) const
{
}

template<typename value_type>
bool List<value_type>::empty(void) const
{
}

template<typename value_type>
size_t List<value_type>::size(void) const
{
}

template<typename value_type>
size_t List<value_type>::max_size(void) const
{
}

template<typename value_type>
value_type &List<value_type>::front()
{
}

template<typename value_type>
value_type const &List<value_type>::front() const
{
}

template<typename value_type>
value_type &List<value_type>::back()
{
}

template<typename value_type>
value_type const &List<value_type>::back() const
{
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::iterator first, List<value_type>::iterator last)
{
}

template<typename value_type>
void List<value_type>::assign(List<value_type>::const_iterator first, List<value_type>::const_iterator last)
{
}

template<typename value_type>
void List<value_type>::assign(size_t size, value_type const &val)
{
}

template<typename value_type>
void List<value_type>::push_front(value_type const &val)
{
}

template<typename value_type>
void List<value_type>::pop_front(void)
{
}

template<typename value_type>
void List<value_type>::push_back(value_type const &val)
{
}

template<typename value_type>
void List<value_type>::pop_back(void)
{
}

template<typename value_type>
typename List<value_type>::iterator List<value_type>::insert(List<value_type>::iterator position, value_type const &val)
{
}

template<typename value_type>
void List<value_type>::insert(List<value_type>::iterator position, size_t size, value_type const &val)
{
}

template<typename value_type>
void List<value_type>::insert(List<value_type>::iterator position, List::iterator first, List::iterator last)
{
}

template<typename value_type>
List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator position)
{
}

template<typename value_type>
List<value_type>::iterator List<value_type>::erase(List<value_type>::iterator first, List<value_type>::iterator last)
{
}

template<typename value_type>
void List<value_type>::swap(List<value_type> &other)
{
}

template<typename value_type>
void List<value_type>::clear(void)
{
}


template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x)
{
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x, List<value_type>::iterator it)
{
}

template<typename value_type>
void List<value_type>::splice(List<value_type>::iterator position, List<value_type> &x, List<value_type>::iterator first, List<value_type>::iterator last)
{
}

template<typename value_type>
void List<value_type>::remove(value_type const &val)
{
}

template<typename value_type>
template<typename Predicate>
void List<value_type>::remove_if(Predicate pred)
{
}

template<typename value_type>
void List<value_type>::unique(void)
{
}

template<typename value_type>
template<typename BinaryPredicate>
void List<value_type>::unique(BinaryPredicate binary_pred)
{
}

template<typename value_type>
void List<value_type>::merge(List &x)
{
}
template<typename value_type>
template<typename Compare>
void List<value_type>::merge(List &x, Compare comp)
{
}

template<typename value_type>
void List<value_type>::sort(void)
{
}

template<typename value_type>
template<typename Compare>
void List<value_type>::sort(List &x, Compare comp)
{
}

template<typename value_type>
void List<value_type>::reverse(void)
{
}
}