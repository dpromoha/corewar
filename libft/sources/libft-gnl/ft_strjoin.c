/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:38:03 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:01:18 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	int		length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(strj = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (s1[j])
		strj[i++] = s1[j++];
	j = 0;
	while (s2[j])
		strj[i++] = s2[j++];
	strj[i] = '\0';
	return (strj);
}
