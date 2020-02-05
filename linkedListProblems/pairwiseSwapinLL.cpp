/*
pair wise swap in LL
*/

#include "linkedList_utility.h"

void pairwiseSwapinLL(Node **headRef) {
  Node *prev = *headRef;
  Node *current = *headRef;
  if (prev == NULL || prev->next == NULL)
    return;
  current = prev->next;
  int temp;
  while (current && current->next) {
    temp = current->data;
    current->data = prev->data;
    prev->data = temp;
    prev = current->next;
    current = prev->next;
  }
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  //   createLinkedList(&h1);
  int a[10] = {102, 204, 106, 208, 110, 212, 114, 216, 118, 220};
  for (int i = 0; i < 10; i += 1) {
    insertNodeatLast(&h2, a[i]);
  }
  //   for (int i = 101; i <= 110; i += 2) {
  //     insertNodeatLast(&h3, i);
  //   }

  //   displayList(h1);
  cout << "list_1 -> ";
  displayList(h2);
  //   cout << "list_2 -> ";
  //   displayList(h3);

  pairwiseSwapinLL(&h2);
  cout << "Ans_LL -> ";
  displayList(h2);
  //   Node *last_h1 = getLastNode(h1);
  //   last_h1->next = h3;

  return 0;
}
