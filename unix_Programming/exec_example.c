#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("PID of exec_test1.c = %d\n", getpid());
  char *args[] = {"Hello", "From", "Parent", NULL};
  int _pid = vfork();
  int wstatus
  if (_pid == 0) {
    if (execv("./myprint", args) == -1) {
      printf("execv failed \n");
      exit(0);
    }
  }
  
  
  printf("Back to exec_test1.c");
  return 0;
}