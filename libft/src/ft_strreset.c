/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:18:36 by pbernier          #+#    #+#             */
/*   Updated: 2017/04/12 20:59:28 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreset(char **as, char *reset)
{
	ft_strdel(as);
	*as = ft_strdup(reset);
	ft_strdel(&reset);
}
