#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int Size;
    int* arr1;
    char* arr2;
};
typedef struct Node* Position;

int main() {
    Position Q = malloc(sizeof(struct Node));
    scanf("%d", &(Q->Size));
    Q->arr1 = malloc(sizeof(int) * Q->Size);
    if (Q->Size == 1) {
        scanf("%d", &(Q->arr1[0]));
        printf("%d", Q->arr1[0]);
    } else if (Q->Size >= 1) {
        Q->arr2 = malloc(sizeof(char) * (Q->Size));
        Q->arr2[Q->Size - 1] = 0;
        for (int i = 0; i < 2 * Q->Size - 1; i++) {
            if (i % 2 == 0) {
                scanf("%d", &(Q->arr1[i>>1]));
            } else {
                scanf(" %c ", &(Q->arr2[i>>1]));
            }
        }
        sort(Q);
        for (int i = 0; i < Q->Size - 1; i++) {
            printf("%d", Q->arr1[i]);
            printf(" %c ", Q->arr2[i]);
        }
        printf("%d\n", Q->arr1[Q->Size - 1]);
    }
    return 0;
}

void sort(Position Q) {
    int p = 1, q = 0;
    int flag = 0;
    int sign = 0;
    for (int i = 0; i < Q->Size - 1; i++) {
        if (flag == 0) {
            if ((Q->arr2[i] == '+') && (i == 0)){
                p = i;
            } else if ((Q->arr2[i] == '*') && (sign == 0)) {
                p = i;
                sign = 1;
            }else {
                p = i + 1;
            }
            flag = 1;
        }
        if (Q->arr2[i] != Q->arr2[i + 1]) {
            flag = 0;
            sign = 1;
            if (Q->arr2[i] == '+' || Q->arr2[i] == '-') {
                sign= 0;
                if (Q->arr2[i + 1] == '*' || Q->arr2[i + 1] == '/') {
                    q = i;
                } else {
                    q = i + 1;
                }
            } else {
                q = i + 1;
            }
            InsertionSort(Q->arr1, p, q);
        }
    }
}

void InsertionSort(int* nums, int p, int q) {
    int key;
    for (int j = p + 1; j <= q; j++) {
        key = nums[j];
        int i = j - 1;
        while (i >= p && nums[i] > key) {
            nums[i + 1] = nums[i];
            i = i - 1;
        }
        nums[i + 1] = key;
    }
}