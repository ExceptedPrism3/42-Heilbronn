# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 08:40:43 by aben-cad          #+#    #+#              #
#    Updated: 2025/08/16 08:51:11 by aben-cad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): rush-02.c
    $(CC) $(CFLAGS) rush-02.c -o $(NAME)

clean:
    rm -f $(NAME)

.PHONY: all clean