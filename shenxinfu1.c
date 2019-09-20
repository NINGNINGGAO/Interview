/*
 * @Author: AGOGIN
 * @Date: 2019-09-18 16:31:05
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-18 17:32:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addchar(char* arr, int n) {
    int ret = n;
    int num1 = 1, num2 = 1;
    while (num2 < ret) {
        for (int k = num1; k <= num2; k++) {
            if (arr[k] == '#') {
                for (int i = ret; i >= 2 * k; i--) {
                    arr[i + 2] = arr[i];
                }
                arr[2 * k] = '#';
                arr[2 * k + 1] = '#';
                ret += 2;
            }
        }
        num1 <<= 1;
        num2 <<= 1;
        num2++;
    }
}

void solution(char* arr, int n, int num) {
    if (num <= n) {
        printf("%c\n", arr[num]);
        solution(arr, n, 2 * num);
        solution(arr, n, 2 * num + 1);
    }
}

int main() {
    int n;
    char temp;
    scanf("%d%c", &n, &temp);
    char arr[2 * n];
    for (int i = 1; i <= n; i++) {
        scanf("%c%c", &(arr[i]), &temp);
    }
    arr[n + 1] = '\0';
    printf("\n\n\n");
    int num = addchar(arr, n);
    solution(arr, num, 1);
    return 0;
}