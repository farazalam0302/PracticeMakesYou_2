#include "linkedList_utility.h"

class CloneLLwithRandomPointers {
public:
  Node *cloneLLwithHashMap(Node *head) {
    if (head == nullptr)
      return head;
    unordered_map<Node *, Node *> hmap;
    // populate hmap with cloned copies;
    hmap[nullptr] = nullptr;
    Node *curr = head;
    while (curr) {
      hmap[curr] = new Node(curr->data);
      curr = curr->next;
    }

    // populate next ptrs and randomptrs of cloned nodes in mmap
    curr = head;
    while (curr) {
      hmap[curr]->next = hmap[curr->next];
      hmap[curr]->random = hmap[curr->random];
      curr = curr->next;
    }
    return hmap[head];
  }

  Node *cloneLLwithInterweavingNewNodes(Node *head) {
    if (head == nullptr)
      return nullptr;
    // add interweaved nodes in between
    Node *curr = head;
    while (curr) {
      Node *newNode = new Node(curr->data);
      newNode->next = curr->next;
      curr->next = newNode;
      curr = newNode->next;
    }
    // set the random ptrs in new list
    curr = head;
    // dup_curr=curr->next;
    while (curr) {
      if (curr->random == nullptr) {
        curr->next->random = nullptr;
      } else {
        curr->next->random = curr->random->next;
      }
      curr = curr->next->next;
    }

    // separate clone nodes and original nodes keep old list also

    curr = head;
    Node *cloneHead = curr->next;
    Node *clone = cloneHead;
    while (clone->next) {
      curr->next = curr->next->next;
      clone->next = clone->next->next;
      curr = curr->next;
      clone = clone->next;
    }
    curr->next = nullptr;
    clone->next = nullptr;

    return cloneHead;
  }
};

int main(int argc, char const *argv[]) {

  CloneLLwithRandomPointers Solution;
  Node *head = nullptr;
  for (int i = 1; i <= 5; i++) {
    insertNodeatLast(&head, i);
  }
  vector<Node *> nBank;
  Node *curr = head;
  while (curr) {
    nBank.push_back(curr);
    curr = curr->next;
  }

  curr = head;
  // 1
  curr->random = nullptr;
  // 2
  curr = curr->next;
  curr->random = nBank[3];
  // 3
  curr = curr->next;
  curr->random = nBank[4];
  // 4
  curr = curr->next;
  curr->random = nBank[0];
  // 5
  curr = curr->next;
  curr->random = nBank[3];

  cout << "original list \n";
  displayList(head);
  displayRandomList(head);
  cout << "original list ^^^^^^^^^^^^^^^^^^^^^^^^^^ \n";

  cout << "Solution.cloneLLwithHashMap(head); \n";
  displayList(Solution.cloneLLwithHashMap(head));
  displayRandomList(Solution.cloneLLwithHashMap(head));
  cout << "Solution.cloneLLwithHashMap(head) ^^^^^^^^^^^^^^^^^^^^^^^^^^ \n";

  cout << "Solution.cloneLLwithInterweavingNewNodes(head); \n";
  displayList(Solution.cloneLLwithInterweavingNewNodes(head));
  displayRandomList(Solution.cloneLLwithInterweavingNewNodes(head));
  cout << "Solution.cloneLLwithInterweavingNewNodes(head) "
          "^^^^^^^^^^^^^^^^^^^^^^^^^^ \n";

  return 0;
}
