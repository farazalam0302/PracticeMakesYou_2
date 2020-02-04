#include "linkedList_utility.h"
void YintersectioninLLviaMap(Node *h1, Node *h2) {

  map<Node *, bool> mmap;
  Node *itr = h1;
  while (itr) {
    mmap.insert(make_pair(itr, true));
    itr = itr->next;
  }
  itr = h2;
  while (itr) {
    if (mmap.find(itr) != mmap.end())
      break;
    itr = itr->next;
  }

  cout << itr->data << endl;
}
int main(int argc, char const *argv[]) {
  Node *h1 = nullptr;
  Node *h2 = nullptr;
  Node *h3 = nullptr;
  createLinkedList(&h1);
  for (int i = 100; i < 110; i++) {
    insertNodeatLast(&h2, i);
  }
  for (int i = 200; i < 210; i++) {
    insertNodeatLast(&h3, i);
  }

  //   displayList(h1);
  //   displayList(h2);
  //   displayList(h3);
  Node *last_h1 = getLastNode(h1);
  Node *last_h2 = getLastNode(h2);
  last_h1->next = h3;
  last_h2->next = h3;
  displayList(h1);
  displayList(h2);
  //   displayList(h3);

  YintersectioninLLviaMap(h1, h2);
  return 0;
}
