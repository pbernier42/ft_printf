/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:45:54 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/04 18:58:01 by pbernier         ###   ########.fr       */
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
		while (tmp[k] >= '0' && tmp[k] <= '9')
			tmp[k++] = 'P';
	while ((tmp = ft_strchr(per, rem)))
		*tmp = 'P';
}

static void		init_ptr(void (*tab[5])(char **, char, char **, char *))
{
	tab[0] = &atr_sharp;
	tab[1] = &atr_posit;
	tab[2] = &atr_negat;
	tab[3] = &atr_space;
	tab[4] = &atr_zero;

	//tab[6] = &atr_lar;
	//tab[4] = &atr_pre;
}

int				extract_nbr(char *per, int *x)
{
	int 	len;
	int 	ret;
	int 	save;
	double	dix;

	ret = 0;
	dix = 0.1;
	len = ++(*x);
	while (per[*x] >= '0' && per[*x] <= '9')
		(*x)++;
	len = *x - len;
	save = *x - 1;
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
		if (str[i[1]] == '0')
			i[0] += ft_intlen_base(extract_nbr(str, &(i[1])), 10) + 1; // {A TESTER} //
		if (spec[i[1]] == str[i[0]])
			ft_memcpy(i, ((int[2]){++(i[0]), -1}), sizeof(int[2]));
	}
	return (i[0] + 1);
}

void	create_str(char **str, char *per, char spec, char *arg)
{
	int		i;
	char	atr[6];
	char	*tmp;
	void	(*tab[5])(char **, char, char **, char *);

	i = -1;
	ft_strcpy(atr, "#+- 0\0");
	init_ptr(tab);
	tmp = ft_strsub(per, 0, isolate_atr(per, atr));
	ft_strdel(&per);
	per = ft_strdup(tmp);
	ft_strdel(&tmp);
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
	while (atr[++i])
		if ((ft_strchr(per, atr[i])))
			tab[i](&per, spec, str, arg);
	*str = ft_strjoin_clean(str, &arg);
	ft_strdel(&arg);
	ft_strdel(&per);
}
