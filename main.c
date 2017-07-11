/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:41:03 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 16:07:54 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "includes/ft_printf.h"
//"%hhS, %hhS", 0, L"米米"
int		main(void)
{
	ft_printf("%zo, %zu, %zx, %zX, %zD, %zO", USHRT_MAX, USHRT_MAX, USHRT_MAX, USHRT_MAX, USHRT_MAX, USHRT_MAX);
	return (0);
}
