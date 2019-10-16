/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:09:58 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:10:19 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unicode_3(unsigned int c)
{
	unsigned char output[4];

	output[0] = ((c & 258048) >> 12) | 0xE0;
	output[1] = ((c & 4032) >> 6) | 0x80;
	output[2] = (c & 63) | 0x80;
	return (write(1, output, 3));
}

static int	unicode_4(unsigned int c)
{
	unsigned char output[4];

	output[0] = ((c & 1835008) >> 18) | 0xF0;
	output[1] = ((c & 258048) >> 12) | 0x80;
	output[2] = ((c & 4032) >> 6) | 0x80;
	output[3] = (c & 63) | 0x80;
	return (write(1, output, 4));
}

int			unicode(t_listik *listik, unsigned int c)
{
	unsigned char output[4];

	if ((listik->convert == 'c' &&
		ft_strcmp("l", listik->length) != 0))
		return (write(1, &c, 1));
	else if (c >= 128 && c <= 2047)
	{
		output[0] = ((c & 4032) >> 6) | 192;
		output[1] = (c & 63) | 128;
		return (write(1, output, 2));
	}
	else if (c >= 2047 && c <= 65535)
		return (unicode_3(c));
	else if (c >= 65536 && c <= 2097151)
		return (unicode_4(c));
	else
		return (write(1, &c, 1));
}

int			how_much_size(wchar_t *s, int length)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (length > i)
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
	return (size);
}

int			help_unicode(t_listik *listik, const wchar_t *s1, int length)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (i < length)
		size += unicode(listik, s1[i++]);
	return (size);
}
