/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:20:23 by pbernier          #+#    #+#             */
/*   Updated: 2016/11/18 14:06:19 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_putnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void		ft_putnbr(int n)
{
	int	save;
	int len;
	int	tab[ft_len_putnbr(n) + 1];

	len = ft_len_putnbr(n);
	save = n;
	tab[len] = 10;
	len--;
	while (len >= 0)
	{
		tab[len] = save % 10;
		if (tab[len] < 0)
			tab[len] = -tab[len];
		len--;
		save = save / 10;
	}
	if (n < 0)
		ft_putchar('-');
	while (tab[save] != 10)
		ft_putchar(tab[save++] + 48);
}
