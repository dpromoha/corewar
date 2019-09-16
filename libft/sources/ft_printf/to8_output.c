/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to8_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:03:08 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:03:12 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	length_field_8(t_listik *listik, unsigned long long *num)
{
	if (listik->convert == 'O')
		*num = (unsigned long)*num;
	else if (ft_strlen(listik->length) == 0)
		*num = (unsigned int)*num;
	else if (ft_strcmp(listik->length, "hh") == 0)
		*num = (unsigned char)*num;
	else if (ft_strcmp(listik->length, "h") == 0)
		*num = (unsigned short)*num;
	else if (ft_strcmp(listik->length, "ll") == 0)
		*num = (unsigned long long)*num;
	else if (ft_strcmp(listik->length, "l") == 0)
		*num = (unsigned long)*num;
	else if (ft_strcmp(listik->length, "z") == 0)
		*num = (size_t)*num;
}

static int	len_for_8(t_listik *listik, unsigned long long num)
{
	int i;

	i = 0;
	num == 0 && listik->accur != 0 &&
		!ft_strchr(listik->flags, '#') ? i += 1 : 0;
	while (num)
	{
		i++;
		num /= 8;
	}
	ft_strchr(listik->flags, '#') ? i += 1 : 0;
	return (i);
}

static void	sign_8(t_listik *listik, int *i)
{
	ft_strchr(listik->flags, '#') ? ft_putchar('0') : 0;
	if (*i < listik->accur)
	{
		while (*i != listik->accur)
		{
			ft_putchar('0');
			(*i)++;
		}
	}
}

static void	another_8(t_listik *listik, t_struct a, unsigned long long n)
{
	if (a.detail == '0')
	{
		sign_8(listik, &a.l);
		width_f(listik, a.l, a.detail);
		from10_to8(listik, n);
	}
	else
	{
		width_f(listik, a.l, a.detail);
		sign_8(listik, &a.l);
		from10_to8(listik, n);
	}
}

int			output_8(t_listik *listik, unsigned long long num)
{
	t_struct	a;

	length_field_8(listik, &num);
	a.l = len_for_8(listik, num);
	a.detail = full_16(listik);
	if (ft_strchr(listik->flags, '-'))
	{
		sign_8(listik, &a.l);
		from10_to8(listik, num);
		width_f(listik, a.l, a.detail);
	}
	else
		another_8(listik, a, num);
	return (full_8(a.l, listik));
}
