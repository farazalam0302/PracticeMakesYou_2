#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
typedef struct {
  Shape super;

  unsigned short radius;
  //  unsigned short height;
} Circle;

void Circle_ctor(Circle *const me, short x, short y, unsigned short radius);

float Circle_getPerimeter(Circle *const me);
// unsigned short Rectangle_getWidth(Rectangle *const me);
// unsigned short Rectangle_getHeight(Rectangle *const me);

#endif /* Circle */
