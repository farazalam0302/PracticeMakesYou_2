/*
LL 1 2 3 4 5 6 7 8 9
int k = 3
Group reversal


*/
reverseLL(Node *head) {
  Node *pre = nullptr;
  Node *curr = head;
  Node *nexxt = curr->next;
  while (nexxt) {
    curr->nexxt = prev;
    prev = curr;
    curr = nexxt;
    nexxt = curr->next;
  }
}

Node *LastNode(Node *head) {
  if (!head)
    return head;
  Node *last = head;
  while (last->next) {
    last = last->next;
  }
  return last;
}

reverseKwiseLL(Node *head, int k) {
  Node *prev = nullptr;
  Node *curr = head;
  Node *nexxt = curr->next;
//   while( )
  stack<Node* >mstack
  while (curr )
  {
	for (int i =0 ; i < k ; i++)
	{
		mstack.push(curr)
		curr=curr->next;
	}
	while(!mstack.empty()){
		Node* tmp=mstack.top() 
	}
	
	
  }
}
