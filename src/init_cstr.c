/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:41:27 by pbernier          #+#    #+#             */
/*   Updated: 2017/07/11 16:58:31 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		isolate_atr(char *str, char *spec)
{
	int		i[2];

	ft_memcpy(i, ((int[2]){0, -1}), sizeof(int[2]));
	while (spec[++(i[1])])
	{
		if (str[i[0]] == '0' && !ft_strchr(str, '-'))
		{
			if (str[i[0] + 1] == '+' || str[i[0] + 1] == '-')
				++i[0];
			i[0] += ft_intlen_base(extract_nbr(str, i[1]), 10) + 1;
		}
		if (spec[i[1]] == str[i[0]])
			ft_memcpy(i, ((int[2]){++(i[0]), -1}), sizeof(int[2]));
	}
	return (i[0]);
}

char	*init_cstr(char (*atr)[6], char **str, char *per, char *arg)
{
	char	*my_atr;

	ft_strcpy(*atr, "#+- 0\0");
	my_atr = ft_strsub(per, 0, isolate_atr(per, *atr));
	if ((arg) && arg[0] == '-')
	{
		ft_strreset(&arg, ft_strsub(arg, 1, ft_strlen(arg) - 1));
		*str = ft_memset(ft_strnew(1), '-', 1);
	}
	else if (!(*str = ft_strnew(2)))
		exit(-1);
	return (my_atr);
}
