/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:41:16 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 09:47:55 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		check_errors(t_vm *vm, int ac)
{
	int i;

	i = 0;
	if (vm->what_is_n_player > 4)
		error_messages(6, vm);
	else if (vm->what_is_n_player <= 0)
		error_messages(8, vm);
	if (!(vm->players = (t_champion**)malloc(sizeof(t_champion*) * (ac + 1))))
		error_messages(2, vm);
	while (i <= ac)
	{
		vm->players[i] = NULL;
		i++;
	}
}

void			validation_flag(t_vm *vm, int ac, char **av)
{
	int		i;

	i = 0;
	vm->what_is_n_player = ac;
	while (i < ac)
	{
		num_flag(vm, av, ac, i);
		if (ft_strequ(av[i], "-s"))
		{
			if (i + 1 > ac)
				error_messages(8, vm);
			vm->what_is_n_player -= 1;
			vm->quiet = 10;
		}
		i++;
	}
	check_errors(vm, ac);
}

static void		error_champions(t_vm *vm, int j)
{
	while (--j >= 0)
		free_struct_player(&(vm->players[j]));
	free(vm->players);
	vm->players = NULL;
	error_messages(4, vm);
}

int				check_test(t_argument a, char **av, int ac, t_vm *vm)
{
	int player;

	if (a.arg_1 >= ac - 1 ||
			(player = ft_atoi(av[a.arg_1])) > vm->what_is_n_player)
		error_messages(1, vm);
	a.arg_1++;
	return (a.arg_1);
}

void			read_cor(t_vm *vm, int ac, char **av)
{
	t_argument	a;
	int			player;

	a.arg_1 = 0;
	a.arg_2 = 0;
	while (a.arg_1 < ac && a.arg_2 < vm->what_is_n_player && !(player = 0))
	{
		if (ft_strequ(av[a.arg_1], "-s"))
			a.arg_1 = check_test(a, av, ac, vm);
		if (ft_strequ(av[a.arg_1], "-n"))
		{
			if (++a.arg_1 >= ac - 1 || !ft_unsignint(av[a.arg_1])
				|| (player = ft_atoi(av[a.arg_1]))
					> vm->what_is_n_player || player < 1)
				error_messages(1, vm);
			a.arg_1++;
		}
		if (!(vm->players[a.arg_2] = champ_error(av[a.arg_1], player)))
			error_champions(vm, a.arg_2);
		a.arg_1++;
		a.arg_2++;
	}
}
