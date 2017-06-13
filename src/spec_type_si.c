/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_si.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/06/13 07:37:33 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char			spec_char(char spec, va_list ap)
{
	spec += 0;
	return ((char)va_arg(ap, int));
}

int				spec_int(char spec, va_list ap)
{
	if (spec == '%')
		return ('%');
	return (va_arg(ap, int));
}

short int		spec_sint(char spec, va_list ap)
{
	spec += 0;
	return ((short int)va_arg(ap, int));
}

long int		spec_lint(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, long int));
}

long long int	spec_llint(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, long long int));
}
