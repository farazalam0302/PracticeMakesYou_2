#include <bits/stdc++.h>
using namespace std;
// using std::string;
template <typename T> class CustomVector {
private:
  vector<T> items{};

public:
  CustomVector(/* args */) { std::cout << "Default c'tor\n "; }
  CustomVector(initializer_list<T> il);      // il ctor
  CustomVector(const CustomVector &rhs);     // copy ctor
  CustomVector(CustomVector &&rhs) noexcept; // move ctor

  ~CustomVector();
  CustomVector<T> &operator=(CustomVector rhs); // copy/swap opr
  CustomVector<T> &operator=(CustomVector &&rhs) noexcept;

  void reset();

  string str() const;
};

template <typename T>
CustomVector<T>::CustomVector(initializer_list<T> il)
    : items{il.begin(), il.end()} {
  std::cout << "il-list c'tor \n";
}

template <typename T>
CustomVector<T>::CustomVector(const CustomVector &rhs) : items{rhs.items} {
  std::cout << "copy c'tor \n";
}
// copy swap
template <typename T>
CustomVector<T> &CustomVector<T>::operator=(CustomVector rhs) {
  std::cout << "copy/swap c'tor\n";
  std::swap(items, rhs.items);
  return *this;
}
// move assignment operator

template <typename T>
CustomVector<T> &CustomVector<T>::operator=(CustomVector &&rhs) noexcept {
  std::cout << "move assignment c'tor\n";
  if (this != &rhs) {
    items = move(rhs.items);
  }
  return *this;
}

// move constr

template <typename T>
CustomVector<T>::CustomVector(CustomVector &&rhs) noexcept
    : items{std::move(rhs.items)} {
  std::cout << "move c'tor \n";
}

// dtor
template <typename T> CustomVector<T>::~CustomVector() {
  std::cout << "d'tor for " << hex << this << endl;
}

// reset

template <typename T> void CustomVector<T>::reset() { items.clear(); }

// str
template <typename T> string CustomVector<T>::str() const {
  string out{};
  if (items.empty())
    return "[empty]";
  for (auto i : items) {
    if (out.size())
      out += ':';
    out += i;
  }
  return out;
}
template <typename T> CustomVector<T> f(CustomVector<T> &&o) { return o; }

int main(int argc, char const *argv[]) {
  CustomVector<string> a{"one", "two", "three", "four", "five"};
  CustomVector<string> b{"five", "six", "seven"};
  std::cout << "a : " << a.str() << endl;
  std::cout << "b : " << b.str() << endl;

  b = a;
  std::cout << "a : " << a.str() << endl;
  std::cout << "c : " << c.str() << endl;

  return 0;
}
