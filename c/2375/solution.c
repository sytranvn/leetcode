#include "solution.h"
#include <stdlib.h>
#include <string.h>
#define start '1'
#define n 9

char *smallestNumber(char *pattern) {
  int pl = strlen(pattern);
  char *result = malloc((pl + 2) * sizeof(char));
  result[pl + 1] = '\0';
  char curr = start;
  int i = 0;
  int j;

  for (; i < pl; i++) {
    if (pattern[i] == 'I') {
      result[i] = curr;
      curr++;
    } else {
      j = i;
      while (j < pl && pattern[j] == 'D')
        j++;
      while (j - i >= 0) {
        result[j--] = curr++;
      }
      i = curr - start - 1;
    }
  }
  if (i == pl)
    result[i] = curr;

  return result;
}
