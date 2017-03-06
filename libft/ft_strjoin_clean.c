/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:16:59 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/06 19:23:00 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clean(char **s1, char **s2)
{
//	static int coucou;
	char	*tmp;
	char	*head;

//	printf("|%d = %s|\n", coucou, *s1);
	if (!(*s1))
		*s1 = ft_strnew(0);
	if (!(*s2))
		*s2 = ft_strnew(0);
	head = *s1;
	tmp = ft_strjoin(*s1, *s2);
	*s1 = ft_strdup(tmp);
	ft_strdel(&head);
	ft_strdel(&tmp);
//	ft_strdel(s2);
//	printf("|%d = %s|\n\n", coucou, *s1);
//	sleep(2);
	return (*s1);
}
