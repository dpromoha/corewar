/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:53:03 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/28 13:25:14 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_length(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		i++;
	}
	if (n > 0)
	{
		while (n / 10 != 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char				*str;
	long long int		nb;
	size_t				i;

	nb = n;
	i = ft_length(nb);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -1 * nb;
	}
	while (nb > 0)
	{
		str[--i] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
