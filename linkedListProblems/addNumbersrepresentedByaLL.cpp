/*
Add two numbers represented by linked lists
*/

#include "linkedList_utility.h"

Node *add2LL(Node *first, Node *second) {
  Node *result = nullptr;
  Node *temp = nullptr;
  Node *prev = nullptr;
  int carry = 0;
  int sum;
  while (first || second) {
    sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
    carry = sum / 10;
    sum = sum % 10;
    temp = new Node(sum);
    if (!result) {
      result = temp;
    } else {
      prev->next = temp;
    }
    prev = temp;
    if (first)
      first = first->next;
    if (second)
      second = second->next;
  }
  if (carry) {
    temp->next = new Node(carry);
  }
  return result;
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  //   createLinkedList(&h1); // 365
  int a[3] = {9, 9, 9};
  for (int i = 0; i < 3; i += 1) {
    insertNodeatLast(&h2, a[i]);
  }
  int b[3] = {8, 4, 1}; // 248
  for (int i = 0; i < 3; i += 1) {
    insertNodeatLast(&h3, b[i]);
  }

  //   displayList(h1);
  cout << "list_1 -> ";
  displayList(h2);
  cout << "list_2 -> ";
  displayList(h3);

  cout << "\n====================================\n" << endl;

  Node *sum_LL = add2LL(h2, h3);
  cout << "sum_LL -> ";
  displayList(sum_LL);

  return 0;
}
