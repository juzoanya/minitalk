# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 17:15:07 by juzoanya          #+#    #+#              #
#    Updated: 2022/02/23 19:26:52 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_S =	server.c \

SRC_C = client.c \


OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJ_S)
	@ar rc $(NAME_S) $(OBJ_S)
	@echo "$(NAME_S) created"
	@ranlib $(NAME_S)
	@echo "$(NAME_S) indexed"

$(NAME_C): $(OBJ_C)
	@ar rc $(NAME_C) $(OBJ_C)
	@echo "$(NAME_C) created"
	@ranlib $(NAME_C)
	@echo "$(NAME_C) indexed"

%.o: %.c
	@gcc $(FLAG) -o $@ $^

clean:
	@rm -f $(OBJ_S) $(OBJ_C)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@echo "$(NAME_S) $(NAME_C) deleted"

re: fclean all

.PHONY: all, clean, fclean, re