/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimap_test.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:34:56 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/02 18:12:53 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTIMAP_TEST_HPP
# define MULTIMAP_TEST_HPP

template<typename key_type, typename value_type>
void test_Multimap(int offset=0)
{
    ft::Multimap<key_type, value_type> st;
    st.insert(std::make_pair(1, offset+1));
    st.insert(std::make_pair(1, offset+1));
    st.insert(std::make_pair(1, offset+1));
    st.insert(std::make_pair(1, offset+1));

	display_container("simple: ", st);
}

#endif
