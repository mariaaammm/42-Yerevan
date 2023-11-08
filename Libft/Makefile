# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 14:26:04 by mpetrosy          #+#    #+#              #
#    Updated: 2022/04/16 15:12:07 by mpetrosy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

BSRCS = $(wildcard ft_lst*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

BOBJS = $(patsubst %.c, %.o, $(BSRCS))

RM = rm -f

AR = ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) bonus

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(BOBJS)
	$(AR) $(NAME) $(BOBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
