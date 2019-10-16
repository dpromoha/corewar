/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_help2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:05:08 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:45:51 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		powk(int after_comma)
{
	int mnozh;

	mnozh = 1;
	while (after_comma > 0)
	{
		mnozh *= 10;
		after_comma--;
	}
	return (mnozh);
}

static double	round(double *num, int after_comma)
{
	t_struct	a;
	double		copy;
	double		after_point_flt;
	int			celoe;
	double		result;

	copy = *num;
	a.i = powk(after_comma + 1);
	after_point_flt = ((*num) * a.i);
	celoe = (int)after_point_flt;
	a.l = (after_point_flt - celoe) * 10;
	if (a.l >= 5)
		celoe += 1;
	result = (double)celoe / (double)a.i;
	return (result);
}

void			ft_floa(double *num, int after_point)
{
	int			mut_ab;
	int			after_point_flt;
	int			multiplier;
	t_struct	a;

	a.i = 0;
	a.ret = 0;
	mut_ab = powk(after_point);
	after_point_flt = (int)((*num) * mut_ab);
	multiplier = powk(after_point - 1);
	while (a.i < after_point)
	{
		a.l = (after_point_flt / multiplier);
		a.l %= 10;
		ft_putnbr(a.l);
		multiplier /= 10;
		a.i++;
	}
}

static void		round_norm(double *num, t_listik **listik)
{
	int		decimal;

	decimal = (long int)((*num) + 0.5);
	if ((*listik)->accur != 0 && (*num) != 0)
		ft_putnbr(decimal);
}

void			normal_fl(double *num, int after_comma, t_listik **listik)
{
	double	copy;
	double	result;

	copy = *num;
	if (!(after_comma) || (*num) == 0)
	{
		while (after_comma--)
			ft_putchar('0');
	}
	else
	{
		while (after_comma--)
		{
			(*num) *= 10;
			if ((*num) < 1)
			{
				result = round(&copy, after_comma);
				ft_floa(&result, after_comma + 1);
				return ;
			}
		}
	}
	round_norm(num, listik);
}
