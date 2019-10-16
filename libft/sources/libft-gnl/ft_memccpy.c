/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 08:51:19 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 15:58:04 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			i;

	dest1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*dest1 = *src1;
		if (*src1 == (unsigned char)c)
			return (dest1 + 1);
		dest1++;
		src1++;
		i++;
	}
	return (0);
}
