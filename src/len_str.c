/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:25:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/06/13 02:15:23 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ret_pw(char *w_atr)
{
	int		i;
	int		ret;
	int		isneg;

	i = 0;
	ret = 0;
	isneg = 0;
	if (!w_atr || !w_atr[i])
		return (-1);
	while (w_atr[i] && w_atr[i] != '.')
	{
		if (w_atr[i] == '-')
			isneg = 1;
		if (w_atr[i] >= '0' && w_atr[i] <= '9')
			ret = ret * 10 + w_atr[i] - '0';
		i++;
	}
	if (isneg == 1)
		ret *= -1;
	return (ret);
}

int		pre_str(char spec, char *w_atr, char **arg, char *my_atr)
{
	int		i;
	int		len;
	int		ret;
	char	*zero;
	char	spec_dos[9];

	i = 0;
	len = 0;
	my_atr += 0;
	ret = -1;
	if (w_atr)
		ret = ret_pw(w_atr + 1);
	ft_strcpy(spec_dos, "diouxXsS\0");
	//printf("spec = [%c] | *w_atr = [%s] | *arg = [%s] | i = [%d] | len = [%d]\n", spec, w_atr, *arg, i, len);
	while (spec_dos[i] != spec && spec_dos[i])
		i++;
	if (!(w_atr) || !spec_dos[i] || !w_atr[1])
		return (ret);
	if (i <= 5 && (*arg)[0] == '0' && extract_nbr(w_atr, 0) == 0
		&& !(i == 2 && ft_strchr(my_atr, 'D')))
	{
		ft_strreset(arg, ft_strnew(0));
		return (ret);
	}
	len = extract_nbr(w_atr, 0) - ft_strlen(*arg);
	if (len > 0 && i <= 5)
	{
		zero = ft_memset(ft_strnew(len), '0', len);
		*arg = ft_strjoin_clean(&zero, arg);
	}
	else if (len < 0 && i >= 6)
		*arg = ft_strsub(*arg, 0, ft_strlen(*arg) + len);
	return (ret);
}

void	delate_zero(char **str, char **arg)
{
	int	len_str;
	unsigned int	i;

	if ((len_str = (ft_strlen(*str)) - 1) == -1)
		return ;
	i = 0;
	//printf("str = [%s], arg = [%s], len_str = [%d]\n", *str, *arg, len_str);
	while (*str && **str && (*str)[len_str] == '0'
			&& (*arg)[i] == '0' && i != ft_strlen(*arg) - 1)
	{
		(*str)[len_str] = '\0';
		--len_str;
		++i;
	}
}

int		wof_str(char **str, char *per, int len_my_atr, char spec)
{
	int		ret;
	int		wof;
	int		len_arg;
	char	*tmp;
	char	*w_atr;

	ret = -1;
	if (per)
		ret = ret_pw(per);
	wof = 0;
	len_arg = ft_strlen(*str);
	tmp = NULL;
	w_atr = ft_strsub(per, len_my_atr, ft_strlen(per) - len_my_atr);
	//printf("spec = [%c] | *w_atr = [%s] | *str = [%s] | len_my_atr = [%d] | per = [%s]\n", spec, w_atr, *str, len_my_atr, per);
	if (per[0] != '.')
		if ((wof = (extract_nbr(w_atr, -1) - len_arg)) > 0)
		{
			if (spec == 'c' && !(*str)[0])
				wof--;
			tmp = ft_strnew(wof);
			ft_memset(tmp, ' ', wof);
			if (!ft_strchr(per, '-'))
				*str = ft_strjoin_clean(&tmp, str);
			else if (ft_strchr(per, '-'))
			{
				*str = ft_strjoin_clean(str, &tmp);
				ft_strdel(&tmp);
			}
		}
	//printf("spec = [%c] | *w_atr = [%s] | *str = [%s] | len_my_atr = [%d] | per = [%s]\n", spec, w_atr, *str, len_my_atr, per);
	ft_strdel(&per);
	ft_strdel(&w_atr);
	return (ret);
}
