/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/06 20:11:52 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
	int		oui;

	oui = 555;
	ft_putnbr(printf("vrai = |%-20.10d|\n", oui));
	ft_putstr("\n\n");
	ft_putnbr(ft_printf("faux = |%-20.10d|\n", oui));
	ft_putstr("\n\n");
	return (0);
}
