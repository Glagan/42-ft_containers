# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/02 15:57:50 by ncolomer          #+#    #+#              #
#    Updated: 2020/01/11 16:46:15 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \
					test/Number.cpp test/vector.cpp test/list.cpp test/stack.cpp \
					test/queue.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -g -Wall -Wextra -Werror -I.

NAME			= ft_containers

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)
				./ft_containers

.PHONY:			test all clean fclean re
