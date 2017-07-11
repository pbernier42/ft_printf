/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:41:15 by pbernier          #+#    #+#             */
/*   Updated: 2017/07/11 17:04:23 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		start_spec(char *str, char *spec)
{
	int		i[2];

	ft_memcpy(i, ((int[2]){0, -1}), sizeof(int[2]));
	while (spec[++(i[1])])
		if (spec[i[1]] == str[i[0]])
			ft_memcpy(i, ((int[2]){++(i[0]), -1}), sizeof(int[2]));
	return (i[0]);
}

static void		isolate_per(char *str, char *spec, int *i)
{
	ft_memcpy(i, ((int[2]){1, 0}), sizeof(int[2]));
	while (str[i[0]] != spec[i[1]])
		if (!(spec[++(i[1])]))
			ft_memcpy(i, ((int[2]){++(i[0]), 0}), sizeof(int[2]));
}

static int		isper(char const *format, int *len, char s[17], char ns[18])
{
	int		i;
	char	last[5];

	i = 0;
	ft_strcpy(s, "sSpdDioOuUxXcC%\0");
	ft_strcpy(ns, "#+- 0.123456789%\0");
	ft_strcpy(last, "hljz\0");
	if (!format[1] || (format[0] == '%' && !ft_strchr(s, format[1])
			&& !ft_strchr(ns, format[1])
			&& !ft_strchr(last, format[1])))
	{
		(*len)++;
		return (0);
	}
	return (-1);
}

char			*ft_decrypt(char const *format, int *i, va_list ap, int *len)
{
	int		n[5];
	char	spec[17];
	char	no_spec[18];
	char	*result;
	void	*arg;

	arg = NULL;
	if (!isper(format, len, spec, no_spec))
		return (ft_strdup("%"));
	isolate_per((char*)format, spec, n);
	n[2] = start_spec((char*)format, no_spec);
	if (spec[n[1]] >= 'A' && spec[n[1]] <= 'Z' &&
			spec[n[1]] != 'X' && spec[n[1]] != 'U')
		spec[n[1]] += 32;
	n[3] = ((n[0] + 1) - n[2]) < 0 ? 0 : ((n[0] + 1) - n[2]);
	n[4] = find_specifier(spec[n[1]], ft_strsub(format, n[2], n[3]), &arg, ap);
	create_str(&result, ft_strsub(format, 1, n[0]), spec[n[1]],
		convert_arg(spec[n[1]], arg, ft_strsub(format, 1, n[0] - 1), n[4]));
	*len += ft_strlen(result);
	if (spec[n[1]] == 'c' && !(int)arg)
		++(*len);
	*i += n[0];
	if (spec[n[1]] == 's' && (arg) && (ft_strcmp((char*)arg, "(null)")) == 0)
		ft_strdel((char**)&arg);
	return (result);
}
