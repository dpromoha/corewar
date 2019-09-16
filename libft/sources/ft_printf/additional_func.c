/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:55:14 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 08:55:20 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	full(t_listik *listik)
{
	return (ft_strchr(listik->flags, '0')
	&& !ft_strchr(listik->flags, '-') ? '0' : ' ');
}

void	width_f(t_listik *listik, int len, char fill)
{
	int width;

	width = listik->width;
	if (listik->accur > len)
		width = width - (listik->accur - len);
	while (width-- > len)
		ft_putchar(fill);
}

char	full_16(t_listik *listik)
{
	if (ft_strchr(listik->flags, '0') && !ft_strchr(listik->flags, '-')
	&& listik->accur == -1)
		return ('0');
	else
		return (' ');
}

int		full_8(int len, t_listik *listik)
{
	if (len >= listik->width && len >= listik->accur)
		return (len);
	else if (listik->accur > listik->width)
		return (listik->accur);
	else
		return (listik->width);
}

int		len_for_long(long long num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}
