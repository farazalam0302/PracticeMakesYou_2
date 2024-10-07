#include "rectangle.h"

void Rectangle_ctor(Rectangle *const me, short x, short y, unsigned short width,
                    unsigned short height) {

  Shape_ctor(&(me->super), x, y);
  me->width = width;
  me->height = height;
}

unsigned short Rectangle_getPerimeter(Rectangle *const me) {
  unsigned short perimeter = (me->height + me->width) << 1;
  return perimeter;
}
unsigned short Rectangle_getWidth(Rectangle *const me) { return me->width; }
unsigned short Rectangle_getHeight(Rectangle *const me) { return me->height; }
