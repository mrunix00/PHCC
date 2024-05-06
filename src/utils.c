#include <stdio.h>
#include <stdlib.h>

#include "include/utils.h"

void
panic(const char *msg)
{
	fprintf(stderr, "Panic: %s\n", msg);
	exit(1);
}

void*
safe_malloc(size_t size)
{
	void *ptr = malloc(size);
	if (ptr == NULL)
		panic("Memory allocation failed!");
	return ptr;
}

void*
safe_realloc(void *ptr, size_t size)
{
	void *tmp_ptr = realloc(ptr, size);
	if (tmp_ptr == NULL)
		panic("Memory allocation failed!");
	return tmp_ptr;
}
