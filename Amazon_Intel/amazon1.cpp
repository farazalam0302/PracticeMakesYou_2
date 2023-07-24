#include <bits/stdc++.h>
using namespace std;

bool myCompare(string &left, string &right) {
  return (left.compare(right) < 0);
}

vector<string> getSuspects(vector<string> &a, int threshold) {
  vector<string> ret;
  unordered_map<string, int> mmap;
  for (auto log : a) {
    // cout << log << ",";
    char *word = (char *)log.c_str();
    string sender = strtok(word, " ");
    string receiver = strtok(nullptr, " ");
    // cout << sender << "->>" << receiver << endl;
    if (sender.compare(receiver) == 0) {
      mmap[sender]++;
      continue;
    }
    mmap[sender]++;
    mmap[receiver]++;
  }

  for (auto &i : mmap) {
    // cout << i.first << " --> " << i.second << endl;
    if (i.second >= threshold) {
      ret.push_back(i.first);
    }
  }
  sort(ret.begin(), ret.end(), myCompare);
  return ret;
}

int main(int argc, char const *argv[]) {
  vector<string> logs{"88 99 200", "99 88 300", "32 12 100", "12 32 15"};
  int threshold = 2;
  vector<string> ret;

  ret = getSuspects(logs, threshold);

  cout << "\n\nANSWER = [ ";
  for (auto &i : ret) {
    cout << i << ", ";
  }

  cout << "]" << endl;

  return 0;
}
