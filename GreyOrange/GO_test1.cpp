
// Node{
//	int i;
//	Node * next;
//}

//

/*
 * 1 -> 2->3->4 //
 * 2->1->3->4 //
 *
 *
 *
 *2->1->4->3->null
 *
 */

// Node* pairwise_Swap(Node* head)
//{
//
//	Node *  temp = null;
//	Node* current = head ; // 1
//	Node*  nexxt = current->next ; // 2
//
//	while(current->next){
//		temp  = current; // 1  // 3
// 		current->next  = nexxt-> next; // 1->3  // 3-> null
//		nexxt->next = temp ; // 2->1           //  4-> 3
//		current = temp->next;  // 3 //  4
//		next = current->next; // 4// null
//
//
//	}
//
//
//
//}
/*
 *
 *
 *

sort0san1s(vector<int> & a) {
Int n = a.size();
Int temp;
Flag0  = 0 ;
flag1= n-1;
for(int i = 0; i < n ; i ++ )
{
  If (a[i] == 0 )
  {
    Temp = a[flag0];
    A[flag0] = a[i];
    A[i] = a[flag0];
flag0++;
}

/*
Else If (a[i] == 1 ){
A[flag1] = a[i];
flag1--;

}

*/
//}
//}
//** /
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};

  int n = a.size();
  int temp;
  int flag0 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      //      temp = a[flag0];
      //      a[flag0] = a[i];
      //      a[i] = temp;
      swap(a[flag0], a[i]);
      flag0++;
    }
  }
  cout << endl;
  for (auto i : a) {
    cout << i << ", ";
  }

  cout << endl;

  //
  return 0;
}
