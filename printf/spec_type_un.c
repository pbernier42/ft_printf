/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_type_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:40:42 by pbernier          #+#    #+#             */
/*   Updated: 2017/05/18 16:54:15 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char				spec_unchar(va_list ap, char spec)
{
	spec += 0;
	return ((unsigned char)va_arg(ap, int));
}

unsigned int				spec_unint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, unsigned int));
}

unsigned short int			spec_unsint(va_list ap, char spec)
{
	spec += 0;
	return ((unsigned short int)va_arg(ap, int));
}

unsigned long int			spec_unlint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, unsigned long int));
}

unsigned long long int		spec_unllint(va_list ap, char spec)
{
	spec += 0;
	return (va_arg(ap, unsigned long long int));
}
