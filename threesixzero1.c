#include <stdio.h>
#include <stdlib.h>

void Sort(int n, int* a, int* t) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}


double solution(int n, int* a, int* t) {
    int v0 = 0;
    double ret = 0;
    for (int i = 0; i < n; i++) {
        ret += v0 * t[i] + (double)a[i] * t[i] * t[i] / 2;
        v0 += a[i] * t[i];
    }
    return ret;
}


int main() {
    int n;
    scanf("%d\n", &n);
    int a[n], t[n];
    char temp;
    for (int i = 0; i < n; i++) {
        scanf("%d %d%c", &(a[i]), &(t[i]), &temp);
    }
    Sort(n, a, t);
    double ret = solution(n, a, t);
    printf("%.1f\n", ret);
    return 0;
}