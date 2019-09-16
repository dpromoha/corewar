#include "corewar.h"

int			main(int ac, char **av)
{
	t_vm	vm;

	ac--;
	av++;
	vm_init(&vm);
	if (!ac)
		end_of_program(&vm);
	else
	{
		if (flags(&vm, &ac, &av) < 0)
			end_of_program(&vm);
		else
		{
			validation_flag(&vm, ac, av);
			read_cor(&vm, ac, av);
			check_flag_n(&vm);
			place_for_player(&vm);
			if (vm.take_v)
				visualization(&vm);
			else
			{
				ft_printf("Introducing contestants...\n");
				who_play(&vm);
				execute(&vm);
				who_is_winner(&vm);
			}
		}
	}
	vm_free(&vm);
}
