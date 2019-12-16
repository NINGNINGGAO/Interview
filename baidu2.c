/*
 * @Author: AGOGIN
 * @Date: 2019-09-10 19:56:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-10 20:55:30
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countNum(int* x, int* y, int m, int num, int* ret) {
    for (int i = 0; i <= num; i++) {
        if (x[i] == m && y[i] > 0) {
            y[i]--;
            (*ret)++;
        } else if (x[i] > m && y[i] > 0) {
            if (i > 0) {
                int j = i - 1;
                while (j >= 0) {
                    if (y[j] > 0) {
                        y[j]--;
                        countNum(x, y, m - x[j], j, ret);
                        break;
                    }
                }
            }
        }
    }
}


int countMax(int* x, int* y, int n, int m) {
    int ret = 0;
    int num;
    for (num = n - 1; num >= 0; num--) {
        if (x[num] < m) {
            break;
        }
    }
    for (int i = n - 1; i > num; i--) {
        ret += y[i];
    }
    int temp, mid;
    for (int i = num; i >= 0; i--) {
        while (y[i] != 0) {
            y[i]--;
            countNum(x, y, m - x[i], i, &ret);
        }
    }
}



void Sort(int* x, int* y, int n) {
    int temp, mid;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;

                mid = y[j];
                y[j] = y[j + 1];
                y[j + 1] = mid;
            }
        }
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int x[n], y[n];
    int i = 0;
    do {
        scanf("%d %d", &(x[i]), &(y[i]));
        i++;
    } while (i <= n);
    Sort(x, y, n);
    int ret = countMax(x, y, n, m);
    printf("%d\n", ret);
    return 0;
}