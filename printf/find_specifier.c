/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:46:28 by rlecart           #+#    #+#             */
/*   Updated: 2017/02/15 18:47:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*ft_flags(char spec, char *per, va_list ap,
		void *(tab)(va_list, char))
{
	int		i;
	int		len;
	char	lm[2];
	char	flags[4];

	i = 0;
	len = ft_strlen(per);
	ft_memcpy(lm, ((char[2]){'\0', '\0'}), sizeof(char[2]));
	ft_strcpy(flags, "hljz");
	if (len >= 2)
		ft_memcpy(lm, ((char[2]){per[len - 2], '\0'}), sizeof(char[2]));
	while (flags[i] && flags[i] != lm[0])
		i++;
	if (!(flags[i]))
		return (tab(ap, spec));

	// reperer les flags
	// retour arriere stock dans str[2];
	// if str[0] = '\0'
	//	if iouxX => INT
	// if srt[1] = h || l
	//	retour arriere;

	return (NULL);
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
	char	flags[2];
	char	spec_nosyn[10];
	void	*(*tab[4])(va_list, char);
	
	i = 0;
	spec_syn(spec, &per);
	ft_strcpy(spec_nosyn, "dic%ouxXsp");
	//ft_flags 
	tab[0] = (void*)spec_int;
	tab[1] = (void*)spec_unint;
	tab[2] = (void*)spec_str;
	tab[3] = (void*)spec_void;
	while (spec_nosyn[i] != spec)
		i++;
	if (i >= 0 && i <= 3)
		i = 0;
	else if (i >= 4 && i <= 7)
		i = 1;
	else if (i == 8)
		i = 2;
	else if (i == 9)
		i = 3;
	*arg = tab[i](ap, spec);
}
