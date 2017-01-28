/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:10:45 by rlecart           #+#    #+#             */
/*   Updated: 2017/01/28 15:53:06 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

static int		counter(int nb)
{
	int		count;

	count = 0;
	while ((nb /= 10) != 0)
		count++;
	return (count + 1);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			d;
	int			i;
	int			c;
	int			len;
	char		*s;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			d = va_arg(ap, int);
			ft_putnbr(d);
			i += 2;
			len += counter(d);
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(ap, char*);
			ft_putstr(s);
			i += 2;
			len += ft_strlen(s);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(ap, int);
			ft_putchar(c);
			i += 2;
			len += 1;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
/*U
int				main(int argc, char **argv)
{
	int		i;

	i = 0;
	printf("%d\n", ft_printf("argc = %d\n", argc));
	printf("%d\n", printf("argc = %d\n", argc));
	while (argv[i])
	{
		printf("%d\n", ft_printf("argv[%d] = %s ### %c\n", i, argv[i], 'g'));
		printf("%d\n", printf("argv[%d] = %s ### %c\n", i, argv[i], 'g'));
		i++;
	}
	return (0);
}*/
