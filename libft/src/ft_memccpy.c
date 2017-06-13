/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:47:17 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/18 06:33:37 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dst_cpy;
	size_t		i;

	dst_cpy = (char*)dst;
	i = -1;
	while (++i < n)
	{
		*(dst_cpy + i) = *((unsigned char *)src + i);
		if (*(dst_cpy + i) == (char)c)
			return (dst_cpy + i + 1);
	}
	return (NULL);
}
