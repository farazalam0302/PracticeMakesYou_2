#include <bits/stdc++.h>
using namespace std;

class People {
 public:
  int aadhar;

  char* name;
  int salary;
  int growth;
  People() {
    aadhar = 0;
    name = new char(8 * 8);
    salary = 100;
  }

  int getSalary() { cout << "salary = " << (salary + growth) << endl; }
  int getSalary(int bonus) {
    cout << "salary = " << (salary + growth + growth * bonus) << endl;
  }
  ~People() { delete[] name; }
};

class Boss : public People {
  float getSalary(float bonus) {
    cout << "salary = " << (salary + growth + growth * bonus * 10) << endl;
  }
};

int main() {
  People p1, p2;

  Boss b();
  People* p = new Boss();
  p->getSalary(100);

  return 0;
}
