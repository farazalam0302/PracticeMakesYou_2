#include "linkedList_utility.h"

Node* reverseLinkedListWithoutStack(Node* head) {
  if (!head) exit(1);

  Node* curr = head;
  Node* prev = nullptr;
  Node* nextt = curr->next;

  while (curr) {
    curr->next = prev;
    prev = curr;
    curr = nextt;
    if (curr) nextt = curr->next;
  }
  //  head = prev;
  //  displayList(head);
  return prev;
}

Node* reverseLinkedListinKgroupsWithoutStack(Node* head, int k) {
  if (!head || !(head->next)) return head;
  Node* curr = head;
  Node* prev = nullptr;
  Node* nextt = nullptr;
  int i = 0;
  while (curr && i < k) {
    nextt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextt;
    i++;
  }
  if (nextt) {
    head->next = reverseLinkedListinKgroupsWithoutStack(nextt, k);
  }
  return prev;
}

Node* reverseLinkedListinKgroupsWithStack(Node* head, int k) {
  if (!head || !(head->next)) return head;
  Node* curr = head;
  Node* prev = nullptr;
  Node* nextt = nullptr;
  bool flagFirstExec = true;
  stack<Node*> myStack;
  int i = 0;
  while (curr) {
    i = 0;
    while (curr && i < k) {
      myStack.push(curr);
      curr = curr->next;
      i++;
    }
    while (!myStack.empty()) {
      if (flagFirstExec) {
        prev = myStack.top();
        myStack.pop();
        head = prev;
        flagFirstExec = false;
      } else {
        prev->next = myStack.top();
        myStack.pop();
        prev = prev->next;
      }
    }
  }
  prev->next = nullptr;
  return head;
}

int main() {
  Node* head = nullptr;
  createLinkedList(&head, 13);
  displayList(head);
  cout << "\n Reversed Linked List\n" << endl;
  Node* r = reverseLinkedListWithoutStack(head);
  displayList(r);

  cout << "\n Reversed Linked List in" << 3 << " nodes groups without stack\n"
       << endl;

  head = nullptr;
  createLinkedList(&head, 13);
  displayList(head);

  r = reverseLinkedListinKgroupsWithoutStack(head, 3);
  displayList(r);

  cout << "\n Reversed Linked List in" << 3 << " nodes groups with stack\n"
       << endl;

  head = nullptr;
  createLinkedList(&head, 18);
  displayList(head);

  r = reverseLinkedListinKgroupsWithStack(head, 4);
  displayList(r);

  return 0;
}
