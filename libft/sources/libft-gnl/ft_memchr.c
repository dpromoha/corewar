/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:52:25 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 15:58:12 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy;
	unsigned char	symb;

	copy = (unsigned char*)s;
	symb = (unsigned char)c;
	if (!n)
		return (NULL);
	while (n--)
	{
		if (*copy == symb)
			return ((char*)copy);
		copy++;
	}
	return (NULL);
}
