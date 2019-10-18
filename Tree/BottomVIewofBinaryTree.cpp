#include "BinaryTree.h"

void printBottomView_BFS(Node *R) {
  // using BFS  levelorder traversal
  if (!R)
    return;
  int hor_d = 0;
  queue<Node *> myQ;
  map<int, int> mymap;
  R->h_dist = hor_d;
  myQ.push(R);
  while (!myQ.empty()) {
    Node *tmp = myQ.front();
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
// typedef pair<int , Node*>
void printBottomView_BFS_withoutDS_Change(pair<int, Node *> &md) {
  // using BFS  levelorder traversal
  if (!(md.second))
    return;
  int hd = 0;

  queue<pair<int, Node *>> Q;
  map<int, int> mapp;

  md.first = hd;
  Q.push(md);
  while (!Q.empty()) {
    pair<int, Node *> tmp = Q.front();
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
  std::cout << std::endl;
}

void printBottomView_2(Node *R) {
  if (!R)
    return;
  pair<int, Node *> mds;
  mds = make_pair(0, R);
  printBottomView_BFS_withoutDS_Change(mds);
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

  cout << "Bottom view tree = \n" << endl;
  printBottomView_2(R1);
  cout << "\n-----------" << endl;
  printBottomView_BFS(R1);

  cout << endl;

  return 0;
}
