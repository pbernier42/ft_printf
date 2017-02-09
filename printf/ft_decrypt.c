/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:49:24 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/09 05:58:31 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		isolate_per(char *str, char *spec, int *i)
{
	ft_memcpy(i, ((int[2]){1, 0}), sizeof(int[2]));
	while (str[i[0]] != spec[i[1]])
		if (!(spec[++(i[1])]))
			ft_memcpy(i, ((int[2]){++(i[0]), 0}), sizeof(int[2]));
}

char			*ft_decrypt(char const *format, int *i/*, va_list ap*/)
{
	char	spec[16];
	int		nb[2];
	char	*result;
	void	*arg;

	ft_strcpy(spec, "sSpdDioOuUxXcC%");

	isolate_per((char*)format, spec, nb);
	//fonction qui trouve spec
//	/*x = */va_arg(ap, typeof(/*QQ*/));
	find_specifier(spec[nb[1]], ft_strsub(format, 1, nb[0]), &arg/*, ap*/);
	
	//convertie si besoin;

	//fonction qui creer le char*
	//1er flag
	//precision
	if (!(create_str(&result, ft_strsub(format, 1, nb[0]), spec[nb[1]], arg)))
		return (NULL);

	//place x dans le Char *;
	*i += nb[0] + 1;
	return (NULL);
}
