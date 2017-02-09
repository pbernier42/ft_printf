/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:13:38 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/09 05:59:43 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *format, ...);
char	*ft_decrypt(char const *format, int *i/*, va_list ap*/);
void	*find_specifier(char spec, char *per, void **arg/*, va_list ap*/);
int		create_str(char **str, char *per, char spec, void *arg);

#endif

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
