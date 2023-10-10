#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
protected:
  Person &person;

public:
  PersonBuilderBase(Person &person) : person{person} {}

  operator Person() const { return std::move(person); }

  PersonAddressBuilder lives() const;
  PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase {
private:
  Person p;

public:
  PersonBuilder() : PersonBuilderBase{p} {};
};