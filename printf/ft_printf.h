/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:13:38 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/21 01:50:56 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int							ft_printf(char const *format, ...);
char						*ft_decrypt(char const *format, int *i, va_list ap,
								int *len);
void						find_specifier(char spec, char *per, void **arg,
								va_list ap);
char						*convert_arg(char spec, void *arg);

char						spec_char(va_list ap, char spec);
int							spec_int(va_list ap, char spec);
short int					spec_sint(va_list ap, char spec);
long int					spec_lint(va_list ap, char spec);
long long int				spec_llint(va_list ap, char spec);

unsigned char				spec_unchar(va_list ap, char spec);
unsigned int				spec_unint(va_list ap, char spec);
unsigned short int			spec_unsint(va_list ap, char spec);
unsigned long int			spec_unlint(va_list ap, char spec);
unsigned long long int		spec_unllint(va_list ap, char spec);

void						*spec_void(va_list ap, char spec);
char						*spec_str(va_list ap, char spec);
ssize_t						spec_ssizet(va_list ap, char spec);
wchar_t						spec_wintt(va_list ap, char spec);
wchar_t						*spec_wchart(va_list ap, char spec);
//int		create_str(char **str, char *per, char spec, void *arg);

#endif
