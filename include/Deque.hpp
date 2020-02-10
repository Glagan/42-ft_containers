/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:46 by ncolomer          #+#    #+#             */
/*   Updated: 2020/02/10 02:31:28 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <limits>
# include "include/Node.hpp"
# include "include/Iterator.hpp"
# include "include/Algorithm.hpp"

namespace ft
{
template<typename T, size_t chunk_size>
class DequeIterator
{
public:
	typedef T value_type;
	typedef value_type* pointer;
	typedef pointer* chunk;
	typedef const pointer const_pointer;
	typedef value_type& reference;
	typedef const reference const_reference;
	typedef ptrdiff_t difference_type;
private:
	pointer current;
	pointer first;
	pointer last;
	chunk node;
	friend class Deque;
public:
	reference operator[](difference_type index) const
	{
    	return (*(*this + index));
	}
};
/**
 * deque is an array of chunks
 * attributes:
 * 	map
 * 	size
 * 	start (iterator)
 * 	end (iterator)
 * a chunk is an array of T with an iterator
 * iterator:
 * 	current
 * 	first
 * 	last
 * 	node
 **/
template<typename T>
class Deque
{
public:
	typedef 10 chunk_size;
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef pointer* chunk;
	typedef const pointer const_pointer;
	typedef value_type& reference;
	typedef const reference const_reference;
	typedef ptrdiff_t difference_type;
	typedef DequeIterator<value_type, chunk_size> iterator;
	typedef DequeIterator<value_type const, chunk_size> const_iterator;
	typedef ReverseDequeIterator<value_type, chunk_size> reverse_iterator;
	typedef ReverseDequeIterator<value_type const, chunk_size> const_reverse_iterator;
private:
	iterator m_first;
	iterator m_last;
	chunk m_container;
	size_type m_size;
public:
	Deque():
		m_first(nullptr), m_last(nullptr),
		m_container(nullptr), m_size(0) {}
	Deque(size_type n, const_reference val=value_type()):
		m_first(nullptr), m_last(nullptr),
		m_container(nullptr), m_size(0) {
		this->assign(n, val);
	}
	Deque(iterator first, iterator last);
	Deque(Deque const &other);
	virtual ~Deque();

	List &operator=(List const &other);

	iterator begin(void)
	{
		return (iterator(this->m_first));
	}
	const_iterator begin(void) const
	{
		return (const_iterator(this->m_first));
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
		return (iterator(this->m_last));
	}
	const_iterator end(void) const
	{
		return (const_iterator(this->m_last));
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
		return (this->m_size == 0);
	}
	size_type size(void) const
	{
		return (this->m_size);
	}
	size_type max_size(void) const
	{
		return (std::numeric_limits<value_type>::max() - 1);
	}
    void resize(size_type n, value_type val=value_type());

    reference operator[](size_type n);
    const_reference operator[](size_type n) const;

    reference at(size_type n);
    const_reference at(size_type n) const;

    reference front(void)
	{
		return (*this->m_first);
	}
    const_reference front(void) const
	{
		return (*this->m_first);
	}
    reference back(void)
	{
		iterator tmp = m_last;
    	--tmp;
		return (*--tmp);
	}
    const_reference back(void) const
	{
		iterator tmp = m_last;
    	--tmp;
		return (*--tmp);
	}

    template <typename InputIterator>
	void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const_reference val);

    void push_back(const_reference val);
    void pop_back(void);

    void push_front(const_reference val);
    void pop_front(void);

    iterator insert(iterator position, const_reference val);
    void insert(iterator position, size_type n, const_reference val);
    template<typename InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last);

    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);

    void swap(Deque &x);
    void clear(void);
};

template<typename T>
bool operator==(Deque<T> const &lhs, Deque<T> const &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template<typename T>
bool operator!=(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (rhs < lhs);
}

template<typename T>
bool operator>=(Deque<T> const &lhs, Deque<T> const &rhs)
{
	return (!(lhs < rhs));
}

template<typename T>
void swap(Deque<T> &x, Deque<T> &y);
}

#endif