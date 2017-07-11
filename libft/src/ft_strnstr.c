/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 01:39:33 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/21 14:01:00 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (lil[0] == '\0')
		return (char*)(big);
	while (big[i] != '\0')
	{
		j = i;
		k = 0;
		while (big[j] == lil[k] && j < (int)len)
		{
			j++;
			k++;
			if (lil[k] == '\0')
				return (char*)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
