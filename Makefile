# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:55:07 by rlecart           #+#    #+#              #
#    Updated: 2017/02/01 16:36:45 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FILE	=	ft_atoi.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_memset.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnew.c
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
