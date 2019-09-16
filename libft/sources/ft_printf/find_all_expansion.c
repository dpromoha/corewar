/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:55:43 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 08:55:45 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_listik	*check(t_listik *listik, const char *f, int *i, va_list ap)
{
	if (!take_flag(listik, f, i, ap) ||
		!take_wid(listik, ap, i, 0) ||
		!take_w(listik, ap, i, 0) ||
		!take_len(listik, f, i, 0) ||
		!take_type(listik, f, i))
		return (listik);
	else
		return (listik);
}

t_listik		*mem_list(const char *format, int *i, va_list ap)
{
	t_listik *new_node;

	new_node = (t_listik *)malloc(sizeof(t_listik));
	new_node->format = format;
	new_node->width = -3;
	new_node->next = NULL;
	new_node->error = 0;
	if (check(new_node, format, i, ap))
		return (new_node);
	return (new_node);
}

void			new_list(t_listik *head, const char *f, int *i, va_list ap)
{
	while (!N(head->next))
		head = head->next;
	head->next = mem_list(f, i, ap);
}

t_listik		*collect(const char *format, va_list ap)
{
	t_listik	*head;
	int			i;

	i = 0;
	head = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += 1;
			if (!N(head))
				new_list(head, format, &i, ap);
			else if (!(head = mem_list(format, &i, ap)))
				return (NULL);
		}
		i++;
	}
	return (head);
}

void			free_listik(t_listik *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}
