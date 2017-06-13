/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:55:52 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/13 07:44:26 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int		*ft_countlen(char const *s, char c, int word)
{
	int		i;
	int		j;
	int		count;
	int		*len;

	i = 0;
	j = 0;
	count = 0;
	if (!(len = (int*)malloc(sizeof(int) * word)))
		return (NULL);
	while (j <= word)
	{
		while (s[i] == c)
			i++;
		if (s[i++] != c)
			count++;
		if (s[i] == c || !s[i])
		{
			len[j++] = count;
			count = 0;
		}
	}
	return (len);
}

static void		ft_cat(char const *s, char **str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] && s[i] != c)
			str[j][k++] = s[i++];
		if (s[i] == c || !s[i])
		{
			j++;
			k = 0;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		word;
	int		*len_by_word;
	char	**str;

	i = -1;
	len_by_word = NULL;
	str = NULL;
	if (s)
	{
		word = ft_countword(s, c);
		len_by_word = ft_countlen(s, c, word);
		if (!(str = (char**)malloc(sizeof(char*) * (word + 1))))
			return (NULL);
		while (++i < word)
			if (!(str[i] = ft_strnew(len_by_word[i])))
				return (NULL);
		str[++i] = NULL;
		ft_cat(s, str, c);
		ft_memdel((void**)&len_by_word);
		return (str);
	}
	return (NULL);
}
