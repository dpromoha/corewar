/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:43:05 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:01:30 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (f == NULL || str == NULL)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		fresh[i] = f(str[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
