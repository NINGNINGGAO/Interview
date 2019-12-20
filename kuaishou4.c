#include <stdio.h>

int solution(int* stones, int stonesnum) {
    int x, y;
    while(1) {
        y = -1;
        x = -1;
        for (int i = 0; i < stonesnum; i++) {
            if (stones[i] == -1) continue;
            if (y < 0 || stones[i] > stones[y]) y = i;
        }

        for (int i = 0; i < stonesnum; i++) {
            if (stones[i] == -1) continue;

            if ((x < 0 || stones[i] > stones[x]) && (i != y)) x = i;
        }
        if (x == -1 || y == -1) break;
        if (stones[y] == stones[x]) {
            stones[y] = -1;
            stones[x] = -1;
        } else {
            stones[y] -= stones[x];
            stones[x] = -1;
        }
    }
    return y == -1 ? 0 : stones[y];
}

int main() {
    int n;
    scanf("%d\n", &n);
    int stones[n];
    char temp;
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &(stones[i]), &temp);
    }
    int ret = solution(stones, n);
    printf("%d\n", ret);
    return 0;
}