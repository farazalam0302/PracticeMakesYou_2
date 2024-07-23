#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Hello from myprint.c\n");
  printf("PID of myprint process is: %d\n", getpid());
  return 0;
}