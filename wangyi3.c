/*
 * @Author: AGOGIN
 * @Date: 2019-09-15 16:02:58
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-15 17:13:55
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort(int* s, int* f, int n) {
    int temp, mid;
    for (int i = 0; i < n - 1; i++) {
        mid = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[mid]) {
                mid = j;
            }
        }
        temp = s[mid];
        s[mid] = s[i];
        s[i] = temp;
        temp = f[mid];
        f[mid] = f[i];
        f[i] = temp;
    }
}

int solution(int* s, int* f, int n) {
    Sort(s, f, n);
    int ret = 0;
    int today = 0;
    for (int i = 0; i < n; i++) {
        if (today + f[i] > s[i]) {
            ret = today + f[i] - s[i];
        }
        today += f[i];
    }
    return ret;
}


int main() {
    int n;
    scanf("%d", &n);
    int s[n], f[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(s[i]), &(f[i]));
    }
    int ret = solution(s, f, n);
    printf("%d\n", ret);
    return 0;
}