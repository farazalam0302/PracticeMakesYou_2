#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data; 
    Node* next; 
    Node():data(0),next(nullptr){}
    Node(int x):data(x),next(nullptr){}
    Node(const Node& cp):data(cp.data){
        next= new Node(*(cp.next));
        cout << "\nCopy Constructor\n" ;
    }
    // Node(Node && cp)
};


class LinkedList {
    public:
    Node* insert(Node*)

};




int main(int argc, char const *argv[])
{
    
    
    return 0;
}
