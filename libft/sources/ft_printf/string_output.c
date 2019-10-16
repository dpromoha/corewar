/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:01:56 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:02:26 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	char_help(t_listik *listik, int width, int c, char fill)
{
	ft_strchr(listik->flags, '-') ? unicode(listik, c) : 0;
	while (width-- > 1)
		ft_putchar(fill);
	!ft_strchr(listik->flags, '-') ? unicode(listik, c) : 0;
	return (1);
}

int			output_char(t_listik *listik, int c)
{
	char	fill;

	fill = full(listik);
	if (listik->width < 1)
		return (unicode(listik, c));
	else
		char_help(listik, listik->width, c, fill);
	return (listik->width);
}

static void	plus(char *str, int len, int *ret)
{
	int i;

	i = 0;
	while (i < len)
		write(1, &str[i++], 1);
	*ret = *ret + len;
}

int			output_string(t_listik *listik, char *str)
{
	t_struct	a;

	a.ret = 0;
	a.i = 0;
	str = (str == 0 ? "(null)" : str);
	a.detail = full(listik);
	a.l = (listik->accur < (int)ft_strlen(str) && listik->accur != -1
	? listik->accur : (int)ft_strlen(str));
	if (listik->width == -1)
	{
		while (a.i < a.l)
			write(1, &str[a.i++], 1);
		return (a.l);
	}
	ft_strchr(listik->flags, '-') ? plus(str, a.l, &a.ret) : 0;
	while (listik->width-- > a.l)
	{
		ft_putchar(a.detail);
		a.ret++;
	}
	!ft_strchr(listik->flags, '-') ? plus(str, a.l, &a.ret) : 0;
	return (a.ret);
}
