/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/syslimits.h>
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
  int **result = malloc(numRows * sizeof(int *));
  *returnSize = numRows;
  *returnColumnSizes = malloc(numRows * sizeof(int *));
  for (int i = 1; i <= numRows; i++) {
    (*returnColumnSizes)[i - 1] = i;
    result[i - 1] = malloc(i * sizeof(int));
    result[i - 1][0] = result[i - 1][i - 1] = 1;
    for (int k = 1; k < i - 1; k++) {
      result[i - 1][k] = result[i - 2][k - 1] + result[i - 2][k];
    }
  }
  return result;
}

