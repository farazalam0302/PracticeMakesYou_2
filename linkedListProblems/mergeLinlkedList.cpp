/*
merge two sorted linked lists

*/
#include "linkedList_utility.h"

Node *merge2LinkedList(Node *a, Node *b) {
  Node *tail = new Node(0);
  Node *dummyhead = tail;

  while (1) {
    if (!a) {
      tail->next = b;
      break;
    }
    if (!b) {
      tail->next = a;
      break;
    }
    if (a->data <= b->data) {
      tail->next = a;
      a = a->next;

    } else {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }
  return (dummyhead->next);
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  //   createLinkedList(&h1);
  for (int i = 102; i <= 110; i += 2) {
    insertNodeatLast(&h2, i);
  }
  for (int i = 101; i <= 110; i += 2) {
    insertNodeatLast(&h3, i);
  }

  //   displayList(h1);
  cout << "list_1 -> ";
  displayList(h2);
  cout << "list_2 -> ";
  displayList(h3);
  Node *hh = merge2LinkedList(h2, h3);
  cout << "merged_list -> ";
  displayList(hh);
  //   Node *last_h1 = getLastNode(h1);
  //   last_h1->next = h3;

  return 0;
}
