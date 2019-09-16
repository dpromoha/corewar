#include "corewar.h"

void	i_zjmp(t_vm *cor, t_exec *proc)
{
	proc->length_step = (short)(cor->arena[modificate_index(proc->op_posit + 1)] * 256
			+ cor->arena[modificate_index(proc->op_posit + 1 + 1)]);
	proc->length_step %= op_posit_MOD;
	if (!proc->carry)
		proc->length_step = 3;
}
