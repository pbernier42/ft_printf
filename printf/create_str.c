/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:45:54 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/27 11:25:41 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remove_char(char *per, char remove)
{
	int		i;
	int		j;
	int		k;
	char	atr[6];
	char	*tmp;

	i = -1;
	j = 0;
	k = 1;
	ft_strcpy(atr, " -+#0\0");
	tmp = NULL;
	while (atr[j] != remove && atr[j])
		j++;
	if (!atr[j])
		return ;
	while (++i <= j)
		while ((tmp = ft_strchr(per, atr[i])))
		{
			*tmp = 'P';
			if (atr[i] == '0')
				while (tmp[k] >= '0' && tmp[k] <= '9')
					tmp[k++] = 'P';
		}
}

static void		init_ptr(void (*tab[5])())
{
	tab[0] = &atr_sharp;
	tab[2] = &atr_pos;
	tab[3] = &atr_neg;
	tab[1] = &atr_space;

	tab[4] = &atr_pre;
	tab[5] = &atr_zero;
	tab[6] = &atr_lar;
}

int				extract_nbr(char *per, int *x)
{
	int 	len;
	int 	ret;
	int 	save;
	double	dix;

	ret = 0;
	dix = 0.1;
	len = *x;
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
		if (spec[i[1]] == str[i[0]])
			ft_memcpy(i, ((int[2]){++(i[0]), -1}), sizeof(int[2]));
	return (i[0] + 1);
}

void	create_str(char **str, char *per, char spec, char *arg)
{
	int		i;
	char	atr[5];
	int		v_alg[4];
	void	(*tab[4])();

	i = -1;
	*str = ft_strnew(0);
	ft_strcpy(atr, "#+- \0");
	ft_memcpy(v_alg, ((int[4]){0, 0, 0, 0}), sizeof(int[4 ]));
	init_ptr(tab);
	per = ft_strsub(per, 0, isolate_atr(per, atr));
	while (atr[++i])
	{
		if (ft_strchr(per, atr[i]) && !v_alg[i]++)
			tab[i]();
		remove_char(per, atr[i]);
	}
	ft_strdel(&per);
}
