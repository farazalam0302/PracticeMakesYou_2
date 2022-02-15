#include <bits/stdc++.h>
using namespace std;
int maximumSubArraySumofKsize(vector<int>& a, int k) {
  int n = a.size();
  if (n < k) return -1;
  if (n == k) {
    int sum = 0;
    for (auto i : a) {
      sum += i;
    }
    return sum;
  }

  int sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += a[i];
  }
  int front = 0;
  int rear = k;

  int f, r;
  int intSum = sum;
  while (rear < n) {
    intSum = intSum + a[rear] - a[front];

    rear++;
    front++;
    if (sum < intSum) {
      sum = intSum;
      f = front;
      r = rear;
    }
  }

  //  cout << f << ", " << (r - 1) << endl;

  for (int i = f; i < r; ++i) {
    cout << a[i] << ", ";
  }
  cout << endl;

  return sum;
}
int main() {
  //
  vector<int> a{1, 2, 3, 6, 5, 4, 5, 1};  //{6, 1, 4, 6, 3, 2, 7, 4};
  int k = 4;
  cout << "\nResult = " << maximumSubArraySumofKsize(a, k) << endl;
  return 0;
}
