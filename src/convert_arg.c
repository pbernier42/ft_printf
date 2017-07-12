/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:16:33 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/12 18:16:36 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		pf_itoa_di(int nbr, char **str)
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

void			spec_dx(void *arg, char *per, char **str)
{
	int			len;
	long long	nbr;

	if ((len = ft_strlen(per)) > 0)
		len--;
	if (per[len] == 'j' || per[len] == 'l' || per[len] == 'z')
	{
		nbr = (long long)arg;
		len = ft_llen(nbr);
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
	else
		pf_itoa_di((int)arg, str);
}

char			*convert_arg(char spec, void *arg, char *per, int fct)
{
	int		i;
	int		base[5];
	char	*str;
	char	spec_nosyn[12];

	i = 0;
	fct += 0;
	ft_memcpy(base, ((int[5]){8, 10, 16, 16, 16}), sizeof(int[5]));
	str = NULL;
	ft_strcpy(spec_nosyn, "ouxXpdisc%U\0");
	while (spec_nosyn[i] != spec)
		i++;
	if (i <= 4)
		pf_ullitoa((long long)arg, &str, base[i], spec);
	else if (i == 5 || i == 6)
		spec_dx(arg, per, &str);
	else if (i == 7 && (char*)arg)
		str = ft_strdup((char*)arg);
	else if (i == 8 || i == 9)
		str = ft_strjoin_clean_char(&str, (char)arg);
	else if (i == 10)
		pf_ullitoa((unsigned long long)arg, &str, 10, spec);
	ft_strdel(&per);
	return (str);
}
