/*

student
   -> rollNo
   -> rank
   -> supw
   -> extracurricular

create min_heap based on rank > supw > extracurricular  

we will use customised priority_queue comaparator 
*/
#include <bits/stdc++.h> 
using namespace std; 

class student {
public :
    int rollNo;
    int rank;
    char supw; // {A,B,C,D,E}
    // bool extracurricular;

    student (int r=0 , int rankk=0 ,  char s='E')
    {
        rollNo = r ;
        rank = rankk;
        supw = s;
        // extracurricular  = extra; 
    }

};

/*

class MyComp
{
public:
    bool operator () (const hNode &l,const hNode &r) const
    {
        return (l.val > r.val);
    }
};

*/
class MyComp
{
    public : 
    bool operator () (student& lhs , student& rhs)
    {
        if (lhs.rank > rhs.rank){
            return true;
        }
        else if (lhs.rank < rhs.rank){
            return false;
        }
        else if ( lhs.rank == rhs.rank && lhs.supw > rhs.supw){
                return true;
        }
        else if (lhs.rank == rhs.rank && lhs.supw < rhs.supw)
        {
            return false;
        }
        else 
        return lhs.rollNo > rhs.rollNo;
    }
};

bool compFunc(student& lhs , student& rhs)
    {
         if (lhs.rank < rhs.rank){
            return true;
        }
        else if (lhs.rank > rhs.rank){
            return false;
        }
        else if ( lhs.rank == rhs.rank && lhs.supw > rhs.supw){
                return true;
        }
        else if (lhs.rank == rhs.rank && lhs.supw < rhs.supw)
        {
            return false;
        }
        else 
        return lhs.rollNo > rhs.rollNo;        
    }

int main() 
{ 
    int n ; 
    // cin >> n ; // no of students
    auto lambdaCompare = [] (student& lhs , student& rhs)
    {
         if (lhs.rank > rhs.rank){
            return true;
        }
        else if (lhs.rank < rhs.rank){
            return false;
        }
        else if ( lhs.rank == rhs.rank && lhs.supw > rhs.supw){
                return true;
        }
        else if (lhs.rank == rhs.rank && lhs.supw < rhs.supw)
        {
            return false;
        }
        else 
        return lhs.rollNo > rhs.rollNo;        
    };
    // priority_queue <student,vector<student>,MyComp> heap;
    // priority_queue <student,vector<student>,decltype(lambdaCompare)> heap (lambdaCompare);

    priority_queue <student,vector<student>,decltype(&compFunc)> heap (compFunc);

    // int roll,rnk,spw;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> roll >> rnk >> spw;
    //     heap.emplace(roll,rnk,spw);
    // }
heap.emplace(1 ,6, 'E');
heap.emplace(2 ,4, 'A');
heap.emplace(3 ,5, 'B');
heap.emplace(4 ,3, 'A');
heap.emplace(5 ,3, 'B');
heap.emplace(6 ,1, 'A');
heap.emplace(7 ,1, 'C');
heap.emplace(8 ,7, 'A');
heap.emplace(9 ,8, 'B');
heap.emplace(10 ,8, 'A');
student hnode;
for (int i = 0; i < 10; i++)
{
    hnode = heap.top();
    cout << "[ RollNo = " << hnode.rollNo << ", Rank = " << hnode.rank << ", SUPW = " << hnode.supw << " ]" << endl;
    heap.pop();
}


    




	
	return 0; 
} 

