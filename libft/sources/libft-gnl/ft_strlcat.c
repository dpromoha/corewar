/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 09:17:04 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 15:59:59 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t zdst;
	size_t j;
	size_t zsrc;

	i = 0;
	zdst = 0;
	j = 0;
	zsrc = 0;
	zsrc = ft_strlen(src);
	zdst = ft_strlen(dst);
	while (dst[i])
		i++;
	if (size < zdst)
		return (size + zsrc);
	while (size != 0 && src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (zdst + zsrc);
}
