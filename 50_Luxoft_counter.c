/*
 *
Write a C module which should implement a simple up-down counter. The module
should  contain three global functions:

        void inc(void);
        void dec(void);
        unsigned read(void);

read() should return a number of previously performed calls of inc() minus a
number of dec() calls,  counted from the program startup.

If you are experienced with multithreaded (MT) programming, then make this
module MT-safe. You are not limited to ANSI C but allowed to use any OS-specific
extensions you are familiar with to achieve MT-safety.

If you are not familiar of MT programming, then write single-threaded code --
this will NOT be considered as a minus for you. Please notice that proper use of
MT programming methods is a plus, but wrong usage is a minus, so judge yourself.

 *
 */

#include <stdio.h>

void inc(void);
void dec(void);
unsigned int read(void);
int counter = 0;  // global;

int lock = 0;  // 0 -> inc allowed and  1 -> dec

void inc(void) {
  lock = !lock;
  counter++;
  lock++;
}
void dec(void) {
  lock++;
  counter++;
  lock = !lock;
}

unsigned int read(void) { return counter; }

int main() {
  if (lock == 0) {
    inc();
  }
  if (lock != 0 && counter != 0) {
    dec();
  }
  printf("%u", read());
  return 0;
}
