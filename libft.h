/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:30:13 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/01 16:34:38 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_itoa_base(int value, int base);
long		ft_itoo(int value);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
int			ft_printf(const char *format, ...);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char *str);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_memdel(void **ap);

#endif
