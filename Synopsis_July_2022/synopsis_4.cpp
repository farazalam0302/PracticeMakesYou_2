#include <bits/stdc++.h>
using namespace std;

class Base
    {
public:
    int data;// 4bytes
    // vptr  ->  vtable  //
    Base()
	{

	cout << "Base construct\n ";
	} //;

      ~Base()
	{
	cout << "Base destruct\n ";

	}
//    virtual f1(){
//	/// some1
//    }

    };

//class Derived1: public Base
//    {
//    //
//public:
//    Derived1()
//	{
//	cout << "Derived1 construct\n ";
//
//	}
//
//    ~Derived1()
//	{
//	cout << "Derived1 destruct\n ";
//
//	}
//
//    };
//
//class Derived2: public Derived1
//    {
//
//public:
//    Derived2()
//	{
//	cout << "Derived2 construct\n ";
//
//	}
//
//    ~Derived2()
//	{
//	cout << "Derived2 destruct\n ";
//
//	}
//
//    };

int main(int argc, char **argv)
    {

    Derived2 *p = new Derived2();

    delete (p);

    Base* pt = new Derived2();
    pt->f1(); //  f1 of derived2


    return 0;
    }
