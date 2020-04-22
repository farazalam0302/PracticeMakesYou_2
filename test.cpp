
// priority_queue::emplace
#include <stdio.h>
// using namespace std;
// void hashingUtil(vector<int> &a, map<int, int> &mp) {
//  for (auto i : a) {
//    if (mp.find(i) == mp.end()) {
//      mp[i] = 1;
//    } else
//      mp[i]++;
//  }
//}
//
//// bool Mycompare(int l, int r) {}
//
// void displayMap(map<int, pair<int, bool>> &oldMAp, bool flag, bool all) {
//  for (auto i : oldMAp) {
//    if ((!(i.second.second) ^ flag) || all)
//      cout << "{" << i.first << "-->" << (bool)(i.second.second) << "} ";
//  }
//  cout << endl;
//}
/*
int main(int argc, char const* argv[]) {
  int m, n;
  m = 20;

  n = 10;
  int** a = (int**)(malloc(sizeof(int*) * m));
  for (int i = 0; i < m; ++i) {
    a[i] = (int*)malloc(sizeof(int) * n);
  }

  for (int i = 0; i < m; ++i) {
    cout << endl;
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << " ";
    }
  }
  cout << endl;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = (i + 1) * (j + 1);
    }
  }
  cout << endl;

  for (int i = 0; i < m; ++i) {
    cout << endl;
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << " ";
    }
  }

  cout << endl;
  return 0;
}
*/

// int main() {
// /////////

//   vector<int> a; //{1, 5, 4, 3, 2, 6};
//   for (int i = 1; i <= 20; i++) {
//     a.push_back(i);
//   }

//   map<int, pair<int, bool>> oldMAp;
//   for (auto i : a) {
//     oldMAp[i] = {i, false};
//   }

//   for (auto i = oldMAp.begin(); i != oldMAp.end(); i++) {
//     if (i->first & 0x1) {
//       i->second.second = true;
//     }
//   }

//   for (auto i = oldMAp.begin(); i != oldMAp.end(); i++) {
//     if (i->second.second) {
//       oldMAp.erase(i);
//     }
//   }

//   // displayMap(oldMAp, true, false);
//   // cout << "-------------------------------------" << endl;
//   // displayMap(oldMAp, false, false);
//   cout << "\n-----------------All "
//           "keys---------------------------------------------------------"
//        << endl;
//   displayMap(oldMAp, false, true);

//   return 0;
// }

int main() {
  printf("Hi Faraz Alam!!!\n");
  return 0;
}