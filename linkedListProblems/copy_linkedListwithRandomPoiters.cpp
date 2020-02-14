#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node *randptr;
  Node() {
    data = 0;
    next = nullptr;
    randptr = nullptr;
  }
  Node(int x) {
    data = x;
    next = nullptr;
    randptr = nullptr;
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
  while (head) {
    cout << head->data << "->";
    //    cout << head->randptr->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void displayListR(Node *head) {
  while (head) {
    cout << head->data << "|";
    cout << head->randptr->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}
void createLinkedList(Node **head) {
  for (int i = 1; i <= 6; i++) {
    insertNodeatLast(head, i);
  }
}
Node *EasiestCopy_with_O_n_space(Node *head) {
  if (!head || !(head->next)) return head;
  vector<Node *> copybuffer;
  Node *itr = head;
  Node *tmp = nullptr;
  while (itr) {
    copybuffer.push_back(itr);
    itr = itr->next;
  }

  for (int i = 0; i < copybuffer.size(); ++i) {
    tmp = new Node(copybuffer[i]->data);
    if (i == 0) itr = tmp;
    tmp->next = copybuffer[i]->next;
    tmp->randptr = copybuffer[i]->randptr;
  }
  return itr;
}

Node *Tricky_copy_with_noExtraspace(Node *head) {
  if (!head || !(head->next)) return head;
  Node *itr = head;
  Node *tmp = nullptr;
  while (itr) {
    tmp = new Node(itr->data);
    tmp->next = itr->next;
    itr->next = tmp;
    itr = itr->next->next;
  }
  displayList(head);
  Node *rethead = head->next;

  // important

  Node *origNode = head;
  Node *origNode_next = origNode->next->next;
  Node *copyNode = origNode->next;
  //  Node *copyNode_next = origNode_next->next;
  int c = 15;
  while (origNode && origNode_next && copyNode && (c--)) {
    copyNode->randptr = origNode->randptr;
    if (origNode_next)
      copyNode->next = origNode_next->next;
    else {
      copyNode->next = nullptr;
      break;
    }
    if (origNode_next) origNode = origNode_next;
    if (origNode->next->next) origNode_next = origNode->next->next;
    if (origNode->next) copyNode = origNode->next;
    //    copyNode_next = origNode_next->next;
  }
  //  copyNode = nullptr;
  return rethead;
}

int main(int argc, char **argv) {
  Node *head = nullptr;
  createLinkedList(&head);
  displayList(head);
  vector<Node *> ptrvec;
  Node *itr = head;
  while (itr) {
    ptrvec.push_back(itr);
    itr = itr->next;
  }
  for (int i = 0; i < 3; ++i) {
    ptrvec[i]->randptr = ptrvec[i % 3 + 3];
  }
  for (int i = 3; i < 6; ++i) {
    ptrvec[i]->randptr = ptrvec[i % 3];
  }
  displayListR(head);
  // original Linked list created

  Node *resultEasy = EasiestCopy_with_O_n_space(head);
  displayListR(resultEasy);
  cout << "\n\n" << endl;
  resultEasy = Tricky_copy_with_noExtraspace(head);
  displayListR(resultEasy);
  return 0;
}
