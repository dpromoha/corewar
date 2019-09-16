/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:58:52 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:59:24 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pointer_len(t_listik *listik, long n)
{
	int i;

	i = 2;
	if (n == 0 && listik->accur != 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static void	add_after(t_listik *listik, int add, int i)
{
	add = listik->accur - i;
	if (i < listik->accur)
	{
		while (add--)
			ft_putchar('0');
	}
}

static void	count_print(t_listik *listik, long n)
{
	int			i;
	int			add_zero;

	i = 0;
	add_zero = 0;
	ft_putstr("0x");
	n == 0 ? i++ : 0;
	while (n)
	{
		i++;
		n /= 16;
	}
	add_after(listik, add_zero, i);
}

static void	sign_c(t_listik *listik, int len, char detail, long c)
{
	if (detail == '0' || ft_strchr(listik->flags, '-'))
	{
		count_print(listik, c);
		from10_to16(listik, c, 0);
		width_f(listik, len, detail);
	}
	else if (!ft_strchr(listik->flags, '-'))
	{
		width_f(listik, len, detail);
		count_print(listik, c);
		from10_to16(listik, c, 0);
	}
}

int			output_pointer(t_listik *listik, void *address)
{
	t_struct	a;
	long		change;

	a.detail = full(listik);
	change = (long)address;
	a.i = pointer_len(listik, change);
	sign_c(listik, a.i, a.detail, change);
	if (a.i >= listik->width && a.i >= listik->accur)
		return (a.i);
	else if (listik->accur > listik->width)
		return (listik->accur + 2);
	return (listik->width);
}
