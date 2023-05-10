// A quack is a data structure combining properties of both stacks and queues.
// It can be viewed as a list of elements written left to right such that three
// operations are possible:
//
// push(x): add a new item x to the left end of the list
// pop(): remove and return the item on the left end of the list
// pull(): remove the item on the right end of the list.
// Implement a quack using three stacks and O(1) additional memory, so that the
// amortized time for any push, pop, or pull operation is O(1).

#include <bits/stdc++.h>
using namespace std;

class Quack {
public:
  list<int> quack;
  int capacity;

  Quack(int c) { capacity = c; }

  void push(int x) {
    if (quack.size() == capacity) {
      cout << "QUACK OVERFLOWN !!!!!\n" << endl;
      return;
    }
    quack.push_front(x);
  }
  int pop() {
    if (quack.empty()) {
      cout << "QUACK UNDERFLOWN !!!" << endl;
      return (-1);
    }
    int x = quack.front();
    quack.pop_front();
    return x;
  }

  int pull() {
    if (quack.empty()) {
      cout << "QUACK UNDERFLOWN !!!" << endl;
      return (-1);
    }
    int x = quack.back();
    quack.pop_back();
    return x;
  }

  void display() {
    if (quack.empty()) {
      cout << "QUACK UNDERFLOWN not displayed!!!" << endl;
      return;
    }
    for (auto i : quack) {
      cout << i << ",   ";
    }
    cout << endl;
  }
};

int main(int argc, char const *argv[]) {
  Quack qstack(5);
  for (size_t i = 0; i < 5; i++) {
    qstack.push(i + 1);
  }
  qstack.display();
  qstack.push(20);

  qstack.pop();
  qstack.display();

  cout << (qstack.pull()) << endl;
  qstack.display();
  cout << (qstack.pull()) << endl;
  qstack.display();
  cout << (qstack.pull()) << endl;
  qstack.display();
  cout << (qstack.pull()) << endl;
  qstack.display();
  cout << (qstack.pull()) << endl;

  return 0;
}
