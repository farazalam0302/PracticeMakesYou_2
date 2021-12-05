#include <bits/stdc++.h>
using namespace std;

int main() {
  int rgba[8] = {0x44332211, 0x44332211, 0x44332211, 0x44332211,
                 0x44332211, 0x44332211, 0x44332211, 0x44332211};
  int rgb[6] = {0};
  int* o = (int*)malloc(sizeof(int) * 6);
  char* pO = (char*)o;

  int bC;
  for (int i = 8 - 1; i >= 0; --i) {
    char* p = (char*)(rgba + i);
    bC = 1;
    while (*p != 0x44) {
      //      cout << hex << (short)(*p);
      *pO = *p;
      pO++;
      p++;
      //      bC++;
    }
    //    if (bC == 4) cout << endl;
  }
  cout << endl;
  for (int i = 0; i < 6; ++i) {
    cout << hex << (int)(*(o + i)) << " ";
  }
  cout << endl;
  return 0;
}
