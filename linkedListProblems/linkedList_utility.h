/*
linked List utility functions??

   --> void createLinkedList(Node **head_ref) creates a linked list of first
nine numbers.

   --> void displayList(Node* head) display linked list

   --> void insertNodeatLast(Node **head, int x) insert node at the end of list.

   --> void insertNodeatHead(Node **head, int x) insert node at the head of
list.

*/
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *next;
  Node *random;
  Node() {
    data = 0;
    next = nullptr;
    random = nullptr;
  }
  Node(int n) {
    data = n;
    next = nullptr;
    random = nullptr;
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

Node *getLastNode(Node *head) {
  if (!head || !(head->next))
    return head;
  while (head->next) {
    head = head->next;
  }
  return head;
}

void displayList(Node *head) {
  while (head) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void displayRandomList(Node *head) {
  while (head) {
    if (head->random) {
      cout << head->data << " 's random -> " << head->random->data << endl;
    } else {
      cout << head->data << " 's random -> NULL\n";
    }
    head = head->next;
  }
  cout << "\n";
}

void createLinkedList(Node **head) {

  for (int i = 1; i < 10; i++) {
    insertNodeatLast(head, i);
  }
}
