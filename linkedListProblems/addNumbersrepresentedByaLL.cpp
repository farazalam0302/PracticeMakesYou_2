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

Node *addLL(Node *l1, Node *l2) {

  if (l1 == NULL)
    return l2;
  if (l2 == NULL)
    return l1;

  Node *result = new Node(0);
  Node *ptrR = result;
  int sum, carry;
  carry = 0;
  while (l1 != NULL && l2 != NULL) {
    sum = (l1->data) + (l2->data) + carry;

    carry = sum / 10;
    sum = sum % 10;
    // ptrR->data=sum;
    ptrR->next = new Node(sum);
    ptrR = ptrR->next;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1 != NULL) {
    sum = l1->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    ptrR->next = new Node(sum);
    ptrR = ptrR->next;
    l1 = l1->next;
  }

  while (l2 != NULL) {
    sum = l2->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    ptrR->next = new Node(sum);
    ptrR = ptrR->next;
    l2 = l2->next;
  }

  if (carry) {
    ptrR->next = new Node(carry);
  }

  //  ptrR->data = ptrR->data + carry;

  return result->next;
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  //   createLinkedList(&h1); // 365
  int a[7] = {9, 9, 9, 9, 9, 9, 9};
  for (int i = 0; i < 7; i += 1) {
    insertNodeatLast(&h2, a[i]);
  }
  int b[4] = {9, 9, 9, 9}; // 248
  for (int i = 0; i < 4; i += 1) {
    insertNodeatLast(&h3, b[i]);
  }

  //   displayList(h1);
  cout << "list_1 -> ";
  displayList(h2);
  cout << "list_2 -> ";
  displayList(h3);

  cout << "\n====================================\n" << endl;

  Node *sum_LL = addLL(h2, h3);
  cout << "sum_LL -> ";
  displayList(sum_LL);

  return 0;
}
