#include "pda.h"
#include <stdlib.h>

#define STACK_MEM_STEP 5
#define STACK_MEM_DEFAULT 10

int cap = 0, cur = 0;
char *stack;

int push(char c) {
  if (!stack) {
    stack = (void *)malloc(STACK_MEM_DEFAULT);
    cap = STACK_MEM_DEFAULT;
  }

  if (cur >= cap) {
    stack = (void *)realloc(stack, cap + STACK_MEM_STEP);
    cap += STACK_MEM_STEP;
  }

  stack[cur++] = c;
  return 0;
}

int pop(char *c) {
  if (cur == 0) {
    return 1;
  }

  if (cur > STACK_MEM_DEFAULT && cap - STACK_MEM_STEP > cur) {
    stack = (void *)realloc(stack, cap - STACK_MEM_STEP);
    cap -= STACK_MEM_STEP;
  }

  *c = stack[--cur];
  return 0;
}
