/*
 * @Author: AGOGIN
 * @Date: 2019-09-10 19:30:32
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-10 19:48:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* Counting(int* arr, int pNum, int fNum) {
    int* countSort = malloc(sizeof(int) * fNum);
    memset(countSort, 0, sizeof(int) * fNum);
    for (int i = 0; i < pNum; i++) {
        countSort[arr[i] - 1]++;
    }
    for (int j = 0; j < fNum; j++) {
        countSort[j]++;
    }
    return countSort;
}

int main() {
    int pNum, fNum;
    scanf("%d %d", &pNum, &fNum);
    int arr[pNum], num = 0;
    char temp;
    do {
        scanf("%d%c", &(arr[num]), &temp);
        num++;
    } while (temp != '\n');
    int* countSort = Counting(arr, pNum, fNum);
    int sum = 0;
    for (int i = 0; i < fNum; i++) {
        countSort[i] /= 2;
        sum += countSort[i];
    }
    printf("%d\n", sum);
    return 0;
}