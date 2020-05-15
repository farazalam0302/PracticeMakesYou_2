#include <bits/stdc++.h>
#include <memory>
using namespace std;

class Entity {
public:
  Entity() { cout << "\n Entity created " << endl; }
  ~Entity() { cout << "\n Entity deleted " << endl; }
  void display(string n) { cout << "\n !!!!!!  Wish you !!! " << n << endl; }
};

int main() {
  {
    // unique_ptr<Entity> entity(new Entity());
    unique_ptr<Entity> entity = std::make_unique<Entity>();

    entity->display("Unique DIsplay");
  }
  cout << "\n unique ptr done BLOCK \n" << endl;

  {
    shared_ptr<Entity> sharedEntity2; // = sharedEntity1;
    {
      shared_ptr<Entity> sharedEntity1 = make_shared<Entity>();
      sharedEntity1->display("SE1 display");
      sharedEntity2 = sharedEntity1;
    }
    sharedEntity2->display("SE2 Display");
    cout << "\n OUTSIDE BLOCK 1 \n" << endl;
  }
  cout << "\n OUTSIDE BLOCK 2\n" << endl;

  return 0;
}