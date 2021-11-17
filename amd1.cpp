#include <bits/stdc++.h>
using namespace std;

// int twoSum(vector<int> &a, int target) {
//  unordered_map<int, int> hmap;
//  int n = a.size();
//  for (int i = 0; i < n; ++i) {
//    hmap[a[i]] = i;
//  }
//
//  for (int i = 0; i < n; ++i) {
//    if (hmap.find(target - a[i]) != hmap.end()) {
//      if (i != hmap[target - a[i]])
//        cout << i+1 << ", " << hmap[target - a[i]] << endl;
//      return 1;
//      else  return 0;
//    }
//  }
//  return 0;
//}
//
//
// int triplets(vector<int> &a, int target)
//{
//	int n = a.size();
//
//		vector<int> t (a.begin()+1, a.end());
//		if (twoSum(t,target-a[0]))
//		{
//			cout << "0";
//		}
//
//
//
//}

int main() {
  //  vector<int> a{1, 3, 2, 4};
  //
  ////  int result = twoSum(a, 6);
  // triplets(a,6);
  //  int a[3] = {1, 2, 3};
  //  unsigned long a0, a1;
  //  a0 = (unsigned long)a;
  //  a1 = (unsigned long)(a + 1);
  //  cout << (a1 - a0) << endl;
  //
  //  cout << "a[0] address " << (a) << endl;
  //  cout << "a[1] address " << (a + 1) << endl;
  string a = "MALAYALAM";
  //  sort(a.begin(), a.end());
  unordered_map<char, int> hmap;
  for (char c : a) {
    hmap[c] = 0;
  }

  string ret = "";

  for (char c : a) {
    if (hmap[c] == 0) {
      cout << c;
      hmap[c] = 1;
    }
  }
  cout << endl;
  //  cout << a << endl;
  return 0;
}
