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
*
*
*
* Method : Heaps
* Method Similar to balancing BST in Method 2 above, we can use a max heap on
left side
* to represent elements that are less than effective median, and a min heap on
* right side to represent elements that are greater than effective median.
*
* After processing an incoming element, the number of elements in heaps differ
* utmost by 1 element. When both heaps contain same number of elements, we pick
* average of heaps root data as effective median. When the heaps are not
balanced,
* we select effective median from the root of heap containing more elements.
*
*  lets say a = [ 5 4 3 6 7 ]    ->sort-> a = [3 4 5 6 7]
*  see this as ,-> 5 <---,
*              |   / \    |
* LT can be  <-|   4  6   | clearly see RT side can be seen as min Heap
*  max_heap    |   /  \   |
*              -->3   7 <-
*
*
*/
#if 0
// C++ program to find med in
// stream of running integers
#include <bits/stdc++.h>
using namespace std;

// function to calculate med of stream
void printMedians(double arr[], int n) {
  // max heap to store the smaller half elements
  priority_queue<double> s;

  // min heap to store the greater half elements
  priority_queue<double, vector<double>, greater<double> > g;

  double med = arr[0];
  s.push(arr[0]);

  cout << med << endl;

  // reading elements of stream one by one
  /* At any time we try to make heaps balanced and
          their sizes differ by at-most 1. If heaps are
          balanced,then we declare median as average of
          min_heap_right.top() and max_heap_left.top()
          If heaps are unbalanced,then median is defined
          as the top element of heap of larger size */
  for (int i = 1; i < n; i++) {
    double x = arr[i];

    // case1(left side heap has more elements)
    if (s.size() > g.size()) {
      if (x < med) {
        g.push(s.top());
        s.pop();
        s.push(x);
      } else
        g.push(x);

      med = (s.top() + g.top()) / 2.0;
    }

    // case2(both heaps are balanced)
    else if (s.size() == g.size()) {
      if (x < med) {
        s.push(x);
        med = (double)s.top();
      } else {
        g.push(x);
        med = (double)g.top();
      }
    }

    // case3(right side heap has more elements)
    else {
      if (x > med) {
        s.push(g.top());
        g.pop();
        g.push(x);
      } else
        s.push(x);

      med = (s.top() + g.top()) / 2.0;
    }

    cout << med << endl;
  }

  cout << "\nLeftMAxHeap \n";
  vector<double> leftMax;
  while (!s.empty()) {
    leftMax.push_back(s.top());
    s.pop();
  }
  for (auto i : leftMax) {
    cout << i << " ";
  }
  cout << "\nRightMinHeap \n";
  vector<double> rightMin;
  while (!g.empty()) {
    rightMin.push_back(g.top());
    g.pop();
  }
  for (auto i : rightMin) {
    cout << i << " ";
  }
}

// Driver program to test above functions
int main() {
  // stream of integers
  double arr[] = {3, 2, 1, 5, 6, 8, 4};  //{5, 15, 10, 20, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printMedians(arr, n);
  return 0;
}

#endif

#if 1

#include <bits/stdc++.h>
using namespace std;

double medianInStreamOfIntegers(vector<double> &a) {
  int aSize = a.size();
  if (aSize == 0)
    return -1.0;
  if (aSize == 1)
    return a[0];
  priority_queue<double> leftMaxHeap;
  priority_queue<double, vector<double>, greater<double>> rightMinHeap;
  double median = a[0];
  leftMaxHeap.push(a[0]);
  cout << median << '\n';
  for (int i = 1; i < a.size(); ++i) {
    double incomingNo = a[i];
    if (leftMaxHeap.size() > rightMinHeap.size()) {
      if (incomingNo < median) {
        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();
        leftMaxHeap.push(incomingNo);

      } else {
        rightMinHeap.push(incomingNo);
      }
      median = 0.5 * (leftMaxHeap.top() + rightMinHeap.top());
    } else if (leftMaxHeap.size() == rightMinHeap.size()) {
      if (incomingNo < median) {
        leftMaxHeap.push(incomingNo);
        median = leftMaxHeap.top();
      } else {
        rightMinHeap.push(incomingNo);
        median = rightMinHeap.top();
      }
    } else {
      if (incomingNo < median) {
        leftMaxHeap.push(incomingNo);

      } else {
        leftMaxHeap.push(rightMinHeap.top());
        rightMinHeap.pop();
        rightMinHeap.push(incomingNo);
      }
      median = 0.5 * (leftMaxHeap.top() + rightMinHeap.top());
    }
    cout << median << '\n';
  }
#if 0


  cout << "\nLeftQ\n";
  vector<double> leftMax;
  while (!leftMaxHeap.empty()) {
    leftMax.push_back(leftMaxHeap.top());
    leftMaxHeap.pop();
  }
  for (int i = leftMax.size() - 1; i >= 0; --i) {
    cout << leftMax[i] << " ";
  }
  cout << "\nRightMinHeap \n";
  vector<double> rightMin;
  while (!rightMinHeap.empty()) {
    rightMin.push_back(rightMinHeap.top());
    rightMinHeap.pop();
  }
  for (int i = 0; i < rightMin.size(); ++i) {
    cout << rightMin[i] << " ";
  }
#endif
  return median;
}

int main() {
  int n;
  //  cin >> n;
  vector<double> a{3, 2, 1, 5, 6, 8, 4}; //(n, 0);

  //  for (int i = 0; i < n; i++) {
  //    cin >> a[i];
  //    //       a.push_back(x);
  //  }

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

  //  bb.medianInStream(a);
  double x = medianInStreamOfIntegers(a);
  cout << "\nMedian = " << x << '\n';
  return 0;
}
#endif
