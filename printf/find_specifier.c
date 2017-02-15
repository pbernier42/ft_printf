/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:46:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/15 08:58:21 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//p
//De plus, elle acceptait D, O, U comme synonymes de ld, lo et lu

static void	spec_syn(char spec, char **per)
{
	int		i;
	char	spec_CS[15];
	void	*tmp;

	i = 0;
	ft_strcpy(spec_CS, "ClcSlsDldOloUlu");
	while (spec_CpS[i] != spec)
		i += 3;
	*per[ft_strlen(*per) - 1] = '\0';
	*per = ft_strjoin_clean(*per, ft_strsub(spec_CSp, i + 1, 2));
}

static void	*spec_str(char spec, char **per/*, va_list ap*/)
{
	void	*tmp;

	if (spec != 's')
		return (NULL);
	//flags ft_flags != NULL
	//done a tmp const char *
	return (/*va_arg(ap, typeof(tmp)*/);
}

static void	*spec_unint(char spec, char **per/*, va_list ap*/)
{
	int		i;
	char	spec_ouxX[4];
	void	*tmp;

	i = 0;
	ft_strcpy(spec_ouxX, "ouxX");
	while (spec_ouxX[i] != spec)
		i++;
	if (!spec_ouxX[i])
		return (NULL);
	//if ft_flags != NULL
	//done a tmp unsigned char
	return (/*va_arg(ap, typeof(tmp)*/);
}

static void	*spec_int(char spec, char **per/*, va_list ap*/)
{
	int		i;
	char	spec_idc[3];
	void	*tmp;

	i = 0;
	ft_strcpy(spec_idc, "dic%");
	while (spec_idc[i] != spec)
		i++;
	if (!spec_idc[i])
		return (NULL);
	if (spec_idc[i] == '%')
		return ('%');
	//if ft_flags != NULL
		tmp = flag
	//else done a tmp int
		tmp = int
	return (/*va_arg(ap, typeof(*tmp)*/);
}

void		*find_specifier(char spec, char *per, void **arg/*, va_list ap*/)
{
	int		i;
	//char	str[5] = "qwert";
	void	*(*tab[3])(char, char *);

//	if (!(tab = (void**)malloc(sizeof(void*) * 4)))
//		return (NULL);
/*	tab[0] = (void *)ft_strlen;
	tab[1] = (void *)ft_strdup;
	tab[2] = (void *)ft_atoi;
	tab[3] = NULL;
	ft_putnbr((int)(tab[0](str)));
	ft_putstr("\n");*/
	spec += 0;
	per += 0;

	i = 0;
	spec_syn(spec, &per);
	tab[1] = (void *)spec_unint;
	tab[2] = (void *)spec_str;
	tab[3] = (void *)spec_syn;
	while (!(*arg = *(tab[i])(spec, &per)))
		i++;
}
