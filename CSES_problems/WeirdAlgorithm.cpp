/*
 *
 *
 *

https://cses.fi/problemset/task/1068/

CSES Problem Set
Weird Algorithm

    Task Submit Results Statistics

    Time limit: 1.00 s Memory limit: 512 MB

Consider an algorithm that takes as input a positive integer n
. If n is even, the algorithm divides it by two, and if n is odd, the algorithm
multiplies it by three and adds one. The algorithm repeats this, until n is one.
For example, the sequence for n=3 is as follows: 3→10→5→16→8→4→2→1

Your task is to simulate the execution of the algorithm for a given value of n.

Input

The only input line contains an integer n.

Output

Print a line that contains all values of n during the algorithm.

Constraints

    1≤n≤10^6


Example

Input:
3

Output:
3 10 5 16 8 4 2 1
 */
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned long long int

int main(int argc, char **argv) {

  ulli n;
  cin >> n;

  while (1) {
    cout << n << " ";
    if (n == 1)
      break;
    if ((n & 1) == 1)
      n = ((n << 1) + n) + 1;
    else {
      n = n >> 1;
    }
  }

  cout << endl;

  return 0;
}
