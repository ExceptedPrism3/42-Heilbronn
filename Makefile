# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 10:00:00 by aben-cad          #+#    #+#              #
#    Updated: 2025/11/05 20:18:06 by aben-cad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_strlen.c \
	ft_strchr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr_x.c \
	ft_putptr.c \
	ft_parser.c \
	ft_utils_bonus.c \
	ft_print_cs.c \
	ft_print_id.c \
	ft_print_ux.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
