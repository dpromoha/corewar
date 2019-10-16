/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:03:12 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/01 13:03:53 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		helpful_atoi(char *str)
{
	long	num;
	t_count	a;

	num = 0;
	a.i = 0;
	a.length = 0;
	a.sign = 1;
	while (str[a.i] == ' ' || str[a.i] == '\t' || str[a.i] == '\n'
		|| str[a.i] == '\v' || str[a.i] == '\f')
		a.i++;
	if ((str[a.i]) == '-')
		a.sign = -1;
	if ((str[a.i]) == '-' || (str[a.i]) == '+')
		a.i++;
	while (str[a.i] == '0')
		a.i++;
	while (str[a.i] >= '0' && str[a.i] <= '9')
	{
		num = num * 10 + (str[a.i++] - '0');
		a.length++;
	}
	a.j = num * a.sign;
	return (a.j);
}
