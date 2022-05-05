#include "linkedList_utility.h"

int kthNode(Node *head, int k) {
  int c = 0;
  Node *curr = head;
  Node *kthnode = head;
  while (curr) {
    if (c >= k) kthnode = kthnode->next;
    curr = curr->next;
    c++;
  }

  return kthnode->data;
}

int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  createLinkedList(&h1);
  for (int i = 100; i <= 110; i++) {
    insertNodeatLast(&h1, i);
  }

  displayList(h1);

  cout << "kth last node = " << kthNode(h1, 15) << endl;
}
