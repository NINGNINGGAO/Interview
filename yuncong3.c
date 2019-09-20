#include <stdio.h>
#include <string.h>
#define Maxnum 10

int Maxlen(int* nums, int numsSize);

int main() {
    int nums[Maxnum];
    int numsSize = 0;
    char temp;
    do {
        scanf("%d%c", &(nums[numsSize]), &temp);
        numsSize++;
    } while (temp == ',');
    int ret = Maxlen(nums,numsSize);
    printf("%d\n", ret);
    return 0;
}

int Maxlen(int* nums, int numsSize) {
    if (numsSize < 2) {
        return numsSize;
    }
    int ret = 1, temp = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] >= nums[i - 1]) {
            temp++;
        } else {
            temp = 1;
        }
        if (temp > ret) {
            ret = temp;
        }
    }
    return ret;
}