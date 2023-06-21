textsection/code section ) Static

/bss

stack

heap

copy constru

class X {
  int a1;
  int *a2;

public:
  X(X &obj) {
    this->a1 = obj.a1;
    this->a2 = new int;
    *a2 = *(obj.a2);
  }
};

obJ1, obj2

          obj1 = obj2

