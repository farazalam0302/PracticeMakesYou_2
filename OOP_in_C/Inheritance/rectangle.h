#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Encapsulation/Shape.h"
typedef struct {
  Shape super;

  unsigned short width;
  unsigned short height;
} Rectangle;

void Rectangle_ctor(Rectangle *const me, short x, short y, unsigned short width,
                    unsigned short height);

unsigned short Rectangle_getPerimeter(Rectangle *const me);
unsigned short Rectangle_getWidth(Rectangle *const me);
unsigned short Rectangle_getHeight(Rectangle *const me);

#endif /* RECT_H */
