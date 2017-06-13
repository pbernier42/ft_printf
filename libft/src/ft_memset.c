/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 07:15:57 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/14 15:20:26 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cpy;
	unsigned int	c_cpy;

	b_cpy = b;
	c_cpy = (unsigned int)c;
	while (len-- != 0)
		*b_cpy++ = c_cpy;
	return (b);
}
