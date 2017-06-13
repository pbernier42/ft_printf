/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:51:56 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/03 00:11:15 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*ptr;

	ptr = *alst;
	while (ptr)
	{
		del(ptr->content, ptr->content_size);
		free(ptr);
		if (ptr->next)
			*alst = NULL;
		ptr = ptr->next;
	}
}
