/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:52:16 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/03 00:09:54 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*str;
	int		len_s1;
	int		i;

	str = NULL;
	if (s1 && c)
	{
		len_s1 = ft_strlen(s1);
		i = 0;
		if (!(str = ft_strnew(len_s1 + 1)))
			return (NULL);
		while (i < len_s1)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = c;
		str[++i] = '\0';
	}
	return (str);
}
