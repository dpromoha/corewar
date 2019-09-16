/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:48:48 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:49:37 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int			i;
	int			output;
	t_listik	*listik;
	t_listik	*copy;
	va_list		ap;

	i = 0;
	output = 0;
	va_start(ap, format);
	listik = collect(format, ap);
	copy = listik;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && listik->width >= -1)
		{
			output += form_val(format, &i, &listik, ap);
			listik = listik->next;
		}
		else
			c_s(format, &i, &listik, &output);
	}
	va_end(ap);
	free_listik(copy);
	return (output);
}
