SRC_CHECKER=src_checker/checker.c\
src_checker/ft_manips.c\
src_checker/get_next_line.c\
src_checker/parsing.c\
src_checker/ft_display_stack.c
SRC_PS=src_push_swap/ft_manips.c\
src_push_swap/ft_push_swap.c\
src_push_swap/extras.c
OBJ_CHECKER=checker.o\
ft_display_stack.o\
ft_manips.o\
get_next_line.o\
parsing.o
OBJ_PS=ft_manips.o\
ft_push_swap.o\
extras.o
NAME="both"

$(NAME) :
	make -C ./libft/
	make checker
	make push_swap

all : $(NAME)

clean :
	make -C ./libft/ clean
	/bin/rm -f $(OBJ_CHECKER)
	/bin/rm -f $(OBJ_PS)

fclean : clean
	make -C ./libft/ fclean
	/bin/rm -f checker
	/bin/rm -f Push_swap

re : fclean all

checker :
	gcc -Wall -Werror -Wextra -c $(SRC_CHECKER)
	gcc $(OBJ_CHECKER) libft/libftprintf.a -o checker

push_swap :
	gcc -Wall -Werror -Wextra -c $(SRC_PS)
	gcc $(OBJ_PS) ./libft/libftprintf.a -o push_swap
