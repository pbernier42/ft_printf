/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:25:21 by pbernier          #+#    #+#             */
/*   Updated: 2017/06/13 07:37:31 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		*spec_void(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, void*));
}

char		*spec_str(char spec, va_list ap)
{
	char	*str;

	spec += 0;
	str = va_arg(ap, char*);
	if (!(str) || (str && (ft_strcmp(str, "(null)") == 0)))
		return (ft_strdup("(null)"));
	return (str);
}

ssize_t		spec_ssizet(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, ssize_t));
}

wchar_t		spec_wintt(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, wchar_t));
}

wchar_t		*spec_wchart(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, wchar_t*));
}
