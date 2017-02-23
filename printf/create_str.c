/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:45:54 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/23 08:33:25 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		len;
	char	atr[6];
	char	*ret;
	char	*tmp;

	i = 0;
	ft_strcpy(atr, "#0+- \0");
	ret = ft_strsub(per, 0, isolate_atr(per, atr));
	tmp = NULL;
	while (ret[i])
	{
		if (ret[i] == '#')
		{
			if (spec == 'o' && arg[0] != '0')
				tmp = ft_strdup("0");
			else if (spec == 'x')
				tmp = ft_strdup("0x");
			else if (spec == 'X')
				tmp = ft_strdup("0X");
		}
		else if (ret[i] == '0' && !(ft_strchr(ret, '-')))
		{
			len = ret[i + 1] - ft_strlen(arg); // gerer le [i + x]
			if (len > 0)
				tmp = ft_memset(ft_strnew(len), '0', len);
		}
		else if (ret[i] == '+')
		{
			if (arg[0] != '-')
				tmp = ft_strdup("+");
		}
		//else if (ret[i] == '-')
		//{
			// a trouver
		//}
		else if (ret[i] == ' ' && !(ft_strchr(ret, '+')))
		{
			tmp = ft_strdup(" ");
		}
		i++;
	}
	ft_strdel(&per);
	ft_strdel(&ret);
	*str = arg;
}
