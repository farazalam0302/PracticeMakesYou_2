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

void printSpiralLevelOrder_recursive_utility(Node *R, int level,
                                             bool direction) {
  if (!R || (level <= 0))
    return;

  if (level == 1)
    cout << R->data << " ";
  if (direction) {
    printSpiralLevelOrder_recursive_utility(R->left, level - 1, direction);
    printSpiralLevelOrder_recursive_utility(R->right, level - 1, direction);
  } else {
    printSpiralLevelOrder_recursive_utility(R->right, level - 1, direction);
    printSpiralLevelOrder_recursive_utility(R->left, level - 1, direction);
  }
}
void printSpiralLevelOrder_recursive(Node *R) {
  if (!R)
    return;
  int depth = height_depth(R);
  bool direction = false;
  for (int level = 1; level <= depth; level++) {
    printSpiralLevelOrder_recursive_utility(R, level, direction);
    direction = !direction;
  }
}

void printSpiralLevelOrder_iterative(Node *R) {
  if (!R)
    return;
  stack<Node *> L2R;
  stack<Node *> R2L;
  L2R.push(R);
  Node *tmp = NULL;
  while (L2R.empty() == false || R2L.empty() == false) {

    while (!L2R.empty()) {
      tmp = L2R.top();
      L2R.pop();
      cout << tmp->data << " ";
      if (tmp->right)
        R2L.push(tmp->right);
      if (tmp->left)
        R2L.push(tmp->left);
    }
    while (!R2L.empty()) {
      tmp = R2L.top();
      R2L.pop();
      cout << tmp->data << " ";
      if (tmp->left)
        L2R.push(tmp->left);
      if (tmp->right)
        L2R.push(tmp->right);
    }
  }
  cout << endl;
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
  cout << "printSpiralLevelOrder = ";
  printSpiralLevelOrder_recursive(R1);
  cout << endl;
  // printSpiralLevelOrder_iterative
  cout << "printSpiralLevelOrder_iterative = ";
  printSpiralLevelOrder_iterative(R1);
  cout << endl;
  return 0;
}
