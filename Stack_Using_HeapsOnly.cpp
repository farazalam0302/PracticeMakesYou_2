/*

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Implement a stack API using only a heap. A stack implements the following
methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element (or throws an
error if there is nothing on the stack) Recall that a heap has the following
operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap

*/
#include <bits/stdc++.h>
using namespace std;

struct MyCompare {
  bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return lhs.first < rhs.first; // maxHeap
  }
};

auto myCompare = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
  return lhs.first < rhs.first;
};

class MyStack {
private:
  int timestamp;
  int capacity;
  int top;
  // clang-format off
  // priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> *heap;  //   operator overloading in class
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCompare)> *heap;  // comparator using lambda function
  // clang-format on

public:
  MyStack(int N) {
    timestamp = 0;
    top = -1;
    capacity = N;
    // clang-format off
    // heap = new priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare>;
    heap = new priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCompare)>;
    // clang-format on
  }
  ~MyStack() { delete heap; }
  void push(int X) {
    if (top == capacity) {
      cout << "Stack OverFlowed .... \n";
      exit(-1);
    }
    heap->push(make_pair(timestamp++, X));
    top++;
  }

  int pop() {
    if (top == -1) {
      cout << "Stack underFlowed .... \n";
      exit(-1);
    }
    int x = heap->top().second;
    heap->pop();
    top--;
    return x;
  }
  bool isEmpty() { return top == -1; }
  //   void display() {}
};

int main(int argc, char const *argv[]) {
  MyStack mstack(5);

  //   for (size_t i = 1; i <= 5; i++) {
  //     mstack.push(i);
  //   }
  mstack.push(8);
  mstack.push(19);
  mstack.push(3);
  cout << mstack.pop() << ", ";
  cout << mstack.pop() << ", ";
  mstack.push(100);
  mstack.push(1000);
  mstack.push(789);
  mstack.push(11111111);
  cout << "\n";
  //  ( 8,19,3,100,13 <- top
  //  13 100 3 19 8
  while (!mstack.isEmpty()) {
    cout << mstack.pop() << ", ";
  }

  cout << endl;

  return 0;
}
