#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    int h[n + 1];
    char temp;
    for (int i = 1; i <= n; i++) {
        scanf("%d%c", &(h[i]), &temp);
    }
    int f[n + 1][n + 1];
    int tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            temp = j - 2;

        }
    }

    return 0;
}