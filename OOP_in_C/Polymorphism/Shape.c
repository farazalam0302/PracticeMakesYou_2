#include "Shape.h"
#include <assert.h>

static void Shape_draw_(Shape const *const me);
static unsigned int Shape_area_(Shape const *const me);

void Shape_ctor(Shape *const me, short x, short y) {
  static struct ShapeVtbl const vtbl = {&Shape_area_, &Shape_draw_};
  me->vptr = &vtbl;
  me->x = x;
  me->y = y;
}

void Shape_moveBy(Shape *const me, short dx, short dy) {
  me->x += dx;
  me->y += dy;
}

static unsigned int Shape_area_(Shape const *const me) {
  assert(0);
  return 0;
}

static void Shape_draw_(Shape const *const me) { assert(0); }
