/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 23:36:11 by pbernier          #+#    #+#             */
/*   Updated: 2017/02/04 17:06:05 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*isolate_per(char *str, char *spec)
{
	int		i[2];

	ft_memcpy(i, ((int[2]){1, 0}), sizeof(int[2]));
	while (str[i[0]] != spec[i[1]])
		if (!(spec[++i[1]]))
			ft_memcpy(i, ((int[2]){++i[0], 0}), sizeof(int[2]));
	return(i);
}

char	*ft_decrypt()
{
	char	*spec;
	int		*nb;

	spec = "sSpdDioOuUxXcC%";
	nb =  isolate_per(, spec);
}
