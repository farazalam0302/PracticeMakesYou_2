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

class Quack_naiveSoln {
public:
  list<int> quack;
  int capacity;

  Quack_naiveSoln(int c) { capacity = c; }

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

class Quack_3Stacks {
  /*
   * solution.

1. stack s1 for push/pop; stack s3 for pull; stack s2 is a copy of s1;

2. instance variable sz to keep track the number of remaining elements.

3. push: push the same element to s1 and s2; pop: first check sz, if sz == 0,
clear s1, otherwise do s1.pop(). pull: first check sz, if sz == 0, clear s1;
otherwise if there is no element in s3, pop all copy elements in s2 to s3, then
do s3.pop().

sz is needed here because pop/pull on s1/s3 are not synchronized with each
other. Even if all elements have been either poped or pulled, s1 or s3 may still
have elements that have already been popped/pulled. So each time sz becomes 0,
we need to clear both s1 and s3.



Runtime/space complexity:

space is O(N) as for each element that is pushed, we store an extra copy in s2.

time: push: O(1);  pop: as long as sz is not 0, s1 is never empty. When sz is 0,
we need to clear both s1 and s3, which takes O(N) time. This only happens
following N pop or pull operations, so pop has amortized O(1) time. pull:
similar with pop except that it takes another O(N) time to push copy elements
from s2 to s3. It also has amortized O(1) time.
   *
   */
public:
  stack<int> *s1;
  stack<int> *s2;
  stack<int> *s3;
  stack<int> t;
  int capacity;

  Quack_3Stacks() {
    capacity = 0;
    s1 = new stack<int>();
    s2 = new stack<int>();
    s3 = new stack<int>();
  }
  ~Quack_3Stacks() {
    delete s1;
    delete s2;
    delete s3;
  }
  void push(int x) {
    s1->push(x);
    s2->push(x);
    capacity++;
  }

  void clear(stack<int> *s) {
    while (!s->empty()) {
      s->pop();
    }
  }

  int pop() {
    if (capacity == 0) {
      clear(s1);
      clear(s3);
      cout << "QUACK UNDERFLOWN!!\n";
      return (-1);
    }
    if (!s2->empty())
      s2->pop();
    capacity--;
    int x = s1->top();
    s1->pop();
    return x;
  }

  int pull() {
    if (capacity == 0) {
      clear(s1);
      clear(s3);
      cout << "QUACK UNDERFLOWN!!\n";
      return (-1);
    } else if (s3->size() == 0) {
      while (s2->size() > 0) {
        s3->push(s2->top());
        s2->pop();
      }
    }
    int x = s3->top();
    s3->pop();
    capacity--;
    return x;
  }
  void display(stack<int> *s, string msg) {
    cout << msg << endl;
    if (s->empty()) {
      cout << "---------empty----" << endl;
      return;
    }
    int tmp;
    while (s->empty() == false) {
      tmp = s->top();
      cout << "|" << (tmp) << "|" << endl;
      t.push(tmp);
      s->pop();
    }
    while (t.empty() == false) {
      tmp = t.top();
      //          cout << (tmp) << endl;
      s->push(tmp);
      t.pop();
    }

    cout << "----------------------------" << endl;
  }
};

class Quack_Pro {
public:
  stack<int> *left;
  stack<int> *right;
  stack<int> *aux;
  stack<int> t;

  Quack_Pro() {
    left = new stack<int>();
    right = new stack<int>();
    aux = new stack<int>();
  }
  ~Quack_Pro() {
    delete left;
    delete right;
    delete aux;
  }

  void display(stack<int> *s, string msg) {
    cout << msg << endl;
    if (s->empty()) {
      cout << "---------empty----" << endl;
      return;
    }
    int tmp;
    while (s->empty() == false) {
      tmp = s->top();
      cout << "|" << (tmp) << "|" << endl;
      t.push(tmp);
      s->pop();
    }
    while (t.empty() == false) {
      tmp = t.top();
      //          cout << (tmp) << endl;
      s->push(tmp);
      t.pop();
    }

    cout << "----------------------------" << endl;
  }

  void push(int x) { left->push(x); }

  int pop() {
    if (left->size() == 0 && right->size() == 0) {
      cout << "QUACK UNDERFLOWN\n";
      return -1;
    }

    if (left->size() == 0) {
      for (size_t i = 0; i < right->size() / 2; i++) {
        aux->push(right->top());
        right->pop();
      }

      while (right->size() > 0) {
        left->push(right->top());
        right->pop();
      }

      while (aux->size() > 0) {
        right->push(aux->top());
        aux->pop();
      }
    }
    int ret = left->top();
    left->pop();
    return ret;
  }

