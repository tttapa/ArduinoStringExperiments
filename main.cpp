// g++ -g -Wall -std=c++14 -DFORUM main.cpp WString.cpp malloc.c realloc.c -o
// main && ./main

#include "WString.h"

#include <iostream>
using namespace std;

#include "testmalloc.h"

String returnAsString(const char *cstr) { return {cstr}; }

int main() {
  {
    String res = String("Hello, ") + "World" + '!';
    printf("Done: \"%s\"\n", res.c_str());
  }

  cout << endl;

  {
    String res;
    {
      String temp = String("Hello, ") + "World" + '!';
      res = temp;
    }
    printf("Done: \"%s\"\n", res.c_str());
  }

  cout << endl;

  {
    String reserverd;
    reserverd.reserve(32);
    reserverd = String("Hello, ") + returnAsString("World") + '!';
    printf("Done: \"%s\"\n", reserverd.c_str());
  }
}