#include "Circle.h"
#include "Rectangle.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Rectangle r1, r2;
  Circle c1, c2;

  /* instantiate rectangles... */
  Rectangle_ctor(&r1, 0, 2, 10, 15);
  Rectangle_ctor(&r2, -1, 3, 5, 8);

  Circle_ctor(&c1, 1, -2, 2);
  Circle_ctor(&c2, 1, -3, 3);

  //    Shape const * s ;
  //    s= &r1;
  printf("Area r1 = %d\n", Shape_area(&r1.super));
  printf("Area r2 = %d\n", Shape_area(&r2.super));
  printf("Area c1 = %d\n", Shape_area(&c1.super));
  printf("Area c2 = %d\n", Shape_area(&c2.super));

  Shape_draw(&r1.super);
  Shape_draw(&r2.super);
  Shape_draw(&c1.super);
  Shape_draw(&c2.super);
  return 0;
}
