/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:45:17 by pbernier          #+#    #+#             */
/*   Updated: 2017/02/15 13:56:44 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_itoa_base(long lg_nbr, int base, char **str, char spec)
{
	int 			len;
	char			hexa[16];
	unsigned int	un_nbr;
	long			nbr;

	ft_strcpy(hexa, "0123456789abcdef");
	if (spec == 'X')
		ft_strcpy(hexa, "0123456789ABCDEF");
	nbr = (int)lg_nbr;
	if (spec != 'd' && spec != 'i')
		nbr = (unsigned int)lg_nbr;				//marche pas pour o ni u
	len = ft_intlen_base(nbr, base);
	*str = ft_strnew(len-- + 1);		//NON SECU//
	if (base == 10 && nbr < 0)
		*str[0] = '-';
	while ((*str)[len] != '-' && len >= 0)
	{
		(*str)[len--] = hexa[ft_absolute(nbr % base)];
		nbr /= base;
	}
}

char	*convert_arg(char spec, void *arg)
{
	char	*str;
	int		i;
	char	spec_nosyn[10];
	int		base[6];

	i = 0;
	ft_strcpy(spec_nosyn, "diouxXsc%p");
	ft_memcpy(base, ((int[6]){10, 10, 8, 10, 16, 16}), sizeof(int[6]));
	while (spec_nosyn[i] != spec)
		i++;
	if (i <= 5)
		ft_itoa_base((long)*arg, base[i], &str, spec);
	if (i == 6)
		str = *arg;
	if (i == 7 || i == 8)
		str = ft_strjoin_clean_char(ft_strnew(0), *arg);
	//p
	return (str);
}
