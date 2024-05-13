/*

 Input : (11,13) (15,20) (22,23) (800 , 1000)
 int k = 0
 user (10-20) //=> (11-13),(15,20)
 user (12-18)
 user (13-35) // (22,23)

*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<pair<int, int>> input{{11, 13}, {15, 20}, {22, 23}, {800, 1000}};
  vector<pair<int, int>> inRange{{10, 20}, {12, 18}, {22, 35}};

  vector<pair<int, int>> result;
  vector < pair<  pair<int,int>* , vector<pair<int, int>>> adjList;

  for (int inRange_i = 0 ;  inRange_i < inRange.size(); inRange_i++ )
  {
for (int i = 0; i < input.size(); i++) {
if (input[i].first >= inRange[inRange_i].first && input[i].first <= inRange[inRange_i].second) {
// result.push_back(input[i]);
adjList.pushback({inRange+inRange_i ,  })
} else if ((input[i].second >= inRange.first &&
input[i].second <= inRange.second)) {
result.push_back(input[i]);
}
}

     
    }

}
//
// 

// for (auto i : result) {
// cout << i.first << ", " << i.second << endl;
// }

//   vector<pair < > vector<pair<int, int> *>> adjList;
// vector<pair<pair<int, int>, vector<pair<int, int>>>> adjList;
/**
 * @brief
 *
 *  (10,20) ->  vector < (11,13) (15,20) >
 *
 *   (12-18) -> vector < (11,13) (15,20) >
 *
 *   (13-35) -> vector < {11, 13}, {15, 20}, {22, 23} >
 *
 * vector <T ,alloactor,  >
 *
 *  vector begin T t t t t tt  t t end
 *
 * v.begin()
 * v.end()
 *
 * v.empty() { v.begin()+1  == v.end() }
 * v.push_back(T2) {
 *   // put value @ v.end()
 *
 *
 * Allocator / alloactes the conatiner
 * capacity = 15
 * vector <int> A ( 10); // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 {16} ...
 * capacity exhausted after copying A will be A's heap loaction must deleted
 *
 * vector <int> A' (25) ;// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 {16} 17 18 b
 * 19 20 21 22 23 24 25 {26} ... capacity 25
 * vector <int> A''(40) 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 {16} 17 18 b 19 20
 *21 22 23 24 25 {26}
 *    * Alloactor alllocates extar heap for upcoming vecctor growth with some
 * Capacity value
 *
 *
 *
 *
 *
 * }
 */
