/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:11:03 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/03 16:11:05 by pbernier         ###   ########.fr       */
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
