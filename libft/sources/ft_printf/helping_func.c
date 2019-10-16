/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:52:18 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 09:53:22 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_prec(int l, t_listik *listik, long long copy)
{
	if (l < listik->accur && copy >= 0)
		l += (listik->accur - l);
	else if (l <= listik->accur && copy < 0)
		l += (listik->accur - l + 1);
	if ((ft_strchr(listik->flags, '+')
	|| ft_strchr(listik->flags, ' ')) && copy >= 0)
		l++;
	return (l);
}

void	add_zero_to(t_listik *listik, unsigned long long num)
{
	int			i;
	long long	copy;
	int			add_zero;

	i = 0;
	copy = num;
	add_zero = 0;
	num == 0 ? i++ : 0;
	while (copy != 0)
	{
		i++;
		copy /= 10;
	}
	if (i < listik->accur)
	{
		add_zero = listik->accur - i;
		while (add_zero--)
			ft_putchar('0');
	}
}
