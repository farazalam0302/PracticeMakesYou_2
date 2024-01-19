/*


171. Excel Sheet Column Number
Easy

616

118

Favorite

Share
Given a column title as appear in an Excel sheet, return its corresponding
column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
Accepted
236,741
Submissions
453,179

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int lent = s.size();
    int ret = 0;
    for (auto i : s) {
      ret = ret * 26;
      ret = ret + (i - 'A' + 1);
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string in = "ZAC";
  cout << s.titleToNumber(in) << endl;

  return 0;
}
