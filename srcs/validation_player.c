/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:06:50 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 09:09:20 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		comment_of_player(t_champion **champ, int fd)
{
	if (!*champ || ((*champ)->head.prog_size =
				check_size(fd)) > CHAMP_MAX_SIZE
			|| check_comment((*champ), fd) == -1 || space_read(fd) == -1)
	{
		if (*champ)
			free((*champ)->process_code_player);
		free(*champ);
		*champ = NULL;
	}
}

static void		check_magic(t_champion *champ, int fd)
{
	unsigned int	magic;
	unsigned char	c;
	int				i;

	magic = 0;
	i = -1;
	while (++i < 4)
	{
		if (read(fd, &c, 1) != 1)
			COREWAR_EXEC_MAGIC == 0 ? 1 : 0;
		magic = magic * 256 + c;
	}
	if ((champ->head.magic = magic != COREWAR_EXEC_MAGIC
			|| check_name(champ, fd) == -1 || space_read(fd) == -1))
	{
		if (champ)
			free(champ->process_code_player);
		free(champ);
		champ = NULL;
		ft_printf(R"ERROR: file isn't appropriate for COREWAR\n"OF);
		system("leaks corewar");
		exit(0);
	}
}

static void		init_vm(t_champion *champ, int numb)
{
	champ->cycle_live = 0;
	champ->n_proc_now = 0;
	champ->numb = numb;
	champ->process_code_player = NULL;
}

t_champion		*champ_error(char *str, int numb)
{
	t_champion		*champ;
	int				fd;

	if ((fd = open(str, O_RDONLY)) == -1 ||
		!(champ = (t_champion *)malloc(sizeof(t_champion))))
		return (NULL);
	init_vm(champ, numb);
	check_magic(champ, fd);
	comment_of_player(&champ, fd);
	if (!champ || !(champ->process_code_player =
				get_execess_code_player(fd, champ->head.prog_size)))
	{
		if (champ)
			free((champ)->process_code_player);
		free(champ);
		champ = NULL;
	}
	if (close(fd) < 0)
	{
		if (champ)
			free((champ)->process_code_player);
		free(champ);
		champ = NULL;
	}
	return (champ);
}
