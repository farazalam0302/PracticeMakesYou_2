/*
Given a sequence of words, print all anagrams together | Set 1
Given an array of words, print all anagrams together. For example, if the given
array is {"cat", "dog", "tac", "god", "act"}, then output may be "cat tac act
dog god".


6
qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789_
poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ0123456789_
qazwsxedcrfvtgbyhnujmikolpQAZWSXEDCRFVTGBYHNUJMIKOLP0123456789_
qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMpoiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ0123456789_
0123456789poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZqazwsxedcrfvtgbyhnujmikolpQAZWSXEDCRFVTGBYHNUJMIKOLP_
qazwsxedcrfvtgbyhnujmikolpQAZWSXEDCRFVTGBYHNUJMIKOLPpoiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ0123456789_



*/

#include <bits/stdc++.h>
using namespace std;

void groupByAnaGrams(vector<string> &s) {
  int sSize = s.size();
  unordered_map<uint64_t, vector<string>> mmap;
  uint64_t mask = 0;
  uint64_t key = 0;
  uint64_t len = 0;
  uint64_t temp;
  for (auto i : s) {
    mask = 0;
    len = i.length();

    for (int j = 0; j < len; j++) {

      if (i[j] >= 'a' && i[j] <= 'z') {
        mask = mask | (1L << (i[j] - 'a'));
        continue;
      } else if (i[j] >= 'A' && i[j] <= 'Z') {
        temp = (1L << (i[j] - 'A' + 26));
        mask = mask | temp;
        continue;
      } else if (i[j] >= '0' && i[j] <= '9') {
        temp = (1L << (i[j] - '0' + 26 + 26));
        mask = mask | temp;
      } else if (i[j] == '_') {
        temp = (1L << (62));
        mask = mask | temp;
      }
      // else if (i[j] == '-') {
      //   temp = (1L << (63));
      //   mask = mask | temp;
      // }
      else {
        cout << i
             << " is Bad Character string!! \nString must be (a-zA-Z0-9)+ Regex"
             << endl;
        exit(EXIT_FAILURE);
      }
    }
    key = mask + len;
    if (mmap.find(key) == mmap.end()) {
      mmap[key].push_back(i);
    } else {
      mmap[key].push_back(i);
    }
    mask = mask ^ mask;
  }
  int count = 1;
  cout << "sno "
       << " | "
       << "keyVal"
       << "\n";
  for (auto i : mmap) {
    cout << count << " | " << hex << i.first << " -> ";
    for (auto j : i.second) {
      cout << j << " ";
    }
    cout << endl;
    count++;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {

  //{"cat", "dog", "tac", "god", "act"}

#if 0 // its commented 
  vector<string> s{"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM",
                   "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm",
                   "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0010"};
#endif

  int n;
  cin >> n;
  vector<string> s(n, "");
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  groupByAnaGrams(s);

  //   unordered_map<int, vector<string>> mmap;// key -> list of similar strings
  /***
   * key = Mask + length(eachString)
   * Mask(64 bit long) represents 0-55 bits maps to alphabets a-zA-Z
   */

  cout << endl;
  return 0;
}
