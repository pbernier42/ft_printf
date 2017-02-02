/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:30:13 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/02 22:48:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

void					ft_putstr(char *str);
void					ft_putchar(char c);
void					ft_putnbr(int n);
size_t					ft_strlen(const char *s);
int						ft_printf(const char *format, ...);
char					*ft_itoa_base(int value, int base);
size_t					ft_intlen(int nb);

#endif
