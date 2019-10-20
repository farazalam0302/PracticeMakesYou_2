#include "BinaryTree.h"
int LCA_Recursive(Node *R, int n1, int n2) {
  if (!R)
    exit(-1);
  if (R->data > n1 && R->data > n2) {
    LCA_Recursive(R->left, n1, n2);
  } else if (R->data < n1 && R->data < n2) {
    LCA_Recursive(R->right, n1, n2);
  } else
    return R->data;
}

int LCA_iterative(Node *R, int n1, int n2) {
  if (!R)
    exit(-1);
  while (R != NULL) {
    if (R->data > n1 && R->data > n2) {
      R = R->left;
    } else if (R->data < n1 && R->data < n2) {
      R = R->right;
    } else
      break;
  }
  return R->data;
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

  cout << "LCS Recursive of 10 , 14 =  " << LCA_Recursive(BST, 10, 14) << endl;
  cout << "LCS Recursive of 4 , 14 =  " << LCA_Recursive(BST, 4, 14) << endl;
  cout << "LCS Recursive of 10 ,20  =  " << LCA_Recursive(BST, 10, 20) << endl;
  cout << "LCS Recursive of 10 , 22 =  " << LCA_Recursive(BST, 10, 22) << endl;

  cout << "LCS  iterative of 10, 14 =  " << (LCA_iterative(BST, 10, 14))
       << endl;
  cout << "LCS  iterative of 4 , 14 =  " << (LCA_iterative(BST, 4, 14)) << endl;
  cout << "LCS iterative of 10 ,20  =  " << (LCA_iterative(BST, 10, 20))
       << endl;
  cout << "LCS iterative of 10 , 22 =  " << (LCA_iterative(BST, 10, 22))
       << endl;

  return 0;
}
