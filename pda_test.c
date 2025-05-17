#include <CUnit/Basic.h>
#include <CUnit/CUError.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
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

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

cleanup:
  CU_cleanup_registry();
  return CU_get_error();
}