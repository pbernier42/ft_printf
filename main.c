/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:41:03 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 16:46:08 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "includes/ft_printf.h"

int		main(void)
{
	ft_printf("%hhS, %hhS", 0, L"米米");
	return (0);
}
