/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:46:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/03/17 17:25:49 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_ptr(char *(*tab[18])(va_list, char))
{
	tab[0] = &spec_int;
	tab[1] = &spec_sint;
	tab[2] = &spec_lint;
	tab[3] = &spec_lint; //maxint
	tab[4] = &spec_unint;
	tab[5] = &spec_char;
	tab[6] = &spec_llint;

	tab[7] = &spec_unint;
	tab[8] = &spec_unsint;
	tab[9] = &spec_unlint;
	tab[10] = &spec_unlint; // unmaxint
	tab[11] = &spec_ssizet;
	tab[12] = &spec_unchar;
	tab[13] = &spec_unllint;
	tab[14] = &spec_wintt;  // C = lc

	tab[15] = &spec_str;
	tab[16] = &spec_void;
	tab[17] = &spec_wchart; // ??
}

int				ft_flags(char *per, int i)
{
	int		j;
	int		len;
	int		pos[10];
	char	lm[2];
	char	flags[2][8];

	j = 0;
	len = ft_strlen(per);
	ft_strcpy(flags[0], " hljz\0");
	ft_strcpy(flags[1], "     hl\0");
	ft_memcpy(lm, ((char[2]){'\0', '\0'}), sizeof(char[2]));
	if (len >= 2)
		ft_memcpy(lm, ((char[2]){per[len - 2], '\0'}), sizeof(char[2]));
	if (len >= 3)
		ft_memcpy(lm, ((char[2]){lm[0], per[len - 3]}), sizeof(char[2]));
	while (lm[0] && flags[0][j] != lm[0])
		j++;
	while (lm[1] && flags[1][j] != lm[1])
		j++;
	ft_memcpy(pos, ((int[10]){0 + j, 0 + j, 0 + j, 12 + j, 7 + j,
				7 + j, 7 + j, 7 + j, 16 + j, 15 + j}), sizeof(int[10]));
	return (pos[i]);
}

void			spec_syn(char spec, char **per)
{
	int		i;
	char	spec_csdou[16];
	char	*tmp;

	i = 0;
	ft_strcpy(spec_csdou, "ClcSlsDldOloUlu\0");
	tmp = NULL;
	while (spec_csdou[i] && spec_csdou[i] != spec)
		i += 3;
	if (!(spec_csdou[i]))
		return ;
	(*per)[ft_strlen(*per) - 1] = '\0';
	tmp = ft_strsub(spec_csdou, i + 1, 2);
	*per = ft_strjoin_clean(per, &tmp);
}

void			find_specifier(char spec, char *per, char **arg, va_list ap)
{
	int		i;
	char	spec_nosyn[11];
	char	*(*tab[18])(va_list, char);

	i = 0;
	ft_strcpy(spec_nosyn, "di%couxXps\0");
	init_ptr(&(*tab));
	spec_syn(spec, &per);

	while (spec_nosyn[i] && spec_nosyn[i] != spec)
		i++;
	*arg = tab[ft_flags(per, i)](ap, spec);
	ft_strdel(&per);
}
