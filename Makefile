NAME := gnl
CC := clang
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g -fsanitize=address

SRCS := get_next_line.c get_next_line_utils.c main.c fmalloc.c read_counter.c

ifeq ($(MAKECMDGOALS),leak)
	CFLAGS += -D LEAK
endif

all: 
	@cp ../get_next_line.c .
	@cp ../get_next_line.h .
	@cp ../get_next_line_utils.c .
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -D BUFFER_SIZE=1 -D N=1

clean:
	rm -f $(NAME)