#ifndef testmalloc_h_
#define testmalloc_h_

#include <stdlib.h>

extern void *testmalloc(size_t);
extern void printfreelist();
extern void testfree(void *);

extern char buffer[];

#endif