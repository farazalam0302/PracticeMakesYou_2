#include <bits/stdc++.h>
using namespace std;
#include "Person.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"

int main(int argc, char const *argv[]) {

  Person p = Person::create()
                 .lives()
                 .at("76 Shahnthan")
                 .with_postcode("250002")
                 .in("Meerut")
                 .works()
                 .at("AMD BLR")
                 .as_a("SSE")
                 .earning(10e7);

  cout << p << endl;
  return 0;
}
