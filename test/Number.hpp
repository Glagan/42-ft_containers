/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:14:55 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/11 18:44:17 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_HPP
# define NUMBER_HPP

# include <iostream>

class Number
{
private:
	static int created;
	static int destructed;
	int n;
public:
	Number();
	Number(int const &a);
	Number(Number const &other);
	virtual ~Number();

	Number &operator=(Number const &other);
	Number &operator=(int value);

	bool operator==(Number const &b);
	bool operator!=(Number const &b);
	bool operator<(Number const &b);
	bool operator<=(Number const &b);
	bool operator>(Number const &b);
	bool operator>=(Number const &b);

	bool operator==(int const &b);
	bool operator!=(int const &b);
	bool operator<(int const &b);
	bool operator<=(int const &b);
	bool operator>(int const &b);
	bool operator>=(int const &b);

	int getValue(void) const;
	static int getCreated(void);
	static int getDestructed(void);
};

bool operator==(Number const &lhs, Number const &rhs);
bool operator!=(Number const &lhs, Number const &rhs);
bool operator<(Number const &lhs, Number const &rhs);
bool operator<=(Number const &lhs, Number const &rhs);
bool operator>(Number const &lhs, Number const &rhs);
bool operator>=(Number const &lhs, Number const &rhs);

std::ostream &operator<<(std::ostream &out, Number const &n);

#endif
