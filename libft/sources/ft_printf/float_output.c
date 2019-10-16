/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:46:53 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:48:29 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prepend_sign(t_listik *listik, double *num)
{
	if (ft_strchr(listik->flags, '+') && *num < 0)
		ft_putchar('-');
	else if (ft_strchr(listik->flags, '+') && *num >= 0)
		ft_putchar('+');
	if (ft_strchr(listik->flags, ' ') && !ft_strchr(listik->flags, '+')
		&& *num < 0)
		ft_putchar('-');
	else if (ft_strchr(listik->flags, ' ')
	&& !ft_strchr(listik->flags, '+') && *num >= 0)
		ft_putchar(' ');
	else if (*num <= 0 && !ft_strchr(listik->flags, '+'))
		ft_putchar('-');
	*num = (*num > 0 ? *num : -(*num));
}

static int	float_length(t_listik *listik, long long num)
{
	int len;

	len = 0;
	num < 0 ? len++ : 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	if (ft_strchr(listik->flags, '+') || ft_strchr(listik->flags, ' '))
		len++;
	if (listik->accur > 0)
		len += listik->accur + 1;
	else if (listik->accur != 0)
		len += 7;
	else if (listik->accur == 0 && ft_strchr(listik->flags, '#'))
		len++;
	return (len);
}

static void	another_fl(t_listik *listik, int af, double num, t_struct a)
{
	if (a.detail == '0')
	{
		ft_prepend_sign(listik, &num);
		width_f(listik, a.i, a.detail);
		float_out(listik, num, af);
	}
	else
	{
		width_f(listik, a.i, a.detail);
		ft_prepend_sign(listik, &num);
		float_out(listik, num, af);
	}
}

int			output_float(t_listik *listik, double num, int after_comma)
{
	t_struct a;

	if (ft_strchr(listik->length, 'l'))
		num = (double)num;
	else if (ft_strchr(listik->length, 'L'))
		num = (long double)num;
	a.i = float_length(listik, (long long)num);
	a.detail = full_16(listik);
	if (ft_strchr(listik->flags, '-'))
	{
		ft_prepend_sign(listik, &num);
		float_out(listik, num, after_comma);
		width_f(listik, a.i, a.detail);
	}
	else
		another_fl(listik, after_comma, num, a);
	if (a.i > listik->width)
		return (a.i);
	return (listik->width);
}
