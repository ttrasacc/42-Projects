SRC = distances.c\
get_next_line.c\
highways.c\
include_pipes.c\
le_min.c\
move_ants.c\
parsing_one.c\
parsing_pipes.c\
parsing_room.c\
pipes_in_rooms.c
OBJ = distances.o\
get_next_line.o\
highways.o\
include_pipes.o\
le_min.o\
move_ants.o\
parsing_one.o\
parsing_pipes.o\
parsing_room.o\
pipes_in_rooms.o
NAME = lem-in

$(NAME) : $(SRC) le_min.h
	@make -C ./libft/
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@gcc $(OBJ) ./libft/libft.a -o lem-in
	@echo "lem-in done"

all : $(NAME)

clean :
	@make -C ./libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "lem-in/files.o deleted"

fclean : clean
	@make -C ./libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@echo "lem-in deleted"

re : fclean all
