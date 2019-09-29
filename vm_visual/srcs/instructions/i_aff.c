/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:36:56 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/20 16:36:57 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			read_for_aff(t_vm *cor)
{
	int size;

	size = 0;
	size = ft_strlen(cor->aff_print);
	if (size == BUFF_SIZE)
	{
		if (!(cor->aff_print =
					(char*)realloc(cor->aff_print, size + BUFF_SIZE)))
			error_messages(9, cor);
	}
	ft_bzero(cor->aff_print + size, BUFF_SIZE);
	return (size);
}

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
		cor->args[i].type =
			get_arg_type(cor->arena[modificate_index(proc->op_posit
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

int					treg_to_int(unsigned char *reg)
{
	int		i;
	int		result;

	i = 3;
	result = reg[3];
	while (i >= 0)
	{
		result = result * 256 + reg[i];
		i--;
	}
	return (result);
}

void				i_aff(t_vm *cor, t_exec *proc)
{
	int		tmp;
	char	c;
	int		size;

	if (check_argument(cor, proc))
	{
		proc->carry = !cor->args[0].val;
		if ((tmp = cor->args[0].val) < REG_NUMBER)
		{
			c = treg_to_int(proc->regs[tmp - 1]) % 256;
			size = read_for_aff(cor);
			ft_strncat(cor->aff_print, &c, 1);
		}
		else if (!cor->take_v)
			write(1, cor->aff_print, 1);
	}
}
