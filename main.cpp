// g++ -g -Wall -std=c++11 main.cpp WString.cpp malloc.c -o main && ./main

#include "WString.h"

#include <iostream>
using namespace std;

#include "testmalloc.h"

int main() {
  cout << "Start" << endl;
  char *mem1 = (char *)testmalloc(8);
  printf("Allocated 1: %lu\n", mem1 - buffer);
  printfreelist();
  char *mem2 = (char *)testmalloc(8);
  printf("Allocated 2: %lu\n", mem2 - buffer);
  printfreelist();
  char *mem3 = (char *)testmalloc(8);
  printf("Allocated 3: %lu\n", mem3 - buffer);
  printfreelist();
  char *mem4 = (char *)testmalloc(8);
  printf("Allocated 4: %lu\n", mem4 - buffer);
  printfreelist();
  char *mem5 = (char *)testmalloc(8);
  printf("Allocated 5: %lu\n", mem5 - buffer);
  printfreelist();
  testfree(mem2);
  printf("Free 2\n");
  printfreelist();
  testfree(mem1);
  printf("Free 1\n");
  printfreelist();
  testfree(mem3);
  printf("Free 3\n");
  printfreelist();
  testfree(mem5);
  printf("Free 5\n");
  printfreelist();
  testfree(mem4);
  printf("Free 4\n");
  printfreelist();
}