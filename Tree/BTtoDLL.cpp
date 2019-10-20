#include "BinaryTree.h"

void BT2DLL_inorder(Node *R, vector<Node *> &a) {
  if (R == NULL)
    return;
  BT2DLL_inorder(R->left, a);
  a.push_back(R);
  BT2DLL_inorder(R->right, a);
}

void BT2DLL_inorder_2(Node *R, Node *prev) {
  if (R == NULL)
    return;
  BT2DLL_inorder_2(R->left, a);

  BT2DLL_inorder_2(R->right, a);
}

int main() {
  Node *R1;
  Node *R2;
  Node *R3;
  Node *R4;
  makeR1(&R1);
  makeR2(&R2);
  makeR3(&R3);
  makeR4(&R4);

  Node *BT2DLL_Treexample = new Node(10);
  BT2DLL_Treexample->left = new Node(12);
  BT2DLL_Treexample->right = new Node(15);
  BT2DLL_Treexample->left->left = new Node(25);
  BT2DLL_Treexample->left->right = new Node(30);
  BT2DLL_Treexample->right->left = new Node(36);

  Node *BST = new Node(20);
  BST->left = new Node(8);
  BST->right = new Node(22);
  BST->left->left = new Node(4);
  BST->left->right = new Node(12);
  BST->left->right->left = new Node(10);
  BST->left->right->right = new Node(14);

  cout << endl;
  int maximum = INT_MIN;
  int minimum = INT_MAX;
  int prev = INT_MIN;
  cout << endl;
  cout << "inorder = ";
  inorder(BT2DLL_Treexample);
  cout << "\n\n---------------\n" << endl;
  vector<Node *> a;
  BT2DLL_inorder(BT2DLL_Treexample, a);
  int sz = a.size();

  //   a[0]->left = NULL;
  //   a[1]->left = a[0];
  //   a[2]->left = a[1];
  //   a[3]->left = a[2];
  //   a[4]->left = a[3];
  //   a[5]->left = a[4];
  //   a[6]->left = a[5];

  //   a[0]->right = NULL;
  //   a[0 + 1]->right = a[0];
  //   a[1 + 1]->right = a[0 + 1];
  //   a[2 + 1]->right = a[1 + 1];
  //   a[3 + 1]->right = a[2 + 1];
  //   a[4 + 1]->right = a[3 + 1];
  //   a[5 + 1]->right = a[4 + 1];

  for (int i = 0; i < (sz - 1); i++) {
    a[i]->right = a[i + 1];
  }
  for (int i = sz - 1; i > 0; i--) {
    a[i]->left = a[i - 1];
  }

  Node *head = a[0];

  Node *tail = a[sz - 1];

  for (auto i : a) {
    cout << i->data << " ";
  }
  cout << endl;
  //   cout << "inorder = ";
  //   inorder(R1);
  cout << "\n\n---------------\n" << endl;
  while (head) {
    cout << head->data << " ";
    head = head->right;
  }
  cout << "\n\n---------------\n" << endl;
  while (tail) {
    cout << tail->data << " ";
    tail = tail->left;
  }

  return 0;
}
