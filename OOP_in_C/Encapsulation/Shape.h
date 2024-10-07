#ifndef SHAPE_H
#define SHAPE_H

typedef struct {
  short x; //  x coordinate
  short y; // y coordinate

} Shape;

void Shape_ctor(Shape *const me, short x, short y);
void Shape_moveBy(Shape *const me, short dx, short dy);
short Shape_getX(Shape *const me);
short Shape_getY(Shape *const me);

#endif // SHAPE_H
