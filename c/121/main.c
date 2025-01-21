#include <stdlib.h>
#include <stdio.h>


int maxProfit(int* prices, int pricesSize) {
    int l = 0, r;
    int *b = malloc(pricesSize);
    int *p = malloc(pricesSize);
    b[0] = 0;
    p[0] = 0;
    for (r=1; r<pricesSize; r++) {
        if (prices[r] < prices[b[r-1]]) {
            b[r] = r;
        } else {
            b[r] = b[r-1];
            if (prices[r] - prices[b[r]] > p[r-1]) {
                p[r] = prices[r] - prices[b[r-1]];
            } else {
                p[r] = p[r-1];
            }
        }
    }
    int result = p[pricesSize-1];
    free(b);
    free(p);
    return p[pricesSize-1];
}

int main() {
    /* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ */
    int prices[20];
    int len = 0;
    int test;

    while (scanf("%d", &prices[len]) != EOF) { len++; };

    int value = maxProfit(prices, len);
    printf("%d\n", value);
    return 0;
}
