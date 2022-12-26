/*

Given a sorted matrix mat[n][m] and an element ‘x’. Find the position of x in
the matrix if it is present, else print -1. Matrix is sorted in a way such that
all elements in a row are sorted in increasing order and for row ‘i’, where 1 <=
i <= n-1, the first element of row ‘i’ is greater than or equal to the last
element of row ‘i-1’. The approach should have O(log n + log m) time complexity.

Examples:

Input : mat[][] = { {1, 5, 9},
                    {14, 20, 21},
                    {30, 34, 43} }
        x = 14
Output : Found at (1, 0)

Input : mat[][] = { {1, 5, 9, 11},
                    {14, 20, 21, 26},
                    {30, 34, 43, 50} }
        x = 42
Output : -1

*/

#include <bits/stdc++.h>
using namespace std;

void searchIn2DMatrix(vector<vector<int>> &A , int target)
{
    int m = A.size();
    int n = A[0].size();

    int lowR,highR,lowC,highC,midR,midC;
    lowR=0;lowC=0;
    highR=m-1;
    highC=n-1;
    midC=lowC+(highC-lowC)/2;
    while((lowR+1)< highR){
	midR=lowR+(highR-lowR)/2;
	if(A[midR][midC] == target)
	    {
	    cout << "Found at (" <<midR<<", "<<midC<<")\n";return ;
	    }
	else if(A[midR][midC] < target){
	    lowR=midR;
	}
	else{
	    highR=midR;
	}
    }


}







int main() {
  // int m, n ;
  // cin >> m >> n;
  int target = 21;
  vector<vector<int>> A{{1, 5, 9, 11}, {14, 20, 21, 26}, {30, 34, 43, 50}};

  searchIn2DMatrix(A, target);
  //  r ? cout << "found\n\n" : cout << "not found\n\n";
  return 0;
}
