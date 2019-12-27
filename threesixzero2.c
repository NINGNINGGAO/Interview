#include <stdio.h>
#include <stdlib.h>

double solve(int* sum, int i, int j) {
    return 1.0 * (sum[i] - sum[j]) / (i - j);
}

int main() {
    int N, M;
    scanf("%d %d\n", &N, &M);
    int a[N + 1];
    int sum[N + 1];
    sum[0] = 0;
    int q[N + 1];
    double dp[N + 1];
    char temp;
    for (int i = 1; i <= N; i++) {
        scanf("%d%c", &(a[i]), &temp);
        sum[i] = sum[i - 1] + a[i];
    }
    int head, tail;
    head = tail = 0;
    double ret = 0;
    for (int i = M; i <= N; i++) {
        while (head < tail && solve(sum, i, ))
    }


    return 0;
}