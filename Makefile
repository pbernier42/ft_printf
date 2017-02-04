# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:55:07 by rlecart           #+#    #+#              #
#    Updated: 2017/02/04 15:07:59 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FILE	=	ft_putstr.c \
			ft_putchar.c \
			ft_strlen.c \
			ft_putnbr.c \
			ft_printf.c \
			ft_itoo.c \
			ft_itoa_base.c \
			ft_memcpy.c
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
