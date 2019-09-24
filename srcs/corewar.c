/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 09:23:20 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/24 09:23:27 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			visual_corewar(&vm);
		}
	}
	vm_free(&vm);
}
