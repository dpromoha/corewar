/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_st_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:38:31 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 08:40:16 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				to_map(unsigned char *reg, void *content)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg[i] = ((unsigned char *)content)[i];
		i++;
	}
}

int					what_is_argument(t_vm *cor, t_exec *proc, t_arg arg,
		int exist)
{
	if (arg.type == T_REG)
		return (treg_to_int(proc->regs[arg.val - 1]));
	if (arg.type == T_IND)
	{
		if (exist)
			return (return_int_size(cor, proc->op_posit +
						arg.val % OP_POSIT_MOD, 4));
		else
			return (return_int_size(cor, proc->op_posit + arg.val, 4));
	}
	if (arg.type == T_DIR)
		return (arg.val);
	return (0);
}

void				mapcpy(t_vm *cor, t_exec *proc, unsigned int op_posit,
		void *content)
{
	int	i;

	i = -1;
	while (++i < REG_SIZE)
	{
		cor->arena[modificate_index(op_posit
				+ i)] = ((unsigned char *)content)[REG_SIZE - i - 1];
		if (cor->take_v)
		{
			cor->visu->attr_arena[modificate_index(op_posit
					+ i)].owner = proc->parent_id;
			cor->visu->attr_arena[modificate_index(op_posit
					+ i)].store_bright = STORE_BRIGHT_TIME;
		}
	}
}

void				i_sti(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.arg_2 = what_is_argument(cor, proc, cor->args[2], 1);
		a.arg_1 = what_is_argument(cor, proc, cor->args[1], 1);
		mapcpy(cor, proc, proc->op_posit + ((a.arg_1 + a.arg_2) % OP_POSIT_MOD),
				proc->regs[cor->args[0].val - 1]);
	}
}

void				i_st(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.result = what_is_argument(cor, proc, cor->args[0], 1);
		if (cor->args[1].type == T_REG)
			to_map(proc->regs[cor->args[1].val - 1], (void *)&a.result);
		else if (cor->args[1].type == T_IND)
			mapcpy(cor, proc, proc->op_posit + cor->args[1].val % OP_POSIT_MOD,
					(void *)&a.result);
	}
}
