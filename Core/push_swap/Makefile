NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

SRC = src/main.c src/parse.c src/stack.c src/utils.c \
      src/ops_swap.c src/ops_push.c src/ops_rotate.c src/ops_revrotate.c \
      src/sort_small.c src/sort_radix.c src/sort_greedy.c src/sort_greedy_utils.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = src/checker.c src/parse.c src/stack.c src/utils.c \
            src/ops_swap.c src/ops_push.c src/ops_rotate.c src/ops_revrotate.c \
            src/sort_small.c src/sort_radix.c src/sort_greedy.c src/sort_greedy_utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: checker

checker: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re bonus