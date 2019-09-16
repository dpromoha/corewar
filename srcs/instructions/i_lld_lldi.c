#include "corewar.h"

/*
** Returns the type of the ith argument following the argcode
*/

static t_arg_type	get_arg_type(unsigned char argcode, int i)
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

/*
** Function that gets the correct value depending on the arg type
*/

static void			get_arg(t_vm *cor, t_exec *proc, int *arg_op_posit, int i)
{
	if (cor->args[i].type == T_REG)
	{
		cor->args[i].val = cor->arena[modificate_index(proc->op_posit + *arg_op_posit)];
		*arg_op_posit += 1;
	}
	else if (cor->args[i].type == T_DIR)
	{
		cor->args[i].val = (cor->op_tab[proc->operation_code - 1].dir_size == 4) ?
				return_int_size(cor, proc->op_posit + *arg_op_posit, DIR_SIZE)
				: (short)(cor->arena[modificate_index(proc->op_posit + *arg_op_posit)] * 256
				+ cor->arena[modificate_index(proc->op_posit + *arg_op_posit + 1)]);
		*arg_op_posit += (cor->op_tab[proc->operation_code - 1].dir_size == 0) ? 4
				: cor->op_tab[proc->operation_code - 1].dir_size;
	}
	else if (cor->args[i].type == T_IND)
	{
		cor->args[i].val = (short)(cor->arena[modificate_index(proc->op_posit + *arg_op_posit)] * 256
				+ cor->arena[modificate_index(proc->op_posit + *arg_op_posit + 1)]);
		*arg_op_posit += 2;
	}
}

/*
** Function that get the values of the arguments necessary for the instruction.
** The types of accepted arguments for the instruction are passed as variadic
** arguments of this function. The function returns true if the types of
** argument are valid, false otherwise.
*/

int					check_argument(t_vm *cor, t_exec *proc)
{
	int				arg_op_posit;
	int				i;
	int				valid;

	arg_op_posit = 2;
	valid = 1;
	i = -1;
	while (++i < cor->op_tab[proc->operation_code - 1].how_much_arg)
	{
		cor->args[i].type = get_arg_type(cor->arena[modificate_index(proc->op_posit
				+ 1)], i);
		get_arg(cor, proc, &arg_op_posit, i);
		if (!(cor->args[i].type & cor->op_tab[proc->operation_code - 1].args[i])
				|| (cor->args[i].type == T_REG && (cor->args[i].val <= 0
						|| cor->args[i].val > REG_NUMBER)))
			valid = 0;
	}
	proc->length_step = arg_op_posit;
	return (valid);
}

void		i_lldi(t_vm *cor, t_exec *proc)
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
			sum = sum * 256 + cor->arena[modificate_index(proc->op_posit + a.result
			 + i)];
		}
		proc->carry = (!sum);
		to_map(proc->regs[cor->args[2].val - 1], (void *)&sum);
	}
}

void		i_lld(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	if (check_argument(cor, proc))
	{
		a.result = what_is_argument(cor, proc, cor->args[0], 0);
		proc->carry = !a.result;
		to_map(proc->regs[cor->args[1].val - 1], (void *)&a.result);
	}
}
