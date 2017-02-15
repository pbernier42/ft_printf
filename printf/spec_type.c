/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:02:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/02/15 18:38:17 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//p
//De plus, elle acceptait D, O, U comme synonymes de ld, lo et lu

int				spec_int(va_list ap, char spec)
{
	if (spec == '%')
		return ('%');
	return (va_arg(ap, int));
}

unsigned int	spec_unint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, unsigned int));
}

char			*spec_str(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, char*));
}

void			*spec_void(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, void*));
}
