#include "corewar.h"

static	int	read_for_aff(t_vm *cor)
{
	int size;

	size = 0;
	size = ft_strlen(cor->aff_print);
	if (size == BUFF_SIZE)
	{
		if (!(cor->aff_print = (char*)realloc(cor->aff_print, size + BUFF_SIZE)))
			error_messages(9, cor);
	}
	ft_bzero(cor->aff_print + size, BUFF_SIZE);
	return (size);
}

int					treg_to_int(unsigned char *reg)
{
	int		i;
	int		result;

	i = 3;
	result = reg[3];
	while (i >= 0)
	{
		result = result * 256 + reg[i];
		i--;
	}
	return (result);
}

void		i_aff(t_vm *cor, t_exec *proc)
{
	int		tmp;
	char	c;
	int		size;

	if (check_argument(cor, proc))
	{
		proc->carry = !cor->args[0].val;
		if ((tmp = cor->args[0].val) < REG_NUMBER)
		{
			c = treg_to_int(proc->regs[tmp - 1]) % 256;
			size = read_for_aff(cor);
			ft_strncat(cor->aff_print, &c, 1);
		}
		else if (!cor->take_v)
			write(1, cor->aff_print, 1);
	}
}
