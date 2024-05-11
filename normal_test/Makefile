CC=clang
CFLAGS=-Wall -Wextra -Werror -g
SRC=main.c ../get_next_line.c ../get_next_line_utils.c -I../
NAME=gnl_tester

all:
	@if [ ! -f ../get_next_line.c ]; then cp ../../get_next_line.c ../ 2>/dev/null|| echo "No get_next_line.c"; exit 1; fi
	@if [ ! -f ../get_next_line_utils.c ]; then cp ../../get_next_line_utils.c ../ 2>/dev/null|| echo "No get_next_line_utils.c"; exit 1; fi
	@if [ ! -f ../get_next_line.h ]; then cp ../../get_next_line.h ../ 2>/dev/null|| echo "No get_next_line.h"; exit 1; fi
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)  2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest 2>/dev/null


