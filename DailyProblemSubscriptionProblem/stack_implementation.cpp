/*
 * Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Implement a stack that has the following methods:

push(val), which pushes an element onto the stack

pop(), which pops off and returns the topmost element of the stack. If there are
no elements in the stack, then it should throw an error or return null.
 max(),which returns the maximum value in the stack currently. If there are no
elements in the stack, then it should throw an error or return null. Each method
should run in constant time.
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
 public:
  vector<int> buffer;
  int top;
  int maxx;
  MyStack() {
    top = -1;
    maxx = INT_MIN;
  }

  void push(int val) {
    buffer.push_back(val);
    top++;
    maxx = max(maxx, val);
  }

  int pop() {
    if (top == -1) {
      cout << "stack underflow\n" << endl;
      exit(1);
    }
    int t = buffer[top];
    top--;
    return t;
  }
  int mAX() {
    if (top == -1) {
      cout << "stack underflow\n" << endl;
      exit(1);
    }
    return maxx;
  }
};

int main() {  //

  MyStack ms;
  for (int i = 1; i < 11; ++i) {
    ms.push(i);
  }

  cout << "Maximum = " << ms.mAX() << endl;

  return 0;
}
