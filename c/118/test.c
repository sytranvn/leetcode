#include "solution.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
 
void test_success(void **state) {
  int numRows = 5;
  int returnSize;
  int* returnColumnSizes;
  int ** result;
  result = generate(numRows, &returnSize, &returnColumnSizes);
  assert_int_equal(returnSize, numRows);
  for (int i = 1; i <= numRows; i++) {
    assert_int_equal(returnColumnSizes[i-1], i);
  }
}
 
int main(void) {
     return run_test(test_success);
}
