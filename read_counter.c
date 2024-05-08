#include "test.h"

extern size_t	read_counter;

#undef read
ssize_t	read_counter_func(int fildes, void *buf, size_t nbyte)
{
	read_counter++;
	return (read(fildes, buf, nbyte));
}
#define read read_counter_func
