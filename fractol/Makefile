NAME	= fractol

SRCS	= $(wildcard *.c)

OBJS	= $(SRCS:.c=.o)

GCC		= cc
MLX		= -lmlx -framework OpenGL -framework AppKit
FLAGS	= -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(GCC) $(MLX) $(FLAGS) $(OBJS) -o $(NAME) -I ./
all: $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
