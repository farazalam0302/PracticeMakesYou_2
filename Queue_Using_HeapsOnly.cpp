/*

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Implement a QUeue API using only a heap. A Q implements the following
methods:

push(item), which adds an element to the Q
pop(), which removes and returns the most recently added element (or throws an
error if there is nothing on the Q) Recall that a heap has the following
operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap

*/
#include <bits/stdc++.h>
using namespace std;

struct MyCompare {
  bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
    return lhs.first > rhs.first; // minHeap
  }
};

auto myCompare = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
  return lhs.first > rhs.first;
};

class MyQueue {
private:
  int timestamp;
  int capacity;
  int front;
  // clang-format off
  // priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> *heap;  //   operator overloading in class
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCompare)> *heap;  // comparator using lambda function
  // clang-format on

public:
  MyQueue(int N) {
    timestamp = 0;
    front = -1;
    capacity = N;
    // clang-format off
    // heap = new priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare>;
    heap = new priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCompare)>;
    // clang-format on
  }
  ~MyQueue() { delete heap; }
  void push(int X) {
    if (front == capacity) {
      cout << "Queue OverFlowed .... \n";
      exit(-1);
    }
    heap->push(make_pair(timestamp++, X));
    front++;
  }

  int pop() {
    if (front == -1) {
      cout << "Queue underFlowed .... \n";
      exit(-1);
    }
    int x = heap->top().second;
    heap->pop();
    front--;
    return x;
  }
  bool isEmpty() { return front == -1; }
  //   void display() {}
};

int main(int argc, char const *argv[]) {
  MyQueue mQueue(5);

  //   for (size_t i = 1; i <= 5; i++) {
  //     mQueue.push(i);
  //   }
  mQueue.push(8);
  mQueue.push(19);
  mQueue.push(3);
  cout << mQueue.pop() << ", ";
  cout << mQueue.pop() << ", ";
  mQueue.push(100);
  mQueue.push(1000);
  mQueue.push(789);
  mQueue.push(11111111);
  cout << "\n";
  //  ( 8,19,3,100,13 <- front
  //  13 100 3 19 8
  while (!mQueue.isEmpty()) {
    cout << mQueue.pop() << ", ";
  }

  cout << endl;

  return 0;
}
