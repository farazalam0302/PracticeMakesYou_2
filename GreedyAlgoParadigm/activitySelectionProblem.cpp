/*
https://practice.geeksforgeeks.org/problems/activity-selection/0

Given N activities with their start and finish times. Select the maximum number
of activities that can be performed by a single person, assuming that a person
can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows
description of testcases. First line is N number of activities then second line
contains N numbers which are starting time of activies.Third line contains N
finishing time of activities.

Output:
For each test case, output a single number denoting maximum activites which can
be performed in new line.

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4

** For More Input/Output Examples Use 'Expected Output' option **
*/

#include <bits/stdc++.h>
using namespace std;
#define prI pair<int, int>

bool mCompare(pair<int, int> &lhs, pair<int, int> &rhs) {
  return lhs.second < rhs.second;
}

class ActivitySelection {
public:
  int activitySelector(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<prI> dt;
    for (int i = 0; i < n; i++) {
      dt.push_back(make_pair(a[i], b[i]));
    }
    sort(dt.begin(), dt.end(), mCompare);
    int j = 0;
    // cout << "( " << dt[j].first << ", " << dt[j].second << " ), ";
    int count = 1;
    for (int i = 1; i < n; i++) {
      if (dt[i].first >= dt[j].second) {
        // cout << "( " << dt[i].first << ", " << dt[i].second << " ), ";
        count++;
        j = i;
      }
    }
    // cout << endl;
    return count;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> start;
    vector<int> finish;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      start.push_back(x);
    }
    for (int i = 0; i < n; i++) {
      cin >> x;
      finish.push_back(x);
    }
    ActivitySelection as;
    cout << as.activitySelector(start, finish) << endl;
  }

  return 0;
}