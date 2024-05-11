#include "test.h"

extern size_t	read_counter;

#undef read

ssize_t	read_counter_func(int fildes, void *buf, size_t nbyte)
{
	ssize_t	ret;

	read_counter++;
	ret = read(fildes, buf, nbyte);
	return (ret);
}

#define read	read_counter_func