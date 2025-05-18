#include "pda.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

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

bool is_openc(char c) { return c == '(' || c == '{' || c == '['; }
bool is_closec(char c) { return c == ')' || c == '}' || c == ']'; }
char open2close(char c) {
  switch (c) {
  case '(':
    return ')';
  case '{':
    return '}';
  case '[':
    return ']';
  }
  return 0;
}

bool _grammar_check(char *exp, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (is_openc(exp[i]))
      push(exp[i]);

    if (is_closec(exp[i])) {
      char c;
      if (pop(&c) || open2close(c) != exp[i])
        return false;
    }
  }

  return cur == 0;
}

bool grammar_check(char *exp, size_t n) {
  bool r;

  r = _grammar_check(exp, n);
  if (stack != NULL) {
    free(stack);
    stack = NULL;
  }
  cur = 0;
  return r;
}