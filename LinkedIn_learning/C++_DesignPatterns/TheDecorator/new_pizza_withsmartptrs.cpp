
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
  unique_ptr<Pizza> m_pizza;

public:
  explicit ToppingDecorator(unique_ptr<Pizza> pizza) : m_pizza(move(pizza)) {}
  string description() const override { return m_pizza->description(); }
  double price() const override { return m_pizza->price(); }
};

class MushroomDecorator : public ToppingDecorator {
public:
  explicit MushroomDecorator(unique_ptr<Pizza> pizza)
      : ToppingDecorator(move(pizza)) {}
  string description() const override {
    return m_pizza->description() + " with mushroom toppings";
  }
  double price() const override { return m_pizza->price() + 20.0; }
};

class TomatoDecorator : public ToppingDecorator {
public:
  explicit TomatoDecorator(unique_ptr<Pizza> pizza)
      : ToppingDecorator(move(pizza)) {}
  string description() const override {
    return m_pizza->description() + " with tomato toppings";
  }
  double price() const override { return m_pizza->price() + 10.0; }
};

class ExtraCheeseDecorator : public ToppingDecorator {
public:
  explicit ExtraCheeseDecorator(unique_ptr<Pizza> pizza)
      : ToppingDecorator(move(pizza)) {}
  string description() const override {
    return m_pizza->description() + " with extracheese toppings";
  }
  double price() const override { return m_pizza->price() + 100.0; }
};

int main() {
  unique_ptr<Pizza> pizzas[]{make_unique<MargheritaPizza>(),
                             make_unique<PepperoniPizza>(),
                             make_unique<HawaiianPizza>()};
  cout << " basePrize " << endl;
  for (const auto &pizza : pizzas) {
    cout << pizza->description() << " costs $" << pizza->price() << endl;
  }

  auto margheritawithMushrooms =
      make_unique<MushroomDecorator>(move(pizzas[0]));
  auto margheritawithMushroomsExtraCheese =
      make_unique<ExtraCheeseDecorator>(move(margheritawithMushrooms));
  cout << margheritawithMushroomsExtraCheese->description() << " costs INR "
       << margheritawithMushroomsExtraCheese->price() << endl;

  auto hawaiianWithMushrooms = make_unique<MushroomDecorator>(move(pizzas[2]));
  cout << hawaiianWithMushrooms->description() << " costs INR "
       << hawaiianWithMushrooms->price() << endl;

  auto hawaiianWithMushroomswithExtraCheese =
      make_unique<ExtraCheeseDecorator>(move(hawaiianWithMushrooms));
  cout << hawaiianWithMushroomswithExtraCheese->description() << " costs INR "
       << hawaiianWithMushroomswithExtraCheese->price() << endl;

  return 0;
}
