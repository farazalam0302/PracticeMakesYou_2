// priority_queue::emplace
#include <bits/stdc++.h>
using namespace std;



int main ()
{
  std::priority_queue<int,vector<int>,less<int>> mypq ;

  mypq.emplace(1);
  mypq.emplace(2);
  mypq.emplace(3);
  mypq.emplace(4);
  

  std::cout << "mypq contains:";
  while (!mypq.empty())
  {
     std::cout << ' ' << mypq.top();
     mypq.pop();
  }
  std::cout << '\n';

  return 0;
}