/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:10:45 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/01 15:30:53 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	counter(int nb)
{
	int		count;

	count = 0;
	while ((nb /= 10) != 0)
		count++;
	return (count + 1);
}

int				ft_printf(const char *format, ...)
{
	t_struct	*pf;

	if (!(pf = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	pf->i = 0;
	pf->len = ft_strlen(format);
	va_start(pf->ap, format);
	while (format[pf->i])
	{
		while (format[pf->i] && format[pf->i] != '%')
			ft_putchar(format[(pf->i)++]);
		if (!(format[pf->i]))
			break;

		if (format[pf->i + 1] == 'd' || format[pf->i + 1] == 'i')
		{
			pf->dig = va_arg(pf->ap, int);
			ft_putnbr(pf->dig);
			pf->i += 2;
			pf->len += (counter(pf->dig) - 2);
		}

		if (format[pf->i + 1] == 's')
		{
			pf->str = va_arg(pf->ap, char*);
			ft_putstr(pf->str);
			pf->i += 2;
			pf->len += (ft_strlen(pf->str) - 2);
		}

		if (format[pf->i + 1] == 'c')
		{
			pf->cha = va_arg(pf->ap, int);
			ft_putchar(pf->cha);
			pf->i += 2;
			pf->len += -1;
		}

		/*if (format[pf->i + 1] == 'o')
		{
			//ft_putchar(pf->cha);
			pf->i += 2;
			pf->len += -1;
		}*/
	}

	va_end(pf->ap);
	free(pf);
	return (pf->len);
}

int				main(void)
{
	long		i = 2147483647;

	printf("F result = %i\n", ft_printf("F = %o\n", i));
	printf("V result = %i\n", printf("V = %o\n", i));

	while (--i > -100)
	{
		printf("%d = [%o	~	%d]\n", i, i, ft_itoo(i));
	}
	return (0);
}
