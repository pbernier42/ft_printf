/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:25:15 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/18 13:22:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(long n)
{
	int		count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int		ft_gain_some_lines(char *isneg, long *n_cpy, int *count)
{
	if (*n_cpy < 0)
	{
		*isneg = '1';
		*n_cpy = *n_cpy * -1;
		*count = ft_nbrlen(*n_cpy * 10);
	}
	else
		*count = ft_nbrlen(*n_cpy);
	return ('1');
}

char			*ft_itoa(int n)
{
	int		count;
	char	isneg;
	char	*str;
	long	n_cpy;

	str = NULL;
	isneg = '0';
	count = 0;
	n_cpy = n;
	if (n_cpy >= -2147483648 && n_cpy != 0 && n_cpy <= 2147483647)
	{
		ft_gain_some_lines(&isneg, &n_cpy, &count);
		if (!(str = ft_strnew(count)))
			return (NULL);
		str[count--] = '\0';
		while (count >= 0)
		{
			str[count--] = n_cpy % 10 + '0';
			n_cpy = n_cpy / 10;
		}
		if (isneg == '1')
			str[0] = '-';
		return (str);
	}
	return (ft_strdup("0"));
}
