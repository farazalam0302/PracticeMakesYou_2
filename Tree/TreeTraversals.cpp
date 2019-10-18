#include "BinaryTree.h"

// using namespace std;

void levelOrderTraversalRecurse(Node *R, int level); // is similar to BFS

void levelOrderTraversalRecurseUtil(Node *R) {
  if (!R)
    return;
  int height = height_depth(R);
  for (int i = 1; i <= height; i++) {
    levelOrderTraversalRecurse(R, i);
  }
}

void levelOrderTraversalRecurse(Node *R, int level) // is similar to BFS
{
  if (!R)
    return;
  if (level == 1) {
    cout << R->data << " ";
  } else if (level > 1) {
    levelOrderTraversalRecurse(R->left, level - 1);
    levelOrderTraversalRecurse(R->right, level - 1);
  }
}
void levelOrderTraversal_BFS(Node *R) {
  if (!R)
    return;
  queue<Node *> Q;
  Node *tmp = R;
  while (tmp) {
    cout << tmp->data << " ";
    Q.push(tmp->left);
    Q.push(tmp->right);
    tmp = Q.front();
    Q.pop();
  }
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
  int maximum = INT_MIN;
  int minimum = INT_MAX;
  int prev = INT_MIN;

  cout << "levelOrderTraversal_BFS = ";
  levelOrderTraversal_BFS(R1);
  cout << endl;
  cout << "depth = " << height_depth(R1);
  cout << endl;

  cout << "inorder = ";
  inorder(R1);
  cout << endl;
  cout << "preorder = ";
  preorder(R1);
  cout << endl;
  cout << "postorder = ";
  postorder(R1);
  cout << endl;
  cout << "levelOrderrecursive = ";
  levelOrderTraversalRecurseUtil(R1);
  cout << endl;

  return 0;
}
