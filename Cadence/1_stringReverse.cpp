#include <bits/stdc++.h>
using namespace std;

void reverseString(string &a) {
  char tmp;
  int n = a.size();
  for (int i = 0; i < n / 2; ++i) {

    tmp = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = tmp;
  }
}

int secondMaximum(vector<int> &a) {
  int firstMax = a[0];
  int secondMax;
  int n = a.size();
  if (n <= 1) {
    cout << "Only single Element\n" << endl;
    exit(0);
  }
  //  int count = 1;
  for (int i = 1; i < n; ++i) {

    if (a[i] > firstMax) {
      secondMax = firstMax;
      firstMax = a[i];
    }

    if (a[i] > secondMax && a[i] < firstMax) {
      secondMax = a[i];
    }

    //    if (a[i] == firstMax) {
    //      count++;
    //  }
  }

  //  if (count == n)
  return secondMax;
}

void segregate0s_1s(vector<int> &a) {
  int n = a.size();
  int oneflag = 0;
  int tmp;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      tmp = a[oneflag];
      a[oneflag] = a[i];
      a[i] = tmp;
      oneflag++;
    }
  }
}

void printArray(vector<int> &a) {
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;
}

int main(int argc, char **argv) {
  //  string a = "allam";
  //  cout << "a = " << a << endl;
  //  reverseString(a);
  //  cout << "a = " << a << endl;

  vector<int> a{0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1};
  // {8 ,10 ,9}

  //  cout << "second max = " << secondMaximum(a) << endl;
  printArray(a);
  segregate0s_1s(a);
  printArray(a);
  return 0;
}
