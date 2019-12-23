/*
 * @Author: AGOGIN
 * @Date: 2019-10-29 16:45:06
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-29 16:58:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define Len 1000
int* solution(int* nums, int num, int* returnSize) {
    int res[Len];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < num; i++) {
        res[nums[i] / 100]++;
    }
    *returnSize = Len;
    return res;
}

int main() {
    int num = 100000;
    int* nums = malloc(sizeof(int) * num);
    char temp;
    FILE *fpRead=fopen("input.txt","r");
    if(fpRead==NULL) exit(0);
    for(int i = 0; i < 100000; i++) {
        fscanf(fpRead,"%d%c",&(nums[i]), &temp);
    }
    int returnSize;
    int*res = solution(nums, num, &returnSize);
    int min, max;
    for (int i = 0; i < returnSize; i++) {
        min = i * 100 - 100;
        max = i * 100 - 1;
        printf("%d-%d %d", min, max, nums[i]);
    }
    return 0;
}