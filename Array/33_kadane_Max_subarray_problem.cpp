
#include <bits/stdc++.h>
using namespace std;
#define SZ 3
int main() {
  int A[SZ] = {-2, 5, -1};
  // {-1, -2, 2, 1, 10, -4, 10, -100};

  // Kadane algo
  int maxSum_now = A[0];
  int currentsumMaxima = A[0];

  int start = 0;
  int end = 0;
  int sentinel = 0;
  for (int i = 0; i < SZ; i++) {
    // currentsumMaxima = max(currentsumMaxima + A[i], A[i]);
    // maxSum_now = max(currentsumMaxima, maxSum_now);

    currentsumMaxima = currentsumMaxima + A[i];
    if (currentsumMaxima > maxSum_now) {
      maxSum_now = currentsumMaxima;
      start = sentinel;
      end = i;
    }
    if (currentsumMaxima < 0) {
      currentsumMaxima = 0;
      sentinel = i + 1;
    }

    // if (currentsumMaxima < 0) {
    //   currentsumMaxima = 0;
    //   }
  }

  cout << "sum = " << maxSum_now << endl;

  for (int i = start; i <= end; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}