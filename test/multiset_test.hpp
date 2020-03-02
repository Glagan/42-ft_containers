/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiset_test.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:35:10 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/02 17:06:38 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTISET_TEST_HPP
# define MULTISET_TEST_HPP

template<typename value_type>
void test_Multiset(void)
{
    ft::Multiset<value_type> st;
    st.insert(1);
    st.insert(1);
    st.insert(1);
    st.insert(1);

    display_container("simple: ", st);
}

#endif
