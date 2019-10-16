/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 09:28:26 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/30 09:28:28 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_help(char *to_read, char *buf, char **line, int i)
{
	to_read = ft_strncpy(to_read, buf, i);
	*line = ft_strjoin(*line, to_read);
	free(to_read);
}

static int		take_inf(char *buf, char **line)
{
	unsigned int	i;
	char			*to_del;
	char			*to_read;

	i = 0;
	to_del = *line;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!(to_read = ft_strnew(i)))
	{
		free(to_del);
		return (-1);
	}
	free_help(to_read, buf, line, i);
	free(to_del);
	return (buf[i] == '\n');
}

static	t_inf	*get_file(t_inf **listich, int fd)
{
	t_inf *target;

	if (!*listich && !(*listich = new_file(fd)))
		return (NULL);
	target = *listich;
	while (target->next && target->fd != fd)
		target = target->next;
	return (target);
}

static void		check(t_inf **output, t_help a)
{
	if ((a.tmp = ft_strchr((*output)->buf, '\n')))
	{
		ft_memmove((*output)->buf, a.tmp + 1,
			ft_strlen(a.tmp + 1));
		ft_strclr((*output)->buf + ft_strlen(a.tmp + 1));
	}
}

int				gnl(const int fd, char **line)
{
	static t_inf	*listich;
	t_inf			*output;
	t_help			a;

	a.second = 1;
	if (line == NULL || !(*line = ft_strnew(1)) || BUFF_SIZE < 1)
		return (-1);
	else if (!(output = get_file(&listich, fd)))
		return (-1);
	else
	{
		while (a.second && !(a.first = take_inf(output->buf, line)))
		{
			ft_strclr(output->buf);
			if ((a.second = read(fd, output->buf, BUFF_SIZE)) < 0)
				return (-1);
		}
		check(&output, a);
	}
	return (ft_strlen(*line) ? 1 : 0 || a.first || a.second);
}
