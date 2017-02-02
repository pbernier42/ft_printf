/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:51:01 by exam              #+#    #+#             */
/*   Updated: 2017/01/03 13:30:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

long		ft_itoo(int value)
{
	long		oct;
	long		ten;
	//long		tmp;

	oct = 0;
	ten = 1;
	while (value)
	{
		if (oct += (value % 8) * ten)
			oct *= -1;
		value /= 8;
		ten *= 10;
	}
	return (oct);
}

int main(int ac, char **av)
{
	int	i = atoi(av[1]);

	ac = 0;
	printf("%o - %ld\n", i , ft_itoo(i));
	return (0);
}
