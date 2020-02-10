/*
Depth First Search/Traversal in Binary Tree
Objective: – Given a Binary Search Tree, Do the Depth First Search/Traversal .

Appraoch:

Approach is quite simple, use Stack.
First add the add root to the Stack.
Pop out an element from Stack and add its right and left children to stack.
Pop out an element and print it and add its children.
Repeat the above two steps until the Stack id empty.

*/
#include "BinaryTree.h"

void dfs_inTREE(Node *root) {
  if (!root) {
    cout << "\nTree does'nt exist\n" << endl;
    return;
  }
  stack<Node *> mystack;
  mystack.push(root);
  while (!mystack.empty()) {
    Node *x = mystack.top();
    mystack.pop();
    cout << " " << x->data;
    if (x->right)
      mystack.push(x->right);
    if (x->left)
      mystack.push(x->left);
  }
}

void iterativePreOrder(Node *root) {
  if (!root) {
    cout << "\nTree does'nt exist\n" << endl;
    return;
  }
  stack<Node *> mystack;
  mystack.push(root);
  Node *itr = root;
  while (!mystack.empty()) {
    Node *x = mystack.top();
    mystack.pop();
    cout << " " << x->data;
    if (x->right)
      mystack.push(x->right);
    if (x->left)
      mystack.push(x->left);
  }
}

void bfs_inTREE(Node *root) {
  if (!root) {
    cout << "\nTree does'nt exist\n" << endl;
    return;
  }
  queue<Node *> myQ;
  myQ.push(root);
  while (!myQ.empty()) {
    Node *x = myQ.front();
    myQ.pop();
    if (x->left)
      myQ.push(x->left);
    if (x->right)
      myQ.push(x->right);
    cout << " " << x->data;
  }
}

int main() {
  Node *R1;
  Node *R2;
  Node *R3;
  Node *R4;
  makeR1(&R1);
  makeBST(&R2);
  makeR3(&R3);
  makeR4(&R4);

  cout << "\n\n-------preorder--------\n" << endl;
  preorder(R1);

  cout << "\n\n-------postorder--------\n" << endl;
  postorder(R1);
  cout << "\n\n-------inorder--------\n" << endl;
  inorder(R1);
  cout << "\n\n-------bfsorder--------\n" << endl;
  bfs_inTREE(R1);
  //   preorder(R1);

  //   cout << "\n\n---------------\n" << endl;
  //   postorder(R1);
  //   cout << "\n\n---------------\n" << endl;
  //   inorder(R1);
  cout << "\n\n-------dfs_inTREE--------\n" << endl;

  dfs_inTREE(R1);

  return 0;
}
