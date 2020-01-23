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

int main(int argc, char const *argv[]) {

  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Kadane kd;

  int normalMaxKadaneSum = kd.maxSumKadane(a);
  int arraySum = 0;
  for (int i = 0; i < n; i++) {
    arraySum += a[i];
    a[i] = -1 * a[i];
  }

  int InvKadaneSum = kd.maxSumKadane(a);

  int answer = max(arraySum + InvKadaneSum, normalMaxKadaneSum);

  cout << "answer = " << answer << endl;

  return 0;
}
