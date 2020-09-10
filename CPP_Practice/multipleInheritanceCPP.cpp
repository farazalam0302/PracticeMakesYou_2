
// multiple inheritance

/*
 * A class may inherit from more than one class by simply specifying more base
classes, separated by commas, in the list of a class's base classes (i.e., after
the colon). For example, if the program had a specific class to print on screen
called Output, and we wanted our classes Rectangle and Triangle to also inherit
its members in addition to those of Polygon we could write:

1
2
class Rectangle: public Polygon, public Output;
class Triangle: public Polygon, public Output;
 *
 */
#include <iostream>
using namespace std;

class Polygon {
 protected:
  int width, height;

 public:
  Polygon(int a, int b) : width(a), height(b) {}
};

class Output {
 public:
  static void print(int i);
};

void Output::print(int i) { cout << i << '\n'; }

class Rectangle : public Polygon, public Output {
 public:
  Rectangle(int a, int b) : Polygon(a, b) {}
  int area() { return width * height; }
};

class Triangle : public Polygon, public Output {
 public:
  Triangle(int a, int b) : Polygon(a, b) {}
  int area() { return width * height / 2; }
};

int main() {
  Rectangle rect(2, 5);
  Triangle trgl(2, 5);
  rect.print(rect.area());
  Triangle::print(trgl.area());
  return 0;
}
