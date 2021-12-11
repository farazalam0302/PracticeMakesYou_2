#include <bits/stdc++.h>
using namespace std;

class Vehicle {
 public:
  virtual void printVehicle() = 0;
};

class TwoWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "\nTwo Wheeler hun main!!!\n" << endl; }
};

class FourWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "\nFour Wheeler hun main!!!\n" << endl; }
};

class Client {
 private:
  Vehicle* pVehicle;

 public:
  Client(int type) {
    // Client explicitly creates classes according to type
    if (type == 1)
      pVehicle = new TwoWheeler();
    else if (type == 2)
      pVehicle = new FourWheeler();
    else
      pVehicle = NULL;
  }

  ~Client() {
    if (pVehicle) {
      delete[] pVehicle;
      pVehicle = NULL;
    }
  }

  Vehicle* getVehicle() { return pVehicle; }
};

int main() {
  Client* pClient = new Client(1);
  Vehicle* pVehicle = pClient->getVehicle();
  pVehicle->printVehicle();
  return 0;
}
