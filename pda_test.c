#include <CUnit/Basic.h>
#include <CUnit/CUError.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "pda.h"

void test_push_pop() {
  for (int i = 0; i < 31; i++) {
    push('a' + i);
  }

  char c;
  for (int i = 30; i >= 0; i--) {
    pop(&c);
    CU_ASSERT(c == 'a' + i);
  }
}

void test_push_count() {
  for (int i = 0; i < 31; i++) {
    push('a' + i);
  }
  CU_ASSERT(cur == 31);

  char c;
  for (int i = 0; i < 10; i++) {
    pop(&c);
  }
  CU_ASSERT(cur == 21);

  for (int i = 0; i < 21; i++) {
    pop(&c);
  }
  CU_ASSERT(cur == 0);
}

typedef struct {
  char *exp;
  bool result;
} testcase_t;

void test_grammar_check() {
  testcase_t testcases[] = {
      {.exp = "1+2", .result = true},
      {.exp = "1+2/4", .result = true},
      {.exp = "(1+2/4)+(3^1)", .result = true},
      {.exp = "(1+3)/(1*(3+1))", .result = true},
      {.exp = "((1+3)/(1*(3+1)))", .result = true},
      {.exp = "(((1+3)/(1*(((3+1)))", .result = false},
      {.exp = "((1+3)/(1*(3+1))))", .result = false},
      {.exp = "(1+3)/(1*(3+1)))", .result = false},
      {.exp = "(1+3", .result = false},
      {.exp = NULL, .result = false},
  };

  for (int i = 0; testcases[i].exp; i++) {
    char *exp = testcases[i].exp;
    CU_ASSERT(grammar_check(exp, strlen(exp)) == testcases[i].result);
  }
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CU_initialize_registry() != CUE_SUCCESS) {
    return CU_get_error();
  }

  pSuite = CU_add_suite("stack", NULL, NULL);
  if (!pSuite)
    goto cleanup;

  if (!CU_add_test(pSuite, "test for push and pop functions", test_push_pop))
    goto cleanup;

  if (!CU_add_test(pSuite, "count push current location", test_push_count))
    goto cleanup;

  if (!CU_add_test(pSuite, "check grammar", test_grammar_check))
    goto cleanup;

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

cleanup:
  CU_cleanup_registry();
  return CU_get_error();
}