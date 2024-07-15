#include <bits/stdc++.h>
using namespace std;

void printBytes(unsigned int *o, int M);

unsigned int *removeAlpha(unsigned int a[], int N) {
  unsigned int M = N * 0.75;

  unsigned int *o = (unsigned int *)malloc(sizeof(int) * M);
  char *pO = (char *)o;

  int bC;
  for (int i = N - 1; i >= 0; --i) {
    char *p = (char *)(a + i);
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

unsigned int *removeRedBlue(unsigned int a[], int N) {
  unsigned int M = N * 0.5;
  unsigned int *o = (unsigned int *)malloc(sizeof(unsigned int) * M);
  char *pO = (char *)o;
  printBytes(a, N);
  int bC;
  for (int i = 0; i < N; ++i) {
    char *p = (char *)(a + i);
    bC = 1;
    while (bC <= 4) {
      if (bC == 2 || bC == 4) {
        *pO = *p;

        pO++;
      }
      p++;
      bC++;
    }
    //    cout << endl;
  }
  cout << endl;
  return o;
}

void printBytes(unsigned int *o, int M) {
  for (int i = 0; i < M; ++i) {
    cout << hex << (int)(*(o + i)) << " ";
  }
  cout << endl;
}

int main() {
  unsigned int N = 8;
  unsigned int rgba[N] = {0xAA332211, 0xAA332211, 0xAA332211, 0xAA332211,
                          0x44332211, 0x44332211, 0x44332211, 0x44332211};
  int rgb[6] = {0};
  cout << "\n\nREMOVE ALPHA IN RGBA\n\n";
  unsigned int *o = removeAlpha(rgba, N);

  int M = N * 0.75;
  printBytes(o, M);
  delete (o);

  // cout << "\n\nREMOVE RED AND BLUE IN RGBA\n\n";

  // unsigned int* o1 = removeRedBlue(rgba, N);

  // int M = N * 0.5;
  // printBytes(o1, M);
  // delete (o1);
  return 0;
}
