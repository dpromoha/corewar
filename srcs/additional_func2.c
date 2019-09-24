/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:33:13 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 09:48:35 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_exec	*new_proc(void)
{
	t_exec	*new;
	int		i;

	if (!(new = (t_exec *)malloc(sizeof(t_exec))))
		return (NULL);
	i = -1;
	while (++i < REG_NUMBER)
	{
		if (!(new->regs[i] = (unsigned char *)malloc(sizeof(unsigned char)
						* REG_SIZE)))
		{
			while (--i >= 0)
				free(new->regs[i]);
			free(new);
			return (NULL);
		}
		ft_bzero(new->regs[i], sizeof(char) * REG_SIZE);
	}
	new->next = NULL;
	return (new);
}

void	delete_proc(t_exec **proc)
{
	int		i;

	i = -1;
	while (++i < REG_NUMBER)
		free((*proc)->regs[i]);
	free(*proc);
	*proc = NULL;
}

void	free_struct_player(t_champion **player)
{
	if (*player)
		free((*player)->process_code_player);
	free(*player);
	*player = NULL;
}

void	num_flag(t_vm *vm, char **av, int ac, int i)
{
	if (ft_strequ(av[i], "-n"))
	{
		if (i + 2 < ac)
		{
			if (ft_atoi(av[i + 1]) == 0)
				error_messages(7, vm);
		}
		else
			error_messages(10, vm);
		vm->what_is_n_player -= 2;
	}
}
