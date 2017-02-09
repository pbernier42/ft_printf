/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:16:59 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/09 03:16:27 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clean(char **s1, char **s2)
{
	char	*tmp;
	char	*head;

	if (!(*s1))
		*s1 = ft_strnew(0);
	if (!(*s2))
		*s2 = ft_strnew(0);
	head = *s1;
	tmp = ft_strjoin(*s1, *s2);
	*s1 = ft_strdup(tmp);
	ft_strdel(&head);
	ft_strdel(&tmp);
	ft_strdel(s2);
	return (*s1);
}
