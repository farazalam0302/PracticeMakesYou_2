#include <iostream>
#include <string>

using namespace std;

class Computer {
public:
  virtual string description() const = 0;
  virtual double price() const = 0;
  virtual ~Computer() = default;
};

class Desktop : public Computer {
public:
  string description() const override { return "Desktop"; }

  double price() const override { return 1000.0; }
};

class Laptop : public Computer {
public:
  string description() const override { return "Laptop"; }

  double price() const override { return 1500.0; }
};

// Decorator

class ComputerDecorator : public Computer {
public:
  explicit ComputerDecorator(Computer *comp) : m_computer(comp) {}
  string description() const override { return m_computer->description(); }
  double price() const override { return m_computer->price(); }

protected:
  const Computer *m_computer;
};

class MemoryUpgradeDecorator : public ComputerDecorator {
public:
  explicit MemoryUpgradeDecorator(Computer *computer)
      : ComputerDecorator(computer) {}

  string description() const override {
    return ComputerDecorator::description() + " with memory upgrade";
  }
  double price() const override { return ComputerDecorator::price() + 500.0; }
};

class GraphicsUpgradeDecorator : public ComputerDecorator {
public:
  explicit GraphicsUpgradeDecorator(Computer *computer)
      : ComputerDecorator(computer) {}

  string description() const override {
    return ComputerDecorator::description() + " with GPU upgrade";
  }
  double price() const override { return ComputerDecorator::price() + 1000.0; }
};

int main() {
  auto laptop = new Laptop();
  auto desktop = new Desktop();
  cout << "base models\n";
  cout << "description | price INR \n";
  cout << (laptop->description()) << " | " << (laptop->price()) << endl;

  cout << (desktop->description()) << " | " << (desktop->price()) << endl;

  auto desktopMemoryUpgrade = new MemoryUpgradeDecorator(desktop);
  auto laptopGPUupgrade = new GraphicsUpgradeDecorator(laptop);
  cout << "upgraded  models\n";
  cout << "description | price INR \n";
  cout << (laptopGPUupgrade->description()) << " | "
       << (laptopGPUupgrade->price()) << endl;

  cout << (desktopMemoryUpgrade->description()) << " | "
       << (desktopMemoryUpgrade->price()) << endl;

  return 0;
}
