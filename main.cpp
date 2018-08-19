// g++ -g -Wall -std=c++14 -DFORUM main.cpp WString.cpp malloc.c realloc.c -o main && ./main

#include "WString.h"

#include <iostream>
using namespace std;

#include "testmalloc.h"

String returnAsString(const char *cstr) { return {cstr}; }

int main() {
  {
    String res;
    {
      String temp = String("Hello, ") + String("World!");
      res = temp;
    }
    printf("String res = \"%s\"\n", res.c_str());
  }

  cout << endl << endl;

  {
    String reserverd;
    reserverd.reserve(32);
    reserverd = "Test";
    reserverd += returnAsString("+returnAsString");
    reserverd += String("+") + "More" + "+";
  }
}