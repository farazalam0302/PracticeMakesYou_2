void func(int cond) {
  char *c = 0;
  char d[] = “a”;
  if (cond) {
    c = d;
    *c = ‘b’;
  }
  *c = ‘c’;
}
