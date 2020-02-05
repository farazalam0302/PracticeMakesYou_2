/*
Remove loop in Linked ListSubmissions

Problems
You are given a linked list of N nodes. The task is to remove the loop from the
linked list, if present.


*/
#include "linkedList_utility.h"

void removeLoopInLL(Node *h_ref) {
  if (!h_ref || !h_ref->next)
    return;

  Node *head = h_ref;
  Node *slow = head;
  Node *fast = head;
  fast = fast->next->next;
  slow = slow->next;
  while (fast->next && fast) {
    if (slow == fast)
      break;
    slow = slow->next;
    fast = fast->next->next;
  }
  if (slow == fast) {
    slow = head;
    while (slow->next != fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = NULL;
  }
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  createLinkedList(&h1);
  for (int i = 100; i <= 110; i++) {
    insertNodeatLast(&h2, i);
  }
  for (int i = 200; i <= 210; i++) {
    insertNodeatLast(&h3, i);
  }

  //   displayList(h1);
  //   displayList(h2);
  //   displayList(h3);
  //   Node *last_h1 = getLastNode(h1);
  Node *last_h2 = getLastNode(h2);
  Node *last_h3 = getLastNode(h3);
  //   last_h1->next = h3;
  last_h2->next = h3;
  last_h3->next = h3;

  removeLoopInLL(h2);

  displayList(h2);

  return 0;
}
