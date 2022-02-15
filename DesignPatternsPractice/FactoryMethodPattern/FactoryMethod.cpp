#include <bits/stdc++.h>
using namespace std;

enum VehicleType { VT_TwoWheeler, VT_ThreeWheeler, VT_FourWheeler };

class Vehicle {
 public:
  virtual void printVehicle() = 0;
  static Vehicle* Create(VehicleType type);
};

class TwoWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "\nTwo Wheeler hun main!!!\n" << endl; }
};

class ThreeWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "\nThree Wheeler hun main!!!\n" << endl; }
};

class FourWheeler : public Vehicle {
 public:
  void printVehicle() { cout << "\nFour Wheeler hun main!!!\n" << endl; }
};

Vehicle* Vehicle::Create(VehicleType type) {
  if (type == VT_TwoWheeler)
    return new TwoWheeler();
  else if (type == VT_ThreeWheeler)
    return new ThreeWheeler();
  else if (type == VT_FourWheeler)
    return new FourWheeler();
  else
    return NULL;
}

// Client class
class Client {
 public:
  // Client doesn't explicitly create objects
  // but passes type to factory method "Create()"
  Client() {
    VehicleType type = VT_ThreeWheeler;
    pVehicle = Vehicle::Create(type);
  }
  ~Client() {
    if (pVehicle) {
      delete[] pVehicle;
      pVehicle = NULL;
    }
  }
  Vehicle* getVehicle() { return pVehicle; }

 private:
  Vehicle* pVehicle;
};

// Driver program
int main() {
  Client* pClient = new Client();
  Vehicle* pVehicle = pClient->getVehicle();
  pVehicle->printVehicle();
  return 0;
}
