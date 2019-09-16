#include "corewar.h"

void	who_play(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < vm->what_is_n_player)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
				vm->players[i]->head.prog_size, vm->players[i]->head.prog_name,
				vm->players[i]->head.comment);
		i++;
	}
}

int				get_prog_name(t_champion *champ, int fd)
{
	int		copy;

	if ((copy = read(fd, champ->head.prog_name, PROG_NAME_LENGTH))
			!= PROG_NAME_LENGTH)
		return (-1);
	else
		champ->head.prog_name[copy] = 0;
	return (0);
}

unsigned int	get_prog_size(int fd)
{
	unsigned int	prog_size;
	unsigned char	buf[5];
	int				copy;
	int				i;

	prog_size = 0;
	i = -1;
	if ((copy = read(fd, buf, 4)) != 4)
		return (CHAMP_MAX_SIZE + 1);
	buf[copy] = 0;
	while (++i < 4)
		prog_size = prog_size * 16 * 16 + buf[i];
	return (prog_size);
}

int				get_comment(t_champion *champ, int fd)
{
	int		copy;

	if ((copy = read(fd, champ->head.comment, COMMENT_LENGTH))
			!= COMMENT_LENGTH)
		return (-1);
	champ->head.comment[COMMENT_LENGTH] = 0;
	return (0);
}

unsigned char	*get_execess_code_player(int fd, unsigned int size)
{
	unsigned char	*instr;
	int				copy;
	unsigned char	buf;

	if (!(instr = (unsigned char *)malloc(sizeof(unsigned char)
			* (size + 1))))
		return (NULL);
	else
	{
		if ((copy = read(fd, instr, size)) != (int)size)
		{
			free(instr);
			return (NULL);
		}
		instr[copy] = 0;
		if ((copy = read(fd, &buf, 1)) != 0)
		{
			free(instr);
			return (NULL);
		}
	}
	return (instr);
}
