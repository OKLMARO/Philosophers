# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 12:15:37 by oamairi           #+#    #+#              #
#    Updated: 2025/12/23 11:52:31 by oamairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=		-Wall -Wextra -Werror

SRCS	=		src/parsing.c src/philo.c src/put.c src/time.c src/utils_philo.c \
				src/utils_philo_bis.c src/utils.c

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