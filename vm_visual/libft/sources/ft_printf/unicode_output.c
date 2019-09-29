/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:08:36 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:09:32 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		bytes_size(wchar_t c)
{
	FIRST(c);
	SECOND(c);
	THIRD(c);
	FOURTH(c);
	return (0);
}

static size_t		help_to_count(wchar_t *s)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] > 0 && s[i] <= 127)
				size += 1;
			else if (s[i] >= 128 && s[i] <= 2047)
				size += 2;
			else if (s[i] >= 2048 && s[i] <= 65535)
				size += 3;
			else if (s[i] >= 65536 && s[i] <= 2097151)
				size += 4;
			i++;
		}
	}
	return (size);
}

static int			output_how_much(t_listik *listik, wchar_t *str)
{
	int	count;
	int size;

	count = 0;
	size = 0;
	if (listik->accur != -1 && listik->accur < (int)help_to_count(str))
	{
		while (size + (int)bytes_size(str[count]) <= listik->accur)
			size += (int)bytes_size(str[count++]);
	}
	else
	{
		if (str)
		{
			while (str[count] != '\0')
				count++;
		}
		else
			return (0);
	}
	return (count);
}

static void			plus(t_listik *n, wchar_t *str, int len, int *ret)
{
	if (str)
		*ret += help_unicode(n, str, len);
}

int					output_unicode(t_listik *listik, wchar_t *str)
{
	t_struct a;

	a.ret = 0;
	a.l = output_how_much(listik, str);
	a.size = how_much_size(str, a.l);
	a.detail = full(listik);
	if (listik->width < 0)
	{
		if (str)
			return (help_unicode(listik, str, a.l));
		listik->accur != 0 ? ft_putstr("(null)") : 0;
		return (6);
	}
	ft_strchr(listik->flags, '-') ? plus(listik, str, a.l, &a.ret) : 0;
	while (listik->width-- > a.size)
	{
		ft_putchar(a.detail);
		a.ret++;
	}
	!ft_strchr(listik->flags, '-') ? plus(listik, str, a.l, &a.ret) : 0;
	return (a.ret);
}
