
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &A) {
    int even = 0;
    int n = A.size();
    int odd = 1;

    int t = 0;
    while (t < n && even < n && odd < n) {
      if (A[t] % 2 == 0) {
        if (t % 2 == 1) {
          swap(A[t], A[even]);
        }

        t++;
        even += 2;

      } else if (A[t] % 2 == 1) {
        if (t % 2 == 0)
          swap(A[t], A[odd]);
        odd += 2;
        t++;
      } else
        t++;
    }

    return A;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  // while (getline(cin, line)) {
  vector<int> A{888, 505, 627, 846};

  vector<int> ret = Solution().sortArrayByParityII(A);

  string out = integerVectorToString(ret);
  cout << out << endl;
  // }
  return 0;
}