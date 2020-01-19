/*

https://practice.geeksforgeeks.org/problems/box-stacking/1


Box StackingSubmissions: 10147   Accuracy: 47.66%   Difficulty: Medium   Marks:
4 Associated Course(s):   Must Do Interview Preparation

Problems
You are given a set of N types of rectangular 3-D boxes, where the ith box has
height h, width w and length l. You task is to create a stack of boxes which is
as tall as possible, but you can only stack a box on top of another box if the
dimensions of the 2-D base of the lower box are each strictly larger than those
of the 2-D base of the higher box. Of course, you can rotate a box so that any
side functions as its base.It is also allowable to use multiple instances of the
same type of box. You task is to complete the function maxHeight which returns
the height of the highest possible stack so formed.

Input:
The first line of input contains an integer T denoting the number of test cases
then T test cases follow. Each test case contains an integer N denoting the
total no of boxes available. In the next line are 3*N space separated values
denoting the height, width and length of the N boxes.

Output:
For each test case in a new line output will be the highest possible stack
height which could be formed.

Constraints:
1<=T<=100
1<=N<=100
1<=l,w,h<=100

Example (To be used for expected output) :
Input:
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1

Output
60
15

Note: The Input/Ouput format and Example given are used for system's internal
purpose, and should be used by a user for Expected Output only. As it is a
function problem, hence a user should not read any input from stdin/console. The
task is to complete the function specified, and not to write the full code.

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
using namespace std;

struct Box {
  int l, b, h;
};

bool myCompare(const Box &l, const Box &r) {
  return ((l.b * l.l) > (r.l * r.b));
}

int maxStackHeight(vector<Box> &boxes) {
  int n = boxes.size();
  vector<Box> rotations(3 * n);
  // possible rotations
  int index = 0;
  for (int i = 0; i < n; i++) {
    // copy original box
    rotations[index].h = boxes[i].h;
    rotations[index].b = max(boxes[i].b, boxes[i].l);
    rotations[index].l = min(boxes[i].b, boxes[i].l);
    index++;

    // first rotation

    rotations[index].h = boxes[i].b;
    rotations[index].b = max(boxes[i].h, boxes[i].l);
    rotations[index].l = min(boxes[i].h, boxes[i].l);
    index++;

    // second rotation
    rotations[index].h = boxes[i].l;
    rotations[index].b = max(boxes[i].b, boxes[i].h);
    rotations[index].l = min(boxes[i].b, boxes[i].h);

    index++;
  }

  for (int i = 0; i < 3 * n; i++) {
    cout << rotations[i].l << " " << rotations[i].b << " " << rotations[i].h
         << endl;
  }

  sort(rotations.begin(), rotations.end(), myCompare);
  cout << "\n\n\n aftre sortiing  \n\n" << endl;
  for (int i = 0; i < 3 * n; i++) {
    cout << rotations[i].l << " " << rotations[i].b << " " << rotations[i].h
         << endl;
  }

  vector<int> msh(n, 0);
  for (int i = 0; i < n; i++) {
    msh[i] = rotations[i].h;
  }

  // Optimised stack height calculation

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (rotations[i].l < rotations[j].l && rotations[i].b < rotations[j].b &&
          msh[i] < msh[j] + rotations[i].h)
        msh[i] = msh[j] + rotations[i].h;
    }
  }
  int maxHeight = msh[0];
  for (int i = 0; i < n; i++) {
    maxHeight = max(maxHeight, msh[i]);
  }

  return maxHeight;
}

int main() {

  int N;
  cin >> N; // no of boxes;
  vector<Box> boxes;
  int tmp;
  int l, b, h;
  for (int i = 0; i < N; i++) {
    Box newBox;
    cin >> newBox.l >> newBox.b >> newBox.h;
    boxes.push_back(newBox);
  }
  int res = maxStackHeight(boxes);
  cout << "result = " << res << endl;
  return 0;
}

/**
 *
  4
  4 6 7
  1 2 3
  4 5 6
  10 12 32
 *
 * *////