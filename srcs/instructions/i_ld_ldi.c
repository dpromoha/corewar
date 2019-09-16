#include "corewar.h"

void		i_ld(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.result = what_is_argument(cor, proc, cor->args[0], 1);
		proc->carry = !a.result;
		to_map(proc->regs[cor->args[1].val - 1], (void *)&a.result);
	}
}

void		i_ldi(t_vm *cor, t_exec *proc)
{
	t_argument	a;
	int			i;
	int			sum;

	i = 0;
	if (check_argument(cor, proc))
	{
		a.arg_1 = what_is_argument(cor, proc, cor->args[0], 1);
		a.arg_2 = what_is_argument(cor, proc, cor->args[1], 1);
		a.result = a.arg_1 + a.arg_2;
		sum = cor->arena[modificate_index(proc->op_posit + a.result % op_posit_MOD)];
		while (++i < 4)
		{
			sum = sum * 256 + cor->arena[modificate_index(proc->op_posit +
				a.result % op_posit_MOD + i)];
		}
		to_map(proc->regs[cor->args[2].val - 1], (void *)&sum);
	}
}
