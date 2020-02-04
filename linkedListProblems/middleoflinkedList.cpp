/*
middle of linked list??
*/
#include "linkedList_utility.h"

Node *middleOfLL(Node *head) {
  if (!head)
    exit(-1);
  Node *slow = head;
  Node *fast = head;
  while (fast && (fast->next)) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main(int argc, char const *argv[]) {
  Node *head = nullptr;
  createLinkedList(&head);
  displayList(head);

  Node *mid = middleOfLL(head);
  //   //   displayList(head);
  cout << mid->data << " <- Mid of LL " << endl;
  return 0;
}
