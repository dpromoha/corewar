/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwp_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:50:54 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:51:56 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			take_type(t_listik *listik, const char *format, int *i)
{
	if (F_PR(format[*i]) || format[*i] == 'c' || format[*i] == 'C'
	|| format[*i] == 's' || format[*i] == 'S' || format[*i] == 'i'
	|| format[*i] == 'I' || format[*i] == 'p' || format[*i] == 'P'
	|| format[*i] == 'd' || format[*i] == 'D' || format[*i] == 'o'
	|| format[*i] == 'O' || format[*i] == 'u' || format[*i] == 'U'
	|| format[*i] == 'f' || format[*i] == 'F')
		listik->convert = format[*i];
	else if (format[*i] == 'X')
		listik->convert = 'X';
	else if (format[*i] == 'x')
		listik->convert = 'x';
	else
	{
		listik->convert = format[*i];
		return (0);
	}
	return (1);
}

int			int_len(int num)
{
	int i;

	i = 0;
	num == 0 ? i++ : 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static int	star_bonus(t_listik *listik, int *pos, int *i, va_list ap)
{
	if (ft_isdigit(listik->format[*i]))
	{
		*pos = int_len(ft_atoi(&(listik->format[*i])));
		if (listik->format[*i + *pos] == '*')
			listik->width = va_arg(ap, int);
		else
			listik->width = ft_atoi(&(listik->format[*i]));
	}
	return (1);
}

void		spec_width_f(t_listik *listik, va_list ap, int *i, int *pos)
{
	star_bonus(listik, pos, i, ap);
	if (listik->format[*i] == '*' && !ft_isdigit(listik->format[*i + 1]))
	{
		listik->width = va_arg(ap, int);
		if (listik->width < 0)
		{
			listik->flags[listik->posit] = '-';
			listik->width = listik->width * -1;
		}
	}
	else if (listik->format[*i] == '*' && ft_isdigit(listik->format[*i + 1]))
	{
		(*i)++;
		listik->width = ft_atoi(&(listik->format[*i]));
		va_arg(ap, int);
	}
}

void		prec_star(t_listik *listik, va_list ap, int *i)
{
	if (ft_isdigit(listik->format[*i]))
		listik->accur = ft_atoi(&(listik->format[*i]));
	else if (listik->format[*i] == '*')
	{
		listik->accur = va_arg(ap, int);
		if (listik->accur < 0)
			listik->accur = -1;
	}
}
