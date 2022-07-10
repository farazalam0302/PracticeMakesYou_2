#include <bits/stdc++.h>
using namespace std;

class LRUAlgo {
  int capacity;
  list<int> deque;
  unordered_map<int, list<int>::iterator> hmap;

public:
  LRUAlgo(int c) : capacity(c) {}

  bool access(int n) {
    if (deque.size() == capacity) {
      if (hmap.find(n) == hmap.end())   {
        int x = deque.back();
        deque.erase(hmap[x]);
        deque.push_front(n);
        hmap.erase(x);
        hmap[n] = deque.begin();
      }
      else
      {
        deque.erase(hmap[n]);
        deque.push_front(n);
        hmap[n] = deque.begin();
      }
    } else {
      if (hmap.find(n) == hmap.end()) {
        deque.push_front(n);
        hmap[n] = deque.begin();
      } else {
        deque.erase(hmap[n]);
        deque.push_front(n);
        hmap[n] = deque.begin();
      }
    }
    for (auto i : deque) {
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
