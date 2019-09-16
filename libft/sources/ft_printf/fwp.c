/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:50:31 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:50:33 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			take_flag(t_listik *listik, const char *format, int *i, va_list ap)
{
	int j;

	j = 0;
	while (FL(format[*i]))
	{
		listik->flags[j++] = format[*i];
		(*i)++;
	}
	take_wid(listik, ap, i, 1) != 1 ? listik->error = (char *)format + (*i)
		: 0;
	return (1);
}

int			take_wid(t_listik *listik, va_list ap, int *i, int check)
{
	int pos;

	pos = 0;
	if (ft_isdigit(listik->format[*i]) || listik->format[*i] == '*')
	{
		CHECK(check);
		spec_width_f(listik, ap, i, &pos);
		while (ft_isdigit(listik->format[*i]) || listik->format[*i] == '*')
			(*i)++;
	}
	else if (take_w(listik, ap, i, 1) != 1)
		listik->width = -2;
	else
		listik->width = -1;
	return (1);
}

int			take_w(t_listik *listik, va_list ap, int *i, int check)
{
	if (listik->format[*i] == '.'
	&& (ft_isdigit(listik->format[*i + 1]) || listik->format[*i + 1] == '*'))
	{
		CHECK(check);
		(*i)++;
		prec_star(listik, ap, i);
		while (ft_isdigit(listik->format[*i]) || listik->format[*i] == '*')
			(*i)++;
	}
	else if (listik->format[*i] == '.')
	{
		CHECK(check);
		(*i)++;
		listik->accur = 0;
	}
	else if (take_len(listik, listik->format, i, 1) != 1)
	{
		listik->error = (char *)listik->format + (*i);
		return (0);
	}
	else
		listik->accur = -1;
	return (1);
}

int			take_len(t_listik *listik, const char *f, int *i, int check)
{
	ft_memset(listik->length, 0, 3);
	if ((f[*i] == 'h' && f[*i + 1] == 'h')
			|| (f[*i] == 'l' && f[*i + 1] == 'l'))
	{
		CHECK(check);
		ft_memmove(listik->length, &f[*i], 2);
		(*i) += 2;
	}
	else if (LEN(f[*i]))
	{
		CHECK(check);
		ft_memmove(listik->length, &f[*i], 1);
		(*i) += 1;
	}
	else if (take_type(listik, f, i) != 1)
		return (0);
	return (1);
}
