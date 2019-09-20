#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



int main() {
    int n, k;
    scanf("%d %d\n", &n, &k);
    int a[n];
    char temp;
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &(a[i]), &temp);
    }
    int min;
    for (int i = 0; i < k; i++) {
        int flag = 0;
        min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (min >= a[j] && a[j] != 0) {
                min = a[j];
                flag = 1;
            }
        }
        if (flag == 1) {
            for (int j = 0; j < n; j++) {
                if (a[j] != 0) {
                    a[j] -= min;
                }
            }
            printf("%d\n", min);
        } else {
            printf("%d\n", 0);
        }
    }
    return 0;
}