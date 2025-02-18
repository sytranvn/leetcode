#include "solution.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
 
void test_success(void **state) {
  assert_int_equal(1, 1);
}
 
int main(void) {
     return run_test(test_success);
}
