#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& a, vector<int>& t, int l, int mid, int r) {
  //  int n1 = mid - l + 1;
  //  int n2 = r - mid;
  int inversionCount = 0;
  //
  //  //  vector<int> L(n1);
  //  //  vector<int> R(n2);
  //  int L[n1];
  //  int R[n2];
  //
  int i, j, k;
  //  for (i = 0; i <= n1; ++i) {
  //    L[i] = a[l + i];
  //  }
  //  for (i = 0; i <= n2; ++i) {
  //    R[i] = a[mid + 1 + i];
  //  }
  i = l;
  j = mid;
  k = l;
  while (i <= mid - 1 && j <= r) {
    if (a[i] <= a[j]) {
      t[k] = a[i];
      i++;
    } else {
      t[k] = a[j];
      j++;
      inversionCount = inversionCount + (mid - i);
    }
    k++;
  }

  while (i <= mid - 1) {
    t[k] = a[i];
    i++;
    k++;
  }
  while (j <= r) {
    t[k] = a[j];
    j++;
    k++;
  }
  for (int e = l; e <= r; ++e) {
    a[e] = t[e];
  }

  return inversionCount;
}

void display(vector<int>& a) {
  cout << "\nArray is as follows \n";
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
}

int mergesort(vector<int>& a, vector<int>& t, int l, int r) {
  int inversioncount = 0;
  if (l < r) {
    int mid = l + (r - l) / 2;
    inversioncount += mergesort(a, t, l, mid);
    inversioncount += mergesort(a, t, mid + 1, r);
    inversioncount += merge(a, t, l, mid, r);
  }
  return inversioncount;
}

int main() {
  vector<int> a{1, 20, 6, 4, 5};
  //  for (int i = 25; i >= 1; --i) {
  //    a.push_back(i);
  //  }
  //
  display(a);
  vector<int> t(a.size());
  int inversionCount = mergesort(a, t, 0, a.size() - 1);
  display(a);

  cout << "\n\n InversionCount = " << inversionCount << endl;
  return 0;
}
