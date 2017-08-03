/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:07:45 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/03 16:07:48 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			remove_char(char *per, char rem)
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
		if (*tmp == '-' || *tmp == '+')
			*tmp = 'R';
		else if (*tmp == '#')
			*tmp = 'D';
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
	int		len;
	int		ret;
	int		save;
	double	dix;

	ret = 0;
	dix = 0.1;
	++x;
	while (per[x] == '+' || per[x] == 'R')
		++x;
	len = x;
	while (per[x] >= '0' && per[x] <= '9')
		x++;
	len = x - len;
	save = x - 1;
	while (len-- > 0)
		ret = ret + ((per[save--] - '0') * (dix *= 10));
	return (ret);
}

void			create_str(char **str, char *per, char spec, char *arg)
{
	int		i;
	int		ret[2];
	char	atr[6];
	char	*my_atr;
	void	(*tab[5])(char **, char, char **, char *);

	i = -1;
	init_ptr(tab);
	my_atr = init_cstr(&atr, str, per, arg);
	while (atr[++i] && (arg) && arg[0])
		if ((ft_strchr(my_atr, atr[i])))
			tab[i](&my_atr, spec, str, arg);
	ret[0] = pre_str(spec, ft_strchr(per, '.'), &arg, my_atr);
	delate_zero(str, &arg);
	*str = ft_strjoin_clean(str, &arg);
	ft_strdel(&arg);
	ret[1] = wof_str(str, per, ft_strlen(my_atr), spec);
	ft_strdel(&my_atr);
	if (ret[0] >= 0 && ret[1] >= 0 && ret[1] > ret[0])
	{
		i = 0;
		while ((*str)[i] == '0' && ret[1]-- > ret[0])
			(*str)[i++] = ' ';
	}
}
