/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/05/30 17:51:06 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
		ft_putnbr(printf("v >%05.3d<\n", 1));
		ft_putstr("\n\n");
		ft_putnbr(ft_printf("f >%05.3d<\n", 1));
		ft_putstr("\n");
	return (0);
}
