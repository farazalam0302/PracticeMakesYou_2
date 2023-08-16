#include <bits/stdc++.h>
using namespace std;

class LinkedList {
public:
  struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *n) : data(x), next(n) {}
  };
  Node *head;

  LinkedList(const LinkedList &c) {
    Node *curr = c.head;
    Node *n = head;
    while (curr) {
      n = new Node(curr->data, curr->next);
    }
  }

  // Move Constructor
  LinkedList(LinkedList &&c) noexcept : head{nullptr} { swap(head, c.head); }

  LinkedList &operator=(LinkedList &&c) {
    if (this == &c) {
      return *this;
    }
    swap(head, c.head);
    return *this;
  }
  ~LinkedList() { cout << "\nLL Destructor called!!\n"; }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
