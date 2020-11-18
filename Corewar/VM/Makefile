SRC_ERROR = ../BETTER_ERROR/better_error.c\
			../BETTER_ERROR/get_next_line.c

SRC_VM =tasks/zero_0x00.c\
		tasks/live_0x01.c\
		tasks/ld_0x02.c\
		tasks/std_0x03.c\
		tasks/add_0x04.c\
		tasks/sub_0x05.c\
		tasks/and_0x06.c\
		tasks/or_0x07.c\
		tasks/xor_0x08.c\
		tasks/zjmp_0x09.c\
		tasks/ldi_0x0a.c\
		tasks/sti_0x0b.c\
		tasks/fork_0x0c.c\
		tasks/lld_0x0d.c\
		tasks/lldi_0x0e.c\
		tasks/lfork_0x0f.c\
		tasks/aff_0x10.c\
		display.c\
		display_2.c\
		main.c\
		checks.c\
		ocp_handling.c\
		extras_ocp_handling.c\
		parsing.c\
		parsing2.c\
		process_handling.c\
		timing.c\
		victory.c\
		victory2.c



OBJ_ERROR = better_error.o\
			get_next_line.o

OBJ_VM =zero_0x00.o\
		live_0x01.o\
		ld_0x02.o\
		std_0x03.o\
		add_0x04.o\
		sub_0x05.o\
		and_0x06.o\
		or_0x07.o\
		xor_0x08.o\
		zjmp_0x09.o\
		ldi_0x0a.o\
		sti_0x0b.o\
		fork_0x0c.o\
		lld_0x0d.o\
		lldi_0x0e.o\
		lfork_0x0f.o\
		aff_0x10.o\
		display.o\
		display_2.o\
		main.o\
		checks.o\
		ocp_handling.o\
		extras_ocp_handling.o\
		parsing.o\
		parsing2.o\
		process_handling.o\
		timing.o\
		victory.o\
		victory2.o


vm :
	reset
	@gcc -Wall -Werror -Wextra -c $(SRC_VM)
	@gcc $(OBJ_VM) -o la_vm -lncurses
	@echo "VM done"

all : vm 

clean :
	@/bin/rm -f $(OBJ_VM)
	@/bin/rm -f $(OBJ_ERROR)
	@echo "cleaned"

fclean : clean
	@/bin/rm -f ../corewar
	@echo "all fcleaned"

re : fclean all
