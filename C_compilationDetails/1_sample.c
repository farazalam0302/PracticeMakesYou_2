//#include <stdio.h>
//#define add(a, b) (a + b)
// int main() {
//  int a = 5, b = 4;
//  printf("a+b = %d\n", add(a, b));
//  return 0;
//}

// C program to illustrate
// \a escape sequence
#include <stdio.h>
int main(void) {
  float a = 1.5f;
  unsigned int b = *((unsigned int*)&a);
  printf("a=%f   ||  b = %x", a, b);

  int c = 0;
  while (b) {
    b = b & (b - 1);
    c++;
  }
  printf("\n\ncount = %d \n", c);

  return (0);
}
