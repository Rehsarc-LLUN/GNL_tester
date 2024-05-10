#include "test.h"

#define malloc(size) fail_malloc(size)

size_t	read_counter = 0;
int	malloc_counter = 1;

// 128 + 11 (signal number) = 139
// 128 + 10 (signal number) = 138
// 128 + 6 (signal number) = 134
void	exit_signal(int sig)
{
	// if (sig == SIGSEGV)
	// 	exit(139);
	// else if (sig == SIGBUS)
	// 	exit(138);
	// else if (sig == SIGABRT)
	// 	exit(134);
	(void)sig;
	exit(139);
}

void	signal_handler(void)
{
	signal(SIGSEGV, exit_signal);
	signal(SIGBUS, exit_signal);
	signal(SIGABRT, exit_signal);
}

int	main(void)
{
	signal_handler();
	{
		const int	fd = open("test1.txt", O_RDONLY);
		const int	write_fd = open("first_result.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		char		*line;

		while ((line = get_next_line(fd)) != NULL)
		{
			dprintf(write_fd, "%s", line);
			free(line);
		}
		close(fd);
	}
	{
		const int	fd = open("test2.txt", O_RDONLY);
		const int	write_fd = open("second_result.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		char		*line;

		while ((line = get_next_line(fd)) != NULL)
		{
			dprintf(write_fd, "%s", line);
			free(line);
		}
		close(fd);
	}
	int fd = open("read_counter.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dprintf(fd, "%zu\n", read_counter);
	close(fd);
	return (0);
}


#ifdef LEAKS

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q gnl >& /dev/null && \
		bash print_status.sh OK >> result.txt || \
		bash print_status.sh LEAK >> result.txt");
}

#endif
