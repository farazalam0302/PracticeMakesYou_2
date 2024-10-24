/*
https://leetcode.com/problems/fruit-into-baskets/description/

You are visiting a farm that has a single row of fruit trees arranged from left
to right. The trees are represented by an integer array fruits where fruits[i]
is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some
strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit.
There is no limit on the amount of fruit each basket can hold. Starting from any
tree of your choice, you must pick exactly one fruit from every tree (including
the start tree) while moving to the right. The picked fruits must fit in one of
your baskets. Once you reach a tree with fruit that cannot fit in your baskets,
you must stop. Given the integer array fruits, return the maximum number of
fruits you can pick.



Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length

SOLUTION INSIGHTS


ntuition
The problem is essentially about finding the longest subarray with at most two
distinct elements. This can be thought of as a sliding window problem where we
expand the window as long as we have two or fewer types of fruits, and shrink it
when we have more than two types. This ensures that we are collecting the
maximum number of fruits while adhering to the constraint of only having two
baskets.

Approach
We use the sliding window technique with two pointers, left and right, to
maintain the window of trees (fruits) we are considering. We use an unordered
map (mmap) to track the count of each fruit type in the current window. Start
with both left and right at 0, and expand the window by moving right to the
right. Add the current fruit (at right) to the map. If the map contains more
than 2 unique fruits, start shrinking the window by moving the left pointer to
the right until we are back to 2 or fewer types of fruits. Track the maximum
length of the window that contains at most 2 distinct fruit types. Return the
maximum length as the result. Complexity Time complexity: The time complexity is
O(n), where n is the number of trees (fruits). Both the left and right pointers
traverse the array exactly once, and operations on the unordered map take
constant time on average.

Space complexity:
The space complexity is O(1), as the unordered map can hold at most 2 fruit
types at any time, and this is constant. The only additional space used is for
storing the fruit types in the map, which is limited to 2.

If you found this explanation helpful, please consider upvoting! Your support
encourages me to continue contributing clear and easy-to-understand solutions.
Thank you and happy coding! 😊

Code


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    unordered_map<int, int> mmap;
    int left{0};
    int right{0};
    int maxlen{0};

    while (right < fruits.size()) {
      mmap[fruits[right]]++;
      if (mmap.size() <= 2) {
        maxlen = max(maxlen, right - left + 1);
      }

      else {
        while (mmap.size() > 2) {
          mmap[fruits[left]]--;
          if (mmap[fruits[left]] == 0) {
            mmap.erase(fruits[left]);
          }
          left++;
        }
      }
      right++;
    }

    return maxlen;
  }
};

int main(int argc, char const *argv[]) {

  /* code */
  Solution s;
  vector<int> a{1, 2, 1};
  vector<int> b{0, 1, 2, 2};
  vector<int> c{1, 2, 3, 2, 2};
  cout << s.totalFruit(a) << endl;
  cout << s.totalFruit(b) << endl;
  cout << s.totalFruit(c) << endl;
  return 0;
}
