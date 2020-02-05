/*
Sort a linked list of 0s, 1s and 2s by changing links

*/
#include "linkedList_utility.h"

void sort_0s_1s_2s(Node *h2) {
  Node *zero = new Node(0);
  Node *ones = new Node(0);
  Node *twos = new Node(0);
  Node *itr = h2;
  Node *ptr0 = zero;
  Node *ptr1 = ones;
  Node *ptr2 = twos;
  while (itr) {
    if (itr->data == 0) {
      ptr0->next = itr;
      ptr0 = ptr0->next;
    } else if (itr->data == 1) {
      ptr1->next = itr;
      ptr1 = ptr1->next;
    } else if (itr->data == 2) {
      ptr2->next = itr;
      ptr2 = ptr2->next;
    }

    itr = itr->next;
  }
  ptr0->next = ones->next ? ones->next : twos->next;
  ptr1->next = twos->next;
  ptr2->next = nullptr;
  cout << "Answer> ";
  displayList(zero->next);
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  for (int i = 1; i <= 15; i += 1) {
    if (i % 3 != 1)
      insertNodeatLast(&h2, (i % 3));
  }

  cout << "list -> ";
  displayList(h2);

  sort_0s_1s_2s(h2);

  return 0;
}
