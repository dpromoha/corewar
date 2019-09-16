#include "corewar.h"

void		help_op(void)
{
	ft_printf("help_op:\n\
\t./corewar [\033[1;35m-dump\033[0m/\033[1;35m-d\033[0m CYCLE] \
[\033[1;36m-n\033[0m NUMB] [\033[1;32m-v\033[0m PLAYER] \
[\033[1;32m-q\033[0m PLAYER]\n\
OPTIONS:\n\
\t[\033[1;32m-v	\033[0m P]\tsee a magic vizualization\n\
\t[\033[1;32m-q	\033[0m P]\tsilent mode\n\
\t[\033[1;35m-dump	\033[0m C]\tdump memory(32 octets) after N cycles\n\
\t[\033[1;35m-d	\033[0m C]\tdump memory(64 octets) after N cycles\n\
\t[\033[1;36m-n	\033[0m N]\tset the number of player\n");
}

void	error_messages(int error_code, t_vm *vm)
{
	error_code == 1 ? ft_printf(R"ERROR: wrong number of player (need number >= 1 <= 4) or appropriate quantity of player\n"OF) : 0;
	error_code == 2 ? ft_printf(R"ERROR: problem with memory allocation\n"OF) : 0;
	error_code == 4 ? ft_printf(R"ERROR: problem with player\n"OF) : 0;
	error_code == 5 ? ft_printf(R"ERROR: number of processes more than need\n"OF) : 0;
	error_code == 6 ? ft_printf(R"ERROR: too many players, PLEASE, write less than 5\n"OF) : 0;
	error_code == 7 ? ft_printf(R"ERROR: number of player can't be 0, PLEASE, change number (> 0 && < 5)\n"OF) : 0;
	error_code == 8 ? ft_printf(R"ERROR: players less than 1\n"OF) : 0;
	error_code == 9 ? ft_printf(R"ERROR: incorrect use of flag -n\n"OF) : 0;
	error_code == 10 ? ft_printf(R"ERROR: number AND player of player must be AFTER flag -n\n"OF) : 0;
	vm_free(vm);
}

void		end_of_program(t_vm *vm)
{
	help_op();
	vm_free(vm);
}

struct s_op	op_tab[16 + 1] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", &i_live, 4, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5,
		"load", &i_ld, 4, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5,
		"store", &i_st, 0, 2},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10,
		"addition", &i_add, 0, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10,
		"soustraction", &i_sub, 0, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", &i_and, 4, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", &i_or, 4, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", &i_xor, 4, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", &i_zjmp, 2, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", &i_ldi, 2, 4},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", &i_sti, 2, 4},
	{"fork", 1, {T_DIR}, 12, 800, "fork", &i_fork, 2, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10,
		"long load", &i_lld, 4, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", &i_lldi, 2, 4},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", &i_lfork, 2, 0},
	{"aff", 1, {T_REG}, 16, 2, "aff", &i_aff, 0, 0},
	{0, 0, {0}, 0, 0, 0, NULL, 0, 0}
};

void	vm_init(t_vm *vm)
{
	vm->players = NULL;
	if (!(vm->arena = (unsigned char *)malloc(sizeof(unsigned char)
			* MEM_SIZE)))
		error_messages(2, vm);
	ft_bzero(vm->arena, sizeof(unsigned char) * MEM_SIZE);
	vm->procs = NULL;
	vm->cycles = 0;
	vm->new_cycles = 0;
	vm->cycle_to_die = 1536;
	vm->live_number = 0;
	vm->live_n_reduction = 0;
	vm->who_is_alive = 0;
	vm->dump_using = 0;
	vm->number_process = 0;
	vm->copy_process = 1;
	vm->op_tab = op_tab;
	vm->take_v = 0;
	vm->visu = NULL;
	vm->quiet = 0;
	vm->flag = 0;
	if (!(vm->aff_print = ft_strnew(BUFF_SIZE)))
		error_messages(2, vm);
}

void			vm_free(t_vm *vm)
{
	int		i;
	t_exec	*cache;

	if (vm->players)
	{
		i = -1;
		while (vm->players[++i])
			free_struct_player(&(vm->players[i]));
	}
	free(vm->players);
	free(vm->arena);
	free(vm->aff_print);
	while (vm->procs)
	{
		cache = vm->procs->next;
		delete_proc(&vm->procs);
		vm->procs = cache;
	}
	vm->procs = NULL;
	if (vm->take_v == 1)
		delete_visu(vm);
	system("leaks corewar");
	exit(0);
}
