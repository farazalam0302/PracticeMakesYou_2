//class A{
//	int a;
//public:
//
//  virtual  int f1();
//
//
//};
//
//class C ;
//class B : protected A
// {
//
//	int b ;
//
//public:
//int f1(int a);//
//C* func(){
//	return new C;
//}
//};
//
//
//class C
//{
//
//};
//
//int main()
//{
//	B*  bptr = new B;
//	B bb;
//
//	B->f1();
//	A* aptr = B;
//
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;

class Base {
public:
	int baseData;
	Base() {
		baseData = 0;

	}
	Base(int d) {
		baseData = d;
	}

	virtual void displayContents() {
		cout << "BaseData = " << baseData << endl;
	}

};



class Child_1 : public Base{
public:
	int childData;
	Child_1(){
		childData = 0;
	}
	Child_1(int f){
		childData = f;
	}

	Child_1(int f, int g){
			childData = f;
			baseData = g;
		}
	void displayContents(){
		cout << "\nData in child\n" << endl;
		cout << "ChildData = " << childData << endl;
		cout << "ChildBaseData = " << baseData << endl;
	}



};



int main(int argc, char **argv) {

	Child_1 c2(100,200);
	c2.displayContents();

	Base  b2 = (Base)c2;

	b2.displayContents();
//	cout << << endl;

cout << "\n-------------------------------------------\n";

	Child_1* c = new Child_1(10,20);

	c->displayContents();

	Base* b = (Base*)c;

	b-> displayContents();


	return 0;
}

