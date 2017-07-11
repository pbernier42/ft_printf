/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:58:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/07/10 15:21:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		pf_sitoa(short nbr, char **str, int base, char spec)
{
	short int	save;
	int			len;
	char		hexa[16];

	len = 1;
	save = nbr;
	ft_strcpy(hexa, "0123456789abcdef");
	if (spec == 'X')
		ft_strcpy(hexa, "0123456789ABCDEF");
	while (save /= base)
			len++;
	if (spec == 'p')
		len += 2;
	if (!(*str = ft_strnew(len--)))
		exit(-1);
	if (spec == 'p')
		ft_memcpy(*str, ((char[2]){'0', 'x'}), sizeof(char[2]));
	while (len >= 0 && (*str)[len] != 'x')
	{
		(*str)[len--] = hexa[nbr % base];
		nbr /= base;
	}
}

void		pf_itoa(int nbr, char **str, int base, char spec)
{
	int		save;
	int		len;
	char	hexa[16];

	len = 1;
	save = nbr;
	ft_strcpy(hexa, "0123456789abcdef");
	if (spec == 'X')
		ft_strcpy(hexa, "0123456789ABCDEF");
	while (save /= base)
			len++;
	if (spec == 'p')
		len += 2;
	if (!(*str = ft_strnew(len--)))
		exit(-1);
	if (spec == 'p')
		ft_memcpy(*str, ((char[2]){'0', 'x'}), sizeof(char[2]));
	while (len >= 0 && (*str)[len] != 'x')
	{
		(*str)[len--] = hexa[nbr % base];
		nbr /= base;
	}
}

void		pf_litoa(long nbr, char **str, int base, char spec)
{
	long	save;
	int		len;
	char	hexa[16];

	len = 1;
	save = nbr;
	ft_strcpy(hexa, "0123456789abcdef");
	if (spec == 'X')
		ft_strcpy(hexa, "0123456789ABCDEF");
	while (save /= base)
			len++;
	if (spec == 'p')
		len += 2;
	if (!(*str = ft_strnew(len--)))
		exit(-1);
	if (spec == 'p')
		ft_memcpy(*str, ((char[2]){'0', 'x'}), sizeof(char[2]));
	while (len >= 0 && (*str)[len] != 'x')
	{
		(*str)[len--] = hexa[nbr % base];
		nbr /= base;
	}
}

void		pf_llitoa(long long nbr, char **str, int base, char spec)
{
	long long	save;
	int			len;
	char		hexa[16];

	len = 1;
	save = nbr;
	ft_strcpy(hexa, "0123456789abcdef");
	if (spec == 'X')
		ft_strcpy(hexa, "0123456789ABCDEF");
	while (save /= base)
			len++;
	if (spec == 'p')
		len += 2;
	if (!(*str = ft_strnew(len--)))
		exit(-1);
	if (spec == 'p')
		ft_memcpy(*str, ((char[2]){'0', 'x'}), sizeof(char[2]));
	while (len >= 0 && (*str)[len] != 'x')
	{
		(*str)[len--] = hexa[nbr % base];
		nbr /= base;
	}
}
