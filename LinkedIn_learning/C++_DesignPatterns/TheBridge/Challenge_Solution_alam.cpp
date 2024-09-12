#include <bits/stdc++.h>
using namespace std;
class IEngine {
public:
  virtual void start() const = 0;
  virtual ~IEngine() = default;
};

class IVehicle {
public:
  explicit IVehicle(const IEngine &engine) : m_engine(engine) {}
  void drive() const {
    m_engine.start();
    driveVehicle();
  }

protected:
  virtual void driveVehicle() const = 0;

private:
  const IEngine &m_engine;
};

class GasEngine : public IEngine {
public:
  virtual void start() const override { cout << "Gas Engine started" << endl; }
};

class ElectricEngine : public IEngine {
public:
  virtual void start() const override {
    cout << "Electric Engine started" << endl;
  }
};

class HybridEngine : public IEngine {
public:
  virtual void start() const override {
    cout << "HybridEngine started" << endl;
  }
};

class Car : public IVehicle {
public:
  Car(const IEngine &engine) : IVehicle(engine) {}
  virtual void driveVehicle() const override { cout << "Car Driving" << endl; }
};

class Truck : public IVehicle {
public:
  Truck(const IEngine &engine) : IVehicle(engine) {}
  virtual void driveVehicle() const override {
    cout << "Truck Driving" << endl;
  }
};
class Bike : public IVehicle {
public:
  Bike(const IEngine &engine) : IVehicle(engine) {}
  virtual void driveVehicle() const override { cout << "Bike Driving" << endl; }
};

int main(int argc, char const *argv[]) {

  auto gasEngine = GasEngine();
  auto eledtricEngine = ElectricEngine();
  auto hybridEngine = HybridEngine();
  // clang-format off
  const unique_ptr<IVehicle>vehicles[]{
	make_unique<Car>(gasEngine),
	make_unique<Truck>(eledtricEngine),
	make_unique<Bike>(hybridEngine)
  };
  // clang-format on
  for (const auto &i : vehicles) {
    i->drive();
    cout << endl;
  }

  return 0;
}
