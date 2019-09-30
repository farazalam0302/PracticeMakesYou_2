/*
Ref LINK :
https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/


Median in a stream of integers (running integers)
Given that integers are read from a data stream. Find median of elements read so
for in efficient way. For simplicity assume there are no duplicates. For
example, let us consider the stream 5, 15, 1, 3 …

After reading 1st element of stream - 5 -> median - 5
After reading 2nd element of stream - 5, 15 -> median - 10
After reading 3rd element of stream - 5, 15, 1 -> median - 5
After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
Making it clear, when the input size is odd, we take the middle element of
sorted data. If the input size is even, we pick average of middle two elements
in sorted stream.

Note that output is effective median of integers read from the stream so far.
Such an algorithm is called online algorithm. Any algorithm that can guarantee
output of i-elements after processing i-th element, is said to be online
algorithm. Let us discuss three solutions for the above problem.

*/
/* --------------------------------------

Given an input stream of N integers. The task is to insert these numbers into
a new stream and find the median of the stream formed by each insertion of X to
the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in
the stream. Then the next N lines contains integer x denoting the number to be
inserted into the stream. Output: For each element added to the stream print the
floor of the new median in a new line.
 

Constraints:
1 <= N <= 106
1 <= x <= 106
Example:
Input:
4
5
15
1
3
Output:
5
10
5
4
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)
*/

#include <bits/stdc++.h>
using namespace std;

class MedianInStream {
public:
  void medianInStream(vector<int> &a) {
    int sz = a.size();
    if (sz == 0)
      return;
    if (sz == 1) {
      cout << "median = " << a[0] << endl;
      return;
    }

    priority_queue<int> leftQ;                             // maxHeap
    priority_queue<int, vector<int>, greater<int>> rightQ; // minHeap

    leftQ.push(a[0]);
    int median = a[0];
    cout << median << endl;
    int l = 1;
    int r = 0;
    int x;

    for (int i = 1; i < sz; i++) {
      l = leftQ.size();
      r = rightQ.size();
      x = a[i];

      if (l > r) {
        if (x < median) {
          rightQ.push(leftQ.top());
          leftQ.pop();
          leftQ.push(x);
        } else {
          rightQ.push(x);
        }
        median = (leftQ.top() + rightQ.top()) / 2.0;
      } else if (l == r) {
        if (x < median) {
          leftQ.push(x);
          median = leftQ.top();
        } else {
          rightQ.push(x);
          median = rightQ.top();
        }
      } else {
        if (x > median) {
          leftQ.push(rightQ.top());
          rightQ.pop();
          rightQ.push(x);
        } else {
          leftQ.push(x);
        }
        median = (leftQ.top() + rightQ.top()) / 2.0;
      }
      cout << median << endl;
    }
  }
};

int main() {

  vector<int> a{5, 15};
  int n;
  //   cin >> n;
  //   int x;
  //   for (int i = 0; i < n; i++) {
  //     cin >> x;
  //     a.push_back(x);
  //   }

  //   priority_queue<int> pq1(a.begin(), a.end());
  //   for (int i = 0; i < a.size(); i++) {
  //     cout << pq1.top() << endl;
  //     pq1.pop();
  //   }

  //   cout << "\n-----------------\n" << endl;
  //   priority_queue<int, vector<int>, greater<int>> pq2(a.begin(), a.end());
  //   for (int i = 0; i < a.size(); i++) {
  //     cout << pq2.top() << endl;
  //     pq2.pop();
  //   }

  MedianInStream bb;
  bb.medianInStream(a);

  return 0;
}