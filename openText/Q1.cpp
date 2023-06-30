// move Constructor
class MoveConstructorClass {
public:
  int s;
  int *p;

  MoveConstructorClass() {
    s = 0;
    p = NULL;
  }
  MoveConstructorClass(int x) {
    s = x;
    p = new int(x);
  }
  MoveConstructorClass(MoveConstructorClass &&m) {
    s = m.s;
    p = m.p; // m.p->(100)@1000 // p = m.p
    m.p = nullptr;
  }
};
/*
 * f(int) |  f(int *)
 *  f(nullptr) will call f(int*)
 *
 */

f() {
  vector<int> r = [](vector<int> a) -> vector<int> {
    int n = a.size();
    for (int i = 0; i < n / 2; i++) {
      int tmp = a[n - i - 1];
      a[n - i - 1] = a[i];
      a[i] = tmp;
    }
    return a;
  };
}
