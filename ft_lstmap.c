/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:08:22 by rlecart           #+#    #+#             */
/*   Updated: 2016/11/22 00:40:40 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ptr;

	ptr = NULL;
	if (lst && f)
	{
		ptr = f(lst);
		ptr->next = lst->next ? ft_lstmap(lst->next, f) : NULL;
	}
	return (ptr);
}
