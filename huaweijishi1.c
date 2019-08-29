#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int ret = 0;
    int temp;
    for (int i = 1; i < N / 3 + 2; i++) {
        double j = (((double)N * N - 2 * i * N)) / (2 * N - 2 * i);
        temp = (int)j;
        if (i < j && j == temp) {
            ret++;
        }
    }
    printf("%d", ret);
    return 0;
}

