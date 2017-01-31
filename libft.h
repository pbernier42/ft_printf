/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:30:13 by rlecart           #+#    #+#             */
/*   Updated: 2017/01/26 18:18:24 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>

void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *s);
int					ft_printf(const char *format, ...);
char				*ft_itoa_base(int value, int base);

#endif
