#include "corewar.h"

static int	active_col(int owner)
{
	if (owner == 1)
		return (COLOR_PAIR(RED_LIVE));
	if (owner == 2)
		return (COLOR_PAIR(GREEN_LIVE));
	if (owner == 3)
		return (COLOR_PAIR(YELLOW_LIVE));
	if (owner == 4)
		return (COLOR_PAIR(BLUE_LIVE));
	return (COLOR_PAIR(GRAY));
}

static int	state_col(int owner)
{
	if (owner == 1)
		return (COLOR_PAIR(RED));
	if (owner == 2)
		return (COLOR_PAIR(GREEN));
	if (owner == 3)
		return (COLOR_PAIR(YELLOW));
	if (owner == 4)
		return (COLOR_PAIR(BLUE));
	return (COLOR_PAIR(GRAY));
}

static int			color_attr(t_vm *vm, int op_posit)
{
	if (vm->visu->attr_arena[op_posit].live_bright-- > 0)
		return (active_col(vm->visu->attr_arena[op_posit].owner));
	if (vm->visu->attr_arena[op_posit].store_bright-- > 0)
		return (state_col(vm->visu->attr_arena[op_posit].owner) | A_BOLD);
	return (state_col(vm->visu->attr_arena[op_posit].owner));
}

void	building_start(t_vm *vm)
{
	int i;
	int j;
	int attribute;

	werase(vm->visu->arena);
	wprintw(vm->visu->arena, "\n\n");
	i = -1;
	while (++i < MEM_SIZE / 64)
	{
		j = 0;
		wprintw(vm->visu->arena, "  ");
		while (j < MEM_SIZE / 64)
		{
			attribute = color_attr(vm, i * 64 + j);
			waddch(vm->visu->arena, ' ');
			wattron(vm->visu->arena, attribute);
			wprintw(vm->visu->arena, "%.2x", vm->arena[i * 64 + j]);
			wattroff(vm->visu->arena, attribute);
			vm->visu->attr_arena[i * 64 + j].cursor = 0;
			j++;
		}
		wprintw(vm->visu->arena, " \n");
	}
	wattron(vm->visu->arena, COLOR_PAIR(GRAY_CURSOR));
	box(vm->visu->arena, '+', '+');
	wattroff(vm->visu->arena, COLOR_PAIR(GRAY_CURSOR));
	wrefresh(vm->visu->arena);
}
