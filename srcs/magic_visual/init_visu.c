#include "corewar.h"

// void        build_c(int i, int j, WINDOW *data)
// {
//     int        j_rem;
    
//     j_rem = j;
//     while (i <= 40)
//     {
//         j = j_rem;
//         while (j <= 16)
//         {
//             if (i == 26 || i == 27 || i == 40 || i == 39)
//             {
//                 wattron(data, COLOR_PAIR(11));
//                 if (j > 4)
//                     mvwprintw(data, i, j, "+");
//                 wattroff(data, COLOR_PAIR(11));
//             }
//             else
//             {
//                 wattron(data, COLOR_PAIR(11));
//                 if (j <= 6)
//                     mvwprintw(data, i, j, "+");
//                 wattroff(data, COLOR_PAIR(11));
//             }
//             j++;
//         }
//         i++;
//     }
// }

// void        build_o(int i, int j, WINDOW *data)
// {
//     int        j_rem;
    
//     j_rem = j;
//     while (i <= 40)
//     {
//         j = j_rem;
//         while (j <= 31)
//         {
//             if (i == 26 || i == 27 || i == 40 || i == 39)
//             {
//                 wattron(data, COLOR_PAIR(11));
//                 mvwprintw(data, i, j, "+");
//                 wattroff(data, COLOR_PAIR(11));
//             }
//             else
//             {
//                 wattron(data, COLOR_PAIR(11));
//                 if (j <= 23)
//                     mvwprintw(data, i, j - 2, "+");
//                 else if (j >= 29)
//                     mvwprintw(data, i, j + 2, "+");
//                 wattroff(data, COLOR_PAIR(11));
//             }
//             j++;
//         }
//         i++;
//     }
// }

// void        draw_data(WINDOW *data)
// {
//     int        i;
//     int        j;
    
//     i = 26;
//     j = 3;
//     build_c(i, j, data);
//     j += 18;
//     build_o(i, j, data);
// }

// void        draw(t_vm *vm, int delay)
// {
//     double    y;
//     double    x;
//     int        i;
//     int        v;
    
//     getmaxyx(stdscr, y, x);
//     WINDOW * arena = newwin(y - 16, (x / 3) * 2 + 20, 0, 0);
//     WINDOW * data = newwin(y - 16, x / 3 - 20, 0, (x / 3) * 2 + 20);
//     box(arena, 100, 100);
//     box(data, 100, 100);
//     start_color();
//     init_pair(1, 8, 8);
//     attron(COLOR_PAIR(1));
//     char    k = '+';
//     wborder(arena, k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1));
//     wborder(data, k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1), k | COLOR_PAIR(1));
//     attroff(COLOR_PAIR(1));
//     i = -1;
//     v = 2;
//     wmove(arena, 1, 5);
//     while (++i < MEM_SIZE)
//     {
//         if (i % 64 == 0)
//             wmove(arena, v++, 5);
//         wprintw(arena, "%.02hhx ", vm->arena[i]);
//     }
//     if (delay == 0)
//         mvwprintw(arena, 2, 220, "** PAUSED **");
//     else
//         mvwprintw(arena, 2, 220, "** IN MOVE **");
    
//     mvwprintw(arena, 4, 210, "Cycles/second limit : 50");
    
//     mvwprintw(arena, 6, 205, "CYCLE_TO_DIE :    %d", vm->cycles_to_die);
    
//     t_championion    **p = vm->players;
    
//     i = 0;
    
//     init_pair(2, COLOR_GREEN, COLOR_BLACK);
//     init_pair(3, COLOR_BLUE, COLOR_BLACK);
//     init_pair(4, COLOR_YELLOW, COLOR_BLACK);
//     init_pair(5, COLOR_RED, COLOR_BLACK);
//     while (i != 4 && p[i] != NULL)
//     {
//         mvwprintw(arena, 8 + i * 2, 205, "Player %d :    ", i + 1);
//         wattron(arena, COLOR_PAIR(i + 2));
//         if (p[i]->header.prog_name[0] == ' ')
//             mvwprintw(arena, 8 + i * 2 + 1, 221, "%s", p[i]->header.prog_name);
//         else
//             mvwprintw(arena, 8 + i * 2 + 1, 221, " %s", p[i]->header.prog_name);
//         wattroff(arena, COLOR_PAIR(i + 2));
//         i++;
//     }
//     wrefresh(arena);
    
//     init_pair(6, COLOR_GREEN, COLOR_GREEN);
//     init_pair(7, COLOR_RED, COLOR_RED);
//     init_pair(8, COLOR_YELLOW, COLOR_YELLOW);
//     init_pair(9, COLOR_BLUE, COLOR_BLUE);
//     init_pair(10, COLOR_WHITE, COLOR_WHITE);
//     init_pair(11, COLOR_MAGENTA, COLOR_MAGENTA);
//     init_pair(12, COLOR_CYAN, COLOR_CYAN);
    
//     draw_data(data);
    
//     wrefresh(data);
//     refresh();
// }

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
	// WINDOW * arena = newwin(y - 16, (x / 3) * 2 + 20, 0, 0);
    // WINDOW * data = newwin(y - 16, x / 3 - 20, 0, (x / 3) * 2 + 20);
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
