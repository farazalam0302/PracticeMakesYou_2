class Shape {
public:
  int a;

  Base(int x) : a(x) {}

  virtual Area() { returning a }
};

class rectangle : Shape {

  int len, breadth;

  Area() { return l * b }

}

class Square : Shape

{
  int l;
  Area() { l *l }
}

main() {
  Shape *ptr;
  ptr = new rectangle(4, 5);

  ptr->Area() // 20
}

f1() {

  ptr = malloc(heap)

      delete ptr;

  using ptr // dangling ptr
}
main() { f1() }