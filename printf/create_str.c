/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:45:54 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/23 06:23:10 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_str(char **str, char *per, char spec, char *arg, int *len)
{
	if (spec >= 'A' && spec <= 'Z' && spec != 'X')
		spec += 32;
	str += 0;
	per += 0;
	spec += 0;
	arg += 0;
	len += 0;
	ft_strdel(&per);
	*str = arg;
}
