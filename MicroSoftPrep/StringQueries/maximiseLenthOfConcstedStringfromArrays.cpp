#include <bits/stdc++.h>
using namespace std;

int maximumLengthString(vector<string>& input) {
  vector<bitset<26>> dp = {bitset<26>()};
  int NoOfUniqueCharsinString = 0;
  int noOfstrings = input.size();
  for (int j = 0; j < noOfstrings; ++j) {
    bitset<26> a;
    for (auto character : input[j]) {
      a.set(character - 'a');
    }
    int n = a.count();
    if (n < input[j].size()) {
      continue;
    }
    for (int i = dp.size() - 1; i >= 0; --i) {
      bitset<26> d = dp[i];
      if ((d & a).any()) continue;
      dp.push_back(d | a);
      NoOfUniqueCharsinString =
          max(NoOfUniqueCharsinString, (int)d.count() + n);
    }
  }
  return NoOfUniqueCharsinString;
}

int main() {
  vector<string> input1 = {"ab", "cd", "ab"};
  vector<string> input2 = {"abcdefghij"};

  int maxlength = maximumLengthString(input1);
  cout << maxlength << endl;

  maxlength = maximumLengthString(input2);
  cout << maxlength << endl;

  return 0;
}