  int pull() {
    if (left->size() == 0 && right->size() == 0) {
      cout << "QUACK UNDERFLOWN\n";
      return -1;
    }

    if (right->size() == 0) {
      for (size_t i = 0; i < left->size() / 2; i++) {
        aux->push(left->top());
        left->pop();
      }

      while (left->size() > 0) {
        right->push(left->top());
        left->pop();
      }

      while (aux->size() > 0) {
        left->push(aux->top());
        aux->pop();
      }
    }
    int ret = right->top();
    right->pop();
    return ret;
  }
};

int main(int argc, char const *argv[]) {

#if 1
  Quack_Pro qPro;
  for (size_t i = 0; i < 9; i++) {
    qPro.push(i + 1);
  }
  cout << "STACK 1" << endl;
  qPro.display(qPro.left, "leftStack");
  qPro.display(qPro.right, "rightStack");
  qPro.display(qPro.aux, "Aux Stack");

  ////////////////////////////
  cout << "popping elements\n";
  for (int i = 0; i < 4; ++i) {
    cout << qPro.pop() << endl;
  }
  ////////////////////////////

  qPro.display(qPro.left, "leftStack");
  qPro.display(qPro.right, "rightStack");
  qPro.display(qPro.aux, "Aux Stack");
  cout << "Pulling elements \n";
  for (int i = 0; i < 3; ++i) {
    cout << qPro.pull() << endl;
  }
  ////////////////////////////

  qPro.display(qPro.left, "leftStack");
  qPro.display(qPro.right, "rightStack");
  qPro.display(qPro.aux, "Aux Stack");

  cout << "Pupping element \n";
  cout << qPro.pop() << endl;
  qPro.display(qPro.left, "leftStack");
  qPro.display(qPro.right, "rightStack");
  qPro.display(qPro.aux, "Aux Stack");

  ////////////////////////////

  cout << "Pulling element \n";
  cout << qPro.pull() << endl;
  qPro.display(qPro.left, "leftStack");
  qPro.display(qPro.right, "rightStack");
  qPro.display(qPro.aux, "Aux Stack");

  ////////////////////////////

  cout << "Pulling element \n";
  cout << qPro.pull() << endl;
  qPro.display(qPro.left, "leftStack");
  qPro.display(qPro.right, "rightStack");
  qPro.display(qPro.aux, "Aux Stack");

  ////////////////////////////

#endif

#if 0 // Naive solution with 2 stacks put 1 to enable

  Quack_3Stacks q3s1;
  for (size_t i = 0; i < 9; i++) {
    q3s1.push(i + 1);
  }
  cout << "STACK 1" << endl;
  q3s1.display(q3s1.s1, "s1");
  q3s1.display(q3s1.s2, "s2");
  q3s1.display(q3s1.s3, "s3");

  cout << "quack capacity = " << q3s1.capacity << endl;
  cout << "popping elements\n";
  for (int i = 0; i < 4; ++i) {
    cout << q3s1.pop() << endl;
  }
  cout << "quack capacity = " << q3s1.capacity << endl;

  q3s1.display(q3s1.s1, "s1");
  q3s1.display(q3s1.s2, "s2");
  q3s1.display(q3s1.s3, "s3");
  cout << "Pulling elements \n";
  for (int i = 0; i < 3; ++i) {
    cout << q3s1.pull() << endl;
  }
  cout << "quack capacity = " << q3s1.capacity << endl;

  q3s1.display(q3s1.s1, "s1");
  q3s1.display(q3s1.s2, "s2");
  q3s1.display(q3s1.s3, "s3");

  cout << "Pupping element \n";
  cout << q3s1.pop() << endl;
  q3s1.display(q3s1.s1, "s1");
  q3s1.display(q3s1.s2, "s2");
  q3s1.display(q3s1.s3, "s3");

  cout << "quack capacity = " << q3s1.capacity << endl;

  cout << "Pulling element \n";
  cout << q3s1.pull() << endl;
  q3s1.display(q3s1.s1, "s1");
  q3s1.display(q3s1.s2, "s2");
  q3s1.display(q3s1.s3, "s3");

  cout << "quack capacity = " << q3s1.capacity << endl;

  cout << "Pulling element \n";
  cout << q3s1.pull() << endl;
  q3s1.display(q3s1.s1, "s1");
  q3s1.display(q3s1.s2, "s2");
  q3s1.display(q3s1.s3, "s3");

  cout << "quack capacity = " << q3s1.capacity << endl;
#endif
#if 0
    Quack_naiveSoln qstack(5);
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
#endif
  return 0;
}