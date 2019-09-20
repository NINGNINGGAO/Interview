#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int main() {
    int n;
    scanf("%d\n", &n);
    int a[n], b[n];
    char temp;
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &(a[i]), &temp);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &(b[i]), &temp);
    }
    int ret = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp = a[i] + b[j];
            ret = ret ^ tmp;
        }
    }
    printf("%d\n", ret);
    return 0;
}