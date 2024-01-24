/*
Given a positive integer n such that n > 2. Divide numbers from 1 to n in two
groups such that absolute difference of sum of each group is minimum. Print any
two groups with their size in first line and in next line print elements of that
group

eg.
Input : 5
Output : 2
         5 2
         3
         4 3 1


https://www.geeksforgeeks.org/divide-1-n-two-groups-minimum-sum-difference/



*/
#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a) {
  cout << endl;
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
}

void solution(int n) {
  vector<int> g1, g2;

  int g1Sum = n * (n + 1) / 4;
  for (int i = n; i >= 1; --i) {

    if (g1Sum - i >= 0) {
      g1.push_back(i);
      g1Sum -= i;
    } else {
      g2.push_back(i);
    }
  }

  printArray(g1);

  printArray(g2);
}

int main(int argc, char const *argv[]) {

  int n;
  cout << "enter n?\n";
  cin >> n;
  solution(n);

  return 0;
}
