#include "BinaryTree.h"

void insertIn_BST_iterative(Node *root, int key) {
  if (!root) {
    root = new Node(key);
    return;
  }
  Node *newNode = new Node(key);
  Node *itr = root;
  Node *parent = NULL;
  while (itr) {
    parent = itr;
    if (key <= itr->data) {
      itr = itr->left;
    } else {
      itr = itr->right;
    }
  }
  if (key <= parent->data) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
}

void minimum_inBST(Node *R) {
  if (!R)
    return;
  Node *itr = R;
  while (itr->left) {
    itr = itr->left;
  }
  cout << "\n" << itr->data << " <<< minimum in tree " << endl;
}

int main() {

  Node *R2;
  int key;
  makeR2(&R2);
  inorder(R2);
  cout << "\nenter key" << endl;
  cin >> key;

  insertIn_BST_iterative(R2, key);
  inorder(R2);
  minimum_inBST(R2);
  return 0;
}
