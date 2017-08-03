/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:09:45 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/03 16:09:47 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		pf_usitoa(unsigned short nbr, char **str, int base, char spec)
{
	unsigned short int	save;
	int					len;
	char				hexa[16];

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

void		pf_uitoa(unsigned int nbr, char **str, int base, char spec)
{
	unsigned int	save;
	int				len;
	char			hexa[16];

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

void		pf_ulitoa(unsigned long nbr, char **str, int base, char spec)
{
	unsigned long	save;
	int				len;
	char			hexa[16];

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

void		pf_ullitoa(unsigned long long nbr, char **str, int base, char spec)
{
	unsigned long long	save;
	int					len;
	char				hexa[16];

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
