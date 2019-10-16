/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:31:05 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:02:47 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (s11[i] && s22[i] && i < n && s11[i] == s22[i])
		i++;
	if (s11[i] == s22[i])
		return (0);
	if (i == n)
		return (s11[i - 1] - s22[i - 1]);
	else
		return (s11[i] - s22[i]);
}
