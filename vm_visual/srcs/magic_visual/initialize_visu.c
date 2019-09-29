#include "corewar.h"

void		visual_corewar(t_vm *vm)
{
	if (vm->take_v)
		visualization(vm);
	else
	{
		ft_printf("Introducing contestants...\n");
		who_play(vm);
		execute(vm);
		who_is_winner(vm);
	}
}

static void	start_set_windows(void)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	if (has_colors() == FALSE)
	{
        endwin();
        ft_printf("Your terminal does not support color\n");
        exit(1);
    }
}

void		start_mem_visu(t_vm *vm)
{
	int i;

	i = 0;
	start_set_windows();
	if (!(vm->visu = (t_visu *)malloc(sizeof(t_visu))))
		return ;
	vm->visu->arena = NULL;
	vm->visu->arena_info = NULL;
	if (!(vm->visu->arena = newwin(HEIGHT, WIDTH, 1, 1)))
		return ;
	if (!(vm->visu->arena_info = newwin(HEIGHT, WIDTH / 2, 1, WIDTH + 2)))
		return ;
	while (i < MEM_SIZE)
	{
		vm->visu->attr_arena[i].live_bright = 0;
		vm->visu->attr_arena[i].store_bright = 0;
		i++;
	}
	vm->visu->in_move = 0;
}
