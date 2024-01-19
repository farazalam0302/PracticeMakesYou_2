/*Represent the fraction of two numbers in the string format
Read
Courses
Jobs
Given two integers representing the Numerator and Denominator of a fraction,
return the fraction in string format. If the fractional part is repeating,
enclose the repeating part in parentheses.

Examples:

Input: Numerator = 1, Denominator = 2
Output: "0.5"
1/2 = 0.5 with no repeating part.

Input: Numerator = 50, Denominator = 22
Output: "2.(27)"
50/22 = 2.27272727... Since fractional part (27)
is repeating, it is enclosed in parentheses.
*/

#include <bits/stdc++.h>
using namespace std;

string calculateFraction(int N, int D) {
  if (N == 0)
    return "0";
  if (D == 0)
    return "";
  string ret = "";

  int sign = (N < 0) ^ (D < 0) ? -1 : 1;
  N = abs(N);
  D = abs(D);

  if (sign == -1) {
    ret += "-";
  }
  ret = ret + to_string(N / D);

  if (N % D == 0)
    return ret;

  ret += ".";

  int rem = N % D;
  unordered_map<int, int> mp;
  int beginBraceindex;
  bool repeating = false;

  while (rem > 0 && !repeating) {

    if (mp.find(rem) != mp.end()) {
      beginBraceindex = mp[rem];
      repeating = true;
      break;
    } else {
      mp[rem] = ret.size();
    }

    rem = rem * 10;
    int tmp = rem / D;
    ret += to_string(tmp);
    rem = rem % D;
  }
  if (repeating) {
    ret += ")";
    ret.insert(beginBraceindex, "(");
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  int N = 10;
  int D = 3;
  cout << calculateFraction(N, D) << endl;
  return 0;
}
