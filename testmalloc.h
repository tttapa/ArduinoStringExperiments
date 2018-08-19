#ifndef testmalloc_h_
#define testmalloc_h_

#include <stdlib.h>

extern void *testmalloc(size_t);
extern void printfreelist();
extern void testfree(void *);
extern void *testrealloc(void *ptr, size_t len);

extern char buffer[];

#endif