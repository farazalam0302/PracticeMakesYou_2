/*
 * To implement linked list and data stored in the node is int.
 * insertion and copy constructors
 */

#include <bits/stdc++.h>
using namespace std;
class Node {

public:
  int data;
  Node *next;
  Node() : data(0), next(nullptr) {}
  Node(int x) : data(x), next(nullptr) {}

  Node(Node &c) {
    cout << "I am in copy cnstr\n ";
    data = c.data;
    cout << "data = " << data << " ";
    if (c.next) {
      next = new Node(*(c.next));
    }
  }
  Node(Node &&c) : data(c.data), next(c.next) {}
};

class LinkedList {
public:
  Node *Head;
  LinkedList() { Head = nullptr; }
  //  Node *Curr;
  void insert(int x) {
    Node *newNode = new Node(x);
    if (Head == nullptr) // No list existed
    {
      Head = newNode;
      return;
    }
    newNode->next = Head;
    Head = newNode;
    return;
  }

  Node *CopyLL(Node *head) {
    if (head == nullptr) {
      cout << "List Under flown!!!" << endl;
      return nullptr;
    }
    Node *retHead = new Node(*head);
    Head = retHead;
    return retHead;
  }

  void printLL() {
    Node *curr = Head;
    while (curr) {
      cout << curr->data << " -> ";
      curr = curr->next;
    }
    cout << endl;
  }
};

int main(int argc, char **argv) {

  LinkedList myLL;
  for (int i = 1; i <= 5; ++i) {
    myLL.insert(i);
  }
  myLL.printLL();

  LinkedList dupLL;
  dupLL.CopyLL(myLL.Head);

  dupLL.printLL();

  return 0;
}

/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * 1  2  3  4  5
 *
 * 1->2
 *
 *
 *
 *
 *
 */
