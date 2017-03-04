/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:49:24 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/04 19:33:50 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		start_spec(char *str, char *spec)
{
	int		i[2];

	ft_memcpy(i, ((int[2]){0, -1}), sizeof(int[2]));
	while (spec[++(i[1])])
		if (spec[i[1]] == str[i[0]])
			ft_memcpy(i, ((int[2]){++(i[0]), -1}), sizeof(int[2]));
	return (i[0]);
}

static void		isolate_per(char *str, char *spec, int *i)
{
	ft_memcpy(i, ((int[2]){1, 0}), sizeof(int[2]));
	while (str[i[0]] != spec[i[1]])
		if (!(spec[++(i[1])]))
			ft_memcpy(i, ((int[2]){++(i[0]), 0}), sizeof(int[2]));
}

char			*ft_decrypt(char const *format, int *i, va_list ap, int *len)
{
	int		nb[3];
	char	spec[17];
	char	no_spec[18];
	char	*result;
	void	*arg;

	ft_strcpy(spec, "sSpdDioOuUxXcC%\0");
	ft_strcpy(no_spec, "#+- 0.123456789%\0");

	// Ajouts de len ('\0')

	// fonction qui trouve spec
	// (nb[0] = taille flags / nb[1] = pos spec)


	isolate_per((char*)format, spec, nb);
	nb[2] = start_spec((char*)format, no_spec);
	if (spec[nb[1]] >= 'A' && spec[nb[1]] <= 'Z' && spec[nb[1]] != 'X')
		spec[nb[1]] += 32;

	// arg = va_list.
	find_specifier(spec[nb[1]],
		ft_strsub(format, nb[2], (nb[0] + 1) - nb[2]), &arg, ap);

	// convert();
	create_str(&result, ft_strsub(format, 1, nb[0]),
			spec[nb[1]], convert_arg(spec[nb[1]], arg));

	// create str
	// 1er flag
	// precision
//	create_str();
//	if (!(create_str(&result, ft_strsub(format, 1, nb[0]), spec[nb[1]], arg)))
//		return (NULL);

	// place x dans le Char *;
//	ft_memdel(&arg);
/*	if ((int*)*arg == '\0')
		*len++;*/
	*len += ft_strlen(result);
	*i += nb[0];
	return (result);
}
