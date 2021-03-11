/*

Minimum number of jumpsSubmissions: 76001   Accuracy: 33.07%   Difficulty:
Medium   Marks: 4 Associated Course(s):   Must Do Interview Preparation DSA-Self
Paced with Doubt Assistance More

Problems
Given an array of integers where each element represents the max number of steps
that can be made forward from that element. The task is to find the minimum
number of jumps to reach the end of the array (starting from the first element).
If an element is 0, then cannot move through that element.

Input:
The first line contains an integer T, depicting total number of test cases. Then
following T lines contains a number n denoting the size of the array. Next line
contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer
is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with
value 3. Now, from here we jump to 5h element with value 9. and from here we
will jump to last.


*/

#include <bits/stdc++.h>
using namespace std;
class MinJumps {
 public:
  int minJumps(vector<int>& a) {
    int n = a.size();
    vector<int> jumpArray(n, INT_MAX);
    vector<int> jumpPathArray(n, -1);
    jumpArray[0] = 0;

    cout << "\n----------------------" << endl;
    cout << "\n       Jump Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpArray[i] << " ";
    }
    cout << "\n----------------------" << endl;
    cout << "\n       Jump Path Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpPathArray[i] << " ";
    }
    cout << "\n----------------------" << endl;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (j + a[j] >= i) {
          if (jumpArray[j] != INT_MAX && jumpArray[i] >= jumpArray[j] + 1) {
            jumpArray[i] = jumpArray[j] + 1;
            jumpPathArray[i] = j;
          }
        }
      }
    }
    cout << "\n       Input Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n----------------------" << endl;
    cout << "\n       Jump Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpArray[i] << " ";
    }
    cout << "\n----------------------" << endl;
    cout << "\n       Jump Path Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpPathArray[i] << " ";
    }
    cout << "\n----------------------" << endl;

    return jumpArray[n - 1];
  }
};

void displayArray(vector<int>& a) {
  cout << endl;
  cout << endl;
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
  cout << endl;
}

int minimumJumpInArray(vector<int>& a) {
  int n = a.size();
  if (n == 0 || a[0] == 0) return INT_MAX;
  vector<int> jumps(n, INT_MAX);
  jumps[0] = 0;
  displayArray(jumps);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (i <= a[j] + j)
        if (jumps[j] != INT_MAX) {
          jumps[i] = min(jumps[i], jumps[j] + 1);
          break;
        }
    }
  }
  vector<int> res;
  for (int i = 0; i < n - 1; ++i) {
    if (jumps[i] != jumps[i + 1]) res.push_back(a[i]);
  }

  displayArray(res);

  displayArray(jumps);
  return jumps[n - 1];
}

int main(int argc, char const* argv[]) {
  int n;
  vector<int> b{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int res = minimumJumpInArray(b);
  if (res == INT_MAX)
    cout << "!!!!  NOT REACHABLE  !!! \n\n" << endl;
  else
    cout << "minimum jumps = " << res << endl;
  /*
   *
  cin >> n;
  vector<int> a(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  MinJumps mj;
  int answer = mj.minJumps(a);
  if (answer != INT_MAX)
    cout << "answer = " << answer << endl;
  else
    cout << "!!!!  NOT REACHABLE  !!! \n\n" << endl;
*/
  return 0;
}

/*
 * // C++ program to count Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
        return (x > y) ? x : y;
}

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{

        // The number of jumps needed to
        // reach the starting index is 0
        if (n <= 1)
                return 0;

        // Return -1 if not possible to jump
        if (arr[0] == 0)
                return -1;

        // initialization
        // stores all time the maximal
        // reachable index in the array.
        int maxReach = arr[0];

        // stores the number of steps
        // we can still take
        int step = arr[0];

        // stores the number of jumps
        // necessary to reach that maximal
        // reachable position.
        int jump = 1;

        // Start traversing array
        int i = 1;
        for (i = 1; i < n; i++) {
                // Check if we have reached the end of the array
                if (i == n - 1)
                        return jump;

                // updating maxReach
                maxReach = max(maxReach, i + arr[i]);

                // we use a step to get to the current index
                step--;

                // If no further steps left
                if (step == 0) {
                        // we must have used a jump
                        jump++;

                        // Check if the current index/position or lesser index
                        // is the maximum reach point from the previous indexes
                        if (i >= maxReach)
                                return -1;

                        // re-initialize the steps to the amount
                        // of steps to reach maxReach from position i.
                        step = maxReach - i;
                }
        }

        return -1;
}

// Driver program to test above function
int main()
{
        int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
        int size = sizeof(arr) / sizeof(int);

        // Calling the minJumps function
        cout << ("Minimum number of jumps to reach end is %d ",
                        minJumps(arr, size));
        return 0;
}
// This code is contributed by
// Shashank_Sharma
 *
 *
 */
