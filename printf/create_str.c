/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:45:54 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/14 19:25:51 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remove_char(char *per, char rem)
{
	int		i;
	int		k;
	char	*tmp;

	i = -1;
	k = 1;
	tmp = ft_strchr(per, rem);
	if (rem == '0')
		while (tmp && tmp[k] >= '0' && tmp[k] <= '9')
			tmp[k++] = 'P';
	while ((tmp = ft_strchr(per, rem)))
	{
		if (*tmp == '-')
			*tmp = 'R';
		else
			*tmp = 'P';
	}
}

static void		init_ptr(void (*tab[5])(char **, char, char **, char *))
{
	tab[0] = &atr_sharp;
	tab[1] = &atr_posit;
	tab[2] = &atr_negat;
	tab[3] = &atr_space;
	tab[4] = &atr_zero;
}

int				extract_nbr(char *per, int x)
{
	int 	len;
	int 	ret;
	int 	save;
	double	dix;

	ret = 0;
	dix = 0.1;
	++x;
	//while (per[x] == '-' || per[x] == '+')
		//++x;
	len = x;
	while (per[x] >= '0' && per[x] <= '9')
		x++;
	len = x - len;
	save = x - 1;
	while (len-- > 0)
	 	ret = ret + ((per[save--] - '0') * (dix *= 10));
	return (ret);
}

static int		isolate_atr(char *str, char *spec)
{
	int		i[2];

	ft_memcpy(i, ((int[2]){0, -1}), sizeof(int[2]));
	while (spec[++(i[1])])
	{
		if (str[i[0]] == '0')
			i[0] += ft_intlen_base(extract_nbr(str, i[1]), 10) + 1;
		if (spec[i[1]] == str[i[0]])
			ft_memcpy(i, ((int[2]){++(i[0]), -1}), sizeof(int[2]));
	}
	return (i[0]);
}

void	create_str(char **str, char *per, char spec, char *arg)
{
	int		i;
	char	atr[6];
	char	*my_atr;
	void	(*tab[5])(char **, char, char **, char *);

	i = -1;
	ft_strcpy(atr, "#+- 0\0");
	init_ptr(tab);
	my_atr = ft_strsub(per, 0, isolate_atr(per, atr));
	if (arg[0] == '-')
	{
		*str = ft_strsub(arg, 1, ft_strlen(arg) - 1);
		ft_strdel(&arg);
		arg = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_memset(ft_strnew(1), '-', 1);
	}
	else if (!(*str = ft_strnew(2)))
		exit(-1);
	if (spec == 'x' && arg[0] == '0')
		ft_strreset(str, 0);
	while (atr[++i] && arg[0])
		if ((ft_strchr(my_atr, atr[i])))
			tab[i](&my_atr, spec, str, arg);
	pre_str(spec, ft_strchr(per, '.'), &arg);
	*str = ft_strjoin_clean(str, &arg);
	ft_strdel(&arg);
	wof_str(str, per, ft_strlen(my_atr));
	ft_strdel(&my_atr);
}
