

/*
 * Median of two sorted arrays of same size

 Difficulty Level : Hard
 Last Updated : 06 Jul, 2022

 There are 2 sorted arrays A and B of size n each. Write an algorithm to find
 the median of the array obtained after merging the above 2 arrays(i.e. array of
 length 2n). The complexity should be O(log(n)).

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

// 1,2,3 //A 1      L -> 5
// 4 //A 2

// 4 5 6 6 7 8 9 10 22 33
//*

/*

     LHeap                           Rheap
                                    2
                                     4
   3                                   5
1


// median (L.top + R.top) /2
// #Lheap > #Rheap // median =- top(Lheap)
//





*/
#include <bits/stdc++.h>
using namespace std;

void populatePQs(priority_queue<int> &Lmax,
                 priority_queue<int, vector<int>, greater<int>> &Rmin,
                 vector<int> &a, int &median) {

  int i = 0;
  if (Lmax.empty()) {
    Lmax.push(a[0]);
    median = a[0];
    i = 1;
  }
  int nA = a.size();
  for (; i < nA; i++) {
    int x = a[i];
    if (Lmax.size() > Rmin.size()) {
      if (x < median) {
        Rmin.push(Lmax.top());
        Lmax.pop();
        Lmax.push(x);

      } else {
        Rmin.push(x);
      }
      median = (Lmax.top() + Rmin.top()) / 2;
    } else if (Lmax.size() == Rmin.size()) {
      if (x < median) {
        Lmax.push(x);
        median = Lmax.top();

      } else {
        Rmin.push(x);
        median = Rmin.top();
      }
    } else {
      if (x < median) {
        Lmax.push(x);

      } else {
        Lmax.push(Rmin.top());
        Rmin.pop();
        Rmin.push(x);
      }
      median = (Lmax.top() + Rmin.top()) / 2;
    }
  }
}

int median(vector<int> &a) {
  int n = a.size();
  if (n & 0x1) {
    int idx = n / 2 + 1;
    return a[idx];
  } else {
    return ((a[n / 2] + a[n / 2 + 1]) / 2);
  }
}

int OlognSoln_median(vector<int> &a, vector<int> &b) {
  int nA = a.size();
  int nB = b.size();
  int mA = median(a);
  int mB = median(b);
  if (mA == mB)
    return mA;
  else if (mA < mB)
}

int main(int argc, char const *argv[]) {

  vector<int> a{5, 6, 7, 9};
  vector<int> b{4, 6, 8, 10};
  // 4 5 6 6 7 8 9 10

  priority_queue<int> LmaxHeap;
  priority_queue<int, vector<int>, greater<int>> RminHeap;

  int median;
  populatePQs(LmaxHeap, RminHeap, a, median);
  populatePQs(LmaxHeap, RminHeap, b, median);

  cout << "LmaxHeap = \n";
  while (!LmaxHeap.empty()) {
    cout << LmaxHeap.top() << " ";
    LmaxHeap.pop();
  }
  cout << "\nRminHeap = \n";
  while (!RminHeap.empty()) {
    cout << RminHeap.top() << " ";
    RminHeap.pop();
  }

  cout << "\nmedian = " << median << endl;
  return 0;
}
