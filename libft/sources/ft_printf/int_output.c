/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:53:39 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:55:08 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			number_len(t_listik *listik, long long num)
{
	int			i;
	long long	copy;

	i = 0;
	if (num == 0 && listik->accur != 0)
		i++;
	copy = num;
	if (num < 0)
		i++;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (check_prec(i, listik, copy));
}

void		what_is_sign(t_listik *listik, long long *num)
{
	if (ft_strchr(listik->flags, '+') && *num < 0)
		ft_putchar('-');
	else if (ft_strchr(listik->flags, '+'))
		ft_putchar('+');
	if (ft_strchr(listik->flags, ' ') && !ft_strchr(listik->flags, '+')
		&& *num < 0)
		ft_putchar('-');
	else if (ft_strchr(listik->flags, ' ') && !ft_strchr(listik->flags, '+'))
		ft_putchar(' ');
	else if (*num < 0 && !ft_strchr(listik->flags, '+'))
		ft_putchar('-');
}

static void	length_field(t_listik *listik, long long *num)
{
	if (listik->convert == 'D')
		*num = (long)*num;
	else if (ft_strlen(listik->length) == 0)
		*num = (int)*num;
	else if (ft_strcmp(listik->length, "hh") == 0)
		*num = (char)*num;
	else if (ft_strcmp(listik->length, "ll") == 0)
		*num = (long long)*num;
	else if (ft_strchr(listik->length, 'h'))
		*num = (short)*num;
	else if (ft_strchr(listik->length, 'l'))
		*num = (long)*num;
	else if (ft_strchr(listik->length, 'z'))
		*num = (ssize_t) * num;
}

static void	another(t_listik *listik, long long *num, int len, char fill)
{
	if (fill == '0')
	{
		what_is_sign(listik, num);
		width_f(listik, len, fill);
		add_zero_to(listik, *num);
		to10(listik, *num);
	}
	else
	{
		width_f(listik, len, fill);
		what_is_sign(listik, num);
		add_zero_to(listik, *num);
		to10(listik, *num);
	}
}

int			output_int(t_listik *listik, long long num)
{
	t_struct	a;

	length_field(listik, &num);
	a.i = number_len(listik, num);
	a.detail = full_16(listik);
	length_field(listik, &num);
	if (ft_strchr(listik->flags, '-'))
	{
		what_is_sign(listik, &num);
		add_zero_to(listik, num);
		to10(listik, num);
		width_f(listik, a.i, a.detail);
	}
	else
		another(listik, &num, a.i, a.detail);
	if (a.i >= listik->width && a.i >= listik->accur)
		return (a.i);
	else if (listik->accur > listik->width)
		return (listik->accur);
	else
		return (listik->width);
}
