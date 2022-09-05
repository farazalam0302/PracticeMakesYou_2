// class A{
//     //
//     ///
////    .
////    . common functionalities
////    .
// public:
//     bool (*funcptr)() ;
//
//
// };

/*
 *  1 3 5 3 1 3 5 7
 *  2
 *  -1 ,<- output
 *  3 , any index found
 *  7
 */
/*
 *  1 2 3 4 6 7 8 9 10
 *
 */

#include <bits/stdc++.h>
#define CONSTANT 5
using namespace std;

class CustomArray {
public:
  int nSize;
  int *back;
  int *buffer;

  CustomArray(int nS) {
    nSize = nS + CONSTANT;
    buffer = new int[nSize];
    back = buffer;
  }

  void push_backk(int x) {
    if (back != buffer + nSize) {
      *back = x;
      back++;
      cout << x << " NO extra Allocation\n";
    } else {
      int nn = nSize + CONSTANT;
      nSize = nn;
      int *newBuffer = new int[nn];
      cout << x << " extra Allocation\n";
      int *ptrNbuf = newBuffer;
      for (int *ptr = buffer; ptr != back; ptr++) {
        *ptrNbuf = *ptr;
        //        ptr++;
        ptrNbuf++;
      }
      back = ptrNbuf;
      *back = x;
      back++;

      delete[] buffer;
      buffer = newBuffer;
    }
  }
  void removeElementAt(int index) {
    if (buffer + index == back - 1) {
      back--;
    }

    else {
      int i = index;
      while (buffer + i != back - 1) {
        buffer[i] = buffer[i + 1];
        i++;
      }
      back--;
    }
  }

  void display() {
    for (int i = 0; buffer + i != back; i++) {
      cout << buffer[i] << ", ";
    }
    cout << endl;
  }
};
/*
 * 1 2 4 5 6 6
 *           back


10 nSize  ->  15 buffer places  1-15  vector
 16 -> buffer -> { newbuffer 16 +  extraspace (10) 26}
                  all elemnets in old_buffer ->  newBuffer (1 -16 --- 26 )
                  delete old buffer  after compying

 }
 *
 *
 */

int main(int argc, char **argv) {

  CustomArray a(10);
  int max = 16;
  for (int i = 1; i <= max; ++i) {
    a.push_backk(i);
  }

  a.display();

  for (int i = 2; i < 8; i++) {
    a.removeElementAt(2);
  }

  a.removeElementAt(3);

  a.display();

  return 0;
}
