/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:41:20 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/15 14:36:56 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		undefined(const char *format, int i)
{
	int		x;
	int		save;

	x = 0;
	save = i + 1;
	while (format[i] == ' ')
		i++;
	if (!format[i])
		return (0);
	i = save;
	return (1);
}

void	initpf(int *i, int *len, char **buff, char **tmp)
{
	*i = -1;
	*len = 0;
	*buff = ft_strnew(0);
	*tmp = NULL;
}

void	display(char **buff, char **tmp, int len, va_list ap)
{
	write(1, *buff, len);
	ft_strdel(buff);
	ft_strdel(tmp);
	va_end(ap);
}

int		ft_checkb(char const *format, int *index, int i, int j)
{
	char	s[16];
	char	ns[21];

	ft_strcpy(s, "sSpdDioOuUxXcC%\0");
	ft_strcpy(ns, "#+- 0.123456789%hljz\0");
	while (format[i])
	{
		while (s[j] && format[i] != s[j])
			j++;
		if (!s[j])
			j = 0;
		else
			return (0);
		while (ns[j] && format[i] != ns[j])
			j++;
		if (!ns[j])
		{
			*index += i;
			return (-1);
		}
		else
			j = 0;
		i++;
	}
	return (-1);
}

int		ft_printf(char const *format, ...)
{
	int			i;
	int			len;
	char		*buff;
	char		*tmp;
	va_list		ap;

	initpf(&i, &len, &buff, &tmp);
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
		{
			buff = ft_strjoin_clean_char(&buff, format[i]);
			len++;
		}
		else if ((undefined(format, i)) && !ft_checkb(&format[i + 1], &i, 0, 0))
		{
			tmp = ft_decrypt(&(format[i]), &i, ap, &len);
			buff = ft_strjoin_clean(&buff, &tmp);
		}
	}
	display(&buff, &tmp, len, ap);
	return (len);
}
