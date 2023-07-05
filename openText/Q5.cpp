// 8   2    3    5    1

//   5    2    4     3

//      3    3     3

//         3    3

//            3

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> a{8, 2, 3, 5, 1};
  //   vector<vector<int>> result
  int n = a.size();
  vector<int> tmp(a.size() - i, 0);
  for (int i = 0; i < n; i++) {

    int k = 0;
    for (int j = i + 1; j < n; j++) {
      tmp[k] = (a[j - 1] + a[j]) / 2;
      k++;
    }
    for (auto &ic : tmp) {
      cout << ic << ", ";
    }

    cout << endl;
  }

  return 0;
}
/*
class A{
private :
 members and functions



publiC:
datamem

functions


friend function (class Object C)
}


class B : protected A{

 friend printData(A& a){

 }

 ptr -> [4 ] @ 1000
 ptr2   /

 delete(ptr2)



static casting
eg: // A B
      (A) B





}


*/