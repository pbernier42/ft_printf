/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/05/26 14:07:39 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
		ft_putnbr(printf("v >%5+d<\n", 42));
		ft_putstr("\n\n");
		ft_printf("rr%#+6ooui\n", 45);
		ft_putnbr(ft_printf("f >%5+d<\n", 42));
		ft_putstr("\n");
	return (0);
}
