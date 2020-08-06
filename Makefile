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

LIBFT = lib/
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3
LFLAGS = -L $(LIBFT) -lft

SRCS = ft_printf.c \
		ft_get_flags.c \
		ft_support.c \
		ft_print_scp.c \
		ft_print_di.c \
		ft_print_u.c \
		ft_print_o.c \
		ft_print_x.c \
		main.c
SRC_DIR = srcs/
SRCS_P = $(addprefix $(SRC_DIR),$(SRCS))

OBJDIR = obj/
OBJ_P = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

HEADERS = ft_printf.h
HEAD_DIR = includes/
HEAD_P = $(addprefix $(HEAD_DIR),$(HEADERS))

# COLOR
GREEN = \033[0;32m
RED = \033[0;31m
BASE = \033[0m

.PHONY: all, clean, fclean, re

all: libft.a $(NAME)

$(NAME): $(OBJ_P) $(HEAD_P)
	$(CC) $(FLAGS) $(OBJ_P) $(LFLAGS) -o $(NAME)

$(OBJDIR)%.o: $(SRC_DIR)%.c $(HEAD_P)
	mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -I $(LIBFT) -I $(HEAD_DIR) -o $@ -c $<

libft.a:
	@make -C $(LIBFT)
	@echo "$(GREEN) libft.a was compiled$(BASE)"

ex:
	gcc $(FLAGS) ex_printf.c -o example.out

clean:
	@make -C $(LIBFT) clean
	rm -rf $(OBJDIR)
	@echo "$(GREEN) obj-files were deleted$(BASE)"

fclean: clean
	@make -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all