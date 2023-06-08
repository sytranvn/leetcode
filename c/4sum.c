#include <stdio.h>
#include <stdlib.h>

#define rowsize sizeof(int) * 4
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int **result;
    int maxsize = 10;
    int n = 0;
    result = malloc(rowsize * maxsize);
    for (int i = 0; i < numsSize - 3; i++) {
        for(int j = i +1; j < numsSize -2; j++) {
            for (int k = j + 1; k < numsSize - 1; k++) {
                for (int l = k + 1; l < numsSize; l++) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        n++;
                        printf("%d\n", *returnSize);
                        if (n == maxsize) {
                            maxsize = maxsize * 2;
                            int**temp = realloc(result, rowsize * maxsize);
                            free(result);
                            result = temp;
                        }
                        result[n - 1] = malloc(sizeof(int) * 4);
                        result[n - 1][0] = nums[i];
                        result[n - 1][1] = nums[j];
                        result[n - 1][2] = nums[k];
                        result[n - 1][3] = nums[l];
                        printf("write sucess\n");
                    }
                }
            }
        }
    }
    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));    
    for (int i = 0; i < n; i++)
        (*returnColumnSizes)[i] = 4;
    return result;
}

int main() {
    int * nums = &(int[]){1,0,-1,0,-2,2};
    int numsSize = 5;
    int target = 0;
    int * returnSize;
    int ** returnColumnSizes;
    fourSum(nums, numsSize, target, returnSize, returnColumnSizes);


    return 0;
}
