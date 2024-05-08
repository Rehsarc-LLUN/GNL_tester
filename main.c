#include "test.h"

#define malloc(size) fail_malloc(size)

extern size_t	read_counter;
extern size_t	malloc_counter;

void	exit_signal(int sig)
{
    if (sig == SIGSEGV) {
        exit(1);
    } else if (sig == SIGBUS) {
        exit(2);
    } else if (sig == SIGABRT) {
        exit(134);
    }
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
	system("leaks -q gnl && ./ok_status.sh || ./ko_status.sh");
}

#endif
