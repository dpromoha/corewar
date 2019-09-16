# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 12:59:57 by dpromoha          #+#    #+#              #
#    Updated: 2019/09/01 12:59:58 by dpromoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FLAGS	=	-Wall -Werror -Wextra -I./includes

OBJDIR	=	./objects/

PFDIR	=	./sources/ft_printf/

LIBDIR	=	./sources/libft-gnl/

PFSRC	=	ft_printf.c find_all_expansion.c fwp.c fwp_help.c \
additional_func.c percent_output.c float_output.c number_system.c \
printf_help.c int_output.c to8_output.c unsigned_output.c \
to16_output.c pointer_output.c unicode.c helping_func.c \
unicode_output.c string_output.c float_help.c float_help2.c \

LIBSRC	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_unsignint.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c help_atoi.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_space.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_strtrim.c \
ft_tolower.c ft_toupper.c ft_itoa.c ft_strnstr.c ft_strsplit.c ft_strndup.c new_file.c \
storage.c reader.c helpful_atoi.c space_read.c \

PFOBJ	=	$(addprefix $(OBJDIR), $(PFSRC:.c=.o))

LIBOBJ	=	$(addprefix $(OBJDIR), $(LIBSRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBOBJ) $(PFOBJ)
	@ar rcs $(NAME) $(PFOBJ) $(LIBOBJ)
	@echo "\033[33mmade $(NAME)\033[0m"

$(OBJDIR):
	@mkdir $(OBJDIR)

$(LIBOBJ): $(OBJDIR)%.o : $(LIBDIR)%.c
	@echo "\033[33mcreating $(NAME) objects\033[0m"
	@gcc -o $@ -c $< $(FLAGS)

$(PFOBJ): $(OBJDIR)%.o : $(PFDIR)%.c
	@gcc -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[31mdelete $(NAME) objects\033[0m"
	@echo "\033[31mdelete $(NAME) bin\033[0m"
	@rm -f $(NAME)

re: fclean $(NAME)
