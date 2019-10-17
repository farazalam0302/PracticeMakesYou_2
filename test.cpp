
// priority_queue::emplace
#include <bits/stdc++.h>
using namespace std;
void hashingUtil(vector<int> &a, map<int, int> &mp) {
  for (auto i : a) {
    if (mp.find(i) == mp.end()) {
      mp[i] = 1;
    } else
      mp[i]++;
  }
}
int main() {
  vector<int> a{1, 3, 4, 5, 6, 4, 3, 6};
  map<int, int> mmap;
  hashingUtil(a, mmap);
  for (auto i : mmap) {
    cout << i.first << " -> " << i.second << endl;
  }
  cout << "endd returned" << endl;
  return 0;
}