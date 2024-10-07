#include "Shape.h"
// Constructor
void Shape_ctor(Shape *const me, short x0, short y0) {
  me->x = x0;
  me->y = y0;
}

// move_By

void Shape_moveBy(Shape *const me, short dx, short dy) {
  me->x = me->x + dx;
  me->y = me->y + dy;
}
short Shape_getX(Shape *const me) { return (me->x); }
short Shape_getY(Shape *const me) { return (me->y); }
