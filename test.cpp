
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
  // vector<int> a{1, 3, 4, 5, 6, 4, 3, 6};
  // map<int, int> mmap;
  list<int> dll;
  deque<int> dq;
  dq.push_back(1);
  dq.push_back(2);
  dq.push_back(3);
  dq.push_front(10);
  dq.push_front(20);
  dq.push_front(30);

  dll.push_back(1);
  dll.push_back(2);
  dll.push_back(3);
  dll.push_front(10);
  dll.push_front(20);
  dll.push_front(30);

  int r = 1;
  dq.resize(6);
  r = 2;

  dq.pop_back();
  r = 29;
  dq.pop_back();
  r = 2;
  dq.pop_front();
  r = 23;
  dq.pop_front();
  r = 100;

  dll.pop_back();
  r = 29;
  dll.pop_back();
  r = 2;
  dll.pop_front();
  r = 23;
  dll.pop_front();
  r = 100;

  return 0;
}