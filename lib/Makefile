# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 17:12:11 by aagrivan          #+#    #+#              #
#    Updated: 2020/08/02 22:57:01 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

FILES_C = ft_atoi.c\
		  ft_bzero.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isblank.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_isxdigit.c\
		  ft_itoa.c\
		  ft_lstadd.c\
		  ft_lstdel.c\
		  ft_lstdelone.c\
		  ft_lstiter.c\
		  ft_lstmap.c\
		  ft_lstnew.c\
		  ft_memalloc.c\
		  ft_memccpy.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memdel.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_putchar.c\
		  ft_putchar_fd.c\
		  ft_putendl.c\
		  ft_putendl_fd.c\
		  ft_putnbr.c\
		  ft_putnbr_fd.c\
		  ft_putstr.c\
		  ft_putstr_fd.c\
		  ft_range.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strclr.c\
		  ft_strcmp.c\
		  ft_strcpy.c\
		  ft_strdel.c\
		  ft_strdup.c\
		  ft_strndup.c\
		  ft_strequ.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strjoin.c\
		  ft_strlcat.c\
		  ft_strlen.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strncat.c\
		  ft_strncmp.c\
		  ft_strncpy.c\
		  ft_strnequ.c\
		  ft_strnew.c\
		  ft_strnstr.c\
		  ft_strrchr.c\
			ft_strrev.c\
		  ft_strsplit.c\
		  ft_strstr.c\
		  ft_strsub.c\
		  ft_strtrim.c\
		  ft_swap.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_itoa_base.c \
		  ft_itoa_base_address16.c \
		  ft_itoa_base_ll.c \
		  ft_itoa_base_ll_pos.c \
		  ft_itoa_base_ull.c \
		  ft_putunbr.c

HEADER = includes

OBJECTS = $(FILES_C:%.c=%.o)
# OBJDIR = obj/
# OBJECTS = $(addprefix $(OBJDIR),$(FILES_C:%.c=%.o))
# знак '%' означает шаблон 

vpath %.c srcs
vpath %.h includes

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "$(NAME) was created."
	ranlib $(NAME)
# начинаясь с @ команда исполняется, но не печатается в выводе

# $(OBJDIR)%.o: $(FILES_C)
%.o : %.c
	@gcc $(FLAGS) -I $(HEADER) -c $< -o $@
# %.o : %.c
# автоматические переменные:
# $@ - имя цели
# $< - первый пререквизит
# $^ - все преревизиты

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "all object files were deleted."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) was deleted."

re: fclean all

# для "нестандартного" имени применяется флаг -f или --file
# make -f <filename> или make --file=<filename>
# м.указать для компиляции несколько файлов make -f <filename> -f <filename>
# при наличии флага -f автомат.поиска по именам makefile/Makefile не производится