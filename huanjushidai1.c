#include <stdio.h>
#include <stdlib.h>

void solution(int** arr, int n, int m, int** flag) {
    int mat[n][m];
    mat[0][0] = arr[0][0];
    flag[0] = (int*)malloc(sizeof(int) * m);
    for (int i = 1; i < n; i++) {
        flag[i] = (int*)malloc(sizeof(int) * m);
        mat[i][0] += arr[i - 1][0];
        flag[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
        mat[0][i] += arr[0][i - 1];
        flag[0][i] = -1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i - 1][j] <= mat[i][j - 1]) {
                mat[i][j] = mat[i - 1][j] + arr[i][j];
                flag[i][j] = 1;
            } else {
                mat[i][j] = mat[i][j - 1] + arr[i][j];
                flag[i][j] = -1;
            }
        }
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &(arr[i][j]));
        }
    }
    int *flag[n];
    solution(arr, n, m, flag);
    int i = n - 1, j = m - 1;
    int ret1[n + m], ret2[n + m];
    int num = 0;
    while (i != 0 || j != 0) {
        if (flag[i][j] == 1) {
            ret1[num] = i;
            ret2[num] = j;
            num++;
            i--;
        } else if (flag[i][j] == -1) {
            ret1[num] = i;
            ret2[num] = j;
            num++;
            j--;
        }
    }
    ret1[num] = 0;
    ret2[num] = 0;
    for (int k = num; k >= 0; k--) {
        printf("%d %d\n", ret1[k], ret2[k]);
    }
    return 0;
}