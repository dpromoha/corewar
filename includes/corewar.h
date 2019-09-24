/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:26:41 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/20 16:26:43 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# include "libft.h"
# include "ft_printf.h"
# include "struct.h"
# include "visualization.h"

# define R "\033[1;31m"
# define OF "\033[0m"

extern	struct s_op op_tab[17];
void				help_op(void);
void				vm_init(t_vm *cor);
void				error_messages(int error_code, t_vm *cor);
int					flags(t_vm *cor, int *ac, char ***av);
void				read_cor(t_vm *cor, int ac, char **av);
int					get_prog_name(t_champion *champ, int fd);
unsigned int		get_prog_size(int fd);
int					get_comment(t_champion *champ, int fd);
unsigned char		*get_execess_code_player(int fd, unsigned int size);
void				check_flag_n(t_vm *cor);
void				place_for_player(t_vm *cor);
void				who_play(t_vm *cor);
void				execute(t_vm *cor);
void				who_is_winner(t_vm *cor);
void				i_live(t_vm *cor, t_exec *proc);
void				i_ld(t_vm *cor, t_exec *proc);
void				i_st(t_vm *cor, t_exec *proc);
void				i_add(t_vm *cor, t_exec *proc);
void				i_sub(t_vm *cor, t_exec *proc);
void				i_or(t_vm *cor, t_exec *proc);
void				i_and(t_vm *cor, t_exec *proc);
void				i_xor(t_vm *cor, t_exec *proc);
void				i_zjmp(t_vm *cor, t_exec *proc);
void				i_sti(t_vm *cor, t_exec *proc);
void				i_ldi(t_vm *cor, t_exec *proc);
void				i_lld(t_vm *cor, t_exec *proc);
void				i_lldi(t_vm *cor, t_exec *proc);
void				i_aff(t_vm *cor, t_exec *proc);
void				i_fork(t_vm *cor, t_exec *proc);
void				i_lfork(t_vm *cor, t_exec *proc);
int					what_is_argument(t_vm *cor, t_exec *proc, t_arg arg,
					int addr_restriction);
int					check_argument(t_vm *cor, t_exec *proc);
int					return_int_size(t_vm *cor, int op_posit, int size);
int					treg_to_int(unsigned char *reg);
int					modificate_index(int new_op_posit);
void				to_map(unsigned char *reg, void *content);
t_exec				*new_proc(void);
void				delete_proc(t_exec **proc);
void				validation_flag(t_vm *cor, int ac, char **av);
void				dump_flag_size(t_vm *cor);
void				vm_free(t_vm *cor);
void				end_of_program(t_vm *cor);
void				free_struct_player(t_champion **champ);
t_arg_type			get_arg_type(unsigned char argcode, int i);
void				get_arg(t_vm *cor, t_exec *proc, int *arg_op_posit, int i);

#endif
