/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:58:04 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:40:14 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	take_dot(t_listik *listik, long long base)
{
	to10(listik, base);
	if (ft_strchr(listik->flags, '#') || listik->accur != 0)
		ft_putchar('.');
}

static void	round_f(long long base, t_listik **n, int length, double *num)
{
	int		decimal;

	decimal = (double)((*num) + 0.5);
	if (decimal == 10 || decimal == 100 || decimal == 1000
			|| decimal == 10000 || decimal == 100000 ||
			decimal == 1000000 || decimal == 10000000)
	{
		base += 1;
		take_dot((*n), base);
		while (length--)
			ft_putchar('0');
	}
	else
	{
		take_dot((*n), base);
		if ((*n)->accur != 0 && num != 0)
			ft_putnbr(decimal);
	}
}

static void	nine_n(t_listik **n, double *num, int after_comma, long long base)
{
	int		length;

	length = after_comma;
	if (num)
	{
		while (after_comma--)
			(*num) *= 10;
	}
	else
	{
		while (after_comma--)
			ft_putchar('0');
	}
	round_f(base, n, length, num);
}

static void	zero_accur(t_listik *listik, double *num, long long base)
{
	if (listik->accur == 0 && (*num) >= 0.5)
	{
		base += 1;
		take_dot(listik, base);
	}
	else if ((*num) == 0 && listik->accur != 0)
		take_dot(listik, base);
	else if ((ft_strchr(listik->flags, '#') &&
			(num != 0 && (*num) < 0.5) && listik->accur != 0) ||
			(ft_strchr(listik->flags, '#') && ((*num) >= 0.5 && (*num) <= 0.9)
			&& listik->accur != 0))
		take_dot(listik, base);
}

void		float_out(t_listik *listik, double num, int after_comma)
{
	long long	base;

	base = (long long)num;
	after_comma <= 0 ? after_comma = 6 : 0;
	num -= base;
	zero_accur(listik, &num, base);
	if (ft_strchr(listik->flags, '#') && (num >= 0.5 && num < 0.9)
			&& listik->accur == 0)
	{
		base += 1;
		take_dot(listik, base);
	}
	else if (listik->accur == 0 && num <= 0.5)
	{
		base == 0 ? ft_putchar('0') : 0;
		take_dot(listik, base);
	}
	else if (!ft_strchr(listik->flags, '#'))
		take_dot(listik, base);
	num >= 0.9 ?
		nine_n(&listik, &num, after_comma, base) :
		normal_fl(&num, after_comma, &listik);
}
