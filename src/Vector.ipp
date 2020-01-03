/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:49:20 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/03 18:09:08 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

template<typename value_type>
Vector<value_type>::iterator::iterator():
	pointer(nullptr)
{
}

template<typename value_type>
Vector<value_type>::iterator::iterator(value_type *val):
	pointer(val)
{
}

template<typename value_type>
Vector<value_type>::iterator::iterator(Vector<value_type>::iterator const &other):
	pointer(other.pointer)
{
}

template<typename value_type>
typename Vector<value_type>::iterator &Vector<value_type>::iterator::operator=(Vector<value_type>::iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
Vector<value_type>::iterator::~iterator()
{
}

template<typename value_type>
value_type &Vector<value_type>::iterator::operator*()
{
	return (*this->pointer);
}

template<typename value_type>
value_type const &Vector<value_type>::const_iterator::operator*() const
{
	return (*this->pointer);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator==(iterator const &other) const
{
	return (this->pointer == other.pointer);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator!=(iterator const &other) const
{
	return (this->pointer != other.pointer);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator<(iterator const &other) const
{
	return (this->pointer < other.pointer);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator<=(iterator const &other) const
{
	return (this->pointer <= other.pointer);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator>(iterator const &other) const
{
	return (this->pointer > other.pointer);
}

template<typename value_type>
bool Vector<value_type>::iterator::operator>=(iterator const &other) const
{
	return (this->pointer >= other.pointer);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator++(int)
{
	++this->pointer;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator++()
{

	Vector<value_type>::iterator tmp(*this);
	operator++();
	return (tmp);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator--(int)
{
	--this->pointer;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::iterator::operator--()
{
	Vector<value_type>::iterator tmp(*this);
	operator--();
	return (tmp);
}

template<typename value_type>
Vector<value_type>::const_iterator::const_iterator():
	iterator(nullptr)
{
}

template<typename value_type>
Vector<value_type>::const_iterator::const_iterator(value_type *val):
	iterator(val)
{
}

template<typename value_type>
Vector<value_type>::const_iterator::const_iterator(Vector<value_type>::const_iterator const &other):
	iterator(other.pointer)
{
}

template<typename value_type>
typename Vector<value_type>::const_iterator &Vector<value_type>::const_iterator::operator=(Vector<value_type>::const_iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
Vector<value_type>::const_iterator::~const_iterator()
{
}

template<typename value_type>
Vector<value_type>::reverse_iterator::reverse_iterator():
	iterator(nullptr)
{
}

template<typename value_type>
Vector<value_type>::reverse_iterator::reverse_iterator(value_type *val):
	iterator(val)
{
}

template<typename value_type>
Vector<value_type>::reverse_iterator::reverse_iterator(Vector<value_type>::reverse_iterator const &other):
	iterator(other.pointer)
{
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator &Vector<value_type>::reverse_iterator::operator=(Vector<value_type>::reverse_iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
Vector<value_type>::reverse_iterator::~reverse_iterator()
{
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator++(int)
{
	--this->pointer;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator++()
{

	Vector<value_type>::reverse_iterator tmp(*this);
	operator--();
	return (tmp);
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator--(int)
{
	++this->pointer;
	return (*this);
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::reverse_iterator::operator--()
{
	Vector<value_type>::reverse_iterator tmp(*this);
	operator++();
	return (tmp);
}


template<typename value_type>
Vector<value_type>::const_reverse_iterator::const_reverse_iterator():
	const_iterator(nullptr), reverse_iterator(nullptr)
{
}

template<typename value_type>
Vector<value_type>::const_reverse_iterator::const_reverse_iterator(value_type *val):
	const_iterator(val), reverse_iterator(val)
{
}

template<typename value_type>
Vector<value_type>::const_reverse_iterator::const_reverse_iterator(Vector<value_type>::const_reverse_iterator const &other):
	const_iterator(other.pointer), reverse_iterator(other.pointer)
{
}

template<typename value_type>
typename Vector<value_type>::const_reverse_iterator &Vector<value_type>::const_reverse_iterator::operator=(Vector<value_type>::const_reverse_iterator const &other)
{
	this->pointer = other.pointer;
	return (*this);
}

template<typename value_type>
Vector<value_type>::const_reverse_iterator::~const_reverse_iterator()
{
}

template<typename value_type>
Vector<value_type>::Vector():
	allocated(128), length(0), container(nullptr), size_type(sizeof(value_type)), difference_type(size_type + 1 - size_type)
{
	this->container = new value_type[128]();
}

template<typename value_type>
Vector<value_type>::Vector(Vector<value_type>::iterator first, Vector<value_type>::iterator last):
	allocated(0), length(0), container(nullptr), size_type(sizeof(value_type)), difference_type(size_type + 1 - size_type)
{
	this->container = nullptr;
	this->assign(first, last);
}

template<typename value_type>
Vector<value_type>::Vector(size_t n, value_type const &val):
	allocated(0), length(0), container(nullptr), size_type(sizeof(value_type)), difference_type(size_type + 1 - size_type)
{
	this->container = nullptr;
	this->resize(n, val);
}

template<typename value_type>
Vector<value_type>::Vector(Vector<value_type> const &other):
	allocated(0), length(0), container(nullptr), size_type(sizeof(value_type)), difference_type(size_type + 1 - size_type)
{
	this->container = nullptr;
	this->reserve(other.allocated);
	this->assign(other.begin(), other.end());
}

template<typename value_type>
Vector<value_type>::~Vector()
{
	delete[] this->container;
	this->length = 0;
}

template<typename value_type>
Vector<value_type> &Vector<value_type>::operator=(Vector<value_type> const &other)
{
	this->clear();
	this->assign(other.begin(), other.end());
}


template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin(void)
{
	return (Vector<value_type>::iterator(&this->front()));
}

template<typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::begin(void) const
{
	return (Vector<value_type>::const_iterator(&this->front()));
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::rbegin(void)
{
	return (Vector<value_type>::reverse_iterator(&this->back()));
}

template<typename value_type>
typename Vector<value_type>::const_reverse_iterator Vector<value_type>::rbegin(void) const
{
	return (Vector<value_type>::const_reverse_iterator(&this->back()));
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end(void)
{
	return (Vector<value_type>::iterator((&this->back()) + 1));
}

template<typename value_type>
typename Vector<value_type>::const_iterator Vector<value_type>::end(void) const
{
	return (Vector<value_type>::const_iterator((&this->back()) + 1));
}

template<typename value_type>
typename Vector<value_type>::reverse_iterator Vector<value_type>::rend(void)
{
	return (Vector<value_type>::reverse_iterator((&this->front()) - 1));
}

template<typename value_type>
typename Vector<value_type>::const_reverse_iterator Vector<value_type>::rend(void) const
{
	return (Vector<value_type>::const_reverse_iterator((&this->front()) - 1));
}

template<typename value_type>
size_t Vector<value_type>::size(void) const
{
	return (this->length);
}

template<typename value_type>
size_t Vector<value_type>::max_size(void) const
{
	return (this->size_type * 1000000); // TODO: ???
}

template<typename value_type>
void Vector<value_type>::resize(size_t size, value_type val)
{
	if (size > this->allocated)
		this->resize(size);
	if (size > this->length)
	{
		for (size_t i = this->length; i < size; i++)
			this->container[i] = val;
		this->length = size;
	}
	else if (size < this->length)
	{
		for (size_t i = size; i < this->length; i++)
			delete this->container[i];
		this->length = size;
	}
}

template<typename value_type>
size_t Vector<value_type>::capacity(void) const
{
	return (this->allocated);
}

template<typename value_type>
bool Vector<value_type>::empty(void) const
{
	return (this->length == 0);
}

template<typename value_type>
void Vector<value_type>::reserve(size_t size)
{
	if (size > this->allocated)
	{
		this->allocated = size;
		value_type *tmp = new value_type[size]();
		for (size_t i = 0; i < this->allocated; i++)
			tmp[i] = this->container[i];
		delete[] this->container;
		this->container = tmp;
		this->allocated = size;
	}
}


template<typename value_type>
value_type &Vector<value_type>::operator[](size_t idx)
{
	return (this->at(idx));
}

template<typename value_type>
value_type const &Vector<value_type>::operator[](size_t idx) const
{
	return (this->at(idx));
}

template<typename value_type>
value_type &Vector<value_type>::at(size_t idx)
{
	assert(idx < this->length);
	return (this->container[idx]);
}

template<typename value_type>
value_type const &Vector<value_type>::at(size_t idx) const
{
	assert(idx < this->length);
	return (this->container[idx]);
}

template<typename value_type>
value_type &Vector<value_type>::front(void)
{
	return (this->container[0]);
}

template<typename value_type>
value_type const &Vector<value_type>::front(void) const
{
	return (this->container[0]);
}

template<typename value_type>
value_type &Vector<value_type>::back(void)
{
	return (this->container[this->length - 1]);
}

template<typename value_type>
value_type const &Vector<value_type>::back(void) const
{
	return (this->container[this->length - 1]);
}

template<typename value_type>
void Vector<value_type>::assign(Vector<value_type>::iterator first, Vector<value_type>::iterator last)
{
	(void)first;
	(void)last;
	// TODO:
}

template<typename value_type>
void Vector<value_type>::assign(size_t size, value_type const &val)
{
	(void)size;
	(void)val;
	// TODO:
}

template<typename value_type>
void Vector<value_type>::push_back(value_type const &val)
{
	if (this->length == this->allocated)
		this->reserve(this->allocated + 128);
	this->container[this->length++] = val;
}

template<typename value_type>
void Vector<value_type>::pop_back(void)
{
	this->length--;
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(Vector<value_type>::iterator position, value_type const &val)
{
	(void)position;
	(void)val;
	// TODO:
}

template<typename value_type>
void Vector<value_type>::insert(Vector<value_type>::iterator position, size_t size, value_type const &val)
{
	(void)position;
	(void)size;
	(void)val;
	// TODO:
}

template<typename value_type>
void Vector<value_type>::insert(Vector<value_type>::iterator position, Vector::iterator first, Vector::iterator last)
{
	(void)position;
	(void)first;
	(void)last;
	// TODO:
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::erase(Vector<value_type>::iterator position)
{
	(void)position;
	// TODO:
}

template<typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::erase(Vector::iterator first, Vector::iterator last)
{
	(void)first;
	(void)last;
	// TODO:
}

template<typename value_type>
void Vector<value_type>::swap(Vector<value_type> &other)
{
	(void)other;
	// TODO:
}

template<typename value_type>
void Vector<value_type>::clear(void)
{
	for (size_t i = 0; i < this->length; i++)
		this->container[i] = value_type();
	this->length = 0;
}

}
