/*
 * [02-Jun 6:14 PM] Faraz Alam

a=11;

[02-Jun 6:14 PM] Faraz Alam

b=21; c=31

[02-Jun 6:15 PM] Pranab Paul

display(); display();

[02-Jun 6:16 PM] Faraz Alam

d1:

a=11; b=21; c=31

d2:

a=12;b=21;c=32;

[02-Jun 6:17 PM] Faraz Alam

d2:

a=12;b=21;c=31

[02-Jun 6:18 PM] Pranab Paul

char * chp = "hello" and char chp[] = "hello"

[02-Jun 6:20 PM] Faraz Alam

char * chp = "hello"

this chp is of nonconst type

it canbe changed dynamically if needed

and char chp[] = "hello"

But Here

chp is of const type always pnt to first charater of string

[02-Jun 6:21 PM] Pranab Paul

chp++ ;  *chp='a';

[02-Jun 6:23 PM] Pranab Paul

Box b1 , b2;

b2 = b1;



Box b1;

Box b2 = b1;



Box b1;

Box b2 (b1);

[02-Jun 6:27 PM] Faraz Alam

class Box {

public:

  Box (Box &b){

//.

.

// initailise all datamemebrs

}

}

[02-Jun 6:29 PM] Faraz Alam

Box (Box b){

[02-Jun 6:31 PM] Pranab Paul

a = b =c;

[02-Jun 6:33 PM] Rajesh Kumar Jain

complex a(1,2);

complex b(3,4);

complex c=a+b;

[02-Jun 6:37 PM] Faraz Alam

Complex& operator +()(complex &a  complex &b){

complex ret;

ret.real = a.real + b.real;

ret.img = a.img + b.img;

return ret;

}



[02-Jun 6:56 PM] Rajesh Kumar Jain

Sum of present ages of A, B and C is 92 years. If 4 years ago, the ratio of
their ages were 1:2:3 respectively, find A’s present age.
 *
 */

// detect a cycle in linked_list

/*
 * class Node{
 * public :
 * int data;
 * Node* next;
 *
 * Node(){
 * data = 0 ;
 * next = nullptr;
 * }
 *
 * Node(int x){
 * data = x ;
 * next = nullptr ;
 * }
 * };
 */

bool detectCycle(Node *Head) {
  if (Head == NULL)
    return true;
  if (Head->next == NULL)
    return true;
  Node *slow = Head;
  Node *fast = Head->next;

  while (fast && fast != slow) {
    slow = slow->next;
    fast = fast->next
  }
}
