/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:02:19 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:04:16 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	n;

	n = 0;
	if (*little == '\0')
		return (char*)(big);
	while (*big != '\0')
	{
		if (n + ft_strlen(little) > len)
			return (NULL);
		if (ft_memcmp(big, little, ft_strlen(little)) == 0)
			return (char*)(big);
		big++;
		n++;
	}
	return (NULL);
}
