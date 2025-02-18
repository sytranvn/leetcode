#include <stdio.h>
int triangularSum(int *nums, int numsSize) {
  for (; numsSize != 1; numsSize--)
    for (int i = 0; i < numsSize - 1; i++)
      nums[i] = (nums[i] + nums[i + 1]) % 10;
  return nums[0];
}

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  printf("%d\n", triangularSum(a, 5));
  return 0;
}
