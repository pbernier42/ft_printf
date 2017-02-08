/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:52:16 by rlecart           #+#    #+#             */
/*   Updated: 2016/12/02 20:20:43 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	str = NULL;
	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		i = 0;
		j = 0;
		if (!(str = ft_strnew(len_s1 + len_s2)))
			return (NULL);
		while (i < len_s1)
		{
			str[i] = s1[i];
			i++;
		}
		while (j < len_s2)
			str[i++] = s2[j++];
		str[len_s1 + len_s2 + 1] = '\0';
	}
	return (str);
}
