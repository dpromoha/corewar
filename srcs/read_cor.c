#include "corewar.h"

static void	num_flag(t_vm *vm, char **av, int ac, int i)
{
	if (ft_strequ(av[i], "-n"))
	{
		if (i + 2 < ac)
		{
			if (ft_atoi(av[i + 1]) == 0)
				error_messages(7, vm);
		}
		else
			error_messages(10, vm);
		vm->what_is_n_player -= 2;
	}
}

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

void		validation_flag(t_vm *vm, int ac, char **av)
{
	int		i;

	i = 0;
	vm->what_is_n_player = ac;
	while (i < ac)
	{
		num_flag(vm, av, ac, i);
		if (ft_strequ(av[i], "-q"))
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

static void		init_vm(t_champion *champ, int numb)
{
	champ->cycle_live = 0;
	champ->n_proc_now = 0;
	champ->numb = numb;
	champ->process_code_player = NULL;
}

static void				check_magic(t_champion *champ, int fd)
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
			|| get_prog_name(champ, fd) == -1 || space_read(fd) == -1))
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

static void				comment_of_player(t_champion **champ, int fd)
{
	if (!*champ || ((*champ)->head.prog_size = get_prog_size(fd)) > CHAMP_MAX_SIZE
			|| get_comment((*champ), fd) == -1 || space_read(fd) == -1)
			{
				if (*champ)
					free((*champ)->process_code_player);
				free(*champ);
				*champ = NULL;
			}
}

static t_champion	*champ_error(char *str, int numb)
{
	t_champion			*champ;
	int				fd;

	if ((fd = open(str, O_RDONLY)) == -1 ||
		!(champ = (t_champion *)malloc(sizeof(t_champion))))
		return (NULL);
	init_vm(champ, numb);
	check_magic(champ, fd);
	comment_of_player(&champ, fd);
	if (!champ || !(champ->process_code_player = get_execess_code_player(fd, champ->head.prog_size)))
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

static void		error_champions(t_vm *vm, int j)
{
	while (--j >= 0)
		free_struct_player(&(vm->players[j]));
	free(vm->players);
	vm->players = NULL;
	error_messages(4, vm);
}

void			read_cor(t_vm *vm, int ac, char **av)
{
	int		i;
	int		j;
	int		player;

	i = 0;
	j = 0;
	while (i < ac && j < vm->what_is_n_player && !(player = 0))
	{
		if (ft_strequ(av[i], "-q"))
		{
			if (i >= ac - 1 ||
				(player = ft_atoi(av[i])) > vm->what_is_n_player)
					error_messages(1, vm);
			i++;
		}
		if (ft_strequ(av[i], "-n"))
		{
			if (++i >= ac - 1 || !ft_unsignint(av[i]) || (player = ft_atoi(av[i]))
					> vm->what_is_n_player || player < 1)
				error_messages(1, vm);
			i++;
		}
		if (!(vm->players[j] = champ_error(av[i], player)))
			error_champions(vm, j);
		i++;
		j++;
	}
}
