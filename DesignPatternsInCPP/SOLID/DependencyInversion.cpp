#include <bits/stdc++.h>
using namespace std;

enum class Relationship { parent, child, sibling };
struct Person {
  string name;
};

struct Relationships // LL
{
  vector<tuple<Person, Relationship, Person>> relations;
  void addParentAndChild(const Person &parent, const Person &child) {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }
};
struct Research // HLL
{
  Research(Relationships &relationships) {
    auto &relations = relationships.relations;
    for (auto &&[first, rel, second] : relations) {
      if (first.name == "John" && rel == Relationship::parent)
        cout << "John has a child Called " << second.name << endl;
    }
  }
};
int main(int argc, char const *argv[]) {
  Person parent{"John"};
  Person child1{"Chris"}, child2{"Matt"};
  Relationships relationships;
  relationships.addParentAndChild(parent, child1);
  relationships.addParentAndChild(parent, child2);

  Research _(relationships);

  return 0;
}
