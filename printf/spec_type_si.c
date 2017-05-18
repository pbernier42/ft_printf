/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_si.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/05/18 16:53:51 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	spec_char(va_list ap, char spec)
{
	spec += 0;
	return ((char)va_arg(ap, int));
}

int			spec_int(va_list ap, char spec)
{
	if (spec == '%')
		return ('%');
	return (va_arg(ap, int));
}

short int	spec_sint(va_list ap, char spec)
{
	spec += 0;
	return ((short int)va_arg(ap, int));
}

long int	spec_lint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, long int));
}

long long int	spec_llint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, long long int));
}
