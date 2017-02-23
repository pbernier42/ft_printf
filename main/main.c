/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:01:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/23 03:18:45 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

int				main(void)
{
	int		oui;

	oui = 0;
	printf("BONJOUR les %s skejgb %d ewghiuwe %x wegoi %p sgji %c soieg HAHAHA\n", "AMIS", 42, 155, &oui, 'h');
	ft_printf("BONJOUR les %s skejgb %d ewghiuwe %x wegoi %p sgji %c soieg HAHAHA\n", "AMIS", 42, 155, &oui, 'h');
	while (1)
		;
	return (0);
}
