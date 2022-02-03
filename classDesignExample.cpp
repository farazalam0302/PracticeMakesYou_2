#include <bits/stdc++.h>
using namespace std;

class Employee {
 public:
  string name;
  int empId;
  int fixedSalary;
  Employee(string naam, int id, int fixedSalar) {
    name = naam;
    empId = id;
    fixedSalary = fixedSalar;
  }

  virtual void getEmployeeDetails() = 0;
  virtual ~Employee() {}
};

class Worker : public Employee {
 public:
  int leaves;
  Worker(string naam, int id, int fixedSalar, int levs)
      : Employee(naam, id, fixedSalar) {
    leaves = levs;
  }
  double calculatePay() {
    double salary = (30 - leaves) * fixedSalary;
    return salary;
  }

  virtual void getEmployeeDetails() {
    cout << " Name = " << name << endl;
    cout << " Emp ID = " << empId << endl;
    cout << " Salary Pay = " << (calculatePay()) << endl;
  }
};

class Manager : public Employee {
 public:
  int bonus;
  int no_of_projects;
  Manager(string naam, int id, int fixedSalar, int noOfProjects)
      : Employee(naam, id, fixedSalar) {
    bonus = 20000;
    no_of_projects = noOfProjects;
  }
  double calculatePay() {
    double salary = fixedSalary * no_of_projects + bonus;
    return salary;
  }

  virtual void getEmployeeDetails() {
    cout << " Name = " << name << " Managing " << no_of_projects << " projects"
         << endl;
    cout << " Emp ID = " << empId << endl;
    cout << " Salary Pay = " << (calculatePay()) << endl;
  }
};

void getEmployeesDetails(vector<Employee*>& V) {
  for (auto i : V) {
    (i->getEmployeeDetails());
  }
}

int main() {
  vector<Employee*> V;
  V.push_back(new Worker("Varun", 1, 2000, 3));
  V.push_back(new Worker("Pooja", 2, 1800, 6));
  V.push_back(new Manager("Faraz Alam", 3, 100000, 10));
  V.push_back(new Manager("Varun", 4, 20000, 10));

  getEmployeesDetails(V);

  return 0;
}
