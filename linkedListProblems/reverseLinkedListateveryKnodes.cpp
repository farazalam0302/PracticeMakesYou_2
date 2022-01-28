#include "linkedList_utility.h"

// Node* reverseLLafterEachKnodes(Node* head, int k) {}

Node* reverseFullList(Node* head) {
  if (!head || !(head->next)) return head;
  Node* prev = nullptr;
  Node* curr = head;
  Node* nextt = nullptr;
  while (curr) {
    nextt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextt;
  }

  return prev;
}

Node* reverseLLafterKnodes(Node* head, int k) {
  if (!head || !(head->next)) return head;
  Node* prev = nullptr;
  Node* curr = head;
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
    head->next = reverseLLafterKnodes(nextt, k);
  }

  return prev;
}

Node* reverseLLafterKnodes_usingStack(Node* head, int k) {
  if (!head || !(head->next)) return head;
  stack<Node*> mstack;
  Node* prev = nullptr;
  Node* curr = head;
  Node* nextt = nullptr;
  int i;  // = 0;
  while (curr) {
    i = 0;
    while (curr && i < k) {
      mstack.push(curr);
      curr = curr->next;
      i++;
    }

    while (!mstack.empty()) {
      if (prev == nullptr) {  // first time ussage to lock head of resultant
        prev = mstack.top();
        mstack.pop();
        head = prev;
      } else {
        prev->next = mstack.top();
        mstack.pop();
        prev = prev->next;
      }
    }
  }
  prev->next = nullptr;
  return head;
}

int main() {
  Node* head = nullptr;
  for (int i = 8; i > 0; i--) {
    insertNodeatHead(&head, i);
  }

  displayList(head);

  //  displayList(reverseFullList(head));

  cout << "\n##############################\n " << endl;

  displayList(reverseLLafterKnodes(head, 3));
  //  displayList(reverseLLafterKnodes_usingStack(head, 3));

  return 0;
}
