#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort(int* a, int n, int* b, int min) {
    for (int i = 0; i < n; i++) {
        b[a[i] - min]++;
    }
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    int a[n];
    char temp;
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &a[i], &temp);
    }
    int min = a[0], max = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
        if (max < a[i]) {
            max = a[i];
        }
    }
    int* b = malloc(sizeof(int) * (max - min + 1));
    memset(b, 0, sizeof(b));
    int num = max - min + 1;
    Sort(a, n, b, min);
    int mid;
    for (int i = 0; i < m; i++) {
        scanf("%d\n", &mid);
        if (mid > max || mid < min) {
            printf("%d\n", 0);
        }else {
            printf("%d\n", b[mid - min]);
        }
    }
    return 0;
}