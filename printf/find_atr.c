/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_atr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 00:22:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/02/27 04:27:45 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	atr_sharp(char **str, char spec, char *arg, char *per, int *x)
{
	int		i;
	char	spec_oxx[4];

	i = 0;
	ft_strcpy(spec_oxx, "oxX\0");
	while (spec_oxx[i] != spec)
		i++;
	if (!spec_oxx[i] || arg[0] == '0')
		return ;
	*str = ft_strdup("0");
	if (spec != 'o')
		ft_strjoin_clean_char(*str, spec);
	per += 0; //??
}

void 	atr_zero(char **str, char spec, char *arg, char *per, int *x)
{
	//int		i;
	int		len;
	char	*tmp;
	//char	spec_diouxx[7];

	i = 0;
	len = extract_nbr(per, ++(*x)) - ft_strlen(str) + ft_strlen(arg);
	--(*x);
	tmp = NULL;
	//ft_strcpy(spec_diouxx, "diouxX\0"); //?
	//while (spec_diouxx[i] != spec)
	//	i++;
	if (/*!spec_diouxx[i] || */ft_strchr(per, '-') || ft_strchr(per, '.') ||
		0 <= len)
		return ;
		// A REVOIR
	tmp = ft_memset(ft_strnew(len), '0', len); //a secu
	//opti
	if (arg[0] == '-')
	{
		ft_strjoin_clean(ft_strdup("-"), tmp);
		arg = ft_strsub(arg, 1, (ft_strlen(arg) - 1))
	}
	else if ((ft_strlen(str)))
		*str = ft_strjoin_clean(str, tmp);
	*str = ft_strjoin_clean(str, arg);
	ft_strdel(&tmp);
	ft_strdel(&arg); //?
}

void 	atr_space(char **str, char spec, char *arg, char *per, int *x)
{
	int		i;
	char	spec_diouxx[7];

	ft_strcpy(spec_diouxx, "diouxX\0"); //?
	while (spec_diouxx[i] != spec)
		i++;
	if (!spec_diouxx[i] || arg[0] == '-' || (ft_strlen(*str)))
		return ;
	*str = ft_strjoin_clean(ft_strdup(" "), arg);
}
