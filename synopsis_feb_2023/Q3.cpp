// BST
#include <bits/stdc++.h>
using namespace std;

int Lsearch(vector<int> &A, int target) {
  int n = A.size();
  for (int i = 0; i < n; i++) {
    if (A[i] > target)
      return i;
  }
  return -1;
}
void printArray(vector<int> &A) {
  for (auto i : A)
    cout << i << ", ";
  cout << endl;
}

int maxCount(vector<int> &A, vector<int> &B, vector<int> &C) {
  int N = A.size();
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  printArray(A);
  printArray(B);
  printArray(C);
  int L2 = -1;
  int L3 = -1;
  int count = 0;

  for (int i = 0; i < N; i++) {
    L2 = Lsearch(B, A[i]);
    if (L2 >= 0) {
      for (int j = L2; j < N; j++) {
        L3 = Lsearch(C, B[j]);
        if (L3 >= 0) {
          count += (N - L3);
        }
      }
    }
  }

  return count;
}

int main(int argc, char **argv) {

  vector<int> A{4, 9, 9, 7};
  vector<int> B{6, 5, 4, 3};
  vector<int> C{8, 2, 2, 6};

  int c = maxCount(A, B, C);
  cout << "Answer = " << c << endl;

  return 0;
}
