
#include <bits/stdc++.h>
using namespace std;

class Pizza {
public:
  virtual string description() const = 0;
  virtual double price() const = 0;
  virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza {
public:
  string description() const override { return "Margherita Pizza"; }

  double price() const override { return 9.99; }
};

class HawaiianPizza : public Pizza {
public:
  string description() const override { return "Hawaiian Pizza"; }

  double price() const override { return 11.99; }
};

class PepperoniPizza : public Pizza {
public:
  string description() const override { return "Pepperoni Pizza"; }

  double price() const override { return 12.99; }
};

// topping Decorator
class ToppingDecorator : public Pizza {
protected:
  Pizza *m_pizza;

public:
  explicit ToppingDecorator(Pizza *pizza) : m_pizza(pizza) {}
  string description() const override { return m_pizza->description(); }
  double price() const override { return m_pizza->price(); }
};

class MushroomDecorator : public ToppingDecorator {
public:
  explicit MushroomDecorator(Pizza *pizza) : ToppingDecorator(pizza) {}
  string description() const override {
    return m_pizza->description() + " with mushroom toppings";
  }
  double price() const override { return m_pizza->price() + 20.0; }
};

class TomatoDecorator : public ToppingDecorator {
public:
  explicit TomatoDecorator(Pizza *pizza) : ToppingDecorator(pizza) {}
  string description() const override {
    return m_pizza->description() + " with tomato toppings";
  }
  double price() const override { return m_pizza->price() + 10.0; }
};

class ExtraCheeseDecorator : public ToppingDecorator {
public:
  explicit ExtraCheeseDecorator(Pizza *pizza) : ToppingDecorator(pizza) {}
  string description() const override {
    return m_pizza->description() + " with extracheese toppings";
  }
  double price() const override { return m_pizza->price() + 100.0; }
};

int main() {
  Pizza *pizzas[] = {new MargheritaPizza(), new PepperoniPizza(),
                     new HawaiianPizza()};
  cout << " basePrize " << endl;
  for (Pizza *pizza : pizzas) {
    cout << pizza->description() << " costs $" << pizza->price() << endl;
  }

  auto margheritawithMushrooms = new MushroomDecorator((pizzas[0]));
  auto margheritawithMushroomsExtraCheese =
      make_unique<ExtraCheeseDecorator>((margheritawithMushrooms));
  cout << margheritawithMushroomsExtraCheese->description() << " costs INR "
       << margheritawithMushroomsExtraCheese->price() << endl;

  return 0;
}
