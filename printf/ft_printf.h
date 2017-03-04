/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:13:38 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/04 18:44:32 by pbernier         ###   ########.fr       */
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
void						create_str(char **str, char *per, char spec,
								char *arg);
void						remove_char(char *per, char rem);

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

void 						atr_sharp(char **per, char spec, char **prefix,
								char *arg);
void 						atr_posit(char **per, char spec, char **prefix,
								char *arg);
void 						atr_negat(char **per, char spec, char **prefix,
								char *arg);
void 						atr_space(char **per, char spec, char **prefix,
								char *arg);
void 						atr_zero(char **per, char spec, char **prefix,
								char *arg);
int							extract_nbr(char *per, int *x);

#endif
