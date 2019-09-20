#include <stdio.h>

int main(){
    int n, m, k;
    int ret = 0;
    scanf("%d %d %d", &n, &m, &k);
    int nums[n];
    if (n < 2 || k < 0) {
        return 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &(nums[i]));
    }
    int max = 0;
    int temp = 0;
    if (m >= k + 1) {
        for (int i = 0; i < k; i++) {
            temp += nums[i];
        }
        max = temp;
        for (int i = k; i < n; i++) {
            temp -= nums[i - k];
            temp += nums[i];
            if (max < temp) {
                max = temp;
            }
        }
    } else {
        for (int j = 0; j <= n - 1 - k; j++) {
            temp = SelectionSort(nums, j, j + k, m);
            if (max < temp) {
                max = temp;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}

int SelectionSort(int* nums, int p, int q, int mid) {
    int arr[q - p + 1];
    for (int i = 0; i <= q - p; i++) {
        arr[i] = nums[i + p];
    }
    int i, j, k, temp;
    for (i = 0; i <= q - p; i++) {
        k = i;
        for (j = i + 1; j <= q; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    int max = 0;
    for (i = q - p - mid + 1; i <= q - p; i++) {
        max += arr[i];
    }
    return max;
}
