#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int mid = 5;
    int ret = 0;
    int res[31] = {0};
    for (int i = 0; i <= 28; i++) {
        if (n & mid == mid) {
            res[ret] = i + 3;
            ret++;
        }
        mid <<= 1;
    }
    if (n >= (-1<<30) - 1 && n <= (-1<<29)) {
        res[ret] = 31;
        ret++;
    }
    printf("%d ",ret);
    for (int i = 0; i <= ret; i++) {
        printf(" %d", res[i]);
    }
}