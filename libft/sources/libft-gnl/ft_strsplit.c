/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:22:47 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/28 13:20:02 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countwords(char const *words, char c)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (*words)
	{
		if (*words == c)
			a = 0;
		else if (a == 0)
		{
			a = 1;
			i++;
		}
		words++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		start;
	int		j;
	int		iter;
	char	**split;

	j = 0;
	iter = 0;
	start = 0;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char*) * ft_countwords(s, c) + 1)))
		return (NULL);
	while (iter < ft_countwords(s, c) && s[iter] && s[j])
	{
		while (s[start] == c)
			start++;
		j = start;
		while (s[j] != c && s[j] != '\0')
			j++;
		split[iter++] = ft_strsub(s, start, j - start);
		start = j;
	}
	split[iter] = 0;
	return (split);
}
