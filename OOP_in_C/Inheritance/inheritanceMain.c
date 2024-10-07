/*
 * Compilation Method
 * gcc -g  rectangle.c inheritanceMain.c  ../Encapsulation/Shape.c -o a.out
 */

#include "rectangle.h"
#include <stdio.h>

int main() {
  Rectangle r1, r2;
  Rectangle_ctor(&r1, 0, 2, 10, 15);
  Rectangle_ctor(&r2, -1, 3, 10, 10);

  printf("Rectangle 1 (x=%d, y=%d, width=%d, height=%d )\n", r1.super.x,
         r1.super.y, r1.width, r1.height);

  printf("Rectangle 2 (x=%d, y=%d, width=%d, height=%d )\n", r2.super.x,
         r2.super.y, r2.width, r2.height);
  Shape_moveBy((Shape *)&r1, 5, 3);
  Shape_moveBy((Shape *)&r2, -4, -8);

  printf("Rectangle 1 (x=%d, y=%d, width=%d, height=%d )\n", r1.super.x,
         r1.super.y, r1.width, r1.height);

  printf("Rectangle 2 (x=%d, y=%d, width=%d, height=%d )\n", r2.super.x,
         r2.super.y, r2.width, r2.height);

  printf("Rectangle 1 Perimeter = %d\n", Rectangle_getPerimeter(&r1));
  printf("Rectangle 2 Perimeter = %d\n", Rectangle_getPerimeter(&r2));

  return 0;
}
