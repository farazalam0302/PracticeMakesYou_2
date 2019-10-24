#include "BinaryTree.h"

void printLeftViewofTree(Node *R, int level, int *maxlevel) {
  if (!R)
    return;
  if (*maxlevel < level) {
    cout << R->data << " ";
    *maxlevel = level;
  }
  printLeftViewofTree(R->left, level + 1, maxlevel);
  printLeftViewofTree(R->right, level + 1, maxlevel);
}

void printLeftViewofTreeUtility(Node *R) {
  if (!R)
    return;
  int maxlevel = 0;
  printLeftViewofTree(R, 1, &maxlevel);
}

void printRightViewofTree(Node *R, int level, int *maxlevel) {
  if (!R)
    return;
  if (*maxlevel < level) {
    cout << R->data << " ";
    *maxlevel = level;
  }
  printRightViewofTree(R->right, level + 1, maxlevel);
  printRightViewofTree(R->left, level + 1, maxlevel);
}

void printRightViewofTreeUtility(Node *R) {
  if (!R)
    return;
  int maxlevel = 0;
  printRightViewofTree(R, 1, &maxlevel);
}

void printVerticalOrder_levelOrderway(Node *R) {
  if (!R)
    return;
  pair<int, Node *> mp = make_pair(0, R);
  map<int, vector<int>> mmap;
  queue<pair<int, Node *>> Q;
  Q.push(mp);
  while (!Q.empty()) {
    pair<int, Node *> tmp = Q.front();
    Q.pop();
    int hd = tmp.first;
    Node *tNode = tmp.second;
    mmap[hd].push_back(tNode->data);
    if (tNode->left != NULL) {
      Q.push({hd - 1, tNode->left});
    }
    if (tNode->right != NULL) {
      Q.push({hd + 1, tNode->right});
    }
  }
  for (auto i = mmap.begin(); i != mmap.end(); i++) {
    for (auto j : (i->second)) {
      cout << j << " ";
    }
    cout << endl;
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

  // // //  printLeftViewofTreeUtility
  cout << "printLeftViewofTreeUtility = ";
  printLeftViewofTreeUtility(R1);
  cout << endl;

  cout << "printrightViewofTreeUtility = ";
  printRightViewofTreeUtility(R1);
  cout << endl;

  return 0;
}
