#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node() : data(0), next(nullptr) {
    cout << "\nDefault Constructor for data = " << data << "\n";
  }
  Node(int x) : data(x), next(nullptr) {
    cout << "\nParems Constructor for data = " << data << "\n";
  }
  Node(const Node &cp) : data(cp.data) {

    if (cp.next) {
      next = new Node(*(cp.next));
    }
    cout << "\nCopy Constructor for data = " << data << "\n";
  }
  Node(Node &&cp) {
    if (&cp != this) {
      data = cp.data;
      next = cp.next;
    }
    cout << "\nIn Move Constructor for data = " << data << "\n";
  }
};

class LinkedList {
public:
  Node *Head;
  LinkedList() { Head = nullptr; }

  void insertLL(int x) {
    if (Head == nullptr) {
      Head = new Node(x);
      return;
    }
    Node *newNode = new Node(x);
    newNode->next = Head;
    Head = newNode;
    return;
  }

  Node copyLL(Node *head) {
    if (head == nullptr) {
      cout << "\nNo list to copy\n";
      return NULL;
    }
    Node retNode(*head);
    return retNode;
  }

  void printLL(Node *head) {
    Node *curr = head;
    while (curr) {
      cout << curr->data << " -> ";
      curr = curr->next;
    }

    cout << endl;
    curr = head;
    while (curr) {
      cout << hex << curr << " -> ";
      curr = curr->next;
    }
    cout << dec << endl;
  }
};

int main(int argc, char const *argv[]) {
  LinkedList myLL;
  for (int i = 1; i <= 5; ++i) {
    myLL.insertLL(i);
  }
  myLL.printLL(myLL.Head);

  LinkedList dupLL;
  Node ret = dupLL.copyLL(myLL.Head);

  dupLL.printLL(&ret);

  return 0;
}
