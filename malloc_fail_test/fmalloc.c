#include "test.h"

extern int	malloc_counter;

#ifndef N
# define N 5
#endif


void	*fail_malloc(size_t size)
{
	if (malloc_counter == N)
		return (NULL);
	malloc_counter++;
	#undef malloc
	void	*ret = malloc(size);
	#define malloc(size) fail_malloc(size)
	return (ret);
}
