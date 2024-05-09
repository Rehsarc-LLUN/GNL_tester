#include "test.h"

extern size_t	read_counter;

ssize_t	read_counter_func(int fildes, void *buf, size_t nbyte)
{
	read_counter++;
	#undef read
	ssize_t	ret = read(fildes, buf, nbyte);
	#define read read_counter_func
	return (ret);
}