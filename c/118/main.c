/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/syslimits.h>
#include "solution.h"


int main() {
  int numRows;
  scanf("%d", &numRows);
  int returnSize;
  int *returnColumnSizes;
  int **result = generate(numRows, &returnSize, &returnColumnSizes);
  printf("[");
  for (int i = 0; i < numRows - 1; i++) {
    printf("[");
    for (int j = 0; j < returnColumnSizes[i] - 1; j++) {
      printf("%d,", result[i][j]);
    }
    printf("%d],", result[i][returnColumnSizes[i] - 1]);
  }
  printf("[");
  for (int j = 0; j < returnColumnSizes[numRows - 1] - 1; j++) {
    printf("%d,", result[numRows - 1][j]);
  }
  printf("%d]", result[numRows - 1][returnColumnSizes[numRows - 1] - 1]);
  printf("]\n");
  return 0;
}
