#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    char a[n][m];
    char temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &a[i][j]);
        }
        scanf("%c", &temp);
    }
    int score[m];
    for (int i = 0; i < m; i++) {
        scanf("%d%c", &(score[i]), &temp);
    }
    int flag[5];
    int ret = 0;
    int mid;
    for (int i = 0; i < m; i++) {
        memset(flag, 0, sizeof(flag));
        for (int j = 0; j < n; j++) {
            flag[(int)(a[j][i] - 'A')]++;
        }
        mid = flag[0];
        for (int k = 1; k < 5; k++) {
            if (mid < flag[k]) {
                mid = flag[k];
            }
        }
        ret += (mid * score[i]);
    }
    printf("%d\n", ret);
    return 0;
}