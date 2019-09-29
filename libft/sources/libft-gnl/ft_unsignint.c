/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:19:15 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/29 13:19:17 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unsignint(char *str)
{
	int		i;
	char	last_digit;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) < 10)
		return (1);
	last_digit = str[ft_strlen(str) - 1];
	str[ft_strlen(str) - 1] = 0;
	if ((unsigned int)ft_atoi(str) > 4294967295 / 10
			|| ((unsigned int)ft_atoi(str) == 4294967295 / 10
				&& last_digit > 5))
		return (0);
	return (1);
}
