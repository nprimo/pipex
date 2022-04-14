# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 09:54:53 by nprimo            #+#    #+#              #
#    Updated: 2022/04/14 15:45:54 by nprimo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra #-fsanitize=address
RM = rm -rf

NAME = pipex

SRC = src
OBJ = obj
INC = inc
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(wildcard $(OBJ)/*.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

