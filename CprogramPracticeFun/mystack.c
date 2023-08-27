#include "mystack.h"

struct Stack *createStack(int capacity) {
  struct Stack *mStack = (struct Stack *)malloc(sizeof(struct Stack));
  mStack->capacity = capacity;
  mStack->top = -1;
  mStack->stk = (int *)malloc(capacity * sizeof(int));
  return mStack;
}

void displayStack(struct Stack *mstack) {
  if (isEmpty(mstack)) {
    printf("%s\n", "Stack is Empty!!");
    return;
  }
  printf("\n");
  for (int i = 0; i < mstack->capacity; i++) {
    printf("%d, ", mstack->stk[i]);
  }
  printf("\n");
}
int isFull(struct Stack *stack) {
  if (stack->top == stack->capacity - 1)
    return 1;
  return 0;
}
int isEmpty(struct Stack *stack) {
  if (stack->top == -1)
    return 1;
  return 0;
}
void push(struct Stack *mStack, int x) {
  if (isFull(mStack)) {
    printf("%s\n", "Stack is overflown!!");
    return;
  }
  mStack->top = mStack->top + 1;
  mStack->stk[mStack->top] = x;
  printf("%d item pushed to stack\n", x);
}
int getTop(struct Stack *mstack) {
  if (isEmpty(mstack)) {
    printf("%s\n", "Stack is Empty!!");
    return INT_MIN;
  }
  return mstack->stk[mstack->top];
}
void pop(struct Stack *mStack) {
  if (isEmpty(mStack)) {
    printf("%s\n", "Stack is Empty!!");
    return;
  }
  mStack->stk[mStack->top] = -1;
  mStack->top = (mStack->top) - 1;
}

int main(int argc, char const *argv[]) {

  struct Stack *stack = createStack(7);
  for (int i = 1; i < 6; i++) {
    push(stack, i);
  }

  printf("\ntop = %d", stack->top);
  printf("\ncapacity = %d", stack->capacity);
  // printf("capac = %d", stack->capacity);

  displayStack(stack);

  printf("\n\n");
  while (isEmpty(stack) == 0) {
    printf("%d, ", getTop(stack));
    pop(stack);
  }
  printf("\n\n");

  return 0;
}
