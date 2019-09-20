#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int N;
    scanf("%d\n", &N);
    int temp;
    for (int p = 1; p <= N; p++) {
        int n;
        scanf("%d\n", &n);
        int sum = 0;
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            scanf("%d%c", &(a[i]), &temp);
            sum += a[i];
        }
        int f[sum / 2 + 1][n / 2 + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            for (int j = sum / 2; j >= a[i]; j--) {
                for (int k = n / 2; k >= 1; k--) {
                    f[j][k] = Max(f[j][k], f[j - a[i]][k - 1] + a[i]);
                }
            }
        }
        printf("%d %d\n", f[sum / 2][ n / 2], sum - f[sum / 2][ n / 2]);
    }
    return 0;
}