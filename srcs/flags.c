#include "corewar.h"

void		who_is_winner(t_vm *vm)
{
	int		winner_no;
	int		i;

	i = 0;
	winner_no = vm->who_is_alive;
	while (vm->players[i])
	{
		if (vm->players[i]->numb == winner_no)
		{
			ft_printf("Contestant %d, \"%s\", has won !\n", winner_no,
					vm->players[i]->head.prog_name);
			return ;
		}
		i++;
	}
	ft_printf("No winner...\n");
}

void		dump_flag_size(t_vm *vm)
{
	int		i;

	i = 0;
	write(1, "0x0000 : ", 9);
	while (i < MEM_SIZE)
	{
		if (i && i % vm->flag == 0)
			ft_printf("\n0x%.4x : ", i);
		ft_printf("%.02hhx ", vm->arena[i]);
		i++;
	}
	write(1, "\n", 1);
	vm_free(vm);
}

static int	read_flag_d(t_vm *vm, int *ac, char ***av)
{
	if (!ft_unsignint((*av)[1]))
		return (-1);
	else
	{
		vm->dump_using = !vm->take_v;
		vm->cycle_dump = help_atoi((*av)[1]);
		(*av) += 2;
		(*ac) -= 2;
	}
	return (0);
}

int			flags(t_vm *vm, int *ac, char ***av)
{
	while (*ac && (*av)[0][0] == '-')
	{
		if (ft_strequ((*av)[0], "-dump"))
		{
			vm->flag = 32;
			if (*ac < 2)
				return (-1);
			read_flag_d(vm, ac, av);
		}
		else if (ft_strequ((*av)[0], "-d"))
		{
			vm->flag = 64;
			if (*ac < 2)
				return (-1);
			read_flag_d(vm, ac, av);
		}
		else if (ft_strequ((*av)[0], "-v"))
		{
			vm->take_v = 1;
			vm->dump_using = 0;
			(*av)++;
			(*ac)--;
		}
		else if (ft_strequ((*av)[0], "-q")
			|| ft_strequ((*av)[0], "-n"))
			break ;
		else
			return (-1);
	}
	return (0);
}
