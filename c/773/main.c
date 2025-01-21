#include <stdio.h>

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    return -1;
}

int main() {
    /* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ */
    int prices[20];
    int len = 0;

    while (scanf("%d", &prices[len]) != EOF) { len++; };

    int value = slidingPuzzle((int**)&prices, len, &len);
    printf("%d\n", value);
    return 0;
}
