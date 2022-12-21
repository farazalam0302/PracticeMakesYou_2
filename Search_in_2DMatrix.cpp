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


bool binarySearch(vector<vector<int>>& A,int target,int row,int lowCol,int highCol){
    
 int m = A.size();
 int n = A[0].size();    
 int midc;
 while (lowCol <= highCol){
     midc=lowCol+ (lowCol+highCol)/2;
     if (A[row][midc] == target)
     {
         cout << "TARGET FOUND AT (" << row << ", "<<midc << ")\n" ;
            return true;
     }
     else if (A[row][midc] > target){
         highCol = midc-1;
     }
     else{
         lowCol = midc+1;
     }
         
 }
    return false;

}


bool searchIn2DMatrix(vector<vector<int>>& A,int target)
{
    int m = A.size();
    int n = A[0].size();
    int lr,hr,lc,hc;
    int midc,midr;
    
    lr = 0; hr = m-1;
    lc = 0; hc = n-1;
    midc = lc + (hc-lc)/2;
    while((lr+1)<hr)
    {
        midr = lr+(hr-lr)/2;
        if (A[midr][midc] == target){
            cout << "TARGET FOUND AT (" << midr << ", "<<midc << ")\n" ;
            return true;
        }
        else if(A[midr][midc] > target)
        {
            hr=midr;
        }
        else {
           lr=midr;
        }
    }
    if (A[lr][midc] ==  target){
        cout << "TARGET FOUND AT (" << lr << ", "<<midc << ")\n" ;
            return true;
    }
    else if (A[lr+1][midc] ==  target){
        cout << "TARGET FOUND AT (" << (lr+1) << ", "<<midc << ")\n" ;
            return true;
    }
    else if ( target < A[lr][midc-1] ){
        binarySearch(A,target,lr,0,midc-1);
    }
    else if ( target >= A[lr][midc+1] &&  target <= A[lr][hc] ){
        binarySearch(A,target,lr,midc+1,hc);
    }
    else if ( target <= A[lr+1][midc-1]){
        binarySearch(A,target,lr+1,0,midc-1);
        // binarySearch(vector<vector<int>>& A,int target,int row,int lowCol,int highCol){

    }
    else if ( target > A[lr+1][midc-1]){
        binarySearch(A,target,lr+1,midc-1,hc);
    }
    
       
    return false;
    
}



int main()
{
    //int m, n ;
    //cin >> m >> n;
    int target = 21;
    vector<vector<int>>A { {1, 5, 9, 11},
                           {14, 20, 21, 26},
                           {30, 34, 43, 50}
                         }; 
    
    bool r  = searchIn2DMatrix(A,target);
    r?cout << "found\n\n" : cout << "not found\n\n";
    return 0;
}
