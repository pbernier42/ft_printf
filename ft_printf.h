/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:13:38 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/01 18:02:02 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

# define BONJOUR pf->cha //??

typedef struct		s_struct
{
	va_list			ap;
	int				i;		//iterateur.
	int				len;	//nombre de caractére lu.
	int				dig;	//stockage d'un int.
	char			*str;	//stockage d'une chaine de caractére.
	char			cha;	//stockage d'un caractére.
/*
      c         Character
      d or i    Signed decimal integer
      e         Scientific notation (mantissa/exponent) using e character
      E         Scientific notation (mantissa/exponent) using E character
      f         Decimal floating point
      g         Uses the shorter of %e or %f
      G         Uses the shorter of %E or %f
      o         Signed octal
      s         String of characters
      u         Unsigned decimal integer
      x         Unsigned hexadecimal integer
      X         Unsigned hexadecimal integer (capital letters)
      p         Pointer address
      n         Nothing printed
      %         Character
*/
	char			**compa;//??
	char			*buff;	//??
	char			*head;	//??
	char			*tmp;	//??
	char			tmp2[2];//??
}					t_struct;

#endif
