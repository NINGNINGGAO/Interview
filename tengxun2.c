#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort(int* x, int* y, int n) {
    int temp, tmp, increment;
    int j;
    for (increment = n / 2; increment > 0; increment >>= 1) {
        for (int i = increment; i < n; i++) {
            temp = y[i];
            tmp = x[i];
            for (j = i - increment; j > 0 && temp < y[j]; j -= increment) {
                y[j + increment] = y[j];
                x[j + increment] = x[j];
            }
            y[j + increment] = temp;
            x[j + increment] = tmp;
        }
    }
}

int solution(int* x, int* y, int n) {
    int max = 0;
    int head = 0, last = n - 1;
    do {
        if (max < (y[head] + y[last])) {
            max = y[head] + y[last];
        }
        x[head]--;
        x[last]--;
        if (x[head] == 0 && head != last) {
            head++;
        }
        if (x[last] == 0 && head != last) {
            last--;
        }
    } while (head != last || x[head] != 0);
    return max;
}

int main() {
    int n;
    scanf("%d\n", &n);
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(x[i]), &(y[i]));
    }
    Sort(x, y, n);
    int ret = solution(x, y, n);
    printf("%d\n", ret);
    return 0;
}

