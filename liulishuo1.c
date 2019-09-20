#include <stdio.h>
#include <stdlib.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))

int solution(int n, int num1, int num2, int* c, int* d) {
    int dp[n + 1][n + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = c[i - 1] + dp[i - 1][0];
        dp[0][i] = d[i - 1] + dp[0][i - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] + Min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[n - i][i] > ret) {
            ret = dp[n - i][i];
        }
    }
    return ret;
}

int main() {
    int n, num1, num2;
    scanf("%d", &n);
    scanf("%d %d", &num1, &num2);
    int c[n], d[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(c[i]), &(d[i]));
    }
    int ret = solution(n, num1, num2, c, d);
    printf("%d\n", ret);
    return 0;
}