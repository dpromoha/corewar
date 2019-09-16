#ifndef STRUCT_H
# define STRUCT_H
# include "corewar.h"

typedef struct			s_argument
{
	int					arg_1;
	int					arg_2;
	int					arg_3;
	int					result;
}						t_argument;

typedef struct			s_champion
{
	t_header			head;
	int					numb;
	unsigned char		*process_code_player;
	unsigned int		cycle_live;
	unsigned int		n_proc_now;
	unsigned int		last_execess;
}						t_champion;

typedef struct			s_exec
{
	unsigned int		n;
	int					parent_id;
	int					carry;
	unsigned char		operation_code;
	unsigned int		i_am_alive;
	unsigned int		cycle_before_instr;
	unsigned int		op_posit;
	int					length_step;
	unsigned char		*(regs[REG_NUMBER]);
	struct s_exec		*next;
}						t_exec;

typedef struct			s_arg
{
	t_arg_type			type;
	int					val;
}						t_arg;

typedef struct			s_vm
{
	int					what_is_n_player;
	t_champion			**players;
	unsigned char		*arena;
	t_exec				*procs;
	struct s_op			*op_tab;
	t_arg				args[3];
	unsigned int		cycles;
	unsigned int		new_cycles;
	int					cycle_to_die;
	unsigned int		live_number;
	unsigned int		live_n_reduction;
	int					who_is_alive;
	int					dump_using;
	unsigned int		cycle_dump;
	unsigned int		number_process;
	unsigned int		copy_process;
	struct s_visu		*visu;
	int					take_v;
	char				*aff_print;
	int					quiet;
	int					flag;
}						t_vm;

typedef struct			s_op
{
	char				*name;
	int					how_much_arg;
	int					args[3];
	unsigned char		operation_code;
	unsigned int		cycle_before_instr;
	char				*extend_name;
	void				(*f)(struct s_vm *, t_exec *);
	int					dir_size;
	int					ind_size;
}						t_op;

#endif