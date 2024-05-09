NAME=gnl
CC=clang
CFLAGS="-Wall -Wextra -Werror -I."
SRCS="get_next_line.c get_next_line_utils.c main.c fmalloc.c read_counter.c"

OK="\033[0;32m[OK]\033[0m"
KO="\033[0;31m[KO]\033[0m"

echo "BUFFER_\\_TESTCASE TEST LEAK READ MALLOC STATIC" > result.txt

bash print_result.sh

for BUFFER_SIZE in {1..10}; do
	$CC $CFLAGS $SRCS -o $NAME -D BUFFER_SIZE=$BUFFER_SIZE -D N=-1
	echo -n "BUFFER_SIZE=$BUFFER_SIZE " >> result.txt
	./$NAME
	if diff first_result.txt test1.txt && diff second_result.txt test2.txt; then
		bash ok_status.sh >> result.txt
	else
		bash ko_status.sh >> result.txt
	fi
	bash print_result.sh
	printf " " >> result.txt
	$CC $CFLAGS $SRCS -o $NAME -D BUFFER_SIZE=$BUFFER_SIZE -D N=-1 -D LEAKS
	./$NAME
	printf "\n" >> result.txt
	bash print_result.sh
done

rm result.txt

make clean