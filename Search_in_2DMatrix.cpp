/*

Given a sorted matrix mat[n][m] and an element ‘x’. Find the position of x in the matrix if it is present, else print -1. Matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= n-1, the first element of row ‘i’ is greater than or equal to the last element of row ‘i-1’. The approach should have O(log n + log m) time complexity.

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

bool binarySearch(vector<vector<int>> &A, int row, int lowC, int highC, int target)
{
    int midC;
    while (lowC <= highC)
    {
        midC = (lowC + highC) / 2;
        if (A[row][midC] == target)
        {
            cout << "FOUND AT (" << row << ", " << midC << ")\n";
            return true;
        }
        else if (A[row][midC] < target)
        {
            lowC = midC + 1;
        }
        else
        {
            highC = midC - 1;
        }
    }
    return false;
}

bool searchIn2DMatrix(vector<vector<int>> &A, int target)
{
    // A is mxn matrix
    int m = A.size();
    int n = A[0].size();
    int lowR, highR, lowC, highC, midC, midR;
    lowR = 0;
    lowC = 0;
    highR = m - 1;
    highC = n - 1;
    midC = lowC + (highC - lowC) / 2;
    while ((lowR + 1) < highR)
    {
        midR = lowR + (highR - lowR) / 2;
        if (A[midR][midC] == target)
        {
            cout << "FOUND AT (" << midR << ", " << midC << ")\n";
            return true;
        }
        else if (A[midR][midC] > target)
        {
            highR = midR;
        }
        else
        {
            lowR = midR;
        }
    }

    lowC = 0;
    highC = n - 1;

    cout << "lowR = " << lowR << endl;

    bool r = binarySearch(A, lowR, 0, n - 1, target);
    if (r)
        return true;
    else
    {
        r = binarySearch(A, lowR + 1, 0, n - 1, target);
    }
    if (r)
        return true;

    return false;
}

void printMatrix(vector<vector<int>> &A)
{

    for (auto i : A)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    // int m, n ;
    // cin >> m >> n;
    int target = -15;
    vector<vector<int>> A{{-11, -9, -5, -1},
                          {1, 5, 9, 11},
                          {14, 20, 21, 26},
                          {30, 34, 43, 50}};

    // while (target){
    // cin >> target;

    printMatrix(A);
    cout << "target = " << target << "\n\n\n"
         << endl;
    bool r = searchIn2DMatrix(A, target);
    r ? cout << " \n\n" : cout << "NOT FOUND\n\n";
    // }
    return 0;
}