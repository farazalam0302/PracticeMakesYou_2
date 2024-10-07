#ifndef SHAPE_H
#define SHAPE_H

struct ShapeVtbl;

typedef struct {
  struct ShapeVtbl const *vptr;
  short x; //  x coordinate
  short y; // y coordinate

} Shape;

struct ShapeVtbl {
  unsigned int (*area)(Shape const *const me);
  void (*draw)(Shape const *const me);
};

void Shape_ctor(Shape *const me, short x, short y);
void Shape_moveBy(Shape *const me, short dx, short dy);
static inline unsigned int Shape_area(Shape const *const me) {
  return ((*me->vptr->area)(me));
}

static inline void Shape_draw(Shape const *const me) {
  ((*me->vptr->draw)(me));
}

#endif // SHAPE_H
