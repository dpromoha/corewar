/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:33:47 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/20 16:34:09 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	step_back(t_champion **players, int i)
{
	int		copy;

	copy = i;
	while (players[copy])
		copy++;
	while (copy > i)
	{
		players[copy] = players[copy - 1];
		copy--;
	}
}

static void	error_flag_n(t_vm *vm, int i, int copy)
{
	t_champion *swap;

	if (vm->players[i]->numb != i + 1)
	{
		copy = i;
		while (vm->players[i]->numb != 0 && ++copy < vm->what_is_n_player)
		{
			if (vm->players[copy]->numb == 0)
			{
				swap = vm->players[i];
				vm->players[i] = vm->players[copy];
				vm->players[copy] = NULL;
				step_back(vm->players, i);
				vm->players[i + 1] = swap;
			}
		}
		if (vm->players[i]->numb == 0)
			vm->players[i]->numb = i + 1;
		else
			error_messages(9, vm);
	}
}

void		check_flag_n(t_vm *vm)
{
	t_champion	*swap;
	int			i;
	int			copy;

	i = 0;
	while (i < vm->what_is_n_player)
	{
		if (vm->players[i]->numb < i + 1
				&& vm->players[i]->numb != 0)
			error_messages(9, vm);
		copy = i;
		while (vm->players[i]->numb != i + 1 && ++copy < vm->what_is_n_player)
		{
			if (vm->players[copy]->numb == i + 1)
			{
				swap = vm->players[i];
				vm->players[i] = vm->players[copy];
				vm->players[copy] = NULL;
				step_back(vm->players, i);
				vm->players[i + 1] = swap;
			}
		}
		error_flag_n(vm, i, copy);
		i++;
	}
}
