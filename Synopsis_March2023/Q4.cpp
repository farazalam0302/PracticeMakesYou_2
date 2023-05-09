// contact
//
// insert(name , mnumber)
// upodate(name , pnumber)
// delete(n)
// display(name,number) // in same order
//
//// a,1  b ,2
//// a,1, b,3

class Contacts {
public:
  string name;
  string mno;
  int timeID;
  map<pair<name, mno>> list;
  list<name>; // A , B, C,
              // list.erase(itr)
              // O (N ) for searching
              // 100000
};
