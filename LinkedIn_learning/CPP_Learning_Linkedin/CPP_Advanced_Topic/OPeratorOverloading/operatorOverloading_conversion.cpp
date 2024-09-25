// rational.cpp by Bill Weinman [bw.org]
// updated 2022-06-18
#include <bits/stdc++.h>
#include <fmt/format.h>
using namespace std;

const string nanstr{"[NAN]"};

class Rational {
  int n{0};
  int d{1};

public:
  Rational(int numerator = 0, int denominator = 1)
      : n(numerator), d(denominator) {}
  Rational(const Rational &rhs) : n(rhs.n), d(rhs.d) {
    cout << "\nCopy constr called\n";
  } // copy constructor
  ~Rational();
  int numerator() const { return n; };
  int denominator() const { return d; };
  Rational reduce() const; // reduce fraction
  string str() const;      // return a formatted STL string
  string raw_str() const;  // return a non-reduced STL string
  operator auto() { return str(); }

  Rational &operator=(const Rational &); // assignment
};

Rational Rational::reduce() const {
  if (n == 0 || d <= 3)
    return *this;
  for (auto div = d - 1; div; --div) {
    if (n % div == 0 && d % div == 0) {
      return Rational(n / div, d / div);
    }
  }
  return *this;
}

string Rational::str() const {
  if (d == 0)
    return nanstr;
  if (d == 1 || n == 0)
    return std::to_string(n);

  auto abs_n = abs(n); // absolute value
  if (abs_n > d) {
    auto whole = n / d;
    auto remainder = abs_n % d;
    if (remainder)
      return std::to_string(whole) + " " + Rational(remainder, d).str();
    else
      return std::to_string(whole);
  } else {
    return reduce().raw_str();
  }
}

string Rational::raw_str() const {
  return std::to_string(n) + "/" + std::to_string(d);
}

Rational &Rational::operator=(const Rational &rhs) {
  if (this != &rhs) {
    n = rhs.numerator();
    d = rhs.denominator();
  }
  cout << "\nCopy Assignment called" << endl;
  return *this;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
  return Rational((lhs.numerator() * rhs.denominator()) +
                      (lhs.denominator() * rhs.numerator()),
                  lhs.denominator() * rhs.denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
  return Rational((lhs.numerator() * rhs.denominator()) -
                      (lhs.denominator() * rhs.numerator()),
                  lhs.denominator() * rhs.denominator());
}
Rational operator*(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.numerator() * rhs.numerator(),
                  lhs.denominator() * rhs.denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.numerator() * rhs.denominator(),
                  lhs.denominator() * rhs.numerator());
}

Rational::~Rational() {
  n = 0;
  d = 1;
}

void p(const string &s) { cout << format("The string is {}\n", s); }

int main() {

  Rational a{7}; // 7/1
  cout << format("a is: {} = {}\n", a.raw_str(), a.str());

  Rational b(25, 15); // 5/3
  cout << format("b is: {} = {}\n", b.raw_str(), b.str());

  auto c = b; // copy constructor
  cout << format("c is: {} = {}\n", c.raw_str(), c.str());

  Rational d; // default constructor
  cout << format("def. d is: {} = {}\n", d.raw_str(), d.str());

  d = c; // assignment operator
  cout << format("d is: {} = {}\n", d.raw_str(), d.str());

  auto &e = d; // reference
  d = e;       // assignment to self!
  cout << format("e is: {} = {}\n", e.raw_str(), e.str());
  cout << format("d is: {} = {}\n", d.raw_str(), d.str());

  cout << '\n';
  cout << format("a + b = {}\n", (a + b).str());
  cout << format("a - b = {}\n", (a - b).str());
  cout << format("a * b = {}\n", (a * b).str());
  cout << format("a / b = {}\n", (a / b).str());

  string msg{"Rational no is "};
  msg += a;
  cout << msg << endl;

  p(a);
  return 0;
}
