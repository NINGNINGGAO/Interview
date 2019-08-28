#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
    int N;
    scanf("%d", &N);
    int array[N][N];
    int flag[N];
    memset(flag, 0,sizeof(flag));
    memset(array, 0, sizeof(array));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &(array[i][j]));
        }
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (flag[i] == 0) {
            ret++;
            flag[i] = 1;
            dfs(array, N, flag, i);
        }
    }
    printf("%d\n", ret);
}

void dfs(int* array, int N, int* flag, int y) {
    for (int i = 0; i < N; i++) {
        if (flag[i] == 0 && array[y * N + i] >= 3) {
            flag[i] = 1;
            dfs(array, N, flag, i);
        }
    }
}