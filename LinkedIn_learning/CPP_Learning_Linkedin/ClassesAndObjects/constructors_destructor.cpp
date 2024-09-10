#include <bits/stdc++.h>
#include <fmt/format.h>
using namespace std;

const string unk{"unknown"};
const string clone_prefix{"clone-"};

class Animal {
private:
  string a_type{};
  string a_name{};
  string a_sound{};

public:
  Animal(/* args */); // default
  Animal(const string &atype, const string &aname,
         const string &asound); // params const
  Animal(const Animal &);       // copy constr
  ~Animal();
  void print() const {
    cout << format("\n {} the {} says {} \n", a_name, a_type, a_sound);
  }
};

Animal::Animal(/* args */) : a_type(unk), a_name(unk), a_sound(unk) {
  cout << "\nDEFAULT CONSTR. CALLED\n";
}

Animal::Animal(const string &atype, const string &aname, const string &asound)
    : a_type(atype), a_name(aname), a_sound(asound) {
  cout << "\nPARAMS. CONSTR. CALLED\n";
}

Animal::Animal(const Animal &a) {
  cout << "\nCOPY CONSTR Called \n";
  a_name = clone_prefix + a.a_name;
  a_type = a.a_type;
  a_sound = a.a_sound;
}

Animal::~Animal() {
  cout << format("\nDestructor. CALLED {} the {}\n", a_name, a_type);
}

int main(int argc, char const *argv[]) {
  const Animal a{};
  a.print();

  const Animal b("goat", "bob", "mmmaaaaaahh");
  b.print();

  const Animal c = b;
  c.print();

    return 0;
}
