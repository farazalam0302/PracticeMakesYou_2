#include <bits/stdc++.h>
using namespace std;

class TrieNode {
 public:
  TrieNode* childeren[256];
  bool isWordValid;
  TrieNode() {
    isWordValid = false;
    for (auto i : childeren) {
      i = nullptr;
    }
  }
};

void insertWordInTrie(TrieNode* r, string& s) {
  if (s.size() == 0) return;
  TrieNode* crawler = r;
  int index;
  for (auto character : s) {
    index = (int)character;
    if (crawler->childeren[index] == nullptr) {
      crawler->childeren[index] = new TrieNode();
    }
    crawler = crawler->childeren[index];
  }
  crawler->isWordValid = true;
}

bool searchInTrie(TrieNode* r, string s) {
  if (s.size() == 0) return false;
  TrieNode* crawl = r;
  int index;
  for (auto c : s) {
    index = c;
    if (crawl->childeren[index] == nullptr) return false;
    crawl = crawl->childeren[index];
  }
  return (crawl != nullptr && crawl->isWordValid);
}

int main() {
  vector<string> keys{"the", "there", "their"};
  TrieNode* Root = new TrieNode();
  for (auto i : keys) {
    insertWordInTrie(Root, i);
  }
  cout << searchInTrie(Root, "ther");
  return 0;
}
