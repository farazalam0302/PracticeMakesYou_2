#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string result = "";
    int w1 = 0;
    int w2 = 0;
    bool alt = false;
    int w1len = word1.length();
    int w2len = word2.length();
    while (w1 < w1len && w2 < w2len) {
      if (!alt) {
        result = result + word1[w1];
        w1++;
        alt = true;
      } else {
        result = result + word2[w2];
        w2++;
        alt = false;
      }
    }
    if (w1 < w1len) {
      result = result + word1.substr(w1);
    }
    if (w2 < w2len) {
      result = result + word2.substr(w2);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string a = "abcde";
  string b = "pqr";
  string r = sol.mergeAlternately(a, b);
  cout << r << endl;
  return 0;
}
