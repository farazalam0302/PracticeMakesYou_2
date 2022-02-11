#include <bits/stdc++.h>
using namespace std;

void removeAlpha(vector<unsigned int>& a) {
  int n = a.size();
  int m = n * 0.75;
  //  unsigned int* out = new unsigned int(m);
  vector<unsigned int> out(m, 0);
  unsigned char* pM;  //= (unsigned char*)(&a[n - 1]);
  unsigned char* pO = (unsigned char*)(&out[0]);
  int c;
  for (int i = n - 1; i >= 0; --i) {
    pM = (unsigned char*)(&a[i]);
    c = 1;
    while (c < 4) {
      *pO = *pM;
      pO++;
      pM++;
      c++;
    }
    pM++;
  }
  cout << endl;

  for (auto i : out) {
    cout << hex << i << ", ";
  }
  cout << endl;
}

int main() {
  //  unsigned int image[8] = {0xAA332211, 0xAA332211, 0xAA332211, 0xAA332211,
  //                           0x44332211, 0x44332211, 0x44332211, 0x44332211};

  vector<unsigned int> image{0xAA332211, 0xAA332211, 0xAA332211, 0xAA332211,
                             0x44332211, 0x44332211, 0x44332211, 0x44332211};
  /*
   * here each pixel comprises of RGBA form as follows
   * 0xAABBGGRR form  AA-> alpha; BB-> blue ; GG-> green ; RR-> Red
   *
   * Remove AA bytes of alpha
   * and compress image to include
   * only RGB data
   * like
   * 0xBBGGRR--
   *
   * eg:
   * input =  {0xAA332211, 0xAA332211, 0xAA332211, 0xAA332211,
                       0x44332211, 0x44332211, 0x44332211, 0x44332211};

      output  =
      {0x33221133 0x22113322 0x11332211,
                       0x33221133 0x22113322  0x11332211};
   *
   */
  removeAlpha(image);
  return 0;
}
