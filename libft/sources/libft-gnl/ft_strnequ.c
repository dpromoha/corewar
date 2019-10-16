/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 08:30:49 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 16:03:49 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*s11;
	char	*s22;

	i = 0;
	s11 = (char*)s1;
	s22 = (char*)s2;
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s11, s22, n) == 0)
		return (1);
	else
		return (0);
}
