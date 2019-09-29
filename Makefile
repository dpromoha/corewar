ASM = asm
ASMDIR = assembler/

VM = corewar
VMDIR = vm_visual/

all: $(VM) $(ASM)

$(ASM):
	@make -C $(ASMDIR)
	@cp $(ASMDIR)$(ASM) ./
	@echo "copied $(ASM)"

$(VM):
	@make -C $(VMDIR)
	@cp $(VMDIR)$(VM) ./
	@echo "copied $(VM)"

clean:
	@make clean -C $(ASMDIR)
	@make clean -C $(VMDIR)

fclean: clean
	@make fclean -C $(ASMDIR)
	@make fclean -C $(VMDIR)
	@rm -rf $(ASM) $(VM)
	@echo "removed $(ASM) and $(VM) copies"

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader
	@echo "\033[31mGLORY TO NORMINETTE\033[0m"