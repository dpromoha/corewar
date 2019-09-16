/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:00:34 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:04:24 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *string;

	string = (char *)s;
	if (ft_strchr(string, c) == NULL)
		return (0);
	while (*string)
		string++;
	while (*string != c)
		string--;
	return ((char*)string);
}
