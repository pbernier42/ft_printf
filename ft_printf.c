/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:10:45 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/04 16:38:25 by pbernier         ###   ########.fr       */
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
