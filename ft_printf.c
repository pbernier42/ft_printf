/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:10:45 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/02 23:07:37 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			len;
	int			dig;
	char		*str;
	char		cha;

	i = 0;
	len = ft_strlen(format);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			ft_putchar(format[i++]);
		if (!(format[i]))
			break;

		if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			dig = va_arg(ap, int);
			ft_putnbr(dig);
			i += 2;
			len += (ft_intlen(dig) - 2);
		}

		if (format[i + 1] == 's')
		{
			str = va_arg(ap, char*);
			ft_putstr(str);
			i += 2;
			len += (ft_strlen(str) - 2);
		}

		if (format[i + 1] == 'c')
		{
			cha = va_arg(ap, int);
			ft_putchar(cha);
			i += 2;
			len += -1;
		}
		if (format[i + 1] == 'o')
		{
			str = ft_itoa_base(va_arg(ap, int), 8);
			ft_putstr(str);
			i += 2;
			len += -1;
		}
	}

	va_end(ap);
	return (len);
}

int				main(void)
{
	int i = 99999999;

	printf("F result = %i\n", ft_printf("F = %o\n", i));
	printf("V result = %i\n", printf("V = %o\n", i));
	return (0);
}
