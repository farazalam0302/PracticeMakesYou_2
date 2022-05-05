// Solution_sack<pair<B, N>>
//
//    unordered_map<B->set(Nuts)>  //
//                                 /*
//                                  * b1 -> (n4,n2,n3)
//                                  *
//                                  *
//                                 b1->n4
//
//                                 b1 n1
//
//                                 //////////
//                                  *
//                                  * B
//                                  * n1,n2....n5
//                                 B == n1  ; -> solution sack
//                                 B<n1  -> lessthanBs
//                                 B>n1  -> greaterthanBs
//                                   B
//                                 n1< >n1
//
//                                             B1
//                                        /         \
//                                  [n3, n2, n1 ]  n6 [ n4 n5   ]
//
//                                 2 B2 < n6  ; > n6
//
//
//                                  B ->rows N is cols
//                                  BXN  = -2
//
//                                  if b==n ; check[b][n] = 0
//                                  if b<n   check[b][n] = -1
//                                  if b>n   check[b][n] = 1
//
//
//
//
//
//
//
//
//                                 */

/// Quick Sort

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int low, int high) {
  int pivot = a[high];
  int i = low - 1;
  int tmp;
  for (int j = low; j < high; ++j) {
    if (a[j] < pivot) {
      i++;
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      //      swap(a[i], a[j]);
    }
  }
  //  swap(a[i + 1], pivot);
  tmp = a[i + 1];
  a[i + 1] = a[high];
  a[high] = tmp;
  return i + 1;
}
void quickSort(vector<int>& a, int low, int high) {
  if (low < high) {
    int pivot = partition(a, low, high);
    quickSort(a, low, pivot - 1);
    quickSort(a, pivot + 1, high);
  }
  return;
}

void printArray(vector<int>& container) {
  for (auto i : container) {
    cout << i << ", ";
  }
  cout << endl;
}

int getPivotofNuts(char* nuts, char pivot, int low, int high) {
  int i = low;
  char tmp;
  for (int j = low; j < high; ++j) {
    if (nuts[j] < pivot) {
      tmp = nuts[i];
      nuts[i] = nuts[j];
      nuts[j] = tmp;
      i++;
    } else if (nuts[j] == pivot) {
      tmp = nuts[j];
      nuts[j] = nuts[high];
      nuts[high] = tmp;
      j--;
    }
  }
  tmp = nuts[i];
  nuts[i] = nuts[high];
  nuts[high] = tmp;

  return i;
}

void quickSOrtNutsAndBolts(char* nuts, char* bolts, int low, int high) {
  if (low < high) {
    int pivot = getPivotofNuts(nuts, bolts[high], low, high);
    getPivotofNuts(bolts, nuts[pivot], low, high);

    quickSOrtNutsAndBolts(nuts, bolts, low, pivot - 1);
    quickSOrtNutsAndBolts(nuts, bolts, pivot + 1, high);
  }
}

void printArray2(char arr[]) {
  for (int i = 0; i < 8; i++) {
    cout << " " << arr[i];
  }
  cout << "\n";
}

int main() {
  vector<int> a{9, 3, 8, 2, 5, 5, 8, 3, 2, 7, 9};
  vector<int> b{9, 3, 8, 2, 5, 5, 8, 3, 2, 7, 9};
  vector<int> c{9, 3, 8, 2, 5, 5, 8, 3, 2, 7, 9};

  char nuts[10] = "abcdabcd";
  char bolts[10] = "dcbadcba";
  cout << "\nBefore Sort\n";
  printArray(a);
  cout << "\nAfter Sort\n";
  quickSort(a, 0, (a.size() - 1));
  printArray(a);

  quickSOrtNutsAndBolts(nuts, bolts, 0, 7);
  printArray2(nuts);

  cout << endl;
  printArray2(bolts);

  return 0;
}
