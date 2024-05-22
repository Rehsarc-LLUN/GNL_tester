CC=clang
CFLAGS=-Wall -Wextra -Werror -g
SRC=main.c ../get_next_line.c ../get_next_line_utils.c -I../
NAME=gnl_tester

all:
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)  2>/dev/null || echo "Compilation failed"
	@./$(NAME) ../gnl_test_files/normalTest 2>/dev/null

clean:
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf my_output

fclean: clean

re: fclean all

.PHONY: all clean fclean re