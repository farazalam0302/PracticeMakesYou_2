#include <bits/stdc++.h>
using namespace std;
bool isValidMove(vector<string>& b, int x, int y) {
  int m = b.size();
  int n = b[0].size();
  if (x >= 0 && x < m && y >= 0 && y < n) {
    if (b[x][y] == '#') {
      return true;
    }
  }
  return false;
}
void dfs(vector<string>& b, int x, int y, vector<vector<bool>>& visited,
         int* count) {
  if (!isValidMove(b, x, y)) {
    //    visited[x][y] = true;
    return;
  }
  if (visited[x][y]) return;

  //  if (b[x][y] == '#')
  (*count) = (*count) + 1;
  visited[x][y] = true;

  dfs(b, x - 1, y, visited, count);
  dfs(b, x + 1, y, visited, count);
  dfs(b, x, y - 1, visited, count);
  dfs(b, x, y + 1, visited, count);
}

vector<int> solution(vector<string>& b) {
  int m = b.size();
  int n = b[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, 0));
  int count = 0;
  vector<int> R(3, 0);
  for (int i = 0; i < m; ++i) {
    //    count = 0;
    for (int j = 0; j < n; ++j) {
      count = 0;
      dfs(b, i, j, visited, &count);
      //      cout << "count  = " << count << endl;
      if (count >= 3) {
        R[2] = R[2] + count / 3;
        count = count % 3;
      }
      if (count >= 2) {
        R[1] = R[1] + count / 2;
        count = count % 2;
      }
      if (count == 1) {
        R[0] = R[0] + 1;
        //        	        count=count%2;
      }
    }
  }

  return R;
}

void printVector(vector<int> container) {
  for (auto i : container) {
    cout << i << ", ";
  }
  cout << endl;
}

int main() {
  vector<int> R;
  // clang-format off
  vector<string> i1 {
	  ".##.#",
	  "#.#..",
	  "#...#",
      "#.##."
  };
  vector<string> i2 {
  	  ".#.#.",
  	  "#.#.#",
  	  ".#.#.",
      "#.#.#"
    };
  vector<string> i3 {
    	  ".#..#",
		  "##..#",
		  "...#."
      };
  vector<string> i4 {
      	  "##.",
  		  "#.#",
  		  ".##"
        };
  vector<string> i5 {
      	  "...",
		  "...",
		  "..."
        };

  vector<string> i6 {
    	  ".#.#.",
    	  "#####",
		  ".#.#."
		      	  };

 //   clang-format on


  cout << " example i1 " << endl;
  R = solution(i1);
  printVector(R);
  cout << " example i2 " << endl;
  R = solution(i2);
  printVector(R);
  cout << " example i3 " << endl;
  R = solution(i3);
  printVector(R);
  cout << " example i4 " << endl;
  R = solution(i4);
  printVector(R);
  cout << " example i5 " << endl;
  R = solution(i5);
  printVector(R);

  cout << " example i6 " << endl;
    R = solution(i6);
    printVector(R);
  return 0;
}
