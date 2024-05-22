#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include "get_next_line.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

#define TIMEOUT_US 1000000

void	exit_signal(int sig)
{
	if (sig == SIGABRT)
		exit(SIGABRT + 128); // 134
	if (sig == SIGBUS)
		exit(SIGBUS + 128); // 138
	if (sig == SIGSEGV)
		exit(SIGSEGV + 128); // 139
}

void	signal_handler(void)
{
	signal(SIGBUS, exit_signal);
	signal(SIGABRT, exit_signal);
	signal(SIGKILL, exit_signal);
}

void	test(char *argv)
{
	const int	fd = open(argv, O_RDONLY);
	const int	output_fd = open("my_output", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	char		*line;

	signal_handler();
	while ((line = get_next_line(fd)) != NULL)
	{
		dprintf(output_fd, "%s", line);
		free(line);
	}
	close(fd);
	close(output_fd);
}

void print_state(int status) {
	int	exit_status = 0;
	if (WIFEXITED(status)) {
		exit_status = WEXITSTATUS(status);
    } if (WIFSIGNALED(status)) {
		exit_status = WTERMSIG(status) + 128;
	}
	if (exit_status == 0) printf("%s✔ %s", GREEN, RESET);
	else if (exit_status == 134) printf("%sABRT %s", RED, RESET);
	else if (exit_status == 138) printf("%sBUS %s", RED, RESET);
	else if (exit_status == 139) printf("%sSEGV %s", RED, RESET);
	else printf("%s✘ %s", RED, RESET);
}

int	main(int argc, char **argv)
{
	(void)argc;
	for (size_t i = 1; argv[i] != NULL; i++)
	{
		bool is_timeout = false;
		int status = 0, pid = fork();
		if (pid == 0) {
			test(argv[i]);
			exit(EXIT_SUCCESS);
		} else {
			usleep(TIMEOUT_US);
			int result = waitpid(pid, &status, WNOHANG);
			if (result == 0) {
				kill(pid, 9);
				printf("%sTIMEOUT %s", RED, RESET);
				is_timeout = true;
			}
		}
		if (!is_timeout) {
			print_state(status);
		}
	}
	return (0);
}
