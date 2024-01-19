/*
https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/

Given an integer n, write a function that returns count of trailing zeroes in
n!. Examples :

Input: n = 5
Output: 1
Explanation: Factorial of 5 is 120 which has one trailing 0.

Input: n = 20
Output: 4
Explanation: Factorial of 20 is 2432902008176640000 which has 4 trailing zeroes.

Input: n = 100
Output: 24

*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int zcount = 0;
  for (int i = 5; n / i >= 1; i = i * 5) {
    zcount = zcount + n / i;
  }

  cout << "zcount = " << zcount << endl;

  return 0;
}
