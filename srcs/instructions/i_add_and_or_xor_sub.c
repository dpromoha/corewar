/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_add_and_or_xor_sub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:35:43 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/20 16:36:01 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		i_add(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.arg_1 = treg_to_int(proc->regs[cor->args[0].val - 1]);
		a.arg_2 = treg_to_int(proc->regs[cor->args[1].val - 1]);
		a.result = a.arg_1 + a.arg_2;
		proc->carry = (!a.result);
		to_map(proc->regs[cor->args[2].val - 1], (void *)&a.result);
	}
}

void		i_and(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.arg_1 = what_is_argument(cor, proc, cor->args[0], 1);
		a.arg_2 = what_is_argument(cor, proc, cor->args[1], 1);
		a.result = a.arg_1 & a.arg_2;
		proc->carry = (!a.result);
		to_map(proc->regs[cor->args[2].val - 1], (void *)&a.result);
	}
}

void		i_or(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.arg_1 = what_is_argument(cor, proc, cor->args[0], 1);
		a.arg_2 = what_is_argument(cor, proc, cor->args[1], 1);
		a.result = a.arg_1 | a.arg_2;
		proc->carry = (!a.result);
		to_map(proc->regs[cor->args[2].val - 1], (void *)&a.result);
	}
}

void		i_xor(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.arg_1 = what_is_argument(cor, proc, cor->args[0], 1);
		a.arg_2 = what_is_argument(cor, proc, cor->args[1], 1);
		a.result = a.arg_1 ^ a.arg_2;
		proc->carry = (!a.result);
		to_map(proc->regs[cor->args[2].val - 1], (void *)&a.result);
	}
}

void		i_sub(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.arg_1 = treg_to_int(proc->regs[cor->args[0].val - 1]);
		a.arg_2 = treg_to_int(proc->regs[cor->args[1].val - 1]);
		a.result = a.arg_1 - a.arg_2;
		proc->carry = (!a.result);
		to_map(proc->regs[cor->args[2].val - 1], (void *)&a.result);
	}
}
