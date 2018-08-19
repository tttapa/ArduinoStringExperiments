// g++ -g -Wall -std=c++11 main.cpp WString.cpp malloc.c -o main && ./main

#include "WString.h"

#include <iostream>
using namespace std;

#include "testmalloc.h"

int main() {
  cout << "Start" << endl;
  void *mem1 = testmalloc(8);
  printf("Allocated 1: %lu\n", (char *)mem1 - buffer);
  printfreelist();
  void *mem2 = testmalloc(8);
  printf("Allocated 2: %lu\n", (char *)mem2 - buffer);
  printfreelist();
  void *mem3 = testmalloc(8);
  printf("Allocated 3: %lu\n", (char *)mem3 - buffer);
  printfreelist();
  void *mem4 = testmalloc(8);
  printf("Allocated 4: %lu\n", (char *)mem4 - buffer);
  printfreelist();
  void *mem5 = testmalloc(8);
  printf("Allocated 5: %lu\n", (char *)mem5 - buffer);
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

  void *mem6 = testmalloc(8);
  printf("Allocated 6: %lu\n", (char *)mem6 - buffer);
  printfreelist();

  mem6 = testrealloc(mem6, 16);
  printf("Reallocated 6: %lu\n", (char *)mem6 - buffer);
  printfreelist();

  testfree(mem4);
  printf("Free 4\n");
  printfreelist();

  testfree(mem6);
  printf("Free 6\n");
  printfreelist();

  cout << endl << endl;

  String res;
  {
    String s = std::move(String("Hello, ") + String("World!"));
    res = std::move(s);
  }
  printf("String res = \"%s\"\n", res.c_str());
}