#include <stdio.h>
#include <stdlib.h>
#define strMax 10000

void solution(char* str1, int num1, char* str2, int num2, int* ret) {
    int max = 0;
    int mid1, mid2;
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            mid1 = i;
            mid2 = j;
            while (mid2 < num2 && str1[mid1] != str2[mid2]) {
                mid2++;
            }
            if (mid2 < num2) {
                while (mid1 < num1 && mid2 < num2 && str1[mid1] == str2[mid2]) {
                    mid1++;
                    mid2++;
                }
                if (max < mid1 - i) {
                    max = mid1 - i;
                    ret[1] = mid1;
                    ret[0] = i;
                }
            }
        }
    }

}


int main() {
    char str1[strMax], str2[strMax];
    int num1 = -1, num2 = -1;
    do {
        num1++;
        scanf("%c", &(str1[num1]));
    } while (str1[num1] != '\n');
    do {
        num2++;
        scanf("%c", &(str2[num2]));
    } while (str2[num2] != '\n');
    int ret[2] = {0};
    solution(str1, num1, str2, num2, ret);
    for (int i = ret[0]; i < ret[1]; i++) {
        printf("%c", str1[i]);
    }
    printf("\n");
    return 0;
}