#include <bits/stdc++.h>
using namespace std;

struct myPair {
  char character;
  int frequency;
};

int main(int argc, char **argv) {
  string a = "bbaaabbaaabba";
  int n = a.size();
  int cA = 0;
  int cB = 0;
  vector<pair<char, int>> pairs;
  for (int i = 0; i < (n); ++i) {
    if (a[i] == 'a') {
      cA = 1;
      while (a[i] == a[i + 1] && a[i] != '\0') {
        cA++;
        i++;
      }
      pairs.push_back({'a', cA});
    }
    if (a[i] == 'b') {
      cB = 1;
      while (a[i] == a[i + 1] && a[i] != '\0') {
        cB++;
        i++;
      }
      pairs.push_back({'b', cB});
    }
  }

  int swaps = 0;
  for (auto &i : pairs) {
    swaps = swaps + i.second / 3;
  }

  cout << "Swaps = " << swaps << endl;

  return 0;
}
