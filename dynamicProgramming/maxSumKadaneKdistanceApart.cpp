/*
Maximum subsequence sum such that all elements are K distance apart
Given an array arr[] of N integers and another integer K. The task is to find
the maximum sum of a subsequence such that the difference of the indices of all
consecutive elements in the subsequence in the original array is exactly K. For
example, if arr[i] is the first element of the subsequence then the next element
has to be arr[i + k] then arr[i + 2k] and so on.

Examples:

Input: arr[] = {2, -3, -1, -1, 2}, K = 2
Output: 3



Input: arr[] = {2, 3, -1, -1, 2}, K = 3
Output: 5

*/

#include <bits/stdc++.h>
using namespace std;

class KadaneSum_k_distanceApart {
public:
  int kadane_K_distanceApart(vector<int> &a, int k, int start) {
    int n = a.size();
    int localMax = 0;
    int globalMax = INT_MIN;

    for (int i = start; i < n; i += k) {
      localMax = max((a[i] + localMax), a[i]);
      globalMax = max(globalMax, localMax);
      //   if (localMax < 0)
      //     localMax = 0;
    }
    return globalMax;
  }

  int basicKadane(vector<int> &a) {
    int n = a.size();
    int localMax = a[0];
    int globalMax = a[0];

    for (int i = 1; i < n; i++) {
      localMax = max((a[i] + localMax), a[i]);
      globalMax = max(globalMax, localMax);
      //   if (localMax < 0)
      //     localMax = 0;
    }
    return globalMax;
  }

  int findMaxSumInArray(vector<int> &a, int k) {
    int maxSum_kDistanceApart = INT_MIN;
    int n = a.size();
    int tmp;

    for (int i = 0; i <= min(n, k); i++) {
      tmp = kadane_K_distanceApart(a, k, i);
      cout << "iteration " << i << "tmp = " << tmp << endl;
      maxSum_kDistanceApart = max(maxSum_kDistanceApart, tmp);
    }
    return maxSum_kDistanceApart;
  }
};

int main(int argc, char const *argv[]) {
  int k;
  int n;
  cin >> n;
  cin >> k;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  KadaneSum_k_distanceApart kd;
  int answer = kd.findMaxSumInArray(a, k);
  cout << "answer = " << answer << endl;
  answer = kd.basicKadane(a);
  cout << "basicKadaneAnswer = " << answer << endl;

  return 0;
}
