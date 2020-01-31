#include "BinaryTree.h"

bool isBST(Node *R, int minimum, int maximum) {
  if (!R)
    return true;
  if (R->data < minimum || R->data > maximum)
    return false;
  return (isBST(R->left, minimum, R->data - 1) &&
          isBST(R->right, R->data + 1, maximum));
}

bool isBSTviaInorderProperty(Node *R, int &prev) {
  if (!R)
    return true;

  if (!isBSTviaInorderProperty(R->left, prev))
    return false;
  if (R->data < prev)
    return false;
  else
    prev = R->data;
  return isBSTviaInorderProperty(R->right, prev);
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

  cout << endl;
  int maximum = INT_MIN;
  int minimum = INT_MAX;
  int prev = INT_MIN;

  isBSTviaInorderProperty(R2, prev) ? cout << "yes it is BST\n"
                                    : cout << "No its not BST\n";

  prev = INT_MIN;
  isBSTviaInorderProperty(R3, prev) ? cout << "yes it is BST\n"
                                    : cout << "No its not BST\n";

  maximum = INT_MIN;
  minimum = INT_MAX;
  isBST(R3, INT_MIN, INT_MAX) ? cout << "yes it is BST\n"
                              : cout << "No its not BST\n";

  // // //  printLeftViewofTreeUtility
  // cout << "printLeftViewofTreeUtility = ";
  // printLeftViewofTreeUtility(R1);
  // cout << endl;

  // cout << "printrightViewofTreeUtility = ";
  // printRightViewofTreeUtility(R1);
  // cout << endl;
  // cout << "levelOrderTraversal_BFS = ";
  // levelOrderTraversal_BFS(R1);
  // cout << endl;
  // cout << "depth = " << height_depth(R1);
  // cout << endl;

  // cout << "inorder = ";
  // inorder(R1);
  // cout << endl;
  // cout << "preorder = ";
  // preorder(R1);
  // cout << endl;
  // cout << "postorder = ";
  // postorder(R1);
  // cout << endl;
  // cout << "levelOrderrecursive = ";
  // levelOrderTraversalRecurseUtil(R1);
  // cout << endl;

  return 0;
}
