/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:35:17 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/11 15:22:32 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_TEST_HPP
# define DEQUE_TEST_HPP

template<typename DequeType>
void test_Deque(void)
{
	DequeType dq;
	for (size_t i = 0; i < 500; i++)
		dq.push_back(i);

	display_container("big deque: ", dq);
}

#endif
