#include <bits/stdc++.h>
using namespace std;
class LRU_cache {
  list<int> dq;
  unordered_map<int, list<int>::iterator> hash;
  int cSize;

public:
  LRU_cache(int n) { cSize = n; }
  void CacheDisplay() {
    for (auto i : dq) {
      cout << i << " ";
    }
    cout << endl;
  }

  ///////////////////////////////////

  void refer(int x) {
    if (hash.find(x) == hash.end()) {
      if (dq.size() == cSize) // queue is full
      {
        hash.erase(dq.back());
        dq.pop_back();
      }

    } else {
      dq.erase(hash[x]);
    }
    dq.push_front(x);
    hash[x] = dq.begin();
  }
  ///////////////////////////////////
};

int main() {
  LRU_cache *lru = new LRU_cache(4);
  lru->refer(1);
  lru->refer(2);
  lru->refer(3);
  lru->refer(1);
  lru->refer(4);
  lru->refer(5);
  lru->CacheDisplay();
  return 0;
}