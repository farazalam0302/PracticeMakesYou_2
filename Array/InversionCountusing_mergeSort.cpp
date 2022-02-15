#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int l, int mid, int r) {
  vector<int> left;
  vector<int> right;
  int i, j, k;
  int inversionCount = 0;
  i = l;
  j = mid;
  k = l;
  vector<int> tmp;
  while (i <= mid - 1 && j <= r) {
    if (a[i] <= a[j]) {
      tmp[k] = a[i];
      i++;

    } else {
      tmp[k] = a[j];
      j++;
      inversionCount = inversionCount + (mid - i);
    }
    k++;
  }
  while (i <= mid - 1) {
    tmp[k] = a[i];
    i++;
    k++;
  }
  while (j <= r) {
    tmp[k] = a[j];
    j++;
    k++;
  }
  a = tmp;
  return inversionCount;
}

int mergeSort(vector<int> &a, int l, int r) {
  int inversionCount = 0;
  if (l < r) {
    int mid = l + (r - l) / 2;
    inversionCount = mergeSort(a, l, mid);
    inversionCount += mergeSort(a, mid + 1, r);
    inversionCount += merge(a, l, mid + 1, r);
  }
  return inversionCount;
}

int main() {
  int n;
  //  cin >> n;
  int x;
  //  vector<int> a;
  vector<int> a{1, 20, 6, 4, 5};
  //  for (int i = 0; i < n; i++) {
  //    cin >> x;
  //    a.push_back(x);
  //  }
  int nn = a.size() - 1;
  cout << "unsorted array = ";
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
  int inversionCount = mergeSort(a, 0, nn);
  //  nn = a.size() - 2;
  cout << "sorted array = ";
  for (auto i : a) {
    cout << i << " ";
  }
  cout << "\n Inversion Count = " << inversionCount << endl;
  return 0;
}
