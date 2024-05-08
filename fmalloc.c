#include <stdlib.h>

extern size_t	malloc_counter;

#ifndef N
# define N 5
#endif

#undef malloc

void	*fail_malloc(size_t size)
{
	if (malloc_counter == N)
		return (NULL);
	malloc_counter++;
	return (malloc(size));
}

#define malloc(size) fail_malloc(size)
