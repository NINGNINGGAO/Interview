#include <stdio.h>
#include <string.h>
int Num(int* arr, int n, int k, int i);
void SelectionSort(int* nums, int p, int q);

int main(){
    int n, k;
    int ret = 0;
    scanf("%d %d", &n, &k);
    int nums[n];
    memset(nums, 0, n);
    if (n < 2 || k < 0) {
        goto endll;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &(nums[i]));
        if (nums[i] <= 0) {
            goto endll;
        }
    }
    SelectionSort(nums, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        ret += Num(nums, n, k, i);
    }
    endll:
        printf("%d\n", ret);
    return 0;
}

int Num(int* arr, int n, int k, int i) {
    int res = 0;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] - arr[i] <= k) {
            res++;
        } else {
            break;
        }
    }
    return res;
}

void SelectionSort(int* nums, int p, int q) {
    int i, j, k, temp;
    for (i = p; i < q; i++) {
        k = i;
        for (j = i + 1; j <= q; j++) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}

