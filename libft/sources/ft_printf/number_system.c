/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_system.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:00:22 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/01 13:00:23 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	from10_to16(t_listik *listik, unsigned long long n, int capital)
{
	int		a;

	if (n == 0 && listik->accur == 0)
		return ;
	a = (capital == 1 ? 'A' : 'a');
	if (n % 16 == n)
	{
		if (n <= 9)
			ft_putchar(n += 48);
		else
			ft_putchar(n = n - 10 + a);
	}
	else
	{
		from10_to16(listik, n / 16, capital);
		n %= 16;
		if (n <= 9)
			ft_putchar(n += 48);
		else
			ft_putchar(n = n - 10 + a);
	}
}

void	from10_to8(t_listik *listik, unsigned long long n)
{
	if (n == 0 && (listik->accur == 0 || ft_strchr(listik->flags, '#')))
		return ;
	if (n % 8 == n)
		ft_putchar(n += 48);
	else
	{
		from10_to8(listik, n / 8);
		ft_putchar(n = n % 8 + 48);
	}
}

void	to10(t_listik *listik, long long n)
{
	if (n == 0 && listik->accur == 0)
		return ;
	if (n % 10 == n)
	{
		if (n < 0)
			ft_putchar(n = n * -1 + 48);
		else
			ft_putchar(n += 48);
	}
	else
	{
		to10(listik, n / 10);
		if (n < 0)
			ft_putchar(n = n % 10 * -1 + 48);
		else
			ft_putchar(n = n % 10 + 48);
	}
}

void	output_uns(t_listik *listik, unsigned long long n)
{
	if (n == 0 && listik->accur == 0)
		return ;
	if (n % 10 == n)
		ft_putchar(n = n + 48);
	else
	{
		output_uns(listik, n / 10);
		ft_putchar(n = n % 10 + 48);
	}
}
