/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:49:24 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/21 04:51:12 by pbernier         ###   ########.fr       */
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

char			*ft_decrypt(char const *format, int *i, va_list ap, int *len)
{
	int		nb[2];
	char	spec[16];
	char	*result;
	void	*arg;

	ft_strcpy(spec, "sSpdDioOuUxXcC%");

	// Ajouts de len ('\0')

	// fonction qui trouve spec
	// (nb[0] = taille flags / nb[1] = pos spec)
	isolate_per((char*)format, spec, nb);

	// arg = va_list.
	find_specifier(spec[nb[1]], ft_strsub(format, 1, nb[0]), &arg, ap);

	// convert();
	create_str(result, ft_strsub(format, 1, nb[0]),
			spec[nb[1]], convert_arg(spec[nb[1]], arg));

	// create str
	// 1er flag
	// precision
//	create_str();
//	if (!(create_str(&result, ft_strsub(format, 1, nb[0]), spec[nb[1]], arg)))
//		return (NULL);

	// place x dans le Char *;
	*i += nb[0];
	*len += ft_strlen((char*)arg);
	return (ft_strdup((char*)arg));
}
