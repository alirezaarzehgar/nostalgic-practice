#ifndef _PDA_H
#define _PDA_H
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

extern int cap, cur;

int push(char c);
int pop(char *c);
bool grammar_check(char* exp, size_t n);

#endif
