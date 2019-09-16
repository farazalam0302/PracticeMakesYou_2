#include <bits/stdc++.h>
using namespace std;


class hNode
{
    public : 
        
        int val;
        int rowNo;
        int colNo;
        hNode(int v=0 , int r=0, int c=0)
        {
            val = v;
            rowNo = r;
            colNo = c;
        }

};

class MyComp
{
public:
    bool operator () (const hNode &l,const hNode &r) const
    {
        return (l.val > r.val);
    }
};



int kthSmallest(vector<vector<int>> &a ,int k)
{
// if (a.empty()) return NULL;

int m = a.size();
int n = a[0].size();
priority_queue<hNode,vector<hNode>,MyComp> pq;

// build or populate P_Q with first row of matrix

int c =0 ;
for (auto i : a[0] )
{
    // hNode hn = {i,0,c};
    pq.emplace(i,0,c);
    c++;
    // pq.push(hn);
}
hNode thn;
for (int i = 0; i < k; i++)
{
    thn = pq.top();
    int next;
    if (thn.rowNo < m-1)
    {
        //thn = { a[thn.rowNo+1][thn.colNo], thn.rowNo+1, thn.colNo };
        pq.pop();
        pq.emplace(a[thn.rowNo+1][thn.colNo], thn.rowNo+1, thn.colNo);
    }
    else {
        pq.pop();
        pq.emplace(INT_MAX, thn.rowNo+1, thn.colNo);
    }
}
int ret  = pq.top().val;


return ret;
    
}

int main() {
    // int a[4][4] = {
    //     {1,2,3,4},
    //     {2,3,4,5},
    //     {3,4,5,6},
    //     {4,5,6,7}
    // };
    int a [3][3] =  {
                        {1,5,9},
                        {10,11,13},
                        {12,13,15}
                    };
    
    vector<vector<int>> b ;
    for (int i =0 ; i < 3 ; i++)
    {
        vector <int> t (a[i],a[i]+3);
        b.push_back(t);
    }
    vector <int> ser;
    for (auto i : b)
    {
        for (auto j : i)
        ser.push_back(j);
    }
    sort(ser.begin(),ser.end());


     int k ;
     cin >> k ; 
    
    int res = kthSmallest(b,k);
    
    cout << k << "th Smallest = " << res << endl;
    
    	return 0;
}
