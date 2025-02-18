#include "solution.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>
 
void test_success(void **state) {
  char pattern[26] = "IIDDIIDD";
  char *res = smallestNumber(pattern);
  assert_string_equal(res, "125436987");
  free(res);
}
 
int main(void) {
     return run_test(test_success);
}
