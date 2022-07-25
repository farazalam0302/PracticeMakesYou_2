/*
 * to find a particular number where the array is rotated
 *
 *  9 10 1 2 3 4 5 6 7 8
 *
 * output
 */

#include <bits/stdc++.h>
using namespace std;

int *binarySearch(int *front, int *rear, int target) {
  if (front == NULL && rear == NULL)
    return NULL;
  if (front == rear && *front == target)
    return front;
  if (front == rear && *front != target)
    return NULL;
  int *mid = front + ((rear - front)) / 2;

  if (*mid == target)
    return (mid);
  if (*mid > target)
    return binarySearch(front, mid - 1, target);
  if (*mid < target)
    return binarySearch(mid + 1, rear, target);
  return NULL;
}

int *binarySearch_Itr(int *front, int *rear, int target) {
  int n = rear - front + 1;
  int *mid; //= front + (rear - front) / 2;
  while (rear - front > 0) {
    mid = front + (rear - front) / 2;
    if (*mid == target)
      return mid;
    if (*mid > target) {
      rear = mid - 1;
    } else {
      front = mid + 1;
    }
  }
  return NULL;
}

int findPivot(int *a, int front, int rear) {
  if (rear < front)
    return -1;
  if (rear == front)
    return front;
  int mid = front + (rear - front) / 2;
  if (mid < rear && a[mid] > a[mid + 1])
    return mid;
  if (mid > front && a[mid] < a[mid - 1])
    return mid - 1;
  if (a[front] >= a[mid])
    return findPivot(a, front, mid - 1);
  return findPivot(a, mid + 1, rear);
}

int main(int argc, char **argv) {
  int a[11] = {
      8, 9, 10, 0, 1, 2,
      3, 4, 5,  6, 7
      //      0, 1,  2, 3, 4, 5, 6, 7, 8, 9, 10
  };
  int target = 5;
  int *result;
  int pivot;
  pivot = findPivot(a, 0, 10);
  cout << " pivot = " << pivot << endl;

  int n = (sizeof(a) / sizeof(a[0]));
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;

  result = binarySearch(a, a + pivot, target);
  if (result == NULL)
    result = binarySearch(a + pivot + 1, a + 10, target);
  if (result) {
    int index = result - a;
    cout << " index = " << index << endl;
    cout << "a [index] = " << a[index] << endl;
  }

  result = binarySearch_Itr(a + pivot + 1, a + 10, target);
  if (result) {
    int index = result - a;
    cout << " index2 = " << index << endl;
    cout << "a [index2] = " << a[index] << endl;
  }

  return 0;
}
