/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:14:27 by exam              #+#    #+#             */
/*   Updated: 2017/02/02 22:28:46 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		save = value;
	int		len = 1;
	char	syn[16] = "0123456789abcdef";
	int		res = 0;

	while ((save /= base) != 0)
		++len;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (--len != -1)
	{
		res = value % base;
		if (res < 0)
			res = -res;
		str[len] = syn[res];
		value = value / base;
	}
	return (str);
}
