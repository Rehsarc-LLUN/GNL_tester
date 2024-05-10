NAME=gnl
CC=clang
CFLAGS="-Wall -Wextra -Werror -I."
SRCS="get_next_line.c get_next_line_utils.c main.c fmalloc.c read_counter.c"

OK="\033[0;32m[OK]\033[0m"
KO="\033[0;31m[KO]\033[0m"

# echo "BUFFER_\\_TESTCASE TEST LEAK READ MALLOC STATIC" > result.txt

if [ -e result.txt ]; then
	rm result.txt
fi

echo '  _______ .__   __.  __      .___________. _______     _______.___________. _______ .______   ' > title.txt
echo ' /  _____||  \ |  | |  |     |           ||   ____|   /       |           ||   ____||   _  \  ' >> title.txt
echo '|  |  __  |   \|  | |  |     `---|  |----`|  |__     |   (----`---|  |----`|  |__   |  |_)  | ' >> title.txt 
echo '|  | |_ | |  . `  | |  |         |  |     |   __|     \   \       |  |     |   __|  |      /  ' >> title.txt
echo '|  |__| | |  |\   | |  `----.    |  |     |  |____.----)   |      |  |     |  |____ |  |\  \-.' >> title.txt
echo ' \______| |__| \__| |_______| ___|__|     |_______|_______/       |__|     |_______|| _| `.__|' >> title.txt


function print_result {
	clear
	cat title.txt
	cat result.txt | column -t -s "	 " 2> /dev/null
}

# Check if the program can compile and run without any error
function test_normal {
	$CC $CFLAGS $SRCS -o $NAME -D BUFFER_SIZE=$BUFFER_SIZE -D N=-1 2> /dev/null
	if [ "$?" -ne 0 ]; then
		bash print_status.sh CompileError >> result.txt
		printf " " >> result.txt
		return
	fi
	./$NAME
	if [ "$?" -eq 134 ]; then
		bash print_status.sh SEGV >> result.txt
		printf " " >> result.txt
		return
	fi
	if diff first_result.txt test1.txt && diff second_result.txt test2.txt; then
		bash print_status.sh OK >> result.txt
	else
		bash print_status.sh KO >> result.txt
	fi
	printf " " >> result.txt
}

for BUFFER_SIZE in {1..10}; do
	echo -n "BUFFER_SIZE=$BUFFER_SIZE " >> result.txt
	test_normal
	print_result
	
	$CC $CFLAGS $SRCS -o $NAME -D BUFFER_SIZE=$BUFFER_SIZE -D N=-1 -D LEAKS
	./$NAME

	printf "\n" >> result.txt
	print_result
done

rm result.txt title.txt

make clean