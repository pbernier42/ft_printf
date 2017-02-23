/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/23 06:46:01 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
	int		oui;

	oui = 55;
	ft_putnbr(printf("vrai = %c\n", oui));
	ft_putstr("\n\n");
	ft_putnbr(ft_printf("faux = %c\n", oui));
	ft_putstr("\n\n");
	while (1)
		;
	return (0);
}
