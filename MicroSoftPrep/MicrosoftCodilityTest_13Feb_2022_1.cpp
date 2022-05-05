/*
 * https://docs.google.com/document/d/1RyXveL1WdP6cXx5wNx8F8Ogu5MqZBSohVp4hLBAQJ9Q/edit?usp=sharing
 *
 */

#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int>& a) {
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
}

int maxApart(vector<int>& a) {
  int n = a.size();
  vector<int> farLeft;  //(n, 0);
  vector<int> farRight(n, 1);
  farLeft.push_back(1);
  for (int i = 1; i < n; ++i) {
    if (a[i] >= a[i - 1]) {
      farLeft.push_back(farLeft[i - 1] + 1);
    } else {
      farLeft.push_back(0);
    }
  }

  farRight[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (farRight[i] >= farRight[i + 1]) {
      farRight[i] = farRight[i + 1] + 1;

    } else
      farRight[i] = 0;
  }

  //  printVector(farLeft);
  //  printVector(farRight);
  int maximum = INT_MIN;
  for (int i = 0; i < n; ++i) {
    maximum = max(abs(farLeft[i] + farRight[i]), maximum);
  }

  return maximum;
}

int main() {
  vector<int> in1{2, 6, 8, 5};
  vector<int> in2{1, 5, 5, 2, 6};
  vector<int> in3{1, 1};

  int result;

  result = maxApart(in1);
  cout << "Result = " << result << endl;
  result = maxApart(in2);
  cout << "Result = " << result << endl;
  result = maxApart(in3);
  cout << "Result = " << result << endl;

  return 0;
}
