#ifndef UTILS_H
#define UTILS_H

void panic(const char *);
void *safe_malloc(size_t);
void *safe_realloc(void *, size_t);

#endif
