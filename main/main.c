/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/12 21:40:05 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
//	ft_putnbr(printf("@moulitest: |%2c|\n", '\0'));
//	ft_putstr("\n\n");
	ft_putnbr(ft_printf("@moulitest: |%2c|\n", '\0'));
	ft_putstr("\n\n");
	return (0);
}
