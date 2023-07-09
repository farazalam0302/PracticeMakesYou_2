#include <bits/stdc++.h>
using namespace std;

struct myPair {
  char character;
  int frequency;
};

int maxSwaps(string &a) {
  int n = a.size();
  cout << "a.size = " << n << endl;
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

  return swaps;
}

int maxSwaps2(string &a) {
  int n = a.size();
  cout << "a.size = " << n << endl;
  int cA = 0;
  int cB = 0;
  int swaps = 0;
  for (int i = 0; i < (n); ++i) {
    if (a[i] == 'a') {
      cA = 1;
      while (a[i] == a[i + 1] && a[i] != '\0') {
        cA++;
        i++;
      }
      swaps += (cA / 3);
    }
    if (a[i] == 'b') {
      cB = 1;
      while (a[i] == a[i + 1] && a[i] != '\0') {
        cB++;
        i++;
      }
      swaps += (cB / 3);
    }
  }
  return swaps;
}

int maxSwaps3(string &a) {
  int n = a.size();
  cout << "a.size = " << n << endl;
  int c = 1;
  int swaps = 0;
  for (int i = 1; i < (n); ++i) {
    if (a[i] == a[i - 1]) {
      c++;
      continue;
    } else {
      swaps = swaps + c / 3;
      c = 1;
    }
  }
  swaps = swaps + c / 3;
  return swaps;
}

int main(int argc, char **argv) {
  string a = "aababaabaabaa";
  int swaps1 = maxSwaps(a);
  cout << "swaps1 = " << swaps1 << endl;

  swaps1 = maxSwaps2(a);
  cout << "swaps2 = " << swaps1 << endl;

  swaps1 = maxSwaps3(a);
  cout << "swaps3 = " << swaps1 << endl;

  return 0;
}
