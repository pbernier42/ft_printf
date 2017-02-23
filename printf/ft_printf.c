/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 23:35:27 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/23 06:43:24 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char const *format, ...)
{
	int			i;
	int			len;
	char		*buff;
	char		*tmp;
	va_list		ap;

	i = 0;
	len = 0;
	buff = ft_strnew(0);
	tmp = NULL;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			buff = ft_strjoin_clean_char(&buff, format[i++]);
			len++;
		}
		else
		{
			tmp = ft_decrypt(&(format[i++]), &i, ap, &len);
			buff = ft_strjoin_clean(&buff, &tmp);
		}
	}
	write(1, buff, len);
	ft_strdel(&buff);
	ft_strdel(&tmp);
	va_end(ap);
	return (len);
}
