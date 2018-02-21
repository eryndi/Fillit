# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwald <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:52:24 by dwald             #+#    #+#              #
#    Updated: 2017/02/23 17:09:17 by dwald            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libft.a

SRC 	= 	ft_atoi.c \
			ft_bzero.c \
			ft_countdigits.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_iswhitespaces.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memdup.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbrn.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strmemrev.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c

OBJ 	=	$(SRC:.c=.o)

HDR		=	includes

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

all		: 	$(NAME)

$(NAME)	:	$(OBJ)
			@ar rc libft.a $(OBJ)
			@ranlib $(NAME)
			@echo "\033[1m\033[32mSuccess : \033[0m compilation libf.a"

%.o:		%.c
			@$(CC) $(FLAG) -o $@ -c $< -I./$(HDR)
clean	:
	rm -f 	$(OBJ)

fclean	: 	clean
	rm -f 	$(NAME)

re		:	fclean all

ree		:	re
			rm -f $(OBJ)

.PHONY: all clean fclean re
