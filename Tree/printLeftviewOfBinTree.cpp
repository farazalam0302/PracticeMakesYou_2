#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode() {
    data = 0;
    left = nullptr;
    right = nullptr;
  }
  TreeNode(int d) {
    data = d;
    left = nullptr;
    right = nullptr;
  }
};

void inorder(TreeNode *R) {
  if (!R)
    return;
  inorder(R->left);
  cout << R->data << " ";
  inorder(R->right);
}

void preorder(TreeNode *R) {
  if (!R)
    return;
  preorder(R->left);
  preorder(R->right);
  cout << R->data << " ";
}
void postorder(TreeNode *R) {
  if (!R)
    return;
  cout << R->data << " ";
  postorder(R->left);
  postorder(R->right);
}
int height_depth(TreeNode *R) {
  if (!R)
    return 0;
  return ((max(height_depth(R->left), height_depth(R->right))) + 1);
}
void levelOrderTraversalRecurse(TreeNode *R, int level); // is similar to BFS

void levelOrderTraversalRecurseUtil(TreeNode *R) {
  if (!R)
    return;
  int height = height_depth(R);
  for (int i = 1; i <= height; i++) {
    levelOrderTraversalRecurse(R, i);
  }
}

void levelOrderTraversalRecurse(TreeNode *R, int level) // is similar to BFS
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
void levelOrderTraversal_BFS(TreeNode *R) {
  if (!R)
    return;
  queue<TreeNode *> Q;
  TreeNode *tmp = R;
  while (tmp) {
    cout << tmp->data << " ";
    Q.push(tmp->left);
    Q.push(tmp->right);
    tmp = Q.front();
    Q.pop();
  }
}

void printLeftViewofTree(TreeNode *R, int level, int *maxlevel) {
  if (!R)
    return;
  if (*maxlevel < level) {
    cout << R->data << " ";
    *maxlevel = level;
  }
  printLeftViewofTree(R->right, level + 1, maxlevel);
  printLeftViewofTree(R->left, level + 1, maxlevel);
}

void printLeftViewofTreeUtility(TreeNode *R) {
  if (!R)
    return;
  int maxlevel = 0;
  printLeftViewofTree(R, 1, &maxlevel);
}
int main() {
  TreeNode *R1 = new TreeNode(1);
  R1->left = new TreeNode(2);
  R1->right = new TreeNode(3);
  R1->left->left = new TreeNode(4);
  R1->left->right = new TreeNode(5);
  R1->right->left = new TreeNode(6);
  R1->right->right = new TreeNode(7);

  TreeNode *R2 = new TreeNode(1);
  R2->left = new TreeNode(2);
  R2->right = new TreeNode(3);
  R2->left->left = new TreeNode(4);
  R2->left->right = new TreeNode(5);
  R2->right->left = new TreeNode(6);
  R2->right->right = new TreeNode(7);
  // //  printLeftViewofTreeUtility
  cout << "printLeftViewofTreeUtility = ";
  printLeftViewofTreeUtility(R1);
  cout << endl;
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
