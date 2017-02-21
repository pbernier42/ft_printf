/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:25:21 by pbernier          #+#    #+#             */
/*   Updated: 2017/02/21 01:50:15 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*spec_void(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, void*));
}

char		*spec_str(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, char*));
}
/*
size_t		spec_sizet(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, size_t));
}
*/
ssize_t		spec_ssizet(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, ssize_t));
}

wchar_t		spec_wintt(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, wchar_t));
}

wchar_t		*spec_wchart(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, wchar_t*));
}
