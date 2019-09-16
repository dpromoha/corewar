/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:58:26 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:58:36 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_sign(t_listik *listik, int field, int detail)
{
	ft_strchr(listik->flags, '-') ? ft_putchar('%') : 0;
	while (field-- > 1)
		ft_putchar(detail);
	!ft_strchr(listik->flags, '-') ? ft_putchar('%') : 0;
}

int			output_percent(t_listik *listik)
{
	char	fill;

	fill = full(listik);
	if (listik->width != -1)
		check_sign(listik, listik->width, fill);
	else
	{
		ft_putchar('%');
		return (1);
	}
	return (listik->width);
}
