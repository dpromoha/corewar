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
	t_argument 	a;

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
