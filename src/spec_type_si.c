/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_si.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:18:16 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/12 18:18:19 by rlecart          ###   ########.fr       */
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
