/*
 * @Author: AGOGIN
 * @Date: 2019-09-15 14:08:02
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-15 14:38:55
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort(int* weight, int* height, int N) {
    int area[N];
    double WH[N];
    for (int i = 0; i < N; i++) {
        area[i] = weight[i] * height[i];
        WH[i] = (double)weight[i] / height[i];
        if (WH[i] > 1) {
            WH[i] = (double)height[i] / weight[i];
        }
    }
    int temp, mid;
    for (int i = 0; i < N - 1; i++) {
        mid = i;
        for (int j = i + 1; j < N; j++) {
            if (area[j] < area[mid]) {
                mid = j;
            } else if (area[j] == area[mid]) {
                if (WH[j] > WH[mid]) {
                    mid = j;
                } else if (WH[j] == WH[mid]) {
                    if (weight[j] < weight[mid]) {
                        mid = j;
                    }
                }
            }
        }
        temp = area[mid];
        area[mid] = area[i];
        area[i] = temp;
        temp = WH[mid];
        WH[mid] = WH[i];
        WH[i] = temp;
        temp = weight[mid];
        weight[mid] = weight[i];
        weight[i] = temp;
        temp = height[mid];
        height[mid] = height[i];
        height[i] = temp;
    }
}


int main() {
    int N;
    scanf("%d", &N);
    int weight[N], height[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &(weight[i]));
        scanf("%d", &(height[i]));
    }
    Sort(weight, height, N);
    printf("%d %d", weight[0], height[0]);
    for (int i = 1; i < N; i++) {
        printf(" %d %d",weight[i], height[i]);
    }
    printf("\n");
    return 0;
}