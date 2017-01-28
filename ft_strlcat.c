/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:50:49 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/18 09:24:20 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		dst_size;
	char		*dst_cpy;
	char		*src_cpy;

	i = -1;
	j = 0;
	dst_cpy = dst;
	src_cpy = (char*)src;
	while (dst_cpy[++i])
		if (i >= size)
			return (i + ft_strlen(src));
	dst_size = i;
	while (src_cpy[j] && i < size - 1)
	{
		if (i >= size)
			return (i + ft_strlen(src));
		dst_cpy[i++] = src_cpy[j++];
	}
	dst_cpy[i] = '\0';
	return (dst_size + ft_strlen(src));
}
