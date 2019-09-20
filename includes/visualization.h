/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:29:10 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/20 16:30:22 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H
# include "corewar.h"
# include <ncurses.h>

# define HEIGHT (MEM_SIZE / 64 + 4)
# define WIDTH ((MEM_SIZE / 64) * 3 + 5)

# define LIVE_BRIGHT_TIME 50
# define STORE_BRIGHT_TIME 50

# define RED			8
# define RED_LIVE		10
# define GREEN			11
# define GREEN_LIVE		13
# define YELLOW			14
# define YELLOW_LIVE	16
# define BLUE			17
# define BLUE_LIVE		19
# define COLOR_GRAY		23
# define GRAY			24
# define GRAY_CURSOR	25
# define BLACK			26
# define WHITE			27

typedef struct		s_attr
{
	int				cursor;
	int				owner;
	int				live_bright;
	int				store_bright;
}					t_attr;

typedef struct		s_visu
{
	WINDOW			*arena;
	WINDOW			*arena_info;
	t_attr			attr_arena[MEM_SIZE];
	int				in_move;
}					t_visu;

void				visualization(t_vm *cor);
void				start_mem_visu(t_vm *cor);
void				build_map(t_vm *cor);
void				define_all_colors(void);
void				how_fast(t_vm *cor);
void				building_start(t_vm *cor);
void				colors_map(t_vm *cor);
void				free_visual(t_vm *cor);

#endif
