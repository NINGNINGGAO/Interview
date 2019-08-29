#include <stdio.h>
#include <string.h>
#define Max(x, y) ((x) > (y) ? (x) : (y))


int main() {
    int lens, num, i , j;
    scanf("%d", &lens);
    int f[lens + 1][lens + 1];
    memset(f, 0, sizeof(f));
    int s[lens], t[lens];
    for (i = 0; i < lens; i++) {
        scanf("%d", &s[i]);
    }
    num= lens;
    for (j = 0; j < num; j++) {
        scanf("%d", &t[j]);
    }
    for (i = 1; i <= lens; i++) {
        for (j = 1 ; j <= num; j++) {
            if (s[i] == t[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Max(f[i - 1][j], Max(f[i][j - 1], f[i - 1][j - 1]));
            }
        }
    }
    printf("%d\n", num - f[lens][num]);
    return 0;
}