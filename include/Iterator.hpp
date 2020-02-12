/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:16:55 by ncolomer          #+#    #+#             */
/*   Updated: 2020/02/24 18:08:15 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "Node.hpp"

namespace ft
{
struct IteratorTrait {};

template<typename It>
class ReverseIterator:
	public It
{
public:
	using typename It::value_type;
    using typename It::pointer;
    using typename It::const_pointer;
    using typename It::reference;
    using typename It::const_reference;
    using typename It::difference_type;
public:
	ReverseIterator(): It() {}
	ReverseIterator(It const &it): It(it) {}
	ReverseIterator(ReverseIterator const &other): It(other.p) {}
	ReverseIterator &operator=(ReverseIterator const &other) {
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		It tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const {
		It tmp(*this);
		return (*--tmp);
	}
	pointer operator->() {
		It tmp(*this);
		return (&*--tmp);
	}
	const_pointer operator->() const {
		It tmp(*this);
		return (&*--tmp);
	}
	ReverseIterator operator++(int) {
		ReverseIterator tmp(*this);
		operator++();
		return (tmp);
	}
	It &operator++() {
		return (this->It::operator--());
	}
	ReverseIterator operator--(int) {
		ReverseIterator tmp(*this);
		operator--();
		return (tmp);
	}
	It &operator--() {
		return (this->It::operator++());
	}
};
}

#endif
