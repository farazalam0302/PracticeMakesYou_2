/*
rotate after k nodes

*/
#include "linkedList_utility.h"

void rotate_afterKthnode(Node **head, int k) {
  Node *current = *head;
  int count = 1;
  while (current && count < k) {
    current = current->next;
    count++;
  }
  if (current == NULL && count < k)
    return;
  Node *kthnode = current;

  while (current->next) {
    current = current->next;
  }
  Node *last = current;
  current->next = *head;
  *head = kthnode->next;
  kthnode->next = nullptr;
}

int main(int argc, char const *argv[]) {
  Node *head = nullptr;
  createLinkedList(&head);
  int k;
  cin >> k;
  rotate_afterKthnode(&head, k);
  displayList(head);
  return 0;
}
