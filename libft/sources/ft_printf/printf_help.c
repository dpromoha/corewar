/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:00:11 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:01:39 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_s(t_listik *listik, int field, int fill)
{
	if (ft_strchr(listik->flags, '-'))
		ft_putchar(listik->convert);
	while (field-- > 1)
		ft_putchar(fill);
	if (!ft_strchr(listik->flags, '-'))
		ft_putchar(listik->convert);
}

static int	errors_occured(t_listik *listik)
{
	t_struct	a;

	a.i = 0;
	a.detail = full(listik);
	if (listik->width == -1)
	{
		ft_putchar(listik->convert);
		return (1);
	}
	check_s(listik, listik->width, a.detail);
	return (listik->width);
}

int			type_conv(t_listik *listik, va_list ap)
{
	if (listik->convert == 'c' || listik->convert == 'C')
		return (output_char(listik, va_arg(ap, int)));
	else if (listik->convert == 's' && ft_strcmp("l", listik->length) != 0)
		return (output_string(listik, va_arg(ap, char *)));
	else if (listik->convert == 'S'
	|| (listik->convert == 's' && ft_strcmp("l", listik->length) == 0))
		return (output_unicode(listik, va_arg(ap, wchar_t*)));
	else if (listik->convert == 'p' || listik->convert == 'P')
		return (output_pointer(listik, va_arg(ap, void *)));
	else if (listik->convert == 'd' || (listik->convert == 'i')
	|| listik->convert == 'D')
		return (output_int(listik, va_arg(ap, long long)));
	else if (listik->convert == 'o' || listik->convert == 'O')
		return (output_8(listik, va_arg(ap, unsigned long long)));
	else if (listik->convert == 'u' || listik->convert == 'U')
		return (output_unsig(listik, va_arg(ap, unsigned long long)));
	else if (listik->convert == 'x')
		return (output_16(listik, va_arg(ap, unsigned long long), 0));
	else if (listik->convert == 'X')
		return (output_16(listik, va_arg(ap, unsigned long long), 1));
	else if (listik->convert == 'f' || listik->convert == 'F')
		return (output_float(listik, va_arg(ap, double), listik->accur));
	else if (listik->convert == '%')
		return (output_percent(listik));
	return (errors_occured(listik));
}

void		c_s(const char *f, int *i, t_listik **h, int *p)
{
	if (f[*i] != '%')
	{
		ft_putchar(f[*i]);
		(*i)++;
		(*p)++;
	}
	else
	{
		*h = (*h)->next;
		while (FL(f[*i]) || F_PR(f[*i]))
			(*i)++;
	}
}

int			form_val(const char *format, int *i, t_listik **head, va_list ap)
{
	int	output;

	output = type_conv(*head, ap);
	(*i)++;
	while (format[*i] != (*head)->convert)
		(*i)++;
	(*i)++;
	return (output);
}
