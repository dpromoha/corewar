/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:23:04 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 09:23:05 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	remove_death_proc(t_vm *vm)
{
	t_exec *current;
	t_exec *previous;

	previous = NULL;
	current = vm->procs;
	while (current)
	{
		if (current->i_am_alive <= vm->cycles - vm->cycle_to_die
				|| vm->cycle_to_die <= 0)
		{
			if (previous && vm->number_process--)
				previous->next = current->next;
			else
				vm->procs = current->next;
			delete_proc(&current);
			current = (previous) ? previous->next : vm->procs;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

static void	init_error_flag(t_vm *vm)
{
	remove_death_proc(vm);
	if (vm->live_number >= NBR_LIVE || vm->live_n_reduction >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->live_n_reduction = 1;
	}
	else
		vm->live_n_reduction++;
	vm->new_cycles = 0;
	vm->live_number = 0;
}

static void	init_instr(t_vm *vm, t_exec *proc)
{
	proc->operation_code = vm->arena[proc->op_posit];
	if (proc->operation_code == 0 || proc->operation_code > 16)
		proc->cycle_before_instr = 1;
	else
	{
		proc->cycle_before_instr =
			vm->op_tab[proc->operation_code - 1].cycle_before_instr;
	}
}

void		flag_is_dump(t_vm *vm)
{
	int		i;

	if (vm->cycle_to_die <= 0 ||
		vm->new_cycles == (unsigned int)vm->cycle_to_die)
	{
		init_error_flag(vm);
		i = -1;
		while (++i < vm->what_is_n_player)
		{
			vm->players[i]->last_execess = vm->players[i]
					->n_proc_now;
			vm->players[i]->n_proc_now = 0;
		}
	}
	if (vm->dump_using && vm->cycles == vm->cycle_dump)
		dump_flag_size(vm);
}

void		execute(t_vm *vm)
{
	t_exec *alive_process;

	while ((alive_process = vm->procs))
	{
		vm->cycles++;
		vm->new_cycles++;
		while (alive_process)
		{
			if (vm->take_v)
				vm->visu->attr_arena[alive_process->op_posit].cursor = true;
			if (!alive_process->cycle_before_instr)
				init_instr(vm, alive_process);
			if (!(--(alive_process->cycle_before_instr)))
			{
				if (alive_process->operation_code && alive_process->operation_code <= 16)
					vm->op_tab[alive_process->operation_code - 1].f(vm, alive_process);
				else
					alive_process->length_step = 1;
				alive_process->op_posit =
				modificate_index(alive_process->op_posit + alive_process->length_step);
			}
			alive_process = alive_process->next;
		}
		visual_and_dump(vm);
	}
}
