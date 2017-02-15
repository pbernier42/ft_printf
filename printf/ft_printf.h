/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:13:38 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/15 18:35:32 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int				ft_printf(char const *format, ...);
char			*ft_decrypt(char const *format, int *i, va_list ap, int *len);
void			find_specifier(char spec, char *per, void **arg, va_list ap);
char			*convert_arg(char spec, void *arg);
int				spec_int(va_list ap, char spec);
unsigned int	spec_unint(va_list ap, char spec);
char			*spec_str(va_list ap, char spec);
void			*spec_void(va_list ap, char spec);
void			*ft_flags(char spec, char *per, va_list ap,
					void *(tab)(va_list, char));
//int		create_str(char **str, char *per, char spec, void *arg);

#endif
