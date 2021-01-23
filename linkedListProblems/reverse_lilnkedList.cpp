#include "linkedList_utility.h"
void reverseLinkeList(Node **head) {
  if (!(*head)) {
    exit(0);
  }
  if (!(*head)->next) return;
  Node *prev = nullptr;
  Node *current = *head;
  Node *nextt = nullptr;
  while (current) {
    nextt = current->next;
    current->next = prev;
    prev = current;
    current = nextt;
  }
  *head = prev;
}
void reverseLLviaStack(Node **head) {
  stack<Node *> ms;
  Node *p = *head;
  while (p) {
    ms.push(p);
    p = p->next;
  }
  if (!ms.empty()) {
    *head = ms.top();
    ms.pop();
  }
  p = *head;
  while (!ms.empty()) {
    p->next = ms.top();
    ms.pop();
    p = p->next;
  }
  p->next = nullptr;
}
int main(int argc, const char **argv) {
  Node *head = nullptr;
  createLinkedList(&head);
  displayList(head);

  reverseLinkeList(&head);
  displayList(head);

  reverseLLviaStack(&head);
  displayList(head);
  return 0;
}
