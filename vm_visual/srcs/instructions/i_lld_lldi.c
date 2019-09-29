/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_lld_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:40:53 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 08:49:23 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		if_is_dir_args(t_vm *vm, int *arg_op_posit, t_exec *proc, int i)
{
	vm->args[i].val =
			(vm->op_tab[proc->operation_code - 1].dir_size == 4) ?
				return_int_size(vm, proc->op_posit + *arg_op_posit, DIR_SIZE)
				: (short)(vm->arena[modificate_index(proc->op_posit +
							*arg_op_posit)] * 256
				+ vm->arena[modificate_index(proc->op_posit +
					*arg_op_posit + 1)]);
	*arg_op_posit +=
		(vm->op_tab[proc->operation_code - 1].dir_size == 0) ? 4
		: vm->op_tab[proc->operation_code - 1].dir_size;
}

t_arg_type		get_arg_type(unsigned char argcode, int i)
{
	unsigned char	argcode_bits;
	unsigned char	type;

	argcode_bits = 0b11000000 >> (2 * i);
	type = (argcode & argcode_bits) >> (6 - 2 * i);
	if (type == REG_CODE)
		return (T_REG);
	else if (type == DIR_CODE)
		return (T_DIR);
	else if (type == IND_CODE)
		return (T_IND);
	return (0);
}

void			get_arg(t_vm *cor, t_exec *proc, int *arg_op_posit, int i)
{
	if (cor->args[i].type == T_REG)
	{
		cor->args[i].val = cor->arena[modificate_index(proc->op_posit +
				*arg_op_posit)];
		*arg_op_posit += 1;
	}
	else if (cor->args[i].type == T_DIR)
		if_is_dir_args(cor, arg_op_posit, proc, i);
	else if (cor->args[i].type == T_IND)
	{
		cor->args[i].val = (short)(cor->arena[modificate_index(proc->op_posit +
					*arg_op_posit)] * 256
				+ cor->arena[modificate_index(proc->op_posit +
					*arg_op_posit + 1)]);
		*arg_op_posit += 2;
	}
}

void			i_lldi(t_vm *cor, t_exec *proc)
{
	t_argument	a;
	int			sum;
	int			i;

	i = 0;
	if (check_argument(cor, proc))
	{
		a.arg_1 = what_is_argument(cor, proc, cor->args[0], 0);
		a.arg_2 = what_is_argument(cor, proc, cor->args[1], 0);
		a.result = a.arg_1 + a.arg_2;
		sum = cor->arena[modificate_index(proc->op_posit + a.result)];
		while (++i < 4)
		{
			sum = sum * 256 +
				cor->arena[modificate_index(proc->op_posit + a.result
						+ i)];
		}
		proc->carry = (!sum);
		to_map(proc->regs[cor->args[2].val - 1], (void *)&sum);
	}
}

void			i_lld(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.result = what_is_argument(cor, proc, cor->args[0], 0);
		proc->carry = !a.result;
		to_map(proc->regs[cor->args[1].val - 1], (void *)&a.result);
	}
}
