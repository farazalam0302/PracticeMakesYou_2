#include "Circle.h"
#include <stdio.h>

static unsigned int Circle_area_(Shape const *const me);
static void Circle_draw_(Shape const *const me);

void Circle_ctor(Circle *const me, short x, short y, unsigned short radius) {
  static struct ShapeVtbl const vtbl = {&Circle_area_, &Circle_draw_};

  Shape_ctor(&(me->super), x, y);
  (me->super).vptr = &vtbl;
  me->radius = radius;
  //  me->height = height;
}

static unsigned int Circle_area_(Shape const *const me) {
  Circle const *const me_ = (Circle const *)me;
  return (unsigned int)(3 * me_->radius * me_->radius);
}
static void Circle_draw_(Shape const *const me) {
  Circle const *const me_ = (Circle const *)me;
  printf("\nCircle_draw_(x=%d,y=%d,radius=%d )\n", me_->super.x, me_->super.y,
         me_->radius);
}

float Circle_getPerimeter(Circle *const me) {
  return ((3.14f * me->radius) * 2);
}
