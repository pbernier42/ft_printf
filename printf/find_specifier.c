/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:46:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/21 02:28:42 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void		init_ptr(void *(*tab[18]))
{
	*tab[0] = spec_int;
	*tab[1] = spec_sint;
	*tab[2] = spec_lint;
	*tab[3] = spec_lint; //maxint
	*tab[4] = spec_unint;
	*tab[5] = spec_char;
	*tab[6] = spec_llint;

	*tab[7] = spec_unint;
	*tab[8] = spec_unsint;
	*tab[9] = spec_unlint;
	*tab[10] = spec_unlint; //unmaxint
	*tab[11] = spec_ssizet;
	*tab[12] = spec_unchar;
	*tab[13] = spec_unllint;
	*tab[14] = spec_wintt;  //??

	*tab[15] = spec_str;
	*tab[16] = spec_void;
	*tab[17] = spec_wchart; //??
}

static int		ft_flags(char *per, int i)
{
	int		j;
	int		len;
	int		pos[10];
	char	lm[2];
	char	flags[2][7];

	j = 0;
	len = ft_strlen(per);
	ft_strcpy(flags[0], " hljz");
	ft_strcpy(flags[1], "     hl");
	ft_memcpy(lm, ((char[2]){'\0', '\0'}), sizeof(char[2]));
	if (len >= 2)
		ft_memcpy(lm, ((char[2]){per[len - 2], '\0'}), sizeof(char[2]));
	if (len >= 3)
		ft_memcpy(lm, ((char[2]){lm[0], per[len - 3]}), sizeof(char[2]));
	while (lm[0] && flags[0][j] != lm[0])
		j++;
	while (lm[1] && flags[1][j] != lm[1])
		j++;
	ft_memcpy(pos, ((char[10]){0 + j, 0 + j, 0 + j, 12 + j,
				7 + j, 7 + j, 7 + j, 7 + j, 16 + j, 15 + j}), sizeof(char[10]));
	return (pos[i]);
}

static void		spec_syn(char spec, char **per)
{
	int		i;
	char	spec_CSDOU[15];
	char	*tmp;

	i = 0;
	ft_strcpy(spec_CSDOU, "ClcSlsDldOloUlu");
	tmp = NULL;
	while (spec_CSDOU[i] && spec_CSDOU[i] != spec)
		i += 3;
	if (!(spec_CSDOU[i]))
		return ;
	*per[ft_strlen(*per) - 1] = '\0';
	tmp = ft_strsub(spec_CSDOU, i + 1, 2);
	*per = ft_strjoin_clean(per, &tmp);
}

void			find_specifier(char spec, char *per, void **arg, va_list ap)
{
	int		i;
	char	spec_nosyn[10];
	void	*(*tab[18])(va_list, char);

	i = 0;
	spec_syn(spec, &per);
	ft_strcpy(spec_nosyn, "di%couxXps");
	while (spec_nosyn[i] != spec)
		i++;
	*arg = tab[ft_flags(per, i)](ap, spec);
}
