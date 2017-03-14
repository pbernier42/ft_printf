/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/14 19:52:33 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
	int		oui;

	oui = 555;
	ft_putnbr(printf("vrai = |@moulitest: %s|\n", NULL));
	ft_putstr("\n\n");
	ft_putnbr(ft_printf("faux = |@moulitest: %s|\n", NULL));
	ft_putstr("\n\n");
	printf("%#+.d", 0);
	return (0);
}
