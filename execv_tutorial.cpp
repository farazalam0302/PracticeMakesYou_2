#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
  // "/usr/bin/sudo", "-E",
  char *argv[] = {"/usr/bin/sudo", "-E", "/usr/bin/love", NULL};
  int _pid = vfork();
  cout << _pid << endl;
  if (_pid == 0) {
    if (execv(argv[0], argv) == -1)
      printf("Failed to execute the command\n");
  }
  return 1;
}