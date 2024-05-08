#include <sys/types.h>
#include <unistd.h>

extern size_t	read_counter;

ssize_t	read_counter_func(int fildes, void *buf, size_t nbyte)
{
	read_counter++;
	return (read(fildes, buf, nbyte));
}
