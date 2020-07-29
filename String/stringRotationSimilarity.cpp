/*
https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0



Given two strings a and b. The task is to find if a string 'a' can be obtained
by rotating another string 'b' by 2 places.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by
rotating string 'b' by two places else print 0.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0

Explanation:
Testcase 1: amazon can be rotated anti-clockwise by two places, which will make
it as azonam.

Testcase 2: geeksgeeksfor can't be formed by any rotation from the given word
geeksforgeeks.
 


** For More Input/Output Examples Use 'Expected Output' option **
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char **argv) {
  int t;
  cin >> t;
  //   t = 1;
  cin.ignore();
  while (t--) {
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);

    int lenA = a.length();
    int lenB = b.length();
    if (lenA != lenB || lenA < 4 || lenB < 4) {
      cout << " Length Error !!!" << endl;
      return 0;
    }

    string tmp = "";
    // anticlockwise
    tmp = b.substr(3) + b.substr(0, 3);
    int x = tmp.compare(a);
    // clockwise
    tmp = "";

    tmp = b.substr(lenB - 2) + b.substr(0, lenB - 2);
    int y = tmp.compare(a);

    if (x == 0 || y == 0) {
      cout << "True " << endl;
    } else {
      cout << "False" << endl;
    }
  }
  return 0;
}