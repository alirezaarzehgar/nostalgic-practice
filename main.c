#include "pda.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *line;
  size_t n;

  for (size_t i = 0; getline(&line, &n, stdin) > -1; i++) {
    if (!grammar_check(line, n))
      printf("❌ \033[91m%zu: %s\033[0m", i, line);
    else
      printf("✅ \033[32m%zu: %s\033[0m", i, line);

    free(line);
    line = NULL;
  }
  return 0;
}
