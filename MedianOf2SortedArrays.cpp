/*
 * Median of two sorted arrays of same size

 Difficulty Level : Hard
 Last Updated : 06 Jul, 2022

 There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)).

 1) Calculate the medians m1 and m2 of the input arrays ar1[]
 and ar2[] respectively.
 2) If m1 and m2 both are equal then we are done.
 return m1 (or m2)
 3) If m1 is greater than m2, then median is present in one
 of the below two subarrays.
 a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
 b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
 4) If m2 is greater than m1, then median is present in one
 of the below two subarrays.
 a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
 b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
 5) Repeat the above process until size of both the subarrays
 becomes 2.
 6) If size of the two arrays is 2 then use below formula to get
 the median.
 Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2

 */

#include <bits/stdc++.h>
using namespace std;
int getMedian (vector<int>& a){
	int n = a.size();
	if (n==0)  return -1;
	if (n == 1)return a[0]
	if(n%2 == 1) {
		return (a[n/2]);
	}
	else
	{
//		int index = n/2+n/2-1
		return ((a[n/2]+a[n/2-1])/2);
}}

int getMedianOfTwoSortedArrays(vector<int> &a1, vector<int> &a2)
{
	int n1  = a1.size();
	int n2  = a2.size();



}

int main(int argc, char **argv) {

	vector<int> a1 { 1, 12, 15, 26, 38 };
	vector<int> a2 { 2, 13, 17, 30, 45 };

	int result;
	result = getMedianOfTwoSortedArrays(a1, a2);
	cout << "Result = " << result << endl;

	return 0;
}
