//diameter of a tree
//
//          1
//
//	 2  3
//
//     4   5  6  7
//     8       /9

int height(Tree R);

int diameter(Tree R)
    {
        if (R== null) return 0
        if (R->left == NULL && R->right == NULL) return 0
        if (R->left)
        int l = height(R->left)
        if (R->right)
        int r = height(R->right);

        //return (l+r-1));

    }

   d(1)


   //. reverse linked ll

   /*
    *  1 2 3 4
    *
    */

   Node * reverseLL(Node* head)
       {
       if (head ==  null || head->next ==NULL) return head;

       Node* prev=Null;
       Node* curr  = head;
       Node* nexxt = curr->next;

       while(nexxt){
	   curr->next =  prev ;
	   prev=curr;
	   curr=nexxt;
	   if (!curr)
	   nexxt=curr->next;


       }
       curr -> next = prev;
       return curr;


       }



   int main()
       {
       //Node* head -> 1 2 3 4
       Node* ret = reverseLL(head);

       }
