/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:40:42 by pbernier          #+#    #+#             */
/*   Updated: 2017/06/13 07:37:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

unsigned char				spec_unchar(char spec, va_list ap)
{
	spec += 0;
	return ((unsigned char)va_arg(ap, int));
}

unsigned int				spec_unint(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, unsigned int));
}

unsigned short int			spec_unsint(char spec, va_list ap)
{
	spec += 0;
	return ((unsigned short int)va_arg(ap, int));
}

unsigned long int			spec_unlint(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, unsigned long int));
}

unsigned long long int		spec_unllint(char spec, va_list ap)
{
	spec += 0;
	return (va_arg(ap, unsigned long long int));
}
