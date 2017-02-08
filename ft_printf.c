/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:10:45 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/04 17:29:26 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//Creation de la structure
static int		init(t_struct **pf, const char *format)
{
	if (!((*pf) = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	(*pf)->i = 0;
	(*pf)->len = 0;
	(*pf)->dig = 0;
	(*pf)->str = NULL;
	(*pf)->cha = 0;
	if (!((*pf)->compa = (char**)malloc(sizeof(char*) * 15)))
		return (-1);
	(*pf)->compa[0] = ft_strdup("BONJOUR");
	(*pf)->buff = ft_strnew(0);
	(*pf)->head = (*pf)->buff;
	(*pf)->tmp = NULL;
	(*pf)->tmp2[0] = '\0';
	(*pf)->tmp2[1] = '\0';
	return (0);
}

static void		*id(char *str)
{

	return (0);
}

int				ft_printf(char const *format, ...)
{
	t_struct	*pf;

	if ((init(&pf, format)) == -1)
		return (-1);
	va_start(pf->ap, format);
	while (format[pf->i])
	{
		while (format[pf->i] && format[pf->i] != '%')
		{
			pf->tmp2[0] = format[pf->i];
			pf->tmp = ft_strjoin(pf->buff, pf->tmp2);
			pf->buff = ft_strdup(pf->tmp);
			ft_strdel(&(pf->head));
			ft_strdel(&(pf->tmp));
			pf->head = pf->buff;
			pf->i++;
		}
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
	pf->len = ft_strlen(format);
	write(1, pf->buff, pf->len);
	free(pf);
	return (pf->len);
}
