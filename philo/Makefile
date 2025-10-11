# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 12:15:37 by oamairi           #+#    #+#              #
#    Updated: 2025/10/11 12:34:57 by oamairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=		-Wall -Wextra -Werror

SRCS	=		philo.c put.c

OBJS	=		$(SRCS:.c=.o)

NAME	=		philo

RM		= 		rm -f

CC		=		cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re