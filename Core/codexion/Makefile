NAME		= codexion

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g3

SRCS		= main.c \
			  utils.c \
			  init.c \
			  monitor.c \
			  scheduler.c \
			  routine.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
