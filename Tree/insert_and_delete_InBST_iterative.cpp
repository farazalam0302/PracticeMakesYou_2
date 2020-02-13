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

Node *minimum_inBST(Node *R) {
  if (!R) return nullptr;
  ;
  Node *itr = R;
  while (itr->left) {
    itr = itr->left;
  }
  //   cout << "\n" << itr->data << " <<< minimum in tree " << endl;
  return itr;
}
Node *deleteNode_in_BST(Node *R, int key) {
  if (!R) {
    cout << "\nTree Not exist!!!!\n" << endl;
    return R;
  }
  Node *itr = R;
  Node *prev;

  Node *tmp;
  if (key < itr->data) {
    itr->left = deleteNode_in_BST(itr->left, key);
    return itr;
  }
  if (key > itr->data) {
    itr->right = deleteNode_in_BST(itr->right, key);
    return itr;
  }
  if (itr->left == NULL) {
    tmp = itr->right;
    delete (itr);
    return tmp;
  }
  if (itr->right == NULL) {
    tmp = itr->left;
    delete (itr);
    return tmp;
  } else {
    Node *succParent = itr->right;
    // find successor
    Node *succ = itr->right;
    while (succ->left) {
      succParent = succ;
      succ = succ->left;
    }
    succParent->left = succ->right;
    itr->data = succ->data;
    delete succ;
    return itr;
  }
}
int main() {
  Node *R2;
  int key;
  makeBST(&R2);
  // inorder(R2);
  cout << "\nenter key" << endl;
  cin >> key;

  //   insertIn_BST_iterative(R2, key);
  cout << "\n";
  inorder(R2);
  //   minimum_inBST(R2);
  cout << "\n";
  R2 = deleteNode_in_BST(R2, 20);
  cout << "\n";
  inorder(R2);
  return 0;
}
