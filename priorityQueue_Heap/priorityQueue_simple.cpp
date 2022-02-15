
/*

student
   -> rollNo
   -> prev
   -> curr
   

create min_heap based on rank > supw > extracurricular  

we will use customised priority_queue comaparator 
*/
#include <bits/stdc++.h> 
using namespace std; 

class student {
public :
    int rollNo;
    int prev;
    int curr; 

    student (int r=0 , int pre=0 ,  int cur=0)
    {
        rollNo = r ;
        prev = pre;
        curr = cur;
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
        if (abs(lhs.prev - lhs.curr)  < abs(rhs.prev - rhs.curr)){
            return true;
        }
        else if (abs(lhs.prev - lhs.curr)  > abs(rhs.prev - rhs.curr)){
            return false;
        }
        else 
        return lhs.rollNo < rhs.rollNo;
    }
};

bool compFunc(student& lhs , student& rhs)
{
        if (abs(lhs.prev - lhs.curr)  < abs(rhs.prev - rhs.curr)){
            return true;
        }
        else if (abs(lhs.prev - lhs.curr)  > abs(rhs.prev - rhs.curr)){
            return false;
        }
        else 
        return lhs.rollNo < rhs.rollNo;
}

int main() 
{ 
    int n ; 
    // cin >> n ; // no of students
    auto lambdaCompare = [] (student& lhs , student& rhs)
   {
        if (abs(lhs.prev - lhs.curr)  < abs(rhs.prev - rhs.curr)){
            return true;
        }
        else if (abs(lhs.prev - lhs.curr)  > abs(rhs.prev - rhs.curr)){
            return false;
        }
        else 
        return lhs.rollNo < rhs.rollNo;
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
heap.emplace( 1 ,100, 1000);
heap.emplace( 2 ,200, 1000);
heap.emplace( 3 ,400, 1000);
heap.emplace( 4 ,300, 1000);
heap.emplace( 5 ,600, 1000);
heap.emplace( 6 ,500, 1000);
heap.emplace( 7 ,900, 1000);
heap.emplace( 8 ,700, 1000);
heap.emplace( 9 ,850, 1000);
heap.emplace(10 ,850, 1000);
student hnode;
for (int i = 0; i < 10; i++)
{
    hnode = heap.top();
    cout << "[ RollNo = " << hnode.rollNo << ", PrevousYearMarks = " << hnode.prev << ", CurrentYearMarks = " << hnode.curr <<
    " PerfDiff = " << abs(hnode.prev - hnode.curr) << " ]" <<  endl;
    heap.pop();
}



	
	return 0; 
}
