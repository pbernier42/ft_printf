# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:55:07 by rlecart           #+#    #+#              #
#    Updated: 2017/03/04 16:42:35 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FILE	=	ft_putstr.c \
			ft_puttab.c \
			ft_putchar.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strjoin_char.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strsplit.c \
			ft_strlcat.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_sqrt.c \
			ft_swap.c \
			ft_range.c \
			ft_strrev.c \
			ft_lstlast.c \
			get_next_line.c \
			ft_strtabdel.c \
			ft_strjoin_clean.c \
			ft_strjoin_clean_char.c \
			ft_absolute.c \
			ft_intlen_base.c
SRC		=	$(addprefix libft/,$(FILE))
FILEPF	=	ft_printf.c \
			ft_decrypt.c \
			find_specifier.c \
			spec_type_si.c \
			spec_type_un.c \
			spec_type_sp.c \
			convert_arg.c \
			create_str.c \
			find_atr.c
SRCPF	=	$(addprefix printf/,$(FILEPF))
OBJ		=	$(SRC:.c=.o) $(SRCPF:.c=.o)

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(FILE:.c=.o) $(FILEPF:.c=.o)
	ranlib $(NAME)
	mv $(FILE:.c=.o) libft
	mv $(FILEPF:.c=.o) printf

%.o: %.c
	$(CC) -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
