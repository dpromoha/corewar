/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:25:43 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/30 09:26:02 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_inf	*new_file(int fd)
{
	t_inf *file;

	if (!(file = (t_inf*)malloc(sizeof(t_inf))))
		return (NULL);
	file->fd = fd;
	file->buf = ft_strnew(BUFF_SIZE);
	if (!file->buf)
	{
		free(file);
		return (NULL);
	}
	file->next = NULL;
	return (file);
}
