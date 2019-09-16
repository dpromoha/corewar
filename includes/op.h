#ifndef OP_H
# define OP_H

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

/*
** Size of the different types.
** NB1: Depending on the instruction, DIR can also have a size of 2.
** NB2: REG_SIZE is the actual size of the registry, not of the reference to the
**      registry in the VM. Registries are referenced with only 1 bit.
*/
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

/*
** Representation of the type in the argcode.
*/
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MEM_SIZE				(4*1024)
# define op_posit_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define REG_NUMBER				16
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

/*
** Byte reprensentation of a type of argument. It is NOT the representation of
** the argcode following the code_of_operat of instructions in the VM.
*/
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

#endif
