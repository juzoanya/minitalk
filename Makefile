# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 17:15:07 by juzoanya          #+#    #+#              #
#    Updated: 2022/06/12 22:51:42 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME_C = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_S =	server.c \
		utils.c \
		helper.c \

SRC_C = client.c \
		utils.c \
		helper.c \


OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all: $(NAME) $(NAME_C)

$(NAME): $(OBJ_S)
	gcc -o $@ $^
	@echo "$(NAME) created"

$(NAME_C): $(OBJ_C)
	gcc -o $@ $^
	@echo "$(NAME_C) created"

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJ_S) $(OBJ_C)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME) $(NAME_C)
	@echo "$(NAME) $(NAME_C) deleted"

re: fclean all

.PHONY: all, clean, fclean, re