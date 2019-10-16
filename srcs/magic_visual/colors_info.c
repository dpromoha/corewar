#include "corewar.h"

void	define_all_colors(void)
{
	use_default_colors();
	start_color();
	init_color(COLOR_GRAY, 300, 300, 300);
	init_color(BLACK, 0, 0, 0);
	init_color(WHITE, 1000, 1000, 1000);
	init_pair(GRAY, COLOR_GRAY, BLACK);
	init_pair(GRAY_CURSOR, COLOR_GRAY, COLOR_GRAY);
	init_pair(RED, COLOR_RED, BLACK);
	init_pair(RED_LIVE, WHITE, COLOR_RED);
	init_pair(GREEN, COLOR_GREEN, BLACK);
	init_pair(GREEN_LIVE, WHITE, COLOR_GREEN);
	init_pair(YELLOW, COLOR_YELLOW, BLACK);
	init_pair(YELLOW_LIVE, WHITE, COLOR_YELLOW);
	init_pair(BLUE, COLOR_BLUE, BLACK);
	init_pair(BLUE_LIVE, WHITE, COLOR_BLUE);
}

static void		name_table(t_vm *cor, int *y)
{
	wmove(cor->visu->arena_info, *y, 3);
	if (cor->visu->in_move == 1)
		wprintw(cor->visu->arena_info, "** IN MOVE **");
	else
		wprintw(cor->visu->arena_info, "** PLEASE, PRESS SPACE TO START A GAME **");
	*y += 4;
	wmove(cor->visu->arena_info, *y, 3);
	wprintw(cor->visu->arena_info, "Cycle : %d", cor->cycles);
	*y += 2;
	wmove(cor->visu->arena_info, *y, 3);
	wprintw(cor->visu->arena_info, "Processes : %d", cor->number_process);
	*y += 2;
	wmove(cor->visu->arena_info, *y, 3);
	wprintw(cor->visu->arena_info, "CYCLE_TO_DIE : %d", cor->cycle_to_die);
	*y += 2;
	wmove(cor->visu->arena_info, *y, 3);
	if (cor->who_is_alive != 0)
		wprintw(cor->visu->arena_info, "LAST ALIVE : %s", cor->players[cor->who_is_alive - 1]->head.prog_name);
}

static int				name_players_by_colors(int i)
{
	if (!i)
		return (COLOR_PAIR(RED));
	if (i == 1)
		return (COLOR_PAIR(GREEN));
	if (i == 2)
		return (COLOR_PAIR(YELLOW));
	if (i == 3)
		return (COLOR_PAIR(BLUE));
	return (COLOR_PAIR(WHITE));
}

void			colors_map(t_vm *cor)
{
	int		i;
	int		y;
	int 	attribute;

	y = 2;
	werase(cor->visu->arena_info);
	name_table(cor, &y);
	i = -1;
	while (++i < cor->what_is_n_player)
	{
		y += 3;
		wmove(cor->visu->arena_info, y, 3);
		wprintw(cor->visu->arena_info, "Player %d : ",
				cor->players[i]->numb);
		attribute = name_players_by_colors(i);
		wattron(cor->visu->arena_info, attribute);
		wprintw(cor->visu->arena_info, "%s", cor->players[i]->head.prog_name);
		wattroff(cor->visu->arena_info, attribute);
	}
	y += 3;
	wmove(cor->visu->arena_info, y, 3);
	wattron(cor->visu->arena_info, COLOR_PAIR(GRAY_CURSOR));
	box(cor->visu->arena_info, '+', '+');
	wattroff(cor->visu->arena_info, COLOR_PAIR(GRAY_CURSOR));
	wmove(cor->visu->arena_info, 4, 3);
	wrefresh(cor->visu->arena_info);
}

void		free_visual(t_vm *vm)
{
	if (vm->visu)
	{
		if (vm->visu->arena)
			delwin(vm->visu->arena);
		if (vm->visu->arena_info)
			delwin(vm->visu->arena_info);
		free(vm->visu);
	}
}
