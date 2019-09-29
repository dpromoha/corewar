/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:19:33 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/29 13:19:34 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		space_read(int fd)
{
	unsigned char	buf[5];
	int				rval;

	if ((rval = read(fd, buf, 4)) != 4)
		return (-1);
	buf[rval] = 0;
	while (*buf)
		if ((*buf)++ != 0)
			return (-1);
	return (0);
}
