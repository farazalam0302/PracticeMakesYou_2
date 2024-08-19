/*

a=0x13

b=0x24


after swapping

a=0x14

b=0x23


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int a = 0x13;
  int b = 0x24;
  int t = a;
  a = (a & 0xf0) | (b & 0xf);
  b = (b & 0xf0) | (t & 0xf);
  
  printf("a = %x\n", a);
  printf("b = %x\n", b);

  return 0;
}
