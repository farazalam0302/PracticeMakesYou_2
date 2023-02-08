void func(int cond) {
  char *c = 0;
  3. char d[] = “a”;
  4. if (cond) {
    5. c = d;
    6. *c = ‘b’;
    7.
  }
  8. *c = ‘c’;
  9.
}
