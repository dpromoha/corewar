# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 13:16:52 by dpromoha          #+#    #+#              #
#    Updated: 2019/09/29 13:16:53 by dpromoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re

NAME 	= 	corewar

FLAGS	=	-Wall -Werror -Wextra -I./includes -I./libft/includes

SRCDIR	=	./srcs/

OBJDIR	=	./obj/

LIBDIR	=	./libft/

INDIR	=	instructions/

VISUDIR	=	magic_visual/

SRC		= 	corewar.c additional_func.c validation.c validation_player.c execute.c flags.c read_cor.c \
		additional_func2.c check_flag_n.c place_for_player.c \
		$(addprefix $(INDIR), $(IN)) \
		$(addprefix $(VISUDIR), $(VISU))

IN		=	i_add_and_or_xor_sub.c i_aff.c i_zjmp.c i_fork_lfork.c i_ld_ldi.c \
			i_live.c i_lld_lldi.c i_st_sti.c \

VISU	=	before_execute.c colors_info.c initialize_visu.c arena.c \

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB		=	libftprintf.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBDIR)$(LIB)
	@cp $(LIBDIR)$(LIB) ./
	@gcc -o $(NAME) $(OBJ) $(LIB) $(FLAGS) -lncurses
	@echo "\033[36mCOREWAR created\033[0m"

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@echo "\033[32mcreating $(NAME) objects\033[0m"
	@gcc -o $@ -c $< $(FLAGS)

$(LIBDIR)$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)
	@mkdir $(OBJDIR)$(INDIR)
	@mkdir $(OBJDIR)$(VISUDIR)
	@mkdir $(OBJDIR)$(VISUDIR)console

clean:
	@make -C $(LIBDIR) clean
	@echo "\033[31mdelete $(NAME) objects\033[0m"
	@rm -rf $(OBJ) $(OBJDIR)

fclean:
	@make -C $(LIBDIR) fclean
	@rm -rf $(OBJ) $(OBJDIR)
	@echo "\033[31mdelete $(NAME) objects\033[0m"
	@echo "\033[31mdelete $(NAME) bin\033[0m"
	@rm -rf $(NAME) $(LIB)

re: fclean $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader
	@echo "\033[31mGLORY TO NORMINETTE\033[0m"

comp:
	@gcc -g $(FLAGS) $(addprefix $(SRCDIR), $(SRC)) libft/libftprintf.a -lncurses -o debug
