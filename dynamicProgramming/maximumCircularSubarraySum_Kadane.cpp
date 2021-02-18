/*

Maximum circular subarray sum
Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of
consecutive number. Examples:

Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

Input: a[] = {10, -3, -4, 7, 6, 5, -4, -1}
Output:  23 (7 + 6 + 5 - 4 -1 + 10)

Input: a[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 (7 + 6 + 5 - 4 - 1 - 1 + 40)

*/

#include <bits/stdc++.h>
using namespace std;
class Kadane {
 public:
  int maxSumKadane(vector<int> &a) {
    int n = a.size();
    int localMax = 0;
    int globalMax = INT_MIN;
    int start = 0, end = -1;
    for (int i = 0; i < n; i++) {
      localMax = localMax + a[i];
      if (localMax > globalMax) {
        globalMax = localMax;
        end = i;
      }
      if (localMax < 0) {
        localMax = 0;
        start = i + 1;
      }
    }
    if (end != -1) {
      //   a.push_back(start);
      //   a.push_back(end);
      return globalMax;
    }
    globalMax = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (a[i] > globalMax) {
        globalMax = a[i];
        start = end = i;
      }
    }
    // a.push_back(start);
    // a.push_back(end);
    return globalMax;
  }
};

int antiKadaneCsum(vector<int> &a) {
  Kadane kd;
  int normalMaxKadaneSum = kd.maxSumKadane(a);
  int arraySum = 0;
  int n = a.size();
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    arraySum += a[i];
    b[i] = -1 * a[i];
  }

  int InvKadaneSum = kd.maxSumKadane(b);

  int answer = max(arraySum + InvKadaneSum, normalMaxKadaneSum);

  return answer;
}

int circularKadaneReplicationTrick(vector<int> &a) {
  vector<int> temp(a.begin(), a.end());
  for (auto i : a) {
    temp.push_back(i);
  }
  cout << "\n\n\n";
  for (auto i : temp) {
    cout << i << " ";
  }
  cout << "\n\n\n";
  Kadane kd;
  return (kd.maxSumKadane(temp));
}

int main(int argc, char const *argv[]) {
  vector<int> a{11, 10, -20, 5, -3, -5, 8, -13, 10};
  //  for (int i = 0; i < n; i++) {
  //    cin >> a[i];
  //  }

  int circularSum = circularKadaneReplicationTrick(a);
  cout << "\n\n Csum = " << circularSum << endl;

  cout << "\n\n CsumUsingAntikadane = " << (antiKadaneCsum(a)) << endl;

  return 0;
}
