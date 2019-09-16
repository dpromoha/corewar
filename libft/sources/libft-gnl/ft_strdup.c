/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:56:04 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:00:46 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (s[length] != '\0')
		length++;
	if (!(str = (char*)malloc(sizeof(*str) * length + 1)))
		return (NULL);
	while (i < length)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
