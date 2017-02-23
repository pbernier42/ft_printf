/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:45:17 by pbernier          #+#    #+#             */
/*   Updated: 2017/02/23 03:15:37 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_itoa(long long nbr, char **str)
{
	int		len;

	len = ft_intlen_base(nbr, 10);
	if (!(*str = ft_strnew(len--)))
		exit(-1);
	if (nbr < 0)
		(*str)[0] = '-';
	while (len >= 0 && (*str)[len] != '-')
	{
		(*str)[len--] = ft_absolute(nbr % 10) + '0';
		nbr /= 10;
	}
}

static int		ft_unintlen_base(unsigned long long nbr, int base)
{
	int		len;

	len = 1;
	while ((nbr /= base))
		len++;
	return (len);
}

static void			pf_uitoa(unsigned long long nbr,
						char **str, int base, char spec)
{
	int 	len;
	char	hexa[16];

	ft_strcpy(hexa, "0123456789abcdef");
	if (spec == 'X')
		ft_strcpy(hexa, "0123456789ABCDEF");
	len = ft_unintlen_base(nbr, base);
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

char	*convert_arg(char spec, void *arg)
{
	int		i;
	int		base[5];
	char	*str;
	char	spec_nosyn[10];

	i = 0;
	ft_memcpy(base, ((int[5]){8, 10, 16, 16, 16}), sizeof(int[5]));
	str = NULL;
	ft_strcpy(spec_nosyn, "ouxXpdisc%");
	while (spec_nosyn[i] != spec)
		i++;
	if (i <= 4)
		pf_uitoa((unsigned long long)arg, &str, base[i], spec);
	else if (i == 5 || i == 6)
		pf_itoa((long long)arg, &str);
	else if (i == 7)
		str = (char*)arg;
	else if (i == 8 || i == 9)
		str = ft_strjoin_clean_char(&str, (char)arg);
	return (str);
}
