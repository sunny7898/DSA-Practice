#include<iostream>
using namespace  std;

int main(){
  int a, b = 1, c = 1;
  a = sizeof(c = ++b + 1);
  printf("a = %d, b = %d, c = %d\n", a, b, c);
}  