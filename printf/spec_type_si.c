/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_si.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/03/17 17:54:49 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*spec_char(va_list ap, char spec)
{
	char	ret[2];

	spec += 0;
	ft_memcpy(ret, ((char[2]){(char)va_arg(ap, int), '\0'}), sizeof(char[2]));
	return ((char *)ret);
}

char	*spec_int(va_list ap, char spec)
{
	int		len;
	int		arg;
	char	*ret;

	if (spec == '%')
		return ((char *)((char[2]){'%', '\0'}));
	arg = va_arg(ap, int);
	pf_itoa(int nbr, char **str);

	return (ret);
}

char	*spec_sint(va_list ap, char spec)
{
	spec += 0;
	return ((short int)va_arg(ap, int));
}

char	*spec_lint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, long int));
}

char	*spec_llint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, long long int));
}
