/*
Given a string, what is the minimum number of adjacent swaps required to convert
a string into a palindrome. If not possible, return -1.

Example 1:

Input: "mamad"
Output: 3
Example 2:

Input: "asflkj"
Output: -1
Example 3:

Input: "aabb"
Output: 2
Example 4:

Input: "ntiin"
Output: 1
Explanation: swap 't' with 'i' => "nitin"


solutions
    * Algorithm:
     *     1. First check the given string is a jumbled/shuffled palindrome or
not.
     *     2. Next have two pointers front at 0 and rear at s.length - 1 and
start iterating.
     *     3. If chars at both the pointers are same then just shrink the window
(increase the front and decrease the rear).
     *     4. or Else
     *          a. find the matching pair and swap the char to rear index
(increase swap count while swapping) and finally shrink the window.
     *          b. if not found just swap once with adjacent index and increase
the swap count (do not shrink the window here)
     *     5. Print the Swap Count
     *
     * Time Complexity: O(n) to find Palindrome + [ O(n) for two pointer
iteration * O(n) for checking and swapping ] so => O(n^2)
     * Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

bool isShuffledPalindrome(string &a) {
  vector<int> charCounts(26, 0);
  int index = 0;
  for (int i = 0; i < a.size(); i++) {
    index = a[i] - 'a';
    charCounts[index]++;
  }
  int oddCounts = 0;
  for (int i = 0; i < 26; i++) {
    if (charCounts[i] % 2 == 1) oddCounts++;
  }

  return oddCounts <= 1;
}

int minimumSwaps(string &input) {
  int len = input.size();
  if (len == 0) return -1;
  int minimumNumSwaps = 0;
  if (isShuffledPalindrome(input)) {
    int front = 0;
    int rear = len - 1;
    char temp;
    while (rear > front) {
      if (input[front] != input[rear]) {
        int k = rear;
        while (k > front && input[k] != input[front]) k--;
        if (k == front) {
          temp = input[front];
          input[front] = input[front + 1];
          input[front + 1] = temp;
          minimumNumSwaps++;
        } else {
          while (k < rear) {
            temp = input[k];
            input[k] = input[k + 1];
            input[k + 1] = temp;
            minimumNumSwaps++;
            k++;
          }
          front++;
          rear--;
        }
      } else {  // 		if (input[front] == input[rear]) {

        front++;
        rear--;
      }
    }

    return minimumNumSwaps;
  } else {
    return -1;
  }
}
int main() {
  string in1 = "mamad";
  string in2 = "mamadm";
  cout << "\n minimumNumSwaps  for " << in1 << " = " << minimumSwaps(in1)
       << endl;

  cout << "\n minimumNumSwaps  for " << in2 << " = " << minimumSwaps(in2)
       << endl;

  // cout << "\n\n " <<in1 <<  endl;

  // char  tmp = in1[0];
  // in1[0] = in1[4];
  // in1[4] = tmp;
  // cout << "\n\n " <<in1 <<  endl;

  return 0;
}
