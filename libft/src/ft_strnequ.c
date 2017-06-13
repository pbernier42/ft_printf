/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:29:28 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/15 10:47:59 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if ((char*)s1 && (char*)s2)
	{
		while (i < n)
		{
			if ((char)s1[i] != (char)s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
