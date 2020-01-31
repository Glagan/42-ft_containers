# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 15:57:50 by ncolomer          #+#    #+#              #
#    Updated: 2020/01/11 17:48:06 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \
					test/Number.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -g -Wall -Wextra -Werror -I.
DEBUG 			= $(addprefix def_, $(MAKECMDGOALS))

NAME			= ft_containers

all:			$(NAME)

.cpp.o:
			    $(CXX) $(CXXFLAGS) -D $(DEBUG) -o $@ -c $<

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -D $(DEBUG) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			fclean $(NAME)
				./ft_containers

test_full:		fclean $(NAME)
				./ft_containers

.PHONY:			test all clean fclean re
