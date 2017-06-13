/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:22:36 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/22 17:29:02 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplitstr(char const *s, char c)
{
	int		i;
	char	**str;

	i = 0;
	str = NULL;
	if (!(str = ft_strsplit(s, c)))
		return (NULL);
	while (str[i])
	{
		str[i] = ft_strjoin_clean_char(&str[i], c);
		i++;
	}
	return (str);
}
