/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:51:18 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 15:53:55 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int						start;
	int						n;
	unsigned long long int	number;

	start = 0;
	n = 1;
	number = 0;
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' ||
			str[start] == '\v' || str[start] == '\f' || str[start] == '\r')
		start++;
	if (str[start] == '+')
		start++;
	else if (str[start] == '-')
	{
		n = -1;
		start++;
	}
	while (str[start] >= '0' && str[start] <= '9')
		number = (number * 10) + (str[start++] - '0');
	if (number > 9223372036854775807)
		number = (n > 0) ? -1 : 0;
	return (n * (int)number);
}
