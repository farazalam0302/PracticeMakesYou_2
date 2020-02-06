/*

https://practice.geeksforgeeks.org/problems/edit-distance/0

Edit DistanceSubmissions: 53214   Accuracy: 33.33%   Difficulty: Medium   Marks:
4 Associated Course(s):   Must Do Interview Preparation

Problems
Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits (operations) required to convert ‘str1′ into
‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test
cases. Then T test cases follow. Each tese case consists of two lines. The first
line of each test case consists of two space separated integers P and Q denoting
the length of the strings str1 and str2 respectively. The second line of each
test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of
operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's'
from str2.

** For More Input/Output Examples Use 'Expected Output' option **
Author: abhiraj26

funda to write edit distance formula
 ===================
| REPLACE | INSERT  |
|_________|_________|
| DELETE  | CURRENT |
|=========|=========|

DPFORMULA : -
if (str[i] == str[j])
{
  dp[i,j] = dp[i-1,j-1]
}
else
{
  dp[i,j] = 1 + min(dp[i-1,j],dp[i,j-1],dp[i-1,j-1])
}
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  t = 1;
  while (t--) {
    int p, q;
    cin >> p, cin >> q;
    string s1, s2;
    cin.ignore();
    getline(cin, s1);
    // cin.ignore();
    getline(cin, s2);
    vector<char> ch1(p + 1);
    vector<char> ch2(q + 1);
    ch1[0] = '$';
    ch2[0] = '$';
    for (int i = 0; i < p; i++) {
      ch1[i + 1] = s1[i];
    }
    for (int i = 0; i < q; i++) {
      ch2[i + 1] = s2[i];
    }

    vector<vector<int>> editDP(p + 1, vector<int>(q + 1, 0));

    // printing dp array
    cout << "s2-> ";
    for (int j = 0; j <= q; j++) {
      cout << ch2[j] << " ";
    }
    cout << endl;
    for (int i = 0; i <= p; i++) {
      cout << ch1[i] << " -> ";
      for (int j = 0; j <= q; j++) {
        cout << editDP[i][j] << " ";
      }
      cout << endl;
    }

    // printing dp array

    for (int i = 0; i <= p; i++) {
      editDP[i][0] = i;
    }

    for (int i = 0; i <= q; i++) {
      editDP[0][i] = i;
    }

    for (int i = 1; i <= p; i++) {
      for (int j = 1; j <= q; j++) {
        if (ch1[i] == ch2[j]) {
          editDP[i][j] = editDP[i - 1][j - 1];
        } else {
          editDP[i][j] = 1 + min(min(editDP[i - 1][j - 1], editDP[i - 1][j]),
                                 editDP[i][j - 1]);
        }
      }
    }

    // printing dp array
    cout << "\n\ns2-> ";
    for (int j = 0; j <= q; j++) {
      cout << ch2[j] << " ";
    }
    cout << endl;
    for (int i = 0; i <= p; i++) {
      cout << ch1[i] << " -> ";
      for (int j = 0; j <= q; j++) {
        cout << editDP[i][j] << " ";
      }
      cout << endl;
    }

    // printing dp array

    cout << "minimum edit distance = " << editDP[p][q] << endl;
  }

  return 0;
}
