/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:07:14 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/03 16:07:17 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int							ft_printf(char const *format, ...);
char						*ft_decrypt(char const *format, int *i, va_list ap,
								int *len);
int							find_specifier(char spec, char *per, void **arg,
								va_list ap);
char						*convert_arg(char spec, void *arg, char *per,
								int fct);
void						create_str(char **str, char *per, char spec,
								char *arg);
char						*init_cstr(char (*atr)[6], char **str, char *per,
								char *arg);
int							extract_nbr(char *per, int x);
void						remove_char(char *per, char rem);
int							wof_str(char **str, char *per, int len_my_atr,
								char spec);
void						delate_zero(char **str, char **arg);
int							pre_str(char spec, char *w_atr, char **arg,
								char *my_atr);
int							init_pstr(int i[2], char **arg, char *w_atr,
								char *my_atr);
int							init_wstr(char **per, int *wof, int *len_arg,
								char **str);
int							ret_pw(char *w_atr);

char						spec_char(char spec, va_list ap);
int							spec_int(char spec, va_list ap);
short int					spec_sint(char spec, va_list ap);
long int					spec_lint(char spec, va_list ap);
long long int				spec_llint(char spec, va_list ap);

unsigned char				spec_unchar(char spec, va_list ap);
unsigned int				spec_unint(char spec, va_list ap);
unsigned short int			spec_unsint(char spec, va_list ap);
unsigned long int			spec_unlint(char spec, va_list ap);
unsigned long long int		spec_unllint(char spec, va_list ap);

void						*spec_void(char spec, va_list ap);
char						*spec_str(char spec, va_list ap);
ssize_t						spec_ssizet(char spec, va_list ap);
wchar_t						spec_wintt(char spec, va_list ap);
wchar_t						*spec_wchart(char spec, va_list ap);

void						atr_sharp(char **per, char spec, char **prefix,
								char *arg);
void						atr_posit(char **per, char spec, char **prefix,
								char *arg);
void						atr_negat(char **per, char spec, char **prefix,
								char *arg);
void						atr_space(char **per, char spec, char **prefix,
								char *arg);
void						atr_zero(char **per, char spec, char **prefix,
								char *arg);

void						pf_ullitoa(unsigned long long nbr, char **str,
								int base, char spec);
void						pf_ulitoa(unsigned long nbr, char **str, int base,
								char spec);
void						pf_uitoa(unsigned int nbr, char **str, int base,
								char spec);
void						pf_usitoa(unsigned short nbr, char **str, int base,
								char spec);
void						pf_llitoa(long long nbr, char **str, int base,
								char spec);
void						pf_litoa(long nbr, char **str, int base, char spec);
void						pf_itoa(int nbr, char **str, int base, char spec);
void						pf_sitoa(short nbr, char **str, int base,
								char spec);

#endif
