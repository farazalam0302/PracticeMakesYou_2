#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

void copyBytes(char *dest, char *src, int number) {
  for (size_t i = 0; i < number; i++) {
    *dest = *src;
    dest++;
    src++;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  char src[] = "Hello World";
  char *dst = new char[20];
  char *sc = src;
  char *dc = src + 6;
  printf("%s\n", src);
  copyBytes(dc, sc, 5);
  printf("%s\n", src);

  return 0;
}
