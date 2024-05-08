#ifndef TEST_H
#define TEST_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include "get_next_line.h"

#define malloc(size) fail_malloc(size)
#define read(fildes, buf, nbyte) read_counter_func(fildes, buf, nbyte)

size_t	read_counter = 0;
size_t	malloc_counter = 1;

#endif