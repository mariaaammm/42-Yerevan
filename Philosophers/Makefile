NAME	= philo

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)

GCC		= gcc
FLAGS	= -Wall -Werror -Wextra -fsanitize=address

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o $(NAME) -I ./

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
