/*
 * @Author: AGOGIN
 * @Date: 2019-09-15 17:14:36
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-15 17:55:24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sqrt(int N) {
    int i = 1;
    while (i * i < N) {
        i++;
    }
    return i;
}

int solution(int N, unsigned int* arr) {
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    if (N == 1) {
        return arr[1];
    } else if (N == 2) {
        return arr[2];
    }
    unsigned int flag1, flag2;
    for (unsigned int i = 3; i <= N; i++) {
        flag1 = 0, flag2 = 0;
        if (i % 2 == 0) {
            flag1 = 2;
            flag2 = i / 2;
        } else {
            for (int j = 3; j <= sqrt(i); j = j + 2) {
                if (i % j == 0) {
                    flag1 = j;
                    flag2 = i / j;
                }
            }
        }
        if (flag1 != 0) {
            if (flag1 != flag2) {
                arr[i] = i - 1 - arr[flag1] - arr[flag2];
            } else {
                arr[i] = i - 1 - arr[flag1];
            }
        } else {
            arr[i] = i - 1;
        }
    }
}


int main() {
    unsigned int N;
    scanf("%d", &N);
    unsigned int arr[N + 1];
    solution(N, arr);
    double ret[N + 1];
    double Fin = 1;
    for (unsigned int i = 1; i <= N; i++) {
        ret[i] = (double)arr[i] / i;
        if (ret[i] < Fin) {
            Fin = ret[i];
        }
    }
    printf("%lf\n", Fin);
    return 0;
}