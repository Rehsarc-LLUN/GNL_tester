CC=clang
CFLAGS=-Wall -Wextra -Werror -g -fsanitize=address
SRC=main.c ../get_next_line.c ../get_next_line_utils.c -I../
NAME=gnl_tester

all:
	@printf "\nRunning sanitize test\n"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -D BUFFER_SIZE=1 2> /dev/null || (echo "Compilation failed" && exit 1)
	@printf "BUFFER_SIZE = 1      "
	@./$(NAME) ../gnl_test_files/normalTest 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest1 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest2 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest3 2>/dev/null
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -D BUFFER_SIZE=4 2> /dev/null || (echo "Compilation failed" && exit 1)
	@printf "\nBUFFER_SIZE = 4      "
	@./$(NAME) ../gnl_test_files/normalTest 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest1 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest2 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest3 2>/dev/null
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -D BUFFER_SIZE=42 2> /dev/null || (echo "Compilation failed" && exit 1)
	@printf "\nBUFFER_SIZE = 42     "
	@./$(NAME) ../gnl_test_files/normalTest 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest1 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest2 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest3 2>/dev/null
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -D BUFFER_SIZE=100000 2> /dev/null || (echo "Compilation failed" && exit 1)
	@printf "\nBUFFER_SIZE = 100000 "
	@./$(NAME) ../gnl_test_files/normalTest 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest1 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest2 2>/dev/null
	@./$(NAME) ../gnl_test_files/normalTest3 2>/dev/null

clean:
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf my_output

fclean: clean

re: fclean all

.PHONY: all clean fclean re