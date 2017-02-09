/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:46:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/09 06:16:27 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*spec_int(char spec/*, va_list ap*/)
{
	int		i;
	char	spec_id[2];
	void	*tmp;

	i = 0;
	ft_strcpy(spec_id, "di");
	while (spec_id[i] != spec)
		i++;
	if (!spec_id[i])
		return (NULL);
//	Fonction verif flags
	return (va_arg(ap, typeof(tmp));
}

void			*find_specifier(char spec, char *per, void **arg/*, va_list ap*/)
{
	char str[6] = "qwert";
	void	*(*tab[4])(void*);

//	if (!(tab = (void**)malloc(sizeof(void*) * 4)))
//		return (NULL);
	tab[0] = (void *)ft_strlen;
	tab[1] = (void *)ft_strdup;
	tab[2] = (void *)ft_atoi;
	tab[3] = NULL;
	ft_putnbr((int)(tab[0](str)));
	ft_putstr("\n");
	spec += 0;
	per += 0;

	while (!(*arg = (tab[i])(spec)))
		i++;
	return (NULL);
}
