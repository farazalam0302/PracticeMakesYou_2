/*

Given a string, the task is to remove duplicates from it. Expected time
complexity O(n) where n is length of input string and extra space O(1) under the
assumption that there are total 256 possible characters in a string.

Note: that original order of characters must be kept same.

Input:
First line of the input is the number of test cases T. And first line of test
case contains a string.

Output:
Modified string without duplicates and same order of characters.

Constraints:
1 <= T <= 15
1 <= |string|<= 1000

Example:
Input:
2
geeksforgeeks
geeks for geeks

Output:
geksfor
geks for

** For More Input/Output Examples Use 'Expected Output' option **

*/

// C++ program to demonstrate working of auto
// and type inference

/**************
 *
 * there are so many solutions including maps or hash of characters to dothis
 * but all needs O(n) extra space the following solution uses hashing technique
 * bitwise i.e each bit from 0-25 bits represent capital letters and 26-51
 * chaacters represent small letters in globalHashMask of 64 bit and other MSBs
 * are dontcare cases
 * */
#include <bits/stdc++.h>
using namespace std;
class RemoveDuplicates {
public:
  string removeDuplicates(string &s) {
    int len = s.length();
    long long int hash = 0;
    string ret = "";
    long long int mask = 0;
    // scanning the string
    for (int i = 0; i < len; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        mask = 1L << (s[i] - 'A');
        if (!(hash & mask)) {
          ret = ret + s[i];
          hash = hash | mask;
        }
      } else if (s[i] >= 'a' && s[i] <= 'z') {
        mask = 1L << (s[i] - 'a' + 26);
        if (!(hash & mask)) {
          ret = ret + s[i];
          hash = hash | mask;
        }
      } else if (s[i] == ' ') {
        mask = 1L << 53;
        if (!(hash & mask)) {
          ret = ret + s[i];
          hash = hash | mask;
        }
      }
    }
    return ret;
  }

  string removeDuplicatesGeneral(string &s) {
    int len = s.length();
    long long int hash[4] = {0, 0, 0, 0};
    string ret = "";
    long long int mask = 0;
    int index;

    // scanning the string
    for (int i = 0; i < len; i++) {
      if (s[i] >= 0 && s[i] <= 255) {
        index = s[i] / 64;
        mask = 1L << (s[i] % 64);
        if (!(hash[index] & mask)) {
          ret = ret + s[i];
          hash[index] = hash[index] | mask;
        }

      } else
        return "";
    }
    return ret;
  }
};

int main() {
  int t;
  cin >> t;
  //   t = 1;
  while (t--) {
    string s;
    // cin >> s;
    s = "kjkhjkgjhghjg hgfhggfgh  jhjhgjhghghfgfdfdghnbjhjkgfhgdfgvh           "
        "  jkgtrtyrtuiokjhj              "
        "kjnkjljiohsdiufhgbsiudfguisdgbfuisdgbc uvjdbsjuhvb jhxcb";
    RemoveDuplicates rd;
    cout << "string = " << rd.removeDuplicatesGeneral(s) << endl;
  }

  return 0;
}
/*

kjhg fdnbvtryuiolscx
kjhg fdnbvtryuiolscx

*/