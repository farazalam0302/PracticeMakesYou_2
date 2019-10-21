#include "BinaryTree.h"

int maxPAthSum_utility(Node *R, int &res) {
  if (!R)
    return 0;
  int l = maxPAthSum_utility(R->left, res);
  int r = maxPAthSum_utility(R->right, res);
  int max_single = max(max(l, r) + R->data, R->data);
  int max_top = max(max_single, l + r + R->data);
  res = max(res, max_top);
  return max_single;
}

int maxPAthSum(Node *R) {
  if (!R)
    return -1;
  int res = INT_MIN;
  maxPAthSum_utility(R, res);

  return res;
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

  int res = maxPAthSum(R1);
  cout << "\n result = " << res << endl;

  return 0;
}
