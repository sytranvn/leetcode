#include <stdio.h>

<<<<<<< HEAD
int maxProfit(int* prices, int pricesSize) {
    int maxVal = 0;
    int b=0;
    int d;
    for (d = 1; d < pricesSize; ++d) {
        if (prices[d] > prices[b]) {
            maxVal += prices[d] - prices[b];
        }
        b = d;
    }
    return maxVal;
}

int main() {
    /* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ */
    int prices[20];
    int len = 0;

    while (scanf("%d", &prices[len]) != EOF) { len++; };

    int value = maxProfit(prices, len);
    printf("%d\n", value);
    return 0;
=======
int maxProfit(int *prices, int pricesSize) {
  int maxVal = 0;
  int b = 0;
  int d;
  for (d = 1; d < pricesSize; ++d) {
    if (prices[d] > prices[b]) {
      maxVal += prices[d] - prices[b];
    }
    b = d;
  }
  return maxVal;
}

int main() {
  /* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ */
  int prices[20];
  int len = 0;

  while (scanf("%d", &prices[len]) != EOF) {
    len++;
  };

  int value = maxProfit(prices, len);
  printf("%d\n", value);
  return 0;
>>>>>>> 92a073f (refactor)
}
