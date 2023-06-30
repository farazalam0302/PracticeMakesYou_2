class base {
  int a;
  /*
   * vptr -> [ ]
   */
  int b;
  virtual base() {}
  virtual ~base() {}
  virtual display() {}
  base &operator=()(base &obj) {
    if (*this != &obj) {
      a = obj.a;
      b = obj.b;
    }
    return *this;
  }
};

class derived : public base {
  int da, db;
  /*
   * vptr -> [derived ]
   */
  virtual derived() {}
  virtual ~derived() {}
  virtual display() {}
};

int main() {
  derived *d = new d(); // vptr -> vtable of derived
  base *b = d;          //
  base b1, b2, b3, b4;

  b1 = b2 = b3 = b4;
  b1 = b1;

  b->display()
}
// operator overloading "
/*
 * operator=() (base &a){
 *
 */
