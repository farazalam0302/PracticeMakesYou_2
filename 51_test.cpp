//
//// priority_queue::emplace
//#include <stdio.h>
//// using namespace std;
//// void hashingUtil(vector<int> &a, map<int, int> &mp) {
////  for (auto i : a) {
////    if (mp.find(i) == mp.end()) {
////      mp[i] = 1;
////    } else
////      mp[i]++;
////  }
////}
////
////// bool Mycompare(int l, int r) {}
////
//// void displayMap(map<int, pair<int, bool>> &oldMAp, bool flag, bool all) {
////  for (auto i : oldMAp) {
////    if ((!(i.second.second) ^ flag) || all)
////      cout << "{" << i.first << "-->" << (bool)(i.second.second) << "} ";
////  }
////  cout << endl;
////}
///*
// int main(int argc, char const* argv[]) {
//  int m, n;
//  m = 20;
//
//  n = 10;
//  int** a = (int**)(malloc(sizeof(int*) * m));
//  for (int i = 0; i < m; ++i) {
//    a[i] = (int*)malloc(sizeof(int) * n);
//  }
//
//  for (int i = 0; i < m; ++i) {
//    cout << endl;
//    for (int j = 0; j < n; ++j) {
//      cout << a[i][j] << " ";
//    }
//  }
//  cout << endl;
//
//  for (int i = 0; i < m; ++i) {
//    for (int j = 0; j < n; ++j) {
//      a[i][j] = (i + 1) * (j + 1);
//    }
//  }
//  cout << endl;
//
//  for (int i = 0; i < m; ++i) {
//    cout << endl;
//    for (int j = 0; j < n; ++j) {
//      cout << a[i][j] << " ";
//    }
//  }
//
//  cout << endl;
//  return 0;
//}
//*/
//
//// int main() {
//// /////////
//
////   vector<int> a; //{1, 5, 4, 3, 2, 6};
////   for (int i = 1; i <= 20; i++) {
////     a.push_back(i);
////   }
//
////   map<int, pair<int, bool>> oldMAp;
////   for (auto i : a) {
////     oldMAp[i] = {i, false};
////   }
//
////   for (auto i = oldMAp.begin(); i != oldMAp.end(); i++) {
////     if (i->first & 0x1) {
////       i->second.second = true;
////     }
////   }
//
////   for (auto i = oldMAp.begin(); i != oldMAp.end(); i++) {
////     if (i->second.second) {
////       oldMAp.erase(i);
////     }
////   }
//
////   // displayMap(oldMAp, true, false);
////   // cout << "-------------------------------------" << endl;
////   // displayMap(oldMAp, false, false);
////   cout << "\n-----------------All "
////           "keys---------------------------------------------------------"
////        << endl;
////   displayMap(oldMAp, false, true);
//
////   return 0;
//// }
#include <bits/stdc++.h>
using namespace std;

// vector<int> frequencyCount(vector<vector<int>> &queries) {
//  vector<int> result;
//  unordered_map<long, int> mmap;
//  unordered_map<int, long> fmap;
//  int n = queries.size();
//  for (int i = 0; i < n; ++i) {
//  }
//}

int main() {
  //  printf("Hi Faraz Alam!!!\n");

  /*
10
1 3
2 3
3 2
1 4
1 5
1 5
1 4
3 2
2 4
3 2
   * */
  //  vector<vector<int>> queries{{1, 3}, {2, 3}, {3, 2}, {1, 4}, {1, 5},
  //                              {1, 5}, {1, 4}, {3, 2}, {2, 4}, {3, 2}};
  //  vector<int> result = frequencyCount(queries);

  int a = 10;
  const int b = 20;
  int c = 50;
  int d = 1000;
  int* const pA = &a;
  const int* pB = &b;
  int const* pC = &c;
  int const* const pCC = &a;

  cout << "*PA  = " << (*pA) << endl;
  cout << "*PB  = " << (*pB) << endl;
  cout << "*pC  = " << (*pC) << endl;
  cout << "*pCC  = " << (*pCC) << endl;
  *pA = *pA + 20;
  //  pA = &c;
  //  *pB = 150;
  //  *pB = *pB + 10;
  //  pB++;

  //  *pC = *pC + 10

  //  pC++;
  //  pCC++;
  //  *pCC = *pCC + 100000;
  cout << "*PA  = " << (*pA) << endl;
  cout << "*PB  = " << (*pB) << endl;
  cout << "*pC  = " << (*pC) << endl;
  return 0;
}

/*
 * There are 4 persons (A, B, C and D) who want to cross a bridge in night.

1.            A takes 1 minute to cross the bridge.

2.            B takes 2 minutes to cross the bridge.

3.            C takes 5 minutes to cross the bridge.

4.            D takes 8 minutes to cross the bridge.

There is only one torch with them and the bridge cannot be crossed without the
torch. There cannot be more than two persons on the bridge at any time, and when
two people cross the bridge together, they must move at the slower person’s
pace.

 *
 *
 * */
