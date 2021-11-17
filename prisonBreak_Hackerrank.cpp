/*
  Problem Statement
Ninja has been caged up in a prison and he is planning to escape from it. The
prison's gate consists of horizontal and vertical bars that are spaced one unit
apart, so the area of each hole between the bars is (1 * 1). Ninja manages to
remove certain bars and make some of these holes bigger. Your task is to
determine the area of the largest hole in the gate after the bars are removed.
For example, let us consider that the initial prison gate with ‘n’ = 8
horizontal and ‘m’ = 8 vertical bars, where the area of the biggest hole in the
bars is (1 * 1). If we remove the 4th horizontal bar and 6th vertical bar, then
our maximum area will be (2 * 2). Input Format: The first line contains an
integer 'T' which denotes the number of test cases or queries to be run.

The first line of each test case contains two single-space separated integers
‘N’ and ‘M’ denoting the number of horizontal and vertical bars respectively.

The second line of each test case contains a single integer ‘X’ denoting the
number of horizontal bars that can be removed.

The third line of each test case contains ‘X’ space-separated integers in an
array ‘H’ denoting the index of horizontal bars that can be removed.

The fourth line of each test case contains a single integer ‘Y’ denoting the
number of vertical bars that can be removed.

The fifth line of each test case contains ‘Y’ space-separated integers in an
array ‘V’ denoting the index of vertical bars that can be removed. Output
Format: For each case, we need to return the area of the largest hole in the
gate after the bars are removed.

The output of each test case will be printed in a separate line.
Note:
You do not need to input or print anything, and it has already been taken care
of. Just implement the given function. Constraints: 1 <= T <= 5 1 <= N <= 100 1
<= M <= 100 1 <= X <= N 1 <= Y <= M 1 <= |H| <= N 1 <= |V| <= M

Time Limit : 1 sec
Sample Input 1:
2
4 4
3
1 3 4
2
2 3
6 5
2
2 4
2
1 4
Sample Output 1:
9
4
Explanation Of Sample Input 1:
Test case 1:
For the first test case of sample output 1, if we remove horizontal bars ‘3’ and
‘4’, and vertical bars ‘2’ and ‘3’, we get the largest area of (3 * 3) as 9
units.

Test case 2:
For the second test case of sample output 1, if we remove horizontal bars ‘2’,
and vertical bars ‘1’, we get the largest area of (2 * 2) as 4 units. Sample
Input 2:
1
10 10
5
1 2 3 4 6
1
9
Sample Output 2:
10
Explanation Of Sample Input 2:
Test case 1:
For the first test case of sample output 2, if we remove horizontal bars ‘1’ to
‘4’, and vertical bars ‘9’, we get the largest area of (5 * 2) as 10 units.
 */
/*
// solution
Here, to find out the maximum area of a hole, we need a maximum number of
consecutive horizontal bars ‘maxHorizontal’ and a maximum consecutive number of
vertical bars ‘maxVertical’ that are removed. Once, we can find them, as we know
that ‘x’ number of horizontal bars can make ‘x’ + 1 hole free, so using this
concept, our maximum hole area will be ('maxHorizonal' + 1) * ('maxVertical' +
1).



Algorithm:


Declare two boolean arrays ‘boolH’ and ‘boolV’ of size ‘N’ + 1 and ‘M’ + 1
respectively and initialize them as true.

Run a loop ‘i’ = 0 to ‘X’ Set all
those indexes false which are present in array ‘H’. Run a loop ‘i’ = 0 to ‘Y’

Set all those indexes false which are present in array ‘V’.

Declare two variables as ‘localMaxHorizontal’ and ‘globalMaxHorizontal’ and set
them as ‘0’ and minimum ‘-1’. Run a loop ‘i’ = 1 to ‘N’ If ‘boolH’ is true
denoting there exist a bar at this index Set ‘localMaxHorizontal’ as 0 Otherwise

Increase ‘localMaxHorizontal’ by 1

Update ‘globalMaxHorizontal’ with the maximum of ‘globalMaxHorizontal’ and
‘localMaxHorizontal’ Declare two variables as ‘localMaxVertical’ and
‘globalMaxVertical’ and set them as ‘0’ and minimum ‘-1’. Run a loop ‘i’ = 1 to
‘M’ If ‘boolV’ is true denoting there exist a bar at this index Set
‘localMaxVertical’ as 0 Otherwise Increase ‘localMaxVertical’ by 1 Update
‘globalMaxVertical’ with the maximum of ‘globalMaxVertical’ and
‘localMaxVertical’ Return (‘globalMaxHorizontal’ + 1) * (‘globalMaxVertical’ +
1)

*/
