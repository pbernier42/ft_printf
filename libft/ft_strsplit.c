/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 00:43:17 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/25 17:47:17 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static t_strsplit		*ft_memset_new(t_strsplit *ptr)
{
	int		i;

	i = 0;
	while (i < ptr->count_tab)
		ptr->len_by_tab[i++] = 0;
	return (ptr);
}

static t_strsplit		*ft_gsm(char const *s, char c, t_strsplit *ptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(ptr->len_by_tab = (int*)malloc(sizeof(int) * ptr->count_tab)))
		return (NULL);
	ptr = ft_memset_new(ptr);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			ptr->len_by_tab[j]++;
			i++;
			if (s[i] == c || s[i] == '\0')
				j++;
		}
	}
	return (ptr);
}

static t_strsplit		*ft_len_tab(char const *s, char c)
{
	t_strsplit		*ptr;
	int				i;

	ptr = NULL;
	if (!(ptr = (t_strsplit*)malloc(sizeof(t_strsplit))))
		return (NULL);
	ptr->count_tab = 0;
	ptr->len_by_tab = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ptr->count_tab++;
		i++;
	}
	ptr = ft_gsm(s, c, ptr);
	return (ptr);
}

char					**ft_strsplit(char const *s, char c)
{
	t_strsplit		*ptr;
	char			**tab;
	int				i;
	int				j;

	tab = NULL;
	if (s)
	{
		if (!(ptr = ft_len_tab(s, c)))
			return (NULL);
		i = -1;
		j = 0;
		if (!(tab = (char**)malloc(sizeof(char*) * (ptr->count_tab + 1))))
			return (NULL);
		while (++i < ptr->count_tab)
		{
			while (s[j] == c)
				j++;
			tab[i] = ft_strsub(s, j, ptr->len_by_tab[i]);
			j = j + ptr->len_by_tab[i];
		}
		tab[i] = NULL;
		free(ptr);
	}
	return (tab);
}
