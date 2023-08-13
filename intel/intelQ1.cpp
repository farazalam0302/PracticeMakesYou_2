#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node() : data(0), next(nullptr) {}
  Node(int x) : data(x), next(nullptr) {}
  //  Node(const Node &cp) : data(cp.data) {
  //
  //    if (cp.next) {
  //      next = new Node(*(cp.next));
  //    }
  //    cout << "\nCopy Constructor\n";
  //  }
  Node(Node &&cp) : data(cp.data), next(cp.next) {
    cout << "\nIn Move Constructor\n" << endl;
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

  Node *copyLL(Node *head) {
    if (head == nullptr) {
      cout << "\nNo list to copy\n";
      return nullptr;
    }
    Node *retNode = new Node(*head);
    return retNode;
  }

  void printLL(Node *head) {
    Node *curr = head;
    while (curr) {
      cout << curr->data << " -> ";
      curr = curr->next;
    }
    cout << endl;
  }
};

int main(int argc, char const *argv[]) {
  LinkedList myLL;
  for (int i = 1; i <= 5; ++i) {
    myLL.insertLL(i);
  }
  myLL.printLL(myLL.Head);

  LinkedList dupLL;
  Node *ret = dupLL.copyLL(myLL.Head);

  dupLL.printLL(ret);

  return 0;
}
