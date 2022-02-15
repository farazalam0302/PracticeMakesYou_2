/*

There have two integer ordered queue(value from small to big), please merge this
two queues to one ordered queue. struct Queue
{
int* pData;
int nLen;
}

Queue* MergeQueue(Queue* pQ1,Queue* pQ2)
{

};

// example: pQ1 ={ { 1, 5}, 2}, pQ2 = {{2,3,6}, 3}, result will be: { {
1,2,3,5,6}, 5}.

*/

/*
 */
#include <bits/stdc++.h>
using namespace std;

struct Queue {
  int* pData;
  int nLen;
};

void printQueue(Queue* r) {
  for (int i = 0; i < r->nLen; i++) cout << (r->pData)[i] << " ";
  cout << "\n size = " << r->nLen << endl;
}
void merge(Queue* r1, Queue* r2) {
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;

  printQueue(r1);
  printQueue(r2);

  Queue* Ret = new Queue();
  int n = r1->nLen + r2->nLen;

  cout << "n = " << n << endl;

  Ret->pData = new int[n];

  Ret->nLen = n;
  while (i < r1->nLen && j < r2->nLen) {
    if ((r1->pData)[i] < (r2->pData)[j]) {
      (Ret->pData)[k] = (r1->pData)[i];
      k++;
      i++;
    }
    if ((r1->pData)[i] > (r2->pData)[j]) {
      (Ret->pData)[k] = (r2->pData)[j];
      k++;
      j++;
    }
  }
  while (i < r1->nLen) {
    (Ret->pData)[k] = (r1->pData)[i];
    i++;
    k++;
  }
  while (j < r2->nLen) {
    (Ret->pData)[k] = (r2->pData)[j];
    j++;
    k++;
  }

  printQueue(Ret);
}

int main() {
  Queue* r1 = new Queue();
  Queue* r2 = new Queue();
  r1->pData = new int[2];
  r2->pData = new int[3];

  r1->pData[0] = 1;
  r1->pData[1] = 4;
  r1->nLen = 2;

  r2->pData[0] = 2;
  r2->pData[1] = 3;
  r2->pData[2] = 5;
  r2->nLen = 3;

  merge(r1, r2);

  //  printQueue(ret);

  return 0;
}
