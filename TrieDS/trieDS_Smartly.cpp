/**************
 *
 * links : https://www.geeksforgeeks.org/trie-insert-and-search/
 *
 * https://medium.com/basecs/trying-to-understand-tries-3ec6bede0014
 *
 *
 * */
#include <bits/stdc++.h>
#include <memory>
#define ALPHABETS 256
using namespace std;
class Trie {

public:
  bool insert(const string &s) {
    auto *p = root.get();
    for (char c : s) {
      if (p->leaves.find(c) == p->leaves.cend()) {
        p->leaves[c] = make_unique<TrieNode>(TrieNode());
      }
      p = p->leaves[c].get();
    }
    // s already existed in this trie
    if (p->isString) {
      return false;
    } else {
      p->isString = true;
      return true;
    }
  }

  string GetShortestUniquePrefix(const string &s) {
    auto *p = root.get();
    string prefix;
    for (char c : s) {
      prefix += c;
      if (p->leaves.find(c) == p->leaves.cend()) {
        return prefix;
      }
      p = p->leaves[c].get();
    }
    return {};
  }

private:
  struct TrieNode {
    bool isString = false;
    unordered_map<char, unique_ptr<TrieNode>> leaves;
  };
  unique_ptr<TrieNode> root = make_unique<TrieNode>(TrieNode());
};

string FindShortestPrefix(const string &s, const unordered_set<string> &D) {
  Trie T;
  for (const string &word : D) {
    T.insert(word);
  }
  return T.GetShortestUniquePrefix(s);
}

int main() {
  unordered_set<string> Sett{"the", "a",  "there", "answer",
                             "any", "by", "bye",   "their"};
  cout << "result = " << FindShortestPrefix("ther", Sett) << endl;
  return 0;
}
