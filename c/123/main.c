#include <stdio.h>

int maxProfit(int *prices, int pricesSize) {
  int p[2] = {0};
  int b = 0;
  int d, np = 0;
  for (d = 0; d < pricesSize; ++d) {
    if (prices[d] > prices[b]) {
      if (prices[d] - prices[b] > np)
        np = prices[d] - prices[b];
    } else {
      if (np > p[0]) {
        p[1] = p[0];
        p[0] = np;
      } else if (np > p[1]) {
        p[1] = np;
      }
      np = 0;
      b = d;
    }
  }
  return p[0] + p[1] + np;
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
}
