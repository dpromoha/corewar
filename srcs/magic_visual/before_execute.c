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
	who_is_winner(vm);
	nodelay(stdscr, false);
	wgetch(stdscr);
	endwin();
}

void	end_visual(t_vm *vm)
{
	clear();
	free_visual(vm);
	endwin();
	system("leaks corewar");
	exit(0);
}

static int	what_is_speed(int c)
{
	if (c == KEY_RIGHT)
		return (100);
	else if (c == KEY_LEFT)
		return (100000);
	else
		return (1000);
}

void		how_fast(t_vm *vm)
{
	int		t;
	int		c;
	int		speed;

	speed = 0;
	t = clock();
	c = wgetch(stdscr);
	if (c == ' ')
	{
		if (c == 'q')
			end_visual(vm);
		vm->visu->in_move = 0;
	}
	else if (c == 'q')
		end_visual(vm);
	else
		speed = what_is_speed(c);
	while (clock() - t < (unsigned long)speed)
		;
	build_map(vm, c);
}

void	build_map(t_vm *vm, char c)
{
	if (vm->cycles != 1 && vm->visu->in_move == 0)
	{
		wmove(vm->visu->arena_info, 2, 3);
		wprintw(vm->visu->arena_info, "** PAUSED ** ");
		if (c == 'q')
			end_visual(vm);
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
