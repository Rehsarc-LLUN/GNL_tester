NAME := gnl
CC := clang
CFLAGS = -Wall -Wextra -Werror -I.
# CFLAGS += -g -fsanitize=address

SRCS := get_next_line.c get_next_line_utils.c main.c fmalloc.c read_counter.c

all: 
	@make clean
	@cp ../get_next_line.c .
	@cp ../get_next_line_utils.c .
	@cp ../get_next_line.h .
	@bash normal_test.sh
	

clean:
	@rm -f $(NAME) get_next_line.c get_next_line_utils.c get_next_line.h first_result.txt second_result.txt read_counter.txt