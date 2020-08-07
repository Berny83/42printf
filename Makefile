# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 20:52:24 by aagrivan          #+#    #+#              #
#    Updated: 2020/07/22 20:52:24 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIBFT = libftprintf/
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3
LFLAGS = -L $(LIBFT) -lftprintf

SRCS = main.c
HEADER = libftprintf/includes/
OBJECTS = $(SRCS:%.c=%.o)

# COLOR
GREEN = \033[0;32m
RED = \033[0;31m
BASE = \033[0m

.PHONY: all, clean, fclean, re

all: libftprintf.a $(NAME)

$(NAME): libftprintf.a $(OBJECTS)
	@$(CC) $(FLAGS) -I $(HEADER) $(OBJECTS) $(LFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(HEADER) -I $(LIBFT) -o $@ -c $<

libftprintf.a:
	@make -C $(LIBFT)
	@echo "$(GREEN) libftprintf.a was compiled$(BASE)"

clean:
	@make -C $(LIBFT) clean
	@rm -rf main.o
	@echo "$(GREEN) obj-files were deleted$(BASE)"

fclean: clean
	@make -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all