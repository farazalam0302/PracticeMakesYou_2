#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Stack {
  int capacity;
  int top;
  int *stk;
};

struct Stack *createStack(int capacity);
int isFull(struct Stack *stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *mStack, int x);
int getTop(struct Stack *mstack);
void pop(struct Stack *mStack);