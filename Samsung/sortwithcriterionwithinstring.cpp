#include <bits/stdc++.h>
using namespace std;

int patternOrder[256];

void printArray() {
  int count = 0;
  for (auto &&i : patternOrder) {
    if (count <= 10) {
      cout << i << ", ";
      count++;
    } else {
      cout << i << ", ";
      count = 0;
      cout << endl;
    }
  }
}

bool myCompare(char left, char right) {
  return (patternOrder[(int)left] < patternOrder[(int)right]);
}

bool myCompare2(char left, char right) {
  return (patternOrder[(int)left] > patternOrder[(int)right]);
}

int main(int argc, char const *argv[]) {
  string orderingPattern = "abcdefghrstuvwxyzijklmnopq";
  int l = orderingPattern.length();
  for (int i = 0; i < l; i++) {
    patternOrder[(int)orderingPattern[i]] = i;
  }
  string in = "abcdefghijklmnopqrstuvwxyz";
  int k = 24;
  l = in.length();
  int c = 0;
  char *ptr = (char *)in.c_str();
  char *endString = ptr + l;
  int direction = 0;
  char *endd;
  while (ptr != NULL && c < l) {

    if (c + k >= l) {
      endd = endString;
    } else {
      endd = ptr + k;
    }

    if (direction == 0) {
      sort(ptr, endd, myCompare);
      direction = 1;
    } else if (direction == 1) {
      sort(ptr, endd, myCompare2);
      direction = 0;
    }
    ptr = ptr + k;
    c += k;
  }

  cout << in << endl;
  return 0;
}
