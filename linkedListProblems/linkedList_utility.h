/*
linked List utility functions??
*/
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *next;
  Node() {
    data = 0;
    next = nullptr;
  }
  Node(int n) {
    data = n;
    next = nullptr;
  }
};

void insertNodeatLast(Node **head, int x) {
  if (!(*head)) {
    *head = new Node(x);
    return;
  }

  Node *newNode = new Node(x);
  Node *t = *head;
  while (t->next) {
    t = t->next;
  }
  t->next = newNode;
}

void insertNodeatHead(Node **head, int x) {
  if (!(*head)) {
    *head = new Node(x);
    return;
  }

  Node *newNode = new Node(x);
  newNode->next = *head;
  *head = newNode;
}

void displayList(Node *head) {
  while (head) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void createLinkedList(Node **head) {

  for (int i = 1; i < 10; i++) {
    insertNodeatLast(head, i);
  }
}
