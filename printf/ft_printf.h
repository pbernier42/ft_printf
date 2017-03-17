/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:13:38 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/17 17:26:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int				ft_printf(char const *format, ...);
char			*ft_decrypt(char const *format, int *i, va_list ap, int *len);
void			find_specifier(char spec, char *per, void **arg,va_list ap);
char			*convert_arg(char spec, void *arg);
void			create_str(char **str, char *per, char spec, char *arg);
int				extract_nbr(char *per, int x);
void			remove_char(char *per, char rem);
void			wof_str(char **str, char *per, int len_my_atr);
void			pre_str(char spec, char *w_atr, char **arg);

char			*spec_char(va_list ap, char spec);
char			*spec_int(va_list ap, char spec);
char			*spec_sint(va_list ap, char spec);
char			*spec_lint(va_list ap, char spec);
char			*spec_llint(va_list ap, char spec);

char			*spec_unchar(va_list ap, char spec);
char			*spec_unint(va_list ap, char spec);
char			*spec_unsint(va_list ap, char spec);
char			*spec_unlint(va_list ap, char spec);
char			*spec_unllint(va_list ap, char spec);

char			*spec_void(va_list ap, char spec);
char			*spec_str(va_list ap, char spec);
char			*spec_ssizet(va_list ap, char spec);
char			*spec_wintt(va_list ap, char spec);
char			*spec_wchart(va_list ap, char spec);

void 			atr_sharp(char **per, char spec, char **prefix, char *arg);
void 			atr_posit(char **per, char spec, char **prefix, char *arg);
void 			atr_negat(char **per, char spec, char **prefix, char *arg);
void 			atr_space(char **per, char spec, char **prefix, char *arg);
void 			atr_zero(char **per, char spec, char **prefix, char *arg);


#endif
