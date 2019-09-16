/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to16_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:08:06 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:08:07 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(t_listik *listik, unsigned long long num)
{
	int		i;

	i = 0;
	if (num == 0 && listik->accur != 0)
		i++;
	if (ft_strchr(listik->flags, '#') && num != 0)
		i += 2;
	while (num)
	{
		i++;
		num /= 16;
	}
	return (i);
}

static void	uns_length_field(t_listik *listik, unsigned long long *num)
{
	if (ft_strlen(listik->length) == 0)
		*num = (unsigned int)*num;
	else if (ft_strcmp(listik->length, "hh") == 0)
		*num = (unsigned char)*num;
	else if (ft_strcmp(listik->length, "ll") == 0)
		*num = (unsigned long long)*num;
	else if (ft_strchr(listik->length, 'h'))
		*num = (unsigned short)*num;
	else if (ft_strchr(listik->length, 'l'))
		*num = (unsigned long)*num;
	else if (ft_strchr(listik->length, 'j'))
		*num = (uintmax_t) * num;
	else if (ft_strchr(listik->length, 'z'))
		*num = (size_t)*num;
}

static void	sign_16(t_listik *listik, int *l)
{
	if (*l < listik->accur)
	{
		if (!(ft_strchr(listik->flags, '#')))
		{
			while (*l != listik->accur)
			{
				ft_putchar('0');
				(*l)++;
			}
		}
	}
}

static void	s_check(t_listik *n, unsigned long long num, int up_down, int *l)
{
	if (num && ft_strchr(n->flags, '#'))
	{
		ft_putchar('0');
		up_down == 1 ? ft_putchar('X') : ft_putchar('x');
	}
	if (*l < n->accur && (ft_strchr(n->flags, '#')))
	{
		while (*l - 2 != n->accur)
		{
			ft_putchar('0');
			(*l)++;
		}
	}
	sign_16(n, l);
}

int			output_16(t_listik *listik, unsigned long long num, int up_low)
{
	t_struct	a;

	uns_length_field(listik, &num);
	a.i = ft_hex_len(listik, num);
	a.detail = full_16(listik);
	if (ft_strchr(listik->flags, '-'))
	{
		s_check(listik, num, up_low, &a.i);
		from10_to16(listik, num, up_low);
		width_f(listik, a.i, a.detail);
	}
	else if (a.detail == '0')
	{
		s_check(listik, num, up_low, &a.i);
		width_f(listik, a.i, a.detail);
		from10_to16(listik, num, up_low);
	}
	else if (a.detail == ' ')
	{
		width_f(listik, a.i, a.detail);
		s_check(listik, num, up_low, &a.i);
		from10_to16(listik, num, up_low);
	}
	CHECK_16(a.i, listik->width);
	return (a.i);
}
