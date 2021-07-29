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

void sortt_0s_1s_2s_noExtraSpace(Node *h) {
  if (h == nullptr) return;
  Node *itr = h;
  int zeros = 0;
  int ones = 0;
  int twos = 0;
  while (itr) {
    if (itr->data == 0)
      zeros++;
    else if (itr->data == 1)
      ones++;
    else if (itr->data == 2)
      twos++;
    itr = itr->next;
  }
  itr = h;
  while (itr && zeros > 0) {
    itr->data = 0;
    zeros--;
    itr = itr->next;
  }

  while (itr && ones > 0) {
    itr->data = 1;
    ones--;
    itr = itr->next;
  }

  while (itr && twos > 0) {
    itr->data = 2;
    twos--;
    itr = itr->next;
  }

  displayList(h);
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  for (int i = 1; i <= 29; i += 1) {
    insertNodeatLast(&h2, (i % 3));
  }

  cout << "list -> ";
  displayList(h2);

  sortt_0s_1s_2s_noExtraSpace(h2);

  return 0;
}
