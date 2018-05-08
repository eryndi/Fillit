# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwald <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 14:52:49 by dwald	       #+#    #+#              #
#    Updated: 2017/03/08 14:35:36 by dwald            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_FILES =	main.c \
		check_errors.c \
		ft_check_contact.c \
		parser.c \
		backtrack_algorithm.c\
		auxiliary_functions.c \
		display.c \
		colors.c

SRC_PATH = 	srcs

OBJ_PATH =	objs

LIB =	libft/libft.a

OBJ =	$(SRC_FILES:.c=.o)

CC =	gcc

FLAG = -Wextra -Wall -Werror	

all: $(NAME)

$(NAME):	$(OBJ) $(LIB)
			@$(CC) $(FLAG) -o $(NAME) $(OBJ) ./$(LIB)
			@echo "\033[1m\033[32mSuccess : \033[0m compilation fillit"

%.o:		$(SRC_PATH)/%.c
			@$(CC) $(FLAG) -o $@ -c $< -I./libft/includes/ -I./incl/ 
	
$(LIB):
			make -C ./libft/

clean:
			/bin/rm -f $(OBJ)
			make fclean -Clibft

fclean:		clean
			/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
