/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:10:56 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:10:59 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_uns(t_listik *listik, unsigned long long num)
{
	int i;

	i = 0;
	if (num == 0 && listik->accur != 0)
		i++;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}

static void	uns_length_field(t_listik *listik, unsigned long long *num)
{
	if (listik->convert == 'U')
		*num = (unsigned long long)*num;
	else if (ft_strlen(listik->length) == 0)
		*num = (unsigned int)*num;
	else if (ft_strcmp(listik->length, "ll") == 0)
		*num = (unsigned long long)*num;
	else if (ft_strcmp(listik->length, "hh") == 0)
		*num = (unsigned char)*num;
	else if (ft_strchr(listik->length, 'h'))
		*num = (unsigned short)*num;
	else if (ft_strchr(listik->length, 'l'))
		*num = (unsigned long)*num;
}

static void	another_uns(t_listik *listik, unsigned long long n, char f, int l)
{
	width_f(listik, l, f);
	add_zero_to(listik, n);
	output_uns(listik, n);
}

int			output_unsig(t_listik *listik, unsigned long long num)
{
	t_struct	a;

	uns_length_field(listik, &num);
	a.i = len_uns(listik, num);
	a.detail = full_16(listik);
	if (ft_strchr(listik->flags, '-'))
	{
		add_zero_to(listik, num);
		output_uns(listik, num);
		width_f(listik, a.i, a.detail);
	}
	else
		another_uns(listik, num, a.detail, a.i);
	if (a.i >= listik->width && a.i >= listik->accur)
		return (a.i);
	else if (listik->accur > listik->width)
		return (listik->accur);
	return (listik->width);
}
