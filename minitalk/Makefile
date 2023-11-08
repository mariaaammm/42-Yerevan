NAME = 
SERVER = server
CLIENT = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(patsubst %.c, %.o, $(SRCS_S))
OBJS_C = $(patsubst %.c, %.o, $(SRCS_C))

RM = rm -f


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(SERVER) $(CLIENT) 

$(SERVER): $(OBJS_S) 
	$(CC) $(FLAGS) -o $(SERVER) $(OBJS_S) 

$(CLIENT): $(OBJS_C)
	$(CC) $(FLAGS) -o $(CLIENT) $(OBJS_C) 

clean:
	$(RM) $(OBJS_S) $(OBJS_C)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
