#include <bits/stdc++.h>
using namespace std;

void printBytes(int* o, int M);

int* removeAlpha(int a[], int N) {
  unsigned int M = N * 0.75;

  int* o = (int*)malloc(sizeof(int) * M);
  char* pO = (char*)o;

  int bC;
  for (int i = N - 1; i >= 0; --i) {
    char* p = (char*)(a + i);
    bC = 1;
    while (bC < 4) {
      *pO = *p;
      pO++;
      p++;
      bC++;
    }
  }

  cout << endl;
  return o;
}

void printBytes(int* o, int M) {
  for (int i = 0; i < M; ++i) {
    cout << hex << (int)(*(o + i)) << " ";
  }
  cout << endl;
}

int main() {
  unsigned int N = 4;
  int rgba[N] = {0x44332211, 0x44332211, 0x44332211, 0x44332211};
  int rgb[6] = {0};

  int* o = removeAlpha(rgba, N);
  int M = N * 0.75;
  printBytes(o, M);
  delete (o);
  return 0;
}
