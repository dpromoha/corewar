#include "corewar.h"

static void	arena_before_start_game(t_vm *vm)
{
	int i;
	int j;
	int op_posit;

	op_posit = 0;
	i = 0;
	while (i < MEM_SIZE)
	{
		vm->visu->attr_arena[i].owner = 0;
		i++;
	}
	i = 0;
	while (i < vm->what_is_n_player)
	{
		j = 0;
		while (j < (int)vm->players[i]->head.prog_size)
		{
			vm->visu->attr_arena[op_posit + j].owner = vm->players[i]->numb;
			j++;
		}
		op_posit += MEM_SIZE / vm->what_is_n_player;
		i++;
	}
}

void	visualization(t_vm *vm)
{
	start_mem_visu(vm);
	keypad(stdscr, true);
	nodelay(stdscr, true);
	define_all_colors();
	arena_before_start_game(vm);
	execute(vm);
	nodelay(stdscr, false);
	wgetch(stdscr);
	endwin();
}

void		how_fast(t_vm *vm)
{
	int		t;
	int		key;

	t = clock();
	while (clock() - t < (unsigned long)10000)
		key = wgetch(stdscr);
	build_map(vm);
}

void	build_map(t_vm *vm)
{
	if (vm->cycles != 1 && vm->visu->in_move == 0)
	{
		wmove(vm->visu->arena_info, 6, 3);
		wprintw(vm->visu->arena_info, "Cycle : %d  ", vm->cycles);
		wrefresh(vm->visu->arena_info);
	}
	else
	{
		building_start(vm);
		colors_map(vm);
	}
}
