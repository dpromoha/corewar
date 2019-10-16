/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 07:46:34 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:05:25 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		length;
	char	*new;

	i = 0;
	length = 0;
	if (!(new = (char*)malloc(sizeof(char) * 2)) || !s)
		return (NULL);
	length = ft_strlen(s);
	ft_memset(new, 0, 2);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!length)
		return (new);
	if (i == length)
		return (new);
	while (!s[length] || s[length] == ' ' || s[length] == '\n' ||
			s[length] == '\t')
		length--;
	if (!(new = (char*)malloc(sizeof(char) * (length - i + 2))))
		return (NULL);
	ft_memset(new, 0, length - i + 2);
	return (ft_strncpy(new, s + i, length - i + 1));
}
