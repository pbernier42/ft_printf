/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:21:10 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/11 17:16:26 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s1_cpy;
	char	*s2_cpy;

	s1_cpy = s1;
	s2_cpy = (char*)s2;
	while (*s1_cpy)
		s1_cpy++;
	while (*s2_cpy)
		*s1_cpy++ = *s2_cpy++;
	*s1_cpy = '\0';
	return (s1);
}
