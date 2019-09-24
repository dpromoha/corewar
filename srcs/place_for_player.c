/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_for_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:10:00 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 09:10:01 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_new_proc(t_exec *process_new, t_vm *vm, int i, int numb)
{
	process_new->parent_id = i + 1;
	process_new->cycle_before_instr = 0;
	process_new->length_step = 0;
	process_new->carry = 0;
	process_new->i_am_alive = 0;
	process_new->op_posit = i * MEM_SIZE / vm->what_is_n_player;
	numb = -vm->players[i]->numb;
	to_map(process_new->regs[0], &numb);
	process_new->next = vm->procs;
	vm->procs = process_new;
}

static void	location(t_vm *vm, int i)
{
	unsigned int j;

	j = 0;
	while (j < vm->players[i]->head.prog_size)
	{
		vm->arena[i * MEM_SIZE / vm->what_is_n_player + j] =
			vm->players[i]->process_code_player[j];
		j++;
	}
}

static void	error_map(t_vm *vm, int numb)
{
	int		i;
	t_exec	*process_new;

	i = -1;
	while (++i < vm->what_is_n_player)
	{
		if (!(process_new = new_proc()))
			error_messages(2, vm);
		vm->number_process++;
		process_new->n = vm->copy_process++;
		init_new_proc(process_new, vm, i, numb);
	}
}

void		place_for_player(t_vm *vm)
{
	int				where_is_empty;
	int				i;

	i = 0;
	where_is_empty = 0;
	while (i < vm->what_is_n_player)
	{
		location(vm, i);
		i++;
	}
	error_map(vm, where_is_empty);
}
