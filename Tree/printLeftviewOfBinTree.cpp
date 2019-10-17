#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  int h_dist;
  TreeNode() {
    data = 0;
    left = nullptr;
    right = nullptr;
    h_dist = 0;
  }
  TreeNode(int d) {
    data = d;
    left = nullptr;
    right = nullptr;
    h_dist = 0;
  }
};

void inorder(TreeNode *R, vector<int> &ret) {
  if (!R)
    return;
  inorder(R->left, ret);
  cout << R->data << " ";
  ret.push_back(R->data);
  inorder(R->right, ret);
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
  printLeftViewofTree(R->left, level + 1, maxlevel);
  printLeftViewofTree(R->right, level + 1, maxlevel);
}

void printLeftViewofTreeUtility(TreeNode *R) {
  if (!R)
    return;
  int maxlevel = 0;
  printLeftViewofTree(R, 1, &maxlevel);
}

void printRightViewofTree(TreeNode *R, int level, int *maxlevel) {
  if (!R)
    return;
  if (*maxlevel < level) {
    cout << R->data << " ";
    *maxlevel = level;
  }
  printRightViewofTree(R->right, level + 1, maxlevel);
  printRightViewofTree(R->left, level + 1, maxlevel);
}

void printRightViewofTreeUtility(TreeNode *R) {
  if (!R)
    return;
  int maxlevel = 0;
  printRightViewofTree(R, 1, &maxlevel);
}

bool isBST(TreeNode *R, int minimum, int maximum) {
  if (!R)
    return true;
  if (R->data < minimum || R->data > maximum)
    return false;
  return (isBST(R->left, minimum, R->data - 1) &&
          isBST(R->right, R->data + 1, maximum));
}

bool isBSTviaInorderProperty(TreeNode *R, int &prev) {
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

void printBottomView_BFS(TreeNode *R) {
  // using BFS  levelorder traversal
  if (!R)
    return;
  int hor_d = 0;
  queue<TreeNode *> myQ;
  map<int, int> mymap;
  R->h_dist = hor_d;
  myQ.push(R);
  while (!myQ.empty()) {
    TreeNode *tmp = myQ.front();
    myQ.pop();
    hor_d = tmp->h_dist;
    mymap[hor_d] = tmp->data;
    if (tmp->left) {
      tmp->left->h_dist = hor_d - 1;
      myQ.push(tmp->left);
    }

    if (tmp->right) {
      tmp->right->h_dist = hor_d + 1;
      myQ.push(tmp->right);
    }
  }
  for (auto i : mymap) {
    cout << i.second << " ";
  }
  cout << endl;
}
// typedef pair<int , TreeNode*>
void printBottomView_BFS_withoutDS_Change(pair<int, TreeNode *> &md) {
  // using BFS  levelorder traversal
  if (!(md.second))
    return;
  int hd = 0;

  queue<pair<int, TreeNode *>> Q;
  map<int, int> mapp;

  md.first = hd;
  Q.push(md);
  while (!Q.empty()) {
    pair<int, TreeNode *> tmp = Q.front();
    Q.pop();
    hd = tmp.first;
    mapp[hd] = (tmp.second)->data;
    if ((tmp.second)->left) {
      int t = hd - 1;
      Q.push(make_pair(t, (tmp.second)->left));
    }
    if ((tmp.second)->right) {
      int t = hd + 1;
      Q.push(make_pair(t, (tmp.second)->right));
    }
  }
  for (auto i : mapp) {
    cout << i.second << " ";
  }
  std::cout << "\n" << std::endl;
}

void printBottomView_2(TreeNode *R) {
  if (!R)
    return;
  pair<int, TreeNode *> mds;
  mds = make_pair(0, R);
  printBottomView_BFS_withoutDS_Change(mds);
}

int main() {
  TreeNode *R1 = new TreeNode(1);
  R1->left = new TreeNode(2);
  R1->right = new TreeNode(3);
  R1->left->left = new TreeNode(4);
  R1->left->right = new TreeNode(5);
  R1->right->left = new TreeNode(6);
  R1->right->right = new TreeNode(7);

  TreeNode *R2 = new TreeNode(40);
  R2->left = new TreeNode(20);
  R2->right = new TreeNode(60);
  R2->left->left = new TreeNode(10);
  R2->left->right = new TreeNode(30);
  R2->right->left = new TreeNode(50);
  R2->right->right = new TreeNode(70);

  TreeNode *R3 = new TreeNode(20);
  R3->left = new TreeNode(10);
  R3->right = new TreeNode(30);
  R3->left->left = new TreeNode(5);
  R3->left->left->left = new TreeNode(2);
  R3->left->left->left->right = new TreeNode(3);
  R3->right->left = new TreeNode(15);

  TreeNode *R4 = new TreeNode(1);
  R4->left = new TreeNode(2);
  R4->right = new TreeNode(3);
  R4->left->right = new TreeNode(5);
  R4->right->left = new TreeNode(6);
  R4->right->right = new TreeNode(7);

  int maximum = INT_MIN;
  int minimum = INT_MAX;
  int prev = INT_MIN;
  printBottomView_BFS(R4);
  cout << "\n-------------------" << endl;
  printBottomView_2(R4);
  // isBSTviaInorderProperty(R2, prev) ? cout << "yes it is BST\n"
  //                                   : cout << "No its not BST\n";

  // prev = INT_MIN;
  // isBSTviaInorderProperty(R3, prev) ? cout << "yes it is BST\n"
  //                                   : cout << "No its not BST\n";

  // maximum = INT_MIN;
  // minimum = INT_MAX;
  // isBST(R3, INT_MIN, INT_MAX) ? cout << "yes it is BST\n"
  //                             : cout << "No its not BST\n";
  /************/
  // vector<int> ret;
  // inorder(R2, ret);
  // cout << endl;
  // for (auto i : ret)
  //   cout << i << " ";
  // cout << endl;

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
