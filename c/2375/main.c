#include <stdio.h>
#include "solution.h"
#include <stdlib.h>


int main() {
  char pattern[26] = {'\0'};
  scanf("%25s", pattern);
  char *res = smallestNumber(pattern);
  printf("%s\n", res);
  free(res);
  return 0;
}
