#if 0
// C++ program for Boggle game
#include <cstring>
#include <iostream>
using namespace std;

#define M 3
#define N 3

// Let the given dictionary be following
string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int n = sizeof(dictionary) / sizeof(dictionary[0]);

// A given function to check if a given string is present in
// dictionary. The implementation is naive for simplicity. As
// per the question dictionary is given to us.
bool isWord(string& str) {
  // Linearly search all words
  for (int i = 0; i < n; i++)
    if (str.compare(dictionary[i]) == 0) return true;
  return false;
}

// A recursive function to print all words present on boggle
void findWordsUtil(char boggle[M][N], bool visited[M][N], int i, int j,
                   string& str) {
  // Mark current cell as visited and append current character
  // to str
  visited[i][j] = true;
  str = str + boggle[i][j];

  // If str is present in dictionary, then print it
  if (isWord(str) | 1) cout << str << endl;

  // Traverse 8 adjacent cells of boggle[i][j]
  for (int row = i - 1; row <= i + 1 && row < M; row++)
    for (int col = j - 1; col <= j + 1 && col < N; col++)
      if (row >= 0 && col >= 0 && !visited[row][col])
        findWordsUtil(boggle, visited, row, col, str);

  // Erase current character from string and mark visited
  // of current cell as false
  str.erase(str.length() - 1);
  visited[i][j] = false;
}

// Prints all words present in dictionary.
void findWords(char boggle[M][N]) {
  // Mark all characters as not visited
  bool visited[M][N] = {{false}};

  // Initialize current string
  string str = "";

  // Consider every character and look for all words
  // starting with this character
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) findWordsUtil(boggle, visited, i, j, str);
}

// Driver program to test above function
int main() {
  char boggle[M][N] = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};

  cout << "Following words of dictionary are present\n";
  findWords(boggle);
  return 0;
}

#endif
#if 1

#include <bits/stdc++.h>
using namespace std;
#define M 3
#define N 3
// std::set<int, decltype(cmp)*> s(cmp);
/*
 * struct lex_compare {
    bool operator() (const int64_t& lhs, const int64_t& rhs) const {
        stringstream s1, s2;
        s1 << lhs;
        s2 << rhs;
        return s1.str() < s2.str();
    }
};
 */

// struct lex_compare {
//  bool operator()(const string& lhs, const string& rhs) const {
//    return lhs == rhs;
//  }
//};
// bool myCompare(string& a, string& b) { return (a == b); }

vector<string> dictionary{"GEEKS", "FOR", "QUIZ", "GO"};
int dictionarySize = dictionary.size();
// all 8 adjacent moves
// vector<int> xMoves{1, 1, 1, 0, 0, 0, -1, -1, -1};
// vector<int> yMoves{-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool isSafeBounded(vector<vector<char>>& boggle, int i, int j) {
  int m = boggle.size();
  int n = boggle[0].size();
  if (i >= 0 && i < m && j >= 0 && j < n) return true;
  return false;
}
bool isWordInDictionary(string& a) {
  for (int i = 0; i < dictionarySize; ++i) {
    if (a.compare(dictionary[i]) == 0) return true;
  }
  return false;
}

bool isWord(string& str) {
  // Linearly search all words
  for (int i = 0; i < dictionarySize; i++) {
    if (str.compare(dictionary[i]) == 0) return true;
  }
  return false;
}

void findWords(char boggle[M][N], bool visited[M][N], int i, int j,
               string& str) {
  visited[i][j] = true;
  str = str + boggle[i][j];
  if (isWord(str)) {
    cout << str << endl;
  }
  //  for (int k = 0; k < 9; ++k) {
  //    if (isSafeBounded(boggle, i + xMoves[k], j + yMoves[k])) {
  //      if (!visited[i + xMoves[k]][j + yMoves[k]]) {
  //        findWords(boggle, visited, i + xMoves[k], j + yMoves[k], str);
  //      }
  //    }
  //  }
  for (int row = i - 1; row < M && row <= i + 1; ++row) {
    for (int col = j - 1; col < N && col <= j + 1; ++col) {
      if (row >= 0 && col >= 0 && !visited[row][col]) {
        findWords(boggle, visited, row, col, str);
      }
    }
  }

  str.erase(str.length() - 1);
  visited[i][j] = false;
}

int main() {
  //  vector<string> wordlist{"GEEKS", "FOR", "QUIZ", "GO"};
  //  for (auto i : wordlist) {
  //    dictionary.push_back(i);
  //  }
  //  vector<vector<char>>
  char boggle[M][N] = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};
  //  int m = boggle.size();
  //  int n = boggle[0].size();
  //  vector<vector<bool>> visited(m, vector<bool>(n, false));
  bool visited[M][N] = {{false}};
  string str = "";
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      findWords(boggle, visited, i, j, str);
    }
  }
  return 0;
}
#endif
