#include "corewar.h"

/*
** Returns the modified version of an index that insures it is within the scope
** of the VM.
*/

int		modificate_index(int new_op_posit)
{
	if (new_op_posit < 0)
		return (MEM_SIZE + (new_op_posit % MEM_SIZE));
	else
		return (new_op_posit % MEM_SIZE);
}

void	init_copy(t_vm **cor, t_exec **new, t_exec **original)
{
	(*new) = new_proc();
	(*cor)->number_process++;
	(*new)->n = (*cor)->copy_process++;
	(*new)->parent_id = (*original)->parent_id;
	(*new)->carry = (*original)->carry;
	(*new)->i_am_alive = (*original)->i_am_alive;
}

static t_exec	*process_copying(t_vm *cor, t_exec *original)
{
	t_exec	*new;
	int		i;

	new = NULL;
	i = -1;
	init_copy(&cor, &new, &original);
	if (cor->number_process > 4294967295 || new->n > 4294967295)
		error_messages(5, cor);
	else
	{
		while (++i < REG_NUMBER)
			ft_memcpy(new->regs[i], original->regs[i], REG_SIZE);
	}
	return (new);
}

void	i_fork(t_vm *cor, t_exec *proc)
{
	t_argument	a;
	t_exec		*new_proc;

	a.arg_1 = (short)(cor->arena[modificate_index(proc->op_posit + 1)] * 256
				+ cor->arena[modificate_index(proc->op_posit + 1 + 1)]);
	new_proc = process_copying(cor, proc);
	new_proc->cycle_before_instr = 0;
	new_proc->op_posit = modificate_index(proc->op_posit + (a.arg_1 % op_posit_MOD));
	new_proc->next = cor->procs;
	cor->procs = new_proc;
	proc->length_step = 3;
}

void	i_lfork(t_vm *cor, t_exec *proc)
{
	t_argument	a;
	t_exec		*new_proc;

	a.arg_1 = (short)(cor->arena[modificate_index(proc->op_posit + 1)] * 256
				+ cor->arena[modificate_index(proc->op_posit + 1 + 1)]);
	new_proc = process_copying(cor, proc);
	new_proc->cycle_before_instr = 0;
	new_proc->op_posit = modificate_index(proc->op_posit + a.arg_1);
	new_proc->next = cor->procs;
	cor->procs = new_proc;
	proc->length_step = 3;
}
