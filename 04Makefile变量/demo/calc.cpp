#include <iostream>
#include "add.h"
// #include "add.cpp"
#include "sub.h"
// #include "sub.cpp"

int main(){
  int a = 10,b=2;
  printf("a + b = %d\n", add(a,b));
  printf("a - b = %d\n", sub(a,b));
  return 0;
}