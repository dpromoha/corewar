/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:44:19 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/20 16:44:29 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	i_zjmp(t_vm *cor, t_exec *proc)
{
	proc->length_step =
		(short)(cor->arena[modificate_index(proc->op_posit + 1)] * 256
			+ cor->arena[modificate_index(proc->op_posit + 1 + 1)]);
	proc->length_step %= OP_POSIT_MOD;
	if (!proc->carry)
		proc->length_step = 3;
}
