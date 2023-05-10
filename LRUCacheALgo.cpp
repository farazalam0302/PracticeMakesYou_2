#include <bits/stdc++.h>
using namespace std;

class LRUAlgo {
  int capacity;
  list<int> DQ;
  unordered_map<int, list<int>::iterator> hmap;

public:
  LRUAlgo(int c) : capacity(c) {}

  bool access(int n) {
    if (DQ.size() == capacity) {
      if (hmap.find(n) == hmap.end()) {
        int x = DQ.back();
        DQ.erase(hmap[x]);
        DQ.push_front(n);
        hmap.erase(x);
        hmap[n] = DQ.begin();
      } else {
        DQ.erase(hmap[n]);
        DQ.push_front(n);
        hmap[n] = DQ.begin();
      }
    } else {
      if (hmap.find(n) == hmap.end()) {
        DQ.push_front(n);
        hmap[n] = DQ.begin();
      } else {
        DQ.erase(hmap[n]);
        DQ.push_front(n);
        hmap[n] = DQ.begin();
      }
    }
    for (auto i : DQ) {
      cout << i << " ";
    }
    return true;
  }

  int getCapacity() const { return capacity; }
};

int main() {
  LRUAlgo *lru = new LRUAlgo(5);
  int page = 1;
  //  cout << "F   R\n";
  while (page) {
    cout << "\nF";
    for (int i = 0; i < (lru->getCapacity() + lru->getCapacity() - 3); ++i) {
      cout << " ";
    }
    cout << "R\n";
    lru->access(page);

    cout << "\nREQUEST nonZero/(zero to stop!!) ";
    cin >> page;
  }
  //
  return 0;
}
