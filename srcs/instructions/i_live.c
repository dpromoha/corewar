/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:34:13 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 08:35:31 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				return_int_size(t_vm *cor, int op_posit, int size)
{
	int		i;
	int		number;

	i = 0;
	number = cor->arena[modificate_index(op_posit)];
	while (i < size)
	{
		number = number * 256 + cor->arena[modificate_index(op_posit + i)];
		i++;
	}
	return (number);
}

static void		print_alive(t_argument a, t_vm *cor, int i)
{
	write(1, "A process shows that player ", 28);
	ft_putnbr(-a.arg_1);
	write(1, " ", 1);
	write(1, "\"", 2);
	ft_putstr(cor->players[i]->head.prog_name);
	write(1, "\"", 2);
	write(1, " is alive\n", 10);
}

static void		visual_live(t_vm *vm, t_exec *proc, t_argument a)
{
	if (vm->take_v)
	{
		vm->visu->attr_arena[proc->op_posit].owner =
			vm->players[a.result]->numb;
		vm->visu->attr_arena[proc->op_posit].live_bright =
			LIVE_BRIGHT_TIME;
	}
}

void			i_live(t_vm *cor, t_exec *proc)
{
	t_argument	a;

	a.result = -1;
	proc->i_am_alive = cor->cycles;
	cor->live_number++;
	a.arg_1 = return_int_size(cor, proc->op_posit + 1, 4);
	while (++a.result < cor->what_is_n_player)
	{
		if (a.arg_1 * -1 == cor->players[a.result]->numb)
		{
			cor->who_is_alive = a.arg_1 * -1;
			cor->players[a.result]->cycle_live = cor->cycles;
			cor->players[a.result]->n_proc_now++;
			if (cor->quiet == 10 || cor->flag == 32 || cor->flag == 64)
				break ;
			else if (!cor->take_v)
				print_alive(a, cor, a.result);
			visual_live(cor, proc, a);
			break ;
		}
	}
	proc->length_step = 5;
}
