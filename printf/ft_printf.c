/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 23:35:27 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/03 00:00:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		init(t_struct **pf)
{
	if (!((*pf) = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	(*pf)->i = 0;
	(*pf)->len = 0;
	(*pf)->dig = 0;
	(*pf)->str = NULL;
	(*pf)->cha = 0;
	(*pf)->buff = ft_strnew(0);
	(*pf)->head = (*pf)->buff;
	(*pf)->tmp = NULL;
	(*pf)->tmp2 = NULL;
	return (1);
}

int				ft_printf(char const *format, ...)
{
	t_struct	*pf;

	if (!(init(&pf)))
		return (-1);
	while (format[pf->i])
	{
		if (format[pf->i] != '%')
		{
			pf->tmp = ft_strjoin_char(pf->buff, format[pf->i]);
			pf->buff = ft_strdup(pf->tmp);
			ft_strdel(&(pf->head));
			ft_strdel(&(pf->tmp));
			pf->head = pf->buff;
			pf->i++;
		}
		else
		{
			pf->tmp2 = ft_decrypt(&pf);
			pf->tmp = ft_strjoin(pf->buff, pf->tmp2);
			pf->buff = ft_strdup(pf->tmp);
			ft_strdel(&(pf->head));
			ft_strdel(&(pf->tmp));
			pf->head = pf->buff;
		}
	}
	pf->len = ft_strlen(pf->buff);
	write(1, pf->buff, pf->len);
	return (0);
}
