/*
There are two singly linked lists of size N and M in a system. But, due to some
programming error the end node of one of the linked list got linked into one of
the node of second list, forming a inverted Y shaped list. Write a program to
get the point where two linked lists intersect each other.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection
point. Note: Expected time complexity is O(m + n) where m and n are lengths of
two linked lists.

Input:
First line of input is the number of test cases T. Every test case has four
lines. First line of every test case contains three numbers, x (number of nodes
before merge point in 1st list), y (number of nodes before merge point in 11nd
list) and z (number of nodes after merge point). Next three lines contain x, y
and z values.

Output:
Print the data of the node in the linked list where two linked lists intersects.

Your Task:
The task is to complete the function intersetPoint() which finds the point of
intersection of two linked list. The function should return data value of a node
where two linked lists merge. If linked list do not merge at any point, then it
shoudl return -1.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= value <= 1000

Example:
Input:
2
2 3 2
10 20
30 40 50
5 10
2 3 2
10 20
30 40 50
10 20

Output:
5
10

Explanation:
Testcase 1: The point of intersection of two linked list is 5, means both of
them get linked (intersects) with each other at node whose value is 5.
 


** For More Input/Output Examples Use 'Expected Output' option **
Contributor: Amit Khandelwal
Author: kartik

*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  bool visited;
  // static Node *lastNode;
  Node() {
    data = 0;
    next = nullptr;
    visited = false;
    // lastNode = this;
  }
  Node(int n, Node *d) {
    data = n;
    next = d;
    visited = false;
    // lastNode = this;
  }
};

Node *LastNodeOf1 = NULL;
Node *LastNodeOf2 = NULL;
Node *LastNodeOf3 = NULL;
void pushAtStarting(Node **h, int data) {
  if (*h == NULL) {
    *h = new Node(data, nullptr);
    return;
  }
  Node *newNode = new Node(data, *h);
  *h = newNode;
  return;
}
void insert(Node **h, int data, int serNo) {
  if (*h == NULL) {
    *h = new Node(data, nullptr);
    if (serNo == 1)
      LastNodeOf1 = *h;
    else if (serNo == 2)
      LastNodeOf2 = *h;
    else if (serNo == 3)
      LastNodeOf3 = *h;
    return;
  }
  Node *newNode = new Node(data, nullptr);
  Node *he = *h;

  // if ((*h)->lastNode) {
  //   ((*h)->lastNode)->next = newNode;
  // ((*h)->lastNode) = newNode;
  // }

  while (he->next) {
    he = he->next;
  }

  he->next = newNode;
  if (serNo == 1)
    LastNodeOf1 = newNode;
  else if (serNo == 2)
    LastNodeOf2 = newNode;
  else if (serNo == 3)
    LastNodeOf3 = newNode;
}

void displayList(Node *head) {
  // print linked list
  Node *scanner = head;
  int timeout = 60;
  while (scanner && timeout) {
    cout << scanner->data << "->";
    scanner = scanner->next;
    timeout--;
  }
  cout << "NULL" << endl;
  // print linked list
}

int LL_length(Node *h) {
  if (!h)
    return 0;
  Node *itr = h;
  int k = 0;
  while (itr) {
    k++;
    itr = itr->next;
  }
  return k;
}

int y_intesectPointOf_flagDS_Method(Node *h1, Node *h2) {
  if (!h1 || !h2)
    return -1;
  // traverse h1
  Node *itr = h1;
  while (itr) {
    itr->visited = true;
    itr = itr->next;
  }
  itr = h2;
  while (itr) {
    if (itr->visited)
      return itr->data;
    itr = itr->next;
  }

  return -1;
}

int y_intesectPointOf_hashMapMethod(Node *h1, Node *h2) {
  if (!h1 || !h2)
    return -1;
  // traverse h1
  unordered_map<Node *, int> mmap;
  Node *itr = h1;
  while (itr) {
    mmap[itr] = 1;
    itr = itr->next;
  }
  itr = h2;
  while (itr) {
    if (mmap.find(itr) != mmap.end()) {
      return mmap.find(itr)->first->data;
    }
  }
  return -1;
}

int y_intesectPointOf_cycleMethod(Node *h1, Node *h2) {
  if (!h1 || !h2)
    return -1;
  // traverse h1
  Node *it1 = h1;
  Node *it2 = h2;
  Node *lastNode1 = NULL;
  int len = 0;
  while (it1->next) {
    len++;
    it1 = it1->next;
  }
  lastNode1 = it1;
  len++;
  int lentmp = len;
  it1->next = h1;
  while (len--) {
    it2 = it2->next;
  }

  Node *n2 = h2;
  while (n2 != it2 && lentmp-- && n2 && it2) {
    n2 = n2->next;
    it2 = it2->next;
  }
  if (!n2)
    return n2->data;
  else
    return -1;
}

int y_intesectPointOf_lengthMethod(Node *h1, Node *h2) {
  if (!h1 || !h2)
    return -1;
  // traverse h1
  Node *itr1;
  Node *itr2;
  int len1 = LL_length(h1);
  int len2 = LL_length(h2);
  int diff = abs(len1 - len2);
  if (len1 < len2) {
    itr1 = h2;
    itr2 = h1;
    while (itr1 && diff) {
      itr1 = itr1->next;
      diff--;
    }

    while (itr1 && itr2 && itr1 != itr2) {
      itr1 = itr1->next;
      itr2 = itr2->next;
    }
    if (itr1 == itr2) {
      return itr1->data;
    }

  } else {
    itr1 = h1;
    itr2 = h2;
    while (itr1 && diff) {
      itr1 = itr1->next;
      diff--;
    }
    while (itr1 && itr2 && itr1 != itr2) {
      itr1 = itr1->next;
      itr2 = itr2->next;
    }
    if (itr1 == itr2) {
      return itr1->data;
    }
  }

  return -1;
}
Node *ReverseLinkedList(Node *head) {
  if (!head || !(head->next))
    return head;
  Node *prev = NULL;
  Node *curr = head;
  Node *nextt = NULL;
  while (curr) {
    nextt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextt;
  }
  return prev;
}

Node *ReverseLinkedListMtoN(Node *head, int m, int n) {
  if (!head || !(head->next))
    return head;
  Node *prev = NULL;
  Node *curr = head;
  Node *nextt = NULL;
  Node *beg = nullptr;
  Node *end = nullptr;
  Node *cont = nullptr;
  int k = n - m + 1;
  m--;
  while (m > 0 && curr) {
    prev = curr;
    curr = curr->next;
    m--;
  }
  cont = prev;
  beg = curr;

  while (k > 0 && curr) {
    nextt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextt;
    k--;
  }

  cont->next = prev;
  beg->next = curr;

  return head;
}
Node *rotate(Node *head, int k) {
  if (!head || !head->next)
    return head;
  Node *headold = head;
  Node *curr = head;
  Node *prev = NULL;
  Node *KthNode = NULL;
  Node *LastNode = NULL;
  int i = 1;
  while (curr->next) {
    if (i == k) {
      KthNode = curr;
    }
    prev = curr;
    curr = curr->next;
    i++;
  }
  LastNode = curr;
  LastNode->next = headold;
  headold = KthNode->next;
  KthNode->next = NULL;
  return headold;
}

int detectloop(Node *head) {

  if (!head || !head->next)
    return 0;
  Node *slow = head;
  Node *fast = head;

  while (fast && fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      return 1;
    }
  }
  return 0;
}

Node *RemoveLoopFromLinkList(Node *head) {
  if (!head || !head->next)
    return head;
  unordered_map<Node *, Node *> mymap;
  Node *curr = head;
  Node *prev = NULL;
  while (curr) {
    if (mymap.find(curr) == mymap.end()) {
      mymap.insert(make_pair(curr, curr));
    } else {
      prev->next = NULL;
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  return head;
}

int main() {

  int t;
  t = 1;
  // cin >> t;
  int x, y, z, tmp;
  while (t--) {
    // cin >> x;
    // cin >> y;
    // cin >> z;
    // list X
    x = 10;
    Node *head1 = NULL;
    for (int i = 0; i < x; i++) {
      // cin >> tmp;

      // insert(&head1, i + 1, 1);
      pushAtStarting(&head1, i + 1);
    }
    cout << "---------------1-------------" << endl;
    displayList(head1);

    Node *s = head1;
    int c;
    cout << "want cicle in linked list at node number ??" << endl;
    cin >> c;
    if (c > 0) {
      c--;
      Node *tmp = head1;
      while (c--) {
        tmp = tmp->next;
      }
      s = tmp;
      while (tmp->next) {
        tmp = tmp->next;
      }
      tmp->next = s;
    }

    cout << "---------------2-------------" << endl;
    displayList(head1);

    if (detectloop(head1))
      cout << "True" << endl;
    else
      cout << "False" << endl;
    // RemoveLoopFromLinkList

    cout << "--------------End-------------" << endl;
    displayList(RemoveLoopFromLinkList(head1));

    // Node *head2 = NULL;
    // for (int i = 0; i < y; i++) {
    //   cin >> tmp;
    //   insert(&head2, tmp, 2);
    // }
    // Node *head3 = NULL;
    // for (int i = 0; i < z; i++) {
    //   cin >> tmp;
    //   insert(&head3, tmp, 3);
    // }
    // cout << "---------------1-------------" << endl;
    // displayList(head1);

    // cout << "---------------2-------------" << endl;
    // displayList(head2);
    // cout << "---------------3-------------" << endl;
    // displayList(head3);

    // LastNodeOf1->next = head3;
    // LastNodeOf2->next = head3;

    // cout << "---------------1-------------" << endl;
    // displayList(head1);
    // cout << "---------------2-------------" << endl;
    // displayList(head2);
    // cout << "---------------3-------------" << endl;
    // displayList(head3);

    // cout << "result of intesection flag Method = "
    //      << y_intesectPointOf_flagDS_Method(head1, head2) << endl;

    // cout << "result of intesection lengthMethod= "
    //      << y_intesectPointOf_lengthMethod(head1, head2) << endl;

    // cout << "result of intesection hashMap method= "
    //      << y_intesectPointOf_hashMapMethod(head1, head2) << endl;

    // cout << "result of intesection flag Method = "
    //      << y_intesectPointOf_flagDS_Method(head1, head2) << endl;

    // cout << "result of intesection Cycle Method = "
    //      << y_intesectPointOf_cycleMethod(head1, head2) << endl;

    // cout << y_intesectPointOf_lengthMethod(head1, head2) << endl;

    // cout << "result of intesection hashMap method= "
    //      << y_intesectPointOf_hashMapMethod(head1, head2) << endl;

    // cout << "length of 1 = " << LL_length(head1) << endl;
  }

  return 0;
}