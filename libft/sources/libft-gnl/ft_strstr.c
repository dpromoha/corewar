/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:01:16 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:05:11 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		i;
	int		length_h;
	int		length_n;

	length_h = ft_strlen(h);
	length_n = ft_strlen(n);
	i = 0;
	if (h[0] == '\0' && n[0] == '\0')
		return (&((char *)h)[i]);
	while (i < length_h)
	{
		if (ft_memcmp(&h[i], n, length_n) == 0)
			return (&((char *)h)[i]);
		i++;
	}
	return (NULL);
}
