all: 
	@make clean
	@make copy
	@make normal
	@make sanitize
	@make leak
	@make read_count
	@make malloc_fail
	@make malloc_fail_leak

clean:
	@rm -f $(NAME) get_next_line.c get_next_line_utils.c get_next_line.h
	@make -C normal_test clean
	@make -C sanitize_test clean

fclean: clean

re: fclean all

.PHONY: all clean fclean re

copy:
	@cp ../get_next_line.c .
	@cp ../get_next_line_utils.c .
	@cp ../get_next_line.h .

.PHONY: copy

# OK, KO, SEGV, TIMEOUT, CompileError
normal:
	@make copy
	@make -C normal_test

# OK, KO, SEGV, TIMEOUT, CompileError
sanitize:
	@make copy
	@make -C sanitize_test

# OK, KO, SEGV, TIMEOUT, LEAK, CompileError
leak:
	@make -C leak_test

# OK, KO, SEGV, TIMEOUT, CompileError, ReadCountError
read_count:
	@make -C read_count_test

# OK, SEGV, TIMEOUT, CompileError, StaticMallocFailError
malloc_fail:
	@make -C malloc_fail_test

# OK, SEGV, LEAK, TIMEOUT, CompileError, StaticMallocFailError
malloc_fail_leak:
	@make -C malloc_fail_leak_test

.PHONY: normal sanitize leak read_count malloc_fail malloc_fail_leak
