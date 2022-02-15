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

class Solution {
public:
  int titleToNumber(string s) {
    int lent = s.size();
    int ret = 0;
    for (auto i : s) {
      int p = 1;
      for (int j = 0; j < lent - 1; j++)
        p = p * 26;
      lent--;
      ret = ret + p * (i - 'A' + 1);
    }
    return ret;
  }
};
