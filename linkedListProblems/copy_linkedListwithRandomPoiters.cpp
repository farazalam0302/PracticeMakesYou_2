/***
 *
 * Query : There is a linked list with extra random pointer as follows
 *
 * 1->2->3->4->5->6->NULL  <--- this is normal traversal of Linked List
 *
 * [1|4] -> [2|5] -> [3|6] -> [4|1] -> [5|2] -> [6|3] -> NULL
 *
 * first node->data = 1; node->next = [2|5] node ; node->randptr = [4|1]Node
 *
 * now the query is to copy this LL to some other list using no extra space.
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node *randomPointer;
  Node() {
    data = 0;
    next = nullptr;
    randomPointer = nullptr;
  }
  Node(int x) {
    data = x;
    next = nullptr;
    randomPointer = nullptr;
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
    cout << "[" << head->data << "] ->";

    head = head->next;
  }
  cout << "NULL\n";
}

void displayListR(Node *head) {
  while (head) {
    cout << "[" << head->data << "|";
    cout << head->randomPointer->data << "] -> ";
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
    tmp->randomPointer = copybuffer[i]->randomPointer;
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
  //  displayList(head);

  // important

  Node *origNode = head;
  Node *origNode_next = origNode->next->next;
  Node *copyNode = origNode->next;
  Node *rethead = copyNode;

  while (origNode_next) {
    copyNode->randomPointer = origNode->randomPointer->next;
    if (origNode_next)
      copyNode->next = origNode_next->next;
    else
      copyNode->next = nullptr;
    origNode = origNode_next;
    copyNode = origNode->next;
    origNode_next = copyNode->next;
  }
  // most important line to change random ptrs in last
  copyNode->randomPointer = origNode->randomPointer->next;
  // most important line to change random ptrs in last

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
    ptrvec[i]->randomPointer = ptrvec[i % 3 + 3];
  }
  for (int i = 3; i < 6; ++i) {
    ptrvec[i]->randomPointer = ptrvec[i % 3];
  }
  displayListR(head);
  // original Linked list created

  //  Node *resultEasy = EasiestCopy_with_O_n_space(head);
  //  displayListR(resultEasy);
  cout << "\n\n" << endl;
  Node *result = Tricky_copy_with_noExtraspace(head);
  //  displayList(result);
  cout << "\n\n" << endl;
  //  displayList(result);

  displayListR(result);
  return 0;
}
