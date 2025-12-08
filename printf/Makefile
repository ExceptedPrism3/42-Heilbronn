NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_printf_utils.c \
	ft_print_nbr.c \
	ft_print_hex.c \
	ft_print_text.c \
	ft_strlen.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re