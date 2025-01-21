#include <stdio.h>
struct Slot {
  int index;
  int a;
  int b;
};

int sumSlots(struct Slot *slots, int numSlots) {
  int sum = 0;
  for (int i = 0; i < numSlots; i++) {
    sum += (slots[i].a & slots[i].index) + (slots[i].b & slots[i].index);
  }
  return sum;
}

void trySlot(int *nums, int numsSize, int numSlots, struct Slot *slots,
             int currentSlot, int *result) {
  slots[currentSlot].index = currentSlot + 1;
  if (currentSlot + 1 == numSlots) {
    int sum = sumSlots(slots, numSlots);
    if (sum > *result)
      *result = sum;
  } else
    trySlot(nums, numsSize, numSlots, slots, currentSlot + 1, result);
}
/*
 * [1,2,3,4,5,6]
 * 3
 * [1,3,10,4,7,1]
 * 9
 * 1 <= numSlots <= 9
 * 1 <= n <= 2 * numSlots
 * 1 <= nums[i] <= 15 (4 bits)
 */
int maximumANDSum(int *nums, int numsSize, int numSlots) {
  int result = 0;
  struct Slot slots[9];
  trySlot(nums, numsSize, numSlots, slots, 0, &result);
  return result;
}

int main(void) {
  int nums[] = {1, 2, 3, 4, 5, 6};
  int result = maximumANDSum(nums, 6, 3);
  printf("%d\n", result);
  return 0;
}
