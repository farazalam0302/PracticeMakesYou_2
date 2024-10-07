#include "Rectangle.h"
#include <stdio.h>

static unsigned int Rectangle_area_(Shape const *const me);
static void Rectangle_draw_(Shape const *const me);

void Rectangle_ctor(Rectangle *const me, short x, short y, unsigned short width,
                    unsigned short height) {
  static struct ShapeVtbl const vtbl = {&Rectangle_area_, &Rectangle_draw_};

  Shape_ctor(&(me->super), x, y);
  (me->super).vptr = &vtbl;
  me->width = width;
  me->height = height;
}

static unsigned int Rectangle_area_(Shape const *const me) {
  Rectangle const *const me_ = (Rectangle const *)me;
  return (unsigned int)(me_->width * me_->height);
}
static void Rectangle_draw_(Shape const *const me) {
  Rectangle const *const me_ = (Rectangle const *)me;
  printf("\nRectangle_draw_(x=%d,y=%d,width=%d,height=%d)\n", me_->super.x,
         me_->super.y, me_->width, me_->height);
}

unsigned short Rectangle_getPerimeter(Rectangle *const me) {
  return ((me->width + me->height) << 1);
}
