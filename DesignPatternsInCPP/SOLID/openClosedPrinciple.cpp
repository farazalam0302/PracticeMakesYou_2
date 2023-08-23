#include <bits/stdc++.h>
using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
  string name;
  Color color;
  Size size;
};

struct ProductFilter {

  vector<Product *> byColor(vector<Product *> items, Color color) {
    vector<Product *> result;
    for (auto &i : items) {
      if (i->color == color)
        result.push_back(i);
    }
    return result;
  }

  vector<Product *> bySize(vector<Product *> items, Size size) {
    vector<Product *> result;
    for (auto &i : items) {
      if (i->size == size)
        result.push_back(i);
    }
    return result;
  }

  vector<Product *> bySizeandColor(vector<Product *> items, Size size,
                                   Color color) {
    vector<Product *> result;
    for (auto &i : items) {
      if (i->size == size && i->color == color)
        result.push_back(i);
    }
    return result;
  }
};

template <typename T> struct Specification {
  virtual bool isSatisfied(T *item) = 0;
};

template <typename T> struct Filter {
  virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product> {
  vector<Product *> filter(vector<Product *> items,
                           Specification<Product> &spec) override {
    vector<Product *> result;
    for (auto &i : items) {
      if (spec.isSatisfied(i)) {
        result.push_back(i);
      }
    }
    return result;
  }
};

struct ColorSpecification : Specification<Product> {
  Color color;
  ColorSpecification(Color color) : color(color) {}
  bool isSatisfied(Product *item) override { return item->color == color; }
};
struct SizeSpecification : Specification<Product> {
  Size size;
  SizeSpecification(Size size) : size(size) {}
  bool isSatisfied(Product *item) override { return item->size == size; }
};

template <typename T> struct AndSpecification : Specification<T> {
  Specification<T> &first;
  Specification<T> &second;
  AndSpecification(Specification<T> &first, Specification<T> &second)
      : first(first), second(second) {}
  bool isSatisfied(T *item) override {
    return first.isSatisfied(item) && second.isSatisfied(item);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};
  Product ball{"Ball", Color::green, Size::large};
  Product pen{"Pen", Color::red, Size::medium};
  vector<Product *> items{&apple, &tree, &house, &ball, &pen};
  //   ProductFilter pf;
  //   auto green_things = pf.byColor(items, Color::green);
  //   for (auto &i : green_things) {
  //     cout << i->name << endl;
  //   }

  BetterFilter bf;
  ColorSpecification Green(Color::green);
  for (auto &i : bf.filter(items, Green)) {
    cout << i->name << " is Green \n";
  }
  SizeSpecification medium(Size::medium);
  for (auto &i : bf.filter(items, medium)) {
    cout << i->name << " is Medium \n";
  }
  SizeSpecification Large(Size::large);
  AndSpecification<Product> GreenAndLarge(Green, Large);

  for (auto &i : bf.filter(items, GreenAndLarge)) {
    cout << i->name << " is GreenAndLarge\n";
  }

  return 0;
}
