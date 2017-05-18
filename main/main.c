/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/05/18 14:36:10 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
	while (1)
	{
		ft_putnbr(printf("@moulitest: %#.o %#.0o\n", 0, 0));
		ft_putnbr(ft_printf("@moulitest: %#.o %#.0o\n", 0, 0));
		ft_putstr("\n");
	}
	return (0);
}
