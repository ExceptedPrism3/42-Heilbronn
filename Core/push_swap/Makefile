NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

SRC = src/main.c src/parse.c src/stack.c src/utils.c \
      src/ops_swap.c src/ops_push.c src/ops_rotate.c src/ops_revrotate.c \
      src/sort_small.c src/sort_radix.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re