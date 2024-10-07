#include <bits/stdc++.h>
using namespace std;

string runLengthEncoding(string a) {
  int len = a.length();
  string ret = "";
  char curr = a[0];
  ret = ret + curr;
  int ch_count = 1;
  for (size_t i = 1; i < len - 1; i++) {
    while (curr == a[i]) {
      ch_count++;
      i++;
    }
    ret = ret + to_string(ch_count) + a[i];
    curr = a[i];
    ch_count = 1;
  }

  return ret;
}

int main(int argc, char const *argv[]) {
  string a{"aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccc"
           "cccccccccccccccccccccccccccccc"};
  string ret = runLengthEncoding(a);
  cout << ret << endl;
  return 0;
}
