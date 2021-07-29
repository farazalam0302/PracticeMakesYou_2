#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node *next;
  Node() {
    data = 0;
    next = nullptr;
  }
  Node(int n) {
    data = n;
    next = nullptr;
  }
};

void insertNodeatLast(Node **head, int x) {
  if (!(*head)) {
    *head = new Node(x);
    return;
  }

  Node *newNode = new Node(x);
  Node *t = *head;
  while (t->next) {
    t = t->next;
  }
  t->next = newNode;
}

void displayList(Node *head) {
  while (head /*&& head->data != 0*/) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void createLinkedList(Node **head, unordered_map<int, Node *> &mmap) {
  for (int i = 1; i < 10; i++) {
    insertNodeatLast(head, i);
  }

  Node *t = *head;
  while (t) {
    mmap.insert(make_pair(t->data, t));
    t = t->next;
  }
}

void deleteGivenNodeInSLL(Node **toBeDeleted) {
  Node *t = *toBeDeleted;
  if (t->next == nullptr)  //  if its a last node just delete the node
  {
    //    delete (t);
    //    t = nullptr;
    delete (*toBeDeleted);
    //    *toBeDeleted = nullptr;
    return;
  }
  /*
   * else  if its not a last node then copy data from next node to this node and
   * delete next node;
   */
  Node *n = t->next;  // next node of t- node
  t->data = n->data;  // copy data of next n-node to t-node
  t->next = n->next;  // copy next-pointers of next n-node to t-node next
  delete (n);         // deleting next node
}

int main() {
  unordered_map<int, Node *> mapOfPtrs;
  /*
   * mapOfPtrs is used to hash data value of nodes to their addresses
   */
  Node *head = nullptr;
  createLinkedList(&head, mapOfPtrs);  // creating Single Linked List

  //  for (auto i : mapOfPtrs) {
  //    cout << i.first << " -> " << hex << i.second << endl;
  //  }

  displayList(head);       // display List Before Deletion
  Node *d = mapOfPtrs[4];  // fetching pointer to desired node to be deleted
  deleteGivenNodeInSLL(&d);
  displayList(head);

  return 0;
}
