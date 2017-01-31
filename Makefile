# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:55:07 by rlecart           #+#    #+#              #
#    Updated: 2017/01/26 18:10:34 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FILE	=	ft_putstr.c \
			ft_putchar.c \
			ft_strlen.c \
			ft_putnbr.c \
			ft_printf.c \
			ft_itoa_base.c
SRC		=	$(FILE)
OBJ		=	$(SRC:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
